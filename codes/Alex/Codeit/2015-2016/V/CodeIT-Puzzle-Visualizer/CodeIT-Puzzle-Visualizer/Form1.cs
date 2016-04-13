using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace CodeIT_Puzzle_Visualizer
{
    public partial class Form1 : Form
    {
        bool Paused = false;
        string OutputFile;
        Bitmap Puzzle = new Bitmap(600, 600);
        Bitmap InitialPuzzle = new Bitmap(600, 600);
        Bitmap Original = new Bitmap(600, 600);
        Bitmap RemovedColor = new Bitmap(20, 20);
        int x = 0, y = 0 , bs=0;
        bool xflag = true, yflag = true, movesflag = true;
        string Moves = "";
        int ClickCount = 0;
        int Points;
        int InitX, InitY;

        public void InputParser(string inFilePath)
        {
            GetInputFileStatusLabel.Text = "Rendering Images ...";
            StreamReader inpFile = new StreamReader(inFilePath);
            string inFile = inpFile.ReadToEnd();
            inpFile.Close();
            int l = inFile.Length;
            int numbersCnt;
            int cn, cnl = 0;
            int flag = 0, bsfl=0;
            int[,] inImgColors = new int[400, 600];
            int i, j;
            numbersCnt = 0;
            cn = 0;

            for (i = 0; i < l; i++)
            {
                if (Char.IsWhiteSpace(inFile, i) && cnl > 0)
                {
                    if (bsfl == 0)
                    {
                        bs = cn;
                        cn = 0;
                        cnl = 0;
                        bsfl = 1;
                    }
                    else
                    {
                        if (numbersCnt >= 400 * 600)
                        {
                            numbersCnt = 400 * 600 + 5555;
                            break;
                        }
                        else
                        {
                            if(cn<0||cn>255)
                            {
                                GetInputFileStatusLabel.Text = "You cant have color intensity less than 0 and bigger than 255";
                                flag = 1;
                                break;
                            }
                            inImgColors[numbersCnt / 600, numbersCnt % 600] = cn;
                            numbersCnt++;
                            cn = 0;
                            cnl = 0;
                        }
                    }
                }
                else
                {
                    if (Char.IsWhiteSpace(inFile, i))
                    {
                        continue;
                    }
                    else
                    {
                        if (inFile[i] >= '0' && inFile[i] <= '9')
                        {
                            cnl++;
                            cn *= 10;
                            cn += inFile[i] - '0';
                        }
                        else
                        {
                            GetInputFileStatusLabel.Text = "There Are Symbols That Are Not Numbers In this Input";
                            flag = 1;
                            break;
                        }
                    }
                }
            }

            if (numbersCnt != 400 * 600 && flag==0)
            {
                GetInputFileStatusLabel.Text = "The Images you try to enter are not 200*200";
            }
            else
            {
                if (bs == 1 || bs == 2 || bs == 5 || bs == 10 || bs == 20)
                {
                    GetInputFileStatusLabel.Text = "The Input File is OK";
                    Color cc = Color.FromArgb(100, 100, 100, 100);
                    int ti, tj;

                    for (i = 0; i < 200; i++)
                    {
                        for (j = 0; j < 600; j += 3)
                        {
                            cc = Color.FromArgb(255, inImgColors[i, j], inImgColors[i, j + 1], inImgColors[i, j + 2]);
                            tj = j / 3;
                            Puzzle.SetPixel(3 * tj, 3 * i + 1, cc);
                            Puzzle.SetPixel(3 * tj, 3 * i + 2, cc);
                            Puzzle.SetPixel(3 * tj, 3 * i, cc);
                            Puzzle.SetPixel(3 * tj + 1, 3 * i + 1, cc);
                            Puzzle.SetPixel(3 * tj + 1, 3 * i + 2, cc);
                            Puzzle.SetPixel(3 * tj + 1, 3 * i, cc);
                            Puzzle.SetPixel(3 * tj + 2, 3 * i + 1, cc);
                            Puzzle.SetPixel(3 * tj + 2, 3 * i + 2, cc);
                            Puzzle.SetPixel(3 * tj + 2, 3 * i, cc);

                            InitialPuzzle.SetPixel(3 * tj, 3 * i + 1, cc);
                            InitialPuzzle.SetPixel(3 * tj, 3 * i + 2, cc);
                            InitialPuzzle.SetPixel(3 * tj, 3 * i, cc);
                            InitialPuzzle.SetPixel(3 * tj + 1, 3 * i + 1, cc);
                            InitialPuzzle.SetPixel(3 * tj + 1, 3 * i + 2, cc);
                            InitialPuzzle.SetPixel(3 * tj + 1, 3 * i, cc);
                            InitialPuzzle.SetPixel(3 * tj + 2, 3 * i + 1, cc);
                            InitialPuzzle.SetPixel(3 * tj + 2, 3 * i + 2, cc);
                            InitialPuzzle.SetPixel(3 * tj + 2, 3 * i, cc);
                        }
                    }

                    MessedUpPicture.Image = Puzzle;


                    for (i = 200; i < 400; i++)
                    {
                        for (j = 0; j < 600; j += 3)
                        {
                            cc = Color.FromArgb(255, inImgColors[i, j], inImgColors[i, j + 1], inImgColors[i, j + 2]);
                            ti = i - 200;
                            tj = j / 3;
                            Original.SetPixel(3 * tj, 3 * ti + 1, cc);
                            Original.SetPixel(3 * tj, 3 * ti + 2, cc);
                            Original.SetPixel(3 * tj, 3 * ti, cc);
                            Original.SetPixel(3 * tj + 1, 3 * ti + 1, cc);
                            Original.SetPixel(3 * tj + 1, 3 * ti + 2, cc);
                            Original.SetPixel(3 * tj + 1, 3 * ti, cc);
                            Original.SetPixel(3 * tj + 2, 3 * ti + 1, cc);
                            Original.SetPixel(3 * tj + 2, 3 * ti + 2, cc);
                            Original.SetPixel(3 * tj + 2, 3 * ti, cc);
                        }
                    }

                    OriginalPucture.Image = Original;
                }
                else
                {
                    GetInputFileStatusLabel.Text = "The block size Is Not Correct";
                }
            }
        }
        public void OutputParser(string outFilePath)
        {
            StreamReader outpFile = new StreamReader(outFilePath);
            OutputFile = outpFile.ReadToEnd();
            outpFile.Close();

            int i, chl = 0;
            for (i = 0; i < OutputFile.Length; i++)
            {
                if (Char.IsWhiteSpace(OutputFile, i) == true)
                {
                    if (chl == 0)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if (OutputFile[i] >= '0' && OutputFile[i] <= '9')
                {
                    x *= 10;
                    x += OutputFile[i] - '0';
                    chl++;
                }
                else
                {
                    xflag = false;
                    break;
                }

            }

            chl = 0;

            if (xflag == true)
            {
                for (i = i + 1; i < OutputFile.Length; i++)
                {

                    if (Char.IsWhiteSpace(OutputFile, i) == true)
                    {
                        if (chl == 0)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (OutputFile[i] >= '0' && OutputFile[i] <= '9')
                    {
                        y *= 10;
                        y += OutputFile[i] - '0';
                        chl++;
                    }
                    else
                    {
                        yflag = false;
                    }
                }
                if (yflag == true)
                {
                    int h = x;
                    x = y;
                    y = h;

                    for (i = i + 1; i < OutputFile.Length; i++)
                    {

                        if (OutputFile[i] == 'L' || OutputFile[i] == 'R' || OutputFile[i] == 'D' || OutputFile[i] == 'U' || Char.IsWhiteSpace(OutputFile, i) == true)
                        {
                            if (Char.IsWhiteSpace(OutputFile, i) != true)
                            {
                                Moves += OutputFile[i];
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                        {
                            movesflag = false;
                        }
                    }
                    if (movesflag == false)
                    {
                        GetOutputFileStatusLabel.Text = "Invalid Move Command";
                        ResultText.Show();
                        PointsValue.Show();
                        PointsValue.Text = "-1";
                    }
                }
            }

            if (xflag == true && yflag == true && movesflag == true)
            {
                x *= bs;
                y *= bs;
                
                InitX = x;
                InitY = y;
                GetOutputFileStatusLabel.Text = "The Ouput File is OK";
            }
        }
        public void Visualization(int ClickCnt)
        {
            int i, j;
            Color cc = new Color();
            Color NewColor = new Color();
            Color OldColor = new Color();
            double cPixelPoints = 0;

            if (ClickCnt == 0)
            {
                if (x >= 0 && x <= 200-bs && y >= 0 && y <= 200-bs)
                {
                    for (i = x; i < x + bs; i++)
                    {
                        for (j = y; j < y + bs; j++)
                        {
                            RemovedColor.SetPixel(i-x,j-y,InitialPuzzle.GetPixel(3 * i, 3 * j));

                            cc = Color.Black;
                            Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                            cc = Color.Red;
                            Puzzle.SetPixel(3 * i, 3 * j, cc);
                            Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                            Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                            Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                            Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                            Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                            Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                            Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);
                        }
                    }

                    if (NextMoveInterval.Value == -1)
                    {
                        XValue.Text = (x / bs).ToString();
                        YValue.Text = (y / bs).ToString();
                    }
                    else
                    {
                        if(NextMoveInterval.Value ==0)
                        {
                            NextMoveButton.Text = "Next Move";
                            XValue.Text = (x / bs).ToString();
                            YValue.Text = (y / bs).ToString();
                        }
                        else
                        {
                            MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                            MoveIntervalTimer.Enabled = true;
                            XValue.Text = (x/bs).ToString();
                            YValue.Text = (y/bs).ToString();
                        }
                    }
                    MessedUpPicture.Image = Puzzle;
                }
                else
                {
                    ExecutionStatusLabel.Text = "The block you want to remove is not within the image";
                    XValue.Text = "-1";
                    YValue.Text = "-1";
                    PointsValue.Text = "-1";
                    PointsValue.Show();
                    ResultText.Show();
                    PauseButton.Hide();
                    ReplayButton.Show();
                    MoveNumber.Text = ClickCnt.ToString();

                    NextMoveButton.Hide();
                    MoveIntervalTimer.Enabled = false;
                }
            }
            else
            {
                if (ClickCnt > Moves.Length)
                {
                    NextMoveButton.Hide();
                    MoveIntervalTimer.Enabled = false;
                    ExecutionStatusLabel.Text = "Execution Finished Succesfully";
                    PauseButton.Hide();
                    ReplayButton.Show();
                    XValue.Text = x.ToString();
                    YValue.Text = y.ToString();

                    for (i = x; i < x + bs; i++)
                    {
                        for (j = y; j < y + bs; j++)
                        {
                            Puzzle.SetPixel(3 * i, 3 * j, RemovedColor.GetPixel(i-x, j-y));
                            Puzzle.SetPixel(3 * i + 1, 3 * j, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i + 2, 3 * j, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i, 3 * j + 1, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i + 1, 3 * j + 1, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i + 2, 3 * j + 1, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i, 3 * j + 2, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i + 1, 3 * j + 2, RemovedColor.GetPixel(i - x, j - y));
                            Puzzle.SetPixel(3 * i + 2, 3 * j + 2, RemovedColor.GetPixel(i - x, j - y));
                        }
                    }

                    MessedUpPicture.Image = Puzzle;

                    for (i = 0; i < 200; i++)
                    {
                        for (j = 1; j < 200; j++)
                        {
                            NewColor = Puzzle.GetPixel(3 * i, 3 * j);
                            OldColor = Original.GetPixel(3 * i, 3 * j);
                            cPixelPoints = Math.Sqrt((NewColor.R - OldColor.R) * (NewColor.R - OldColor.R) + (NewColor.B - OldColor.B) * (NewColor.B - OldColor.B) + (NewColor.G - OldColor.G) * (NewColor.G - OldColor.G));
                            Points += (int)Math.Floor(cPixelPoints);
                        }
                    }
                    ResultText.Show();
                    PointsValue.Show();
                    ResultText.Show();
                    PointsValue.Text = Points.ToString();
                }
                else
                {
                    Points += 1;
                    ExecutionStatusLabel.Text = "Current Move: " + Moves[ClickCnt - 1];

                    switch (Moves[ClickCnt - 1])
                    {

                        case 'R':
                            x += bs;
                            if (x >= 0 && x <= 200 - bs && y >= 0 && y <= 200 - bs)
                            {
                                XValue.Text = (x/bs).ToString();
                                YValue.Text = (y/bs).ToString();
                                MoveNumber.Text = ClickCnt.ToString();

                                for (i = x; i < x + bs; i++)
                                {
                                    for (j = y; j < y + bs; j++)
                                    {
                                        cc = Puzzle.GetPixel(3 * i, 3 * j);
                                        i-=bs;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);

                                        i+=bs;
                                        cc = Color.Black;
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        cc = Color.Red;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);
                                    }
                                }

                                if ((int)NextMoveInterval.Value == -1)
                                {
                                }
                                else
                                {
                                    MessedUpPicture.Image = Puzzle;
                                    if((int)NextMoveInterval.Value == 0)
                                    {
                                        NextMoveButton.Show();
                                    }
                                    else
                                    {
                                        MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                                        MoveIntervalTimer.Enabled = true;
                                    }
                                }
                            }
                            else
                            {
                                ExecutionStatusLabel.Text = "The block you want to remove is outside of the image";
                                XValue.Text = "-1";
                                YValue.Text = "-1";
                                PointsValue.Text = "-1";
                                PointsValue.Show();
                                ResultText.Show();
                                PauseButton.Hide();
                                ReplayButton.Show();
                                MoveNumber.Text = ClickCnt.ToString();

                                NextMoveButton.Hide();
                                MoveIntervalTimer.Enabled = false;
                            }
                            break;
                        case 'L':
                            x-=bs;
                            if (x >= 0 && x <= 200 - bs && y >= 0 && y <= 200 - bs)
                            {
                                XValue.Text = (x / bs).ToString();
                                YValue.Text = (y / bs).ToString();
                                MoveNumber.Text = ClickCnt.ToString();

                                for (i = x; i < x + bs; i++)
                                {
                                    for (j = y; j < y + bs; j++)
                                    {
                                        cc = Puzzle.GetPixel(3 * i, 3 * j);
                                        i+=bs;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);

                                        i-=bs;
                                        cc = Color.Black;
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        cc = Color.Red;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);
                                    }
                                }

                                if ((int)NextMoveInterval.Value == -1)
                                {
                                }
                                else
                                {
                                    MessedUpPicture.Image = Puzzle;
                                    if ((int)NextMoveInterval.Value == 0)
                                    {
                                        NextMoveButton.Show();
                                    }
                                    else
                                    {
                                        MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                                        MoveIntervalTimer.Enabled = true;
                                    }
                                }
                            }
                            else
                            {
                                ExecutionStatusLabel.Text = "The block you want to remove is outside of the image";
                                XValue.Text = "-1";
                                YValue.Text = "-1";
                                PointsValue.Text = "-1";
                                PointsValue.Show();
                                ResultText.Show();
                                PauseButton.Hide();
                                ReplayButton.Show();
                                MoveNumber.Text = ClickCnt.ToString();

                                NextMoveButton.Hide();
                                MoveIntervalTimer.Enabled = false;
                            }
                            break;
                        case 'U':
                            y-=bs;
                            if (x >= 0 && x <= 200 - bs && y >= 0 && y <= 200 - bs)
                            {
                                XValue.Text = (x / bs).ToString();
                                YValue.Text = (y / bs).ToString();
                                MoveNumber.Text = ClickCnt.ToString();

                                for (i = x; i < x + bs; i++)
                                {
                                    for (j = y; j < y + bs; j++)
                                    {
                                        cc = Puzzle.GetPixel(3 * i, 3 * j);
                                        j+=bs;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);

                                        j-=bs;
                                        cc = Color.Black;
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        cc = Color.Red;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);
                                    }
                                }

                                if ((int)NextMoveInterval.Value == -1)
                                {
                                }
                                else
                                {
                                    MessedUpPicture.Image = Puzzle;
                                    if ((int)NextMoveInterval.Value == 0)
                                    {
                                        NextMoveButton.Show();
                                    }
                                    else
                                    {
                                        MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                                        MoveIntervalTimer.Enabled = true;
                                    }
                                }
                            }
                            else
                            {
                                ExecutionStatusLabel.Text = "The block you want to remove is outside of the image";
                                XValue.Text = "-1";
                                YValue.Text = "-1";
                                PointsValue.Text = "-1";
                                PointsValue.Show();
                                ResultText.Show();
                                PauseButton.Hide();
                                ReplayButton.Show();
                                MoveNumber.Text = ClickCnt.ToString();

                                NextMoveButton.Hide();
                                MoveIntervalTimer.Enabled = false;
                            }
                            break;
                        case 'D':
                            y+=bs;
                            if (x >= 0 && x <= 200 - bs && y >= 0 && y <= 200 - bs)
                            {
                                XValue.Text = (x / bs).ToString();
                                YValue.Text = (y / bs).ToString();
                                MoveNumber.Text = ClickCnt.ToString();

                                for (i = x; i < x + bs; i++)
                                {
                                    for (j = y; j < y + bs; j++)
                                    {
                                        cc = Puzzle.GetPixel(3 * i, 3 * j);
                                        j-=bs;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);

                                        j+=bs;
                                        cc = Color.Black;
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 1, cc);
                                        cc = Color.Red;
                                        Puzzle.SetPixel(3 * i, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 1, cc);
                                        Puzzle.SetPixel(3 * i, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 1, 3 * j + 2, cc);
                                        Puzzle.SetPixel(3 * i + 2, 3 * j + 2, cc);
                                    }
                                }

                                if ((int)NextMoveInterval.Value == -1)
                                {
                                }
                                else
                                {
                                    MessedUpPicture.Image = Puzzle;
                                    if ((int)NextMoveInterval.Value == 0)
                                    {
                                        NextMoveButton.Show();
                                    }
                                    else
                                    {
                                        MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                                        MoveIntervalTimer.Enabled = true;
                                    }
                                }
                            }
                            else
                            {
                                ExecutionStatusLabel.Text = "The block you want to remove is outside of the image";
                                XValue.Text = "-1";
                                YValue.Text = "-1";
                                PointsValue.Text = "-1";
                                PointsValue.Show();
                                ResultText.Show();
                                PauseButton.Hide();
                                ReplayButton.Show();
                                MoveNumber.Text = ClickCnt.ToString();

                                NextMoveButton.Hide();
                                MoveIntervalTimer.Enabled = false;
                            }
                            break;
                    }
                }
            }
        }

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            testGenGetImageDialog.Filter = "Images (*.JPG)|*.JPG";
            GetInputFileDialog.Filter = "Text Files (*.in)|*.in";
            GetOutputFileDialog.Filter = "Text Files (*.out)|*.out";
            ChooseSolutionFileDialog.Filter = "Executables (*.exe)|*.exe";
        }
        private void testButton_Click(object sender, EventArgs e)  
        {
            int i, j,i1,i2,j1,j2,i3,j3, swpcnt,rbs;

            int[,] tgiRed = new int[200, 200];
            int[,] tgiGreen = new int[200, 200];
            int[,] tgiBlue = new int[200, 200];

            int[,] tgiMRed = new int[200, 200];
            int[,] tgiMGreen = new int[200, 200];
            int[,] tgiMBlue = new int[200, 200];

            DialogResult result = testGenGetImageDialog.ShowDialog();
            Random rnd = new Random();
            Bitmap testGenImage;

            if (result == DialogResult.OK)
            {
                StreamWriter testGenFileOut = new StreamWriter("puzzle.in");
                testGenImage = new Bitmap(testGenGetImageDialog.FileName);

                if (testGenImage.Width != 200 || testGenImage.Height != 200)
                {
                    testGenStatusLabel.Text = "The image is with  wrong size. Please enter another one with size 200x200!";
                }
                else
                {
                    testGenStatusLabel.Text = "Generating the test data ... ";
                    for (i = 0; i < 200; i++)
                    {
                        for (j = 0; j < 200; j++)
                        {
                            Color currentPixel = testGenImage.GetPixel(j,i);
                            tgiRed[i,j] = currentPixel.R;
                            tgiGreen[i,j] = currentPixel.G;
                            tgiBlue[i,j] = currentPixel.B;
                            tgiMRed[i,j] = currentPixel.R;
                            tgiMGreen[i,j] = currentPixel.G;
                            tgiMBlue[i,j] = currentPixel.B;
                        }
                    }

                    swpcnt = rnd.Next(0, 7000);
                    rbs = rnd.Next(0, 4);

                    switch (rbs)
                    {
                        case 0:  rbs = 1; break;
                        case 1:  rbs = 2;  break;
                        case 2:  rbs = 5; break;
                        case 3:  rbs = 10; break;
                        case 4:  rbs = 20; break;
                    }

                    //rbs = ;
                    //swpcnt = ;

                    if (rbs == 1 || rbs == 2 || rbs == 5 || rbs == 10 || rbs == 20)
                    {
                        testGenFileOut.Write(rbs); testGenFileOut.Write("\n");

                        int hlp;
                        for (i = 0; i < swpcnt; i++)
                        {

                            i1 = rnd.Next(0, 200 / rbs);
                            i2 = rnd.Next(0, 200 / rbs);
                            j1 = rnd.Next(0, 200 / rbs);
                            j2 = rnd.Next(0, 200 / rbs);

                            i1 *= rbs;
                            i2 *= rbs;
                            j1 *= rbs;
                            j2 *= rbs;

                            for (i3 = 0; i3 < rbs; i3++)
                            {
                                for (j3 = 0; j3 < rbs; j3++)
                                {
                                    hlp = tgiMRed[i1 + i3, j1 + j3];
                                    tgiMRed[i1 + i3, j1 + j3] = tgiMRed[i2 + i3, j2 + j3];
                                    tgiMRed[i2 + i3, j2 + j3] = hlp;

                                    hlp = tgiMGreen[i1 + i3, j1 + j3];
                                    tgiMGreen[i1 + i3, j1 + j3] = tgiMGreen[i2 + i3, j2 + j3];
                                    tgiMGreen[i2 + i3, j2 + j3] = hlp;

                                    hlp = tgiMBlue[i1 + i3, j1 + j3];
                                    tgiMBlue[i1 + i3, j1 + j3] = tgiMBlue[i2 + i3, j2 + j3];
                                    tgiMBlue[i2 + i3, j2 + j3] = hlp;
                                }
                            }
                        }

                        for (i = 0; i < 200; i++)
                        {
                            for (j = 0; j < 200; j++)
                            {
                                testGenFileOut.Write(tgiMRed[i, j]);
                                testGenFileOut.Write(" ");
                                testGenFileOut.Write(tgiMGreen[i, j]);
                                testGenFileOut.Write(" ");
                                testGenFileOut.Write(tgiMBlue[i, j]);
                                testGenFileOut.Write(" ");
                            }
                            testGenFileOut.Write("\n");
                        }

                        for (i = 0; i < 200; i++)
                        {
                            for (j = 0; j < 200; j++)
                            {
                                testGenFileOut.Write(tgiRed[i, j]);
                                testGenFileOut.Write(" ");
                                testGenFileOut.Write(tgiGreen[i, j]);
                                testGenFileOut.Write(" ");
                                testGenFileOut.Write(tgiBlue[i, j]);
                                testGenFileOut.Write(" ");
                            }
                            testGenFileOut.Write("\n");
                        }

                        testGenFileOut.Close();
                        testGenStatusLabel.Text = "Test File Done";
                    }
                    else
                    {
                         testGenStatusLabel.Text = "You have entered invalid block size!";
                    }
                }
                testGenFileOut.Close();
            }
            else
            {
                testGenStatusLabel.Text = "No Image Was Choosed. Please Try Again";
            }
        }
        private void chooseInputFileButton_Click(object sender, EventArgs e)
        {
            DialogResult result = GetInputFileDialog.ShowDialog();
            string inFilePath = GetInputFileDialog.FileName;
            if(result == DialogResult.OK)
            {
                InputParser(inFilePath);

                if (GetInputFileStatusLabel.Text == "The Input File is OK" && GetOutputFileStatusLabel.Text == "The Ouput File is OK")
                {
                    StartVisualisationButton.Show();
                    UIText1.Show();
                    NextMoveInterval.Show();
                    ExecutionStatusLabel.Show();
                    ResultText.Show();
                    PointsValue.Show();
                    RunSolutionButton.Hide();
                    RunSolutionStatusLabel.Hide();
                }
            }
            else
            {
                GetInputFileStatusLabel.Text = "No Input File Was Selected. Please Try Again";
            }
        }
        private void chooseOutputFileButton_Click(object sender, EventArgs e)
        {
            DialogResult result = GetOutputFileDialog.ShowDialog();
                        
            if (result == DialogResult.OK)
            {
                string outFilePath = GetOutputFileDialog.FileName;

                OutputParser(outFilePath);

                if (GetInputFileStatusLabel.Text == "The Input File is OK" && GetOutputFileStatusLabel.Text == "The Ouput File is OK")
                {
                    StartVisualisationButton.Show();
                    UIText1.Show();
                    NextMoveInterval.Show();
                    ExecutionStatusLabel.Show();
                    ExecutionStatusLabel.Text = "The Execution Is ready To Start";
                    RunSolutionButton.Hide();
                    RunSolutionStatusLabel.Hide();
                }
            }
            else
            {
                GetOutputFileStatusLabel.Text = "No Output File Was Choosed. Please Try Again";
            }
        }
        private void StartVisualisationButton_Click(object sender, EventArgs e)
        {
            RunSolutionButton.Hide();
            RunSolutionStatusLabel.Hide();
            NextMoveInterval.Hide();
            EmptySquareText.Show();
            XText.Show();
            YText.Show();
            XValue.Show();
            YValue.Show();
            MoveNumberText.Show();
            MoveNumber.Show();

            testGenStatusLabel.Hide();
            GetInputFileStatusLabel.Hide();
            GetOutputFileStatusLabel.Hide();
            testButton.Hide();
            chooseInputFileButton.Hide();
            chooseOutputFileButton.Hide();
            StartVisualisationButton.Hide();
            UIText1.Hide();
            StopExecutionButton.Show();

            if (NextMoveInterval.Value == 0)
            {
                NextMoveButton.Show();
                NextMoveButton.Text = "Remove Zone";
            }
            else
            {
                if (NextMoveInterval.Value > 0)
                {
                    MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                    MoveIntervalTimer.Enabled = true;
                    PauseButton.Show();
                }
                else
                {
                    NextMoveButton.Hide();
                    for (ClickCount = 0; ClickCount <= Moves.Length +1; ClickCount++)
                    {
                        Visualization(ClickCount);
                    }
                }
            }
        }
        private void MoveIntervalTimer_Tick(object sender, EventArgs e)
        {
            if (Paused == true)
            {
                MoveIntervalTimer.Interval = (int)NextMoveInterval.Value;
                MoveIntervalTimer.Enabled = true;
            }
            else
            {
                Visualization(ClickCount);
                ClickCount++;
            }
        }
        private void StopExecutionButton_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }
        private void RunSolution_Click(object sender, EventArgs e)
        {
            
            DialogResult result = ChooseSolutionFileDialog.ShowDialog();
            int i, j;
            if (result == DialogResult.OK)
            {
                string SolutionPath = ChooseSolutionFileDialog.FileName;
                string InOutPath = "";
                RunSolutionStatusLabel.Show();
                Process RunSolution = new Process();

                try
                {
                    RunSolution.StartInfo.FileName = SolutionPath;
                    var watch = System.Diagnostics.Stopwatch.StartNew();
                    RunSolution.Start();
                    RunSolution.WaitForExit();
                    var elapsedMs = watch.ElapsedMilliseconds;
                    RunSolutionStatusLabel.Text = "Execution succesfull. Time used:" + elapsedMs.ToString() + "ms";
                    watch.Stop();
                    for(i=SolutionPath.Length-1; i>=0; i--)
                    {
                        if(SolutionPath[i]=='\\')
                        {
                            break;
                        }
                    }
                    
                    for(j=0;j<i;j++)
                    {
                        InOutPath += SolutionPath[j];
                    }

                    try
                    {
                        InputParser(InOutPath + "\\puzzle.in");
                    }
                    catch(Exception)
                    {
                        GetInputFileStatusLabel.Text = "Input File Missing";
                    }

                    try
                    {
                        OutputParser(InOutPath + "\\puzzle.out");
                    }
                    catch (Exception)
                    {
                        GetOutputFileStatusLabel.Text = "Output File Missing";
                    }
                    ExecutionStatusLabel.Show();
                    MoveNumber.Show();
                    chooseInputFileButton.Hide();
                    chooseOutputFileButton.Hide();
                    if (GetInputFileStatusLabel.Text == "The Input File is OK" && GetOutputFileStatusLabel.Text == "The Ouput File is OK")
                    {
                        StartVisualisationButton.Show();
                        UIText1.Show();
                        NextMoveInterval.Show();
                        ExecutionStatusLabel.Show();
                        ResultText.Show();
                        PointsValue.Show();
                        RunSolutionButton.Hide();
                        ExecutionStatusLabel.Text = "The Execution Is ready To Start";
                    }
                }
                catch(Exception)
                {
                    RunSolutionStatusLabel.Text = "Something went wrong. Please try again";
                }
            }
            else
            {
                RunSolutionStatusLabel.Show();
                RunSolutionStatusLabel.Text = "No File Was Selected. Please Try Again";
            }
        }
        private void ReplayButton_Click(object sender, EventArgs e)
        {
            int i, j;
            Points = 0;
            ReplayButton.Hide();
            ResultText.Hide();
            PointsValue.Hide();
            NextMoveInterval.Show();
            for (i=0;i<600;i++)
            {
                for(j=0;j<600;j++)
                {
                    Puzzle.SetPixel(i,j, InitialPuzzle.GetPixel(i,j));
                }
            }
            MessedUpPicture.Image = Puzzle;
            x = InitX;
            y = InitY;
            ClickCount = 0;

            StartVisualisationButton.Show();
        }
        private void PauseButton_Click(object sender, EventArgs e)
        {
            if(Paused==false)
            {
                Paused=true;
                PauseButton.Text = "Continue";
            }
            else
            {
                Paused=false;
                PauseButton.Text = "Pause";
            }
        }
        private void NextMoveButton_Click(object sender, EventArgs e)
        {
            Visualization(ClickCount);
            ClickCount++;
        }
    }
}
