namespace CodeIT_Puzzle_Visualizer
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.testGenGetImageDialog = new System.Windows.Forms.OpenFileDialog();
            this.testButton = new System.Windows.Forms.Button();
            this.testGenStatusLabel = new System.Windows.Forms.Label();
            this.chooseInputFileButton = new System.Windows.Forms.Button();
            this.GetInputFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.GetInputFileStatusLabel = new System.Windows.Forms.Label();
            this.MessedUpPicture = new System.Windows.Forms.PictureBox();
            this.OriginalPucture = new System.Windows.Forms.PictureBox();
            this.chooseOutputFileButton = new System.Windows.Forms.Button();
            this.GetOutputFileStatusLabel = new System.Windows.Forms.Label();
            this.GetOutputFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.StartVisualisationButton = new System.Windows.Forms.Button();
            this.NextMoveInterval = new System.Windows.Forms.NumericUpDown();
            this.UIText1 = new System.Windows.Forms.Label();
            this.NextMoveButton = new System.Windows.Forms.Button();
            this.PointsValue = new System.Windows.Forms.Label();
            this.ResultText = new System.Windows.Forms.Label();
            this.ExecutionStatusLabel = new System.Windows.Forms.Label();
            this.StopExecutionButton = new System.Windows.Forms.Button();
            this.PauseButton = new System.Windows.Forms.Button();
            this.MoveIntervalTimer = new System.Windows.Forms.Timer(this.components);
            this.EmptySquareText = new System.Windows.Forms.Label();
            this.XText = new System.Windows.Forms.Label();
            this.XValue = new System.Windows.Forms.Label();
            this.YText = new System.Windows.Forms.Label();
            this.YValue = new System.Windows.Forms.Label();
            this.MoveNumberText = new System.Windows.Forms.Label();
            this.MoveNumber = new System.Windows.Forms.Label();
            this.ReplayButton = new System.Windows.Forms.Button();
            this.RunSolutionButton = new System.Windows.Forms.Button();
            this.ChooseSolutionFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.RunSolutionStatusLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.MessedUpPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.OriginalPucture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NextMoveInterval)).BeginInit();
            this.SuspendLayout();
            // 
            // testButton
            // 
            this.testButton.Location = new System.Drawing.Point(12, 0);
            this.testButton.Name = "testButton";
            this.testButton.Size = new System.Drawing.Size(75, 23);
            this.testButton.TabIndex = 0;
            this.testButton.Text = "TestGen";
            this.testButton.UseVisualStyleBackColor = true;
            this.testButton.Click += new System.EventHandler(this.testButton_Click);
            // 
            // testGenStatusLabel
            // 
            this.testGenStatusLabel.AutoSize = true;
            this.testGenStatusLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.testGenStatusLabel.Location = new System.Drawing.Point(123, 5);
            this.testGenStatusLabel.Name = "testGenStatusLabel";
            this.testGenStatusLabel.Size = new System.Drawing.Size(0, 18);
            this.testGenStatusLabel.TabIndex = 1;
            // 
            // chooseInputFileButton
            // 
            this.chooseInputFileButton.Location = new System.Drawing.Point(12, 36);
            this.chooseInputFileButton.Name = "chooseInputFileButton";
            this.chooseInputFileButton.Size = new System.Drawing.Size(75, 23);
            this.chooseInputFileButton.TabIndex = 2;
            this.chooseInputFileButton.Text = "Input";
            this.chooseInputFileButton.UseVisualStyleBackColor = true;
            this.chooseInputFileButton.Click += new System.EventHandler(this.chooseInputFileButton_Click);
            // 
            // GetInputFileStatusLabel
            // 
            this.GetInputFileStatusLabel.AutoSize = true;
            this.GetInputFileStatusLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.GetInputFileStatusLabel.Location = new System.Drawing.Point(123, 41);
            this.GetInputFileStatusLabel.Name = "GetInputFileStatusLabel";
            this.GetInputFileStatusLabel.Size = new System.Drawing.Size(0, 18);
            this.GetInputFileStatusLabel.TabIndex = 4;
            // 
            // MessedUpPicture
            // 
            this.MessedUpPicture.BackColor = System.Drawing.Color.LightCoral;
            this.MessedUpPicture.Location = new System.Drawing.Point(8, 102);
            this.MessedUpPicture.Name = "MessedUpPicture";
            this.MessedUpPicture.Size = new System.Drawing.Size(600, 600);
            this.MessedUpPicture.TabIndex = 5;
            this.MessedUpPicture.TabStop = false;
            // 
            // OriginalPucture
            // 
            this.OriginalPucture.BackColor = System.Drawing.Color.Chartreuse;
            this.OriginalPucture.Location = new System.Drawing.Point(622, 102);
            this.OriginalPucture.Name = "OriginalPucture";
            this.OriginalPucture.Size = new System.Drawing.Size(600, 600);
            this.OriginalPucture.TabIndex = 6;
            this.OriginalPucture.TabStop = false;
            // 
            // chooseOutputFileButton
            // 
            this.chooseOutputFileButton.Location = new System.Drawing.Point(12, 71);
            this.chooseOutputFileButton.Name = "chooseOutputFileButton";
            this.chooseOutputFileButton.Size = new System.Drawing.Size(75, 23);
            this.chooseOutputFileButton.TabIndex = 7;
            this.chooseOutputFileButton.Text = "Output";
            this.chooseOutputFileButton.UseVisualStyleBackColor = true;
            this.chooseOutputFileButton.Click += new System.EventHandler(this.chooseOutputFileButton_Click);
            // 
            // GetOutputFileStatusLabel
            // 
            this.GetOutputFileStatusLabel.AutoSize = true;
            this.GetOutputFileStatusLabel.Cursor = System.Windows.Forms.Cursors.No;
            this.GetOutputFileStatusLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.GetOutputFileStatusLabel.Location = new System.Drawing.Point(123, 71);
            this.GetOutputFileStatusLabel.Name = "GetOutputFileStatusLabel";
            this.GetOutputFileStatusLabel.Size = new System.Drawing.Size(0, 18);
            this.GetOutputFileStatusLabel.TabIndex = 8;
            // 
            // StartVisualisationButton
            // 
            this.StartVisualisationButton.Location = new System.Drawing.Point(403, 70);
            this.StartVisualisationButton.Name = "StartVisualisationButton";
            this.StartVisualisationButton.Size = new System.Drawing.Size(87, 23);
            this.StartVisualisationButton.TabIndex = 9;
            this.StartVisualisationButton.Text = "Start";
            this.StartVisualisationButton.UseVisualStyleBackColor = true;
            this.StartVisualisationButton.Visible = false;
            this.StartVisualisationButton.Click += new System.EventHandler(this.StartVisualisationButton_Click);
            // 
            // NextMoveInterval
            // 
            this.NextMoveInterval.Location = new System.Drawing.Point(1063, 75);
            this.NextMoveInterval.Maximum = new decimal(new int[] {
            5000,
            0,
            0,
            0});
            this.NextMoveInterval.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            this.NextMoveInterval.Name = "NextMoveInterval";
            this.NextMoveInterval.Size = new System.Drawing.Size(68, 20);
            this.NextMoveInterval.TabIndex = 10;
            this.NextMoveInterval.Visible = false;
            // 
            // UIText1
            // 
            this.UIText1.AutoSize = true;
            this.UIText1.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.UIText1.Location = new System.Drawing.Point(872, 75);
            this.UIText1.Name = "UIText1";
            this.UIText1.Size = new System.Drawing.Size(169, 18);
            this.UIText1.TabIndex = 11;
            this.UIText1.Text = "Interval between moves";
            this.UIText1.Visible = false;
            // 
            // NextMoveButton
            // 
            this.NextMoveButton.Location = new System.Drawing.Point(403, 34);
            this.NextMoveButton.Name = "NextMoveButton";
            this.NextMoveButton.Size = new System.Drawing.Size(87, 23);
            this.NextMoveButton.TabIndex = 12;
            this.NextMoveButton.Text = "Remove Pixel";
            this.NextMoveButton.UseVisualStyleBackColor = true;
            this.NextMoveButton.Visible = false;
            this.NextMoveButton.Click += new System.EventHandler(this.NextMoveButton_Click);
            // 
            // PointsValue
            // 
            this.PointsValue.AutoSize = true;
            this.PointsValue.Cursor = System.Windows.Forms.Cursors.No;
            this.PointsValue.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PointsValue.Location = new System.Drawing.Point(916, 35);
            this.PointsValue.Name = "PointsValue";
            this.PointsValue.Size = new System.Drawing.Size(17, 18);
            this.PointsValue.TabIndex = 13;
            this.PointsValue.Text = "0";
            this.PointsValue.Visible = false;
            // 
            // ResultText
            // 
            this.ResultText.AutoSize = true;
            this.ResultText.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ResultText.Location = new System.Drawing.Point(799, 35);
            this.ResultText.Name = "ResultText";
            this.ResultText.Size = new System.Drawing.Size(51, 18);
            this.ResultText.TabIndex = 14;
            this.ResultText.Text = "Result";
            this.ResultText.Visible = false;
            // 
            // ExecutionStatusLabel
            // 
            this.ExecutionStatusLabel.AutoSize = true;
            this.ExecutionStatusLabel.Cursor = System.Windows.Forms.Cursors.Default;
            this.ExecutionStatusLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ExecutionStatusLabel.Location = new System.Drawing.Point(520, 72);
            this.ExecutionStatusLabel.Name = "ExecutionStatusLabel";
            this.ExecutionStatusLabel.Size = new System.Drawing.Size(0, 18);
            this.ExecutionStatusLabel.TabIndex = 15;
            this.ExecutionStatusLabel.Visible = false;
            // 
            // StopExecutionButton
            // 
            this.StopExecutionButton.Location = new System.Drawing.Point(523, 35);
            this.StopExecutionButton.Name = "StopExecutionButton";
            this.StopExecutionButton.Size = new System.Drawing.Size(75, 23);
            this.StopExecutionButton.TabIndex = 18;
            this.StopExecutionButton.Text = "Restart";
            this.StopExecutionButton.UseVisualStyleBackColor = true;
            this.StopExecutionButton.Visible = false;
            this.StopExecutionButton.Click += new System.EventHandler(this.StopExecutionButton_Click);
            // 
            // PauseButton
            // 
            this.PauseButton.Location = new System.Drawing.Point(622, 34);
            this.PauseButton.Name = "PauseButton";
            this.PauseButton.Size = new System.Drawing.Size(75, 23);
            this.PauseButton.TabIndex = 19;
            this.PauseButton.Text = "Pause";
            this.PauseButton.UseVisualStyleBackColor = true;
            this.PauseButton.Visible = false;
            this.PauseButton.Click += new System.EventHandler(this.PauseButton_Click);
            // 
            // MoveIntervalTimer
            // 
            this.MoveIntervalTimer.Tick += new System.EventHandler(this.MoveIntervalTimer_Tick);
            // 
            // EmptySquareText
            // 
            this.EmptySquareText.AutoSize = true;
            this.EmptySquareText.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.EmptySquareText.Location = new System.Drawing.Point(799, 5);
            this.EmptySquareText.Name = "EmptySquareText";
            this.EmptySquareText.Size = new System.Drawing.Size(111, 18);
            this.EmptySquareText.TabIndex = 20;
            this.EmptySquareText.Text = "Empty Square:";
            this.EmptySquareText.Visible = false;
            // 
            // XText
            // 
            this.XText.AutoSize = true;
            this.XText.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.XText.Location = new System.Drawing.Point(916, 5);
            this.XText.Name = "XText";
            this.XText.Size = new System.Drawing.Size(28, 18);
            this.XText.TabIndex = 21;
            this.XText.Text = "X=";
            this.XText.Visible = false;
            // 
            // XValue
            // 
            this.XValue.AutoSize = true;
            this.XValue.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.XValue.Location = new System.Drawing.Point(940, 5);
            this.XValue.Name = "XValue";
            this.XValue.Size = new System.Drawing.Size(19, 18);
            this.XValue.TabIndex = 22;
            this.XValue.Text = "X";
            this.XValue.Visible = false;
            // 
            // YText
            // 
            this.YText.AutoSize = true;
            this.YText.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.YText.Location = new System.Drawing.Point(975, 5);
            this.YText.Name = "YText";
            this.YText.Size = new System.Drawing.Size(26, 18);
            this.YText.TabIndex = 23;
            this.YText.Text = "Y=";
            this.YText.Visible = false;
            // 
            // YValue
            // 
            this.YValue.AutoSize = true;
            this.YValue.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.YValue.Location = new System.Drawing.Point(998, 5);
            this.YValue.Name = "YValue";
            this.YValue.Size = new System.Drawing.Size(17, 18);
            this.YValue.TabIndex = 24;
            this.YValue.Text = "Y";
            this.YValue.Visible = false;
            // 
            // MoveNumberText
            // 
            this.MoveNumberText.AutoSize = true;
            this.MoveNumberText.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.MoveNumberText.ForeColor = System.Drawing.SystemColors.ControlText;
            this.MoveNumberText.Location = new System.Drawing.Point(1039, 5);
            this.MoveNumberText.Name = "MoveNumberText";
            this.MoveNumberText.Size = new System.Drawing.Size(109, 18);
            this.MoveNumberText.TabIndex = 25;
            this.MoveNumberText.Text = "Move Number:";
            this.MoveNumberText.Visible = false;
            // 
            // MoveNumber
            // 
            this.MoveNumber.AutoSize = true;
            this.MoveNumber.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.MoveNumber.Location = new System.Drawing.Point(1149, 5);
            this.MoveNumber.Name = "MoveNumber";
            this.MoveNumber.Size = new System.Drawing.Size(0, 18);
            this.MoveNumber.TabIndex = 26;
            this.MoveNumber.Visible = false;
            // 
            // ReplayButton
            // 
            this.ReplayButton.Location = new System.Drawing.Point(718, 34);
            this.ReplayButton.Name = "ReplayButton";
            this.ReplayButton.Size = new System.Drawing.Size(75, 23);
            this.ReplayButton.TabIndex = 27;
            this.ReplayButton.Text = "Replay";
            this.ReplayButton.UseVisualStyleBackColor = true;
            this.ReplayButton.Visible = false;
            this.ReplayButton.Click += new System.EventHandler(this.ReplayButton_Click);
            // 
            // RunSolutionButton
            // 
            this.RunSolutionButton.Location = new System.Drawing.Point(403, 0);
            this.RunSolutionButton.Name = "RunSolutionButton";
            this.RunSolutionButton.Size = new System.Drawing.Size(87, 23);
            this.RunSolutionButton.TabIndex = 28;
            this.RunSolutionButton.Text = "Run Solution";
            this.RunSolutionButton.UseVisualStyleBackColor = true;
            this.RunSolutionButton.Click += new System.EventHandler(this.RunSolution_Click);
            // 
            // RunSolutionStatusLabel
            // 
            this.RunSolutionStatusLabel.AutoSize = true;
            this.RunSolutionStatusLabel.Cursor = System.Windows.Forms.Cursors.No;
            this.RunSolutionStatusLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RunSolutionStatusLabel.Location = new System.Drawing.Point(520, 5);
            this.RunSolutionStatusLabel.Name = "RunSolutionStatusLabel";
            this.RunSolutionStatusLabel.Size = new System.Drawing.Size(0, 18);
            this.RunSolutionStatusLabel.TabIndex = 29;
            this.RunSolutionStatusLabel.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1234, 712);
            this.Controls.Add(this.RunSolutionStatusLabel);
            this.Controls.Add(this.RunSolutionButton);
            this.Controls.Add(this.ReplayButton);
            this.Controls.Add(this.MoveNumber);
            this.Controls.Add(this.MoveNumberText);
            this.Controls.Add(this.YValue);
            this.Controls.Add(this.YText);
            this.Controls.Add(this.XValue);
            this.Controls.Add(this.XText);
            this.Controls.Add(this.EmptySquareText);
            this.Controls.Add(this.PauseButton);
            this.Controls.Add(this.StopExecutionButton);
            this.Controls.Add(this.ExecutionStatusLabel);
            this.Controls.Add(this.ResultText);
            this.Controls.Add(this.PointsValue);
            this.Controls.Add(this.NextMoveButton);
            this.Controls.Add(this.UIText1);
            this.Controls.Add(this.NextMoveInterval);
            this.Controls.Add(this.StartVisualisationButton);
            this.Controls.Add(this.GetOutputFileStatusLabel);
            this.Controls.Add(this.chooseOutputFileButton);
            this.Controls.Add(this.OriginalPucture);
            this.Controls.Add(this.MessedUpPicture);
            this.Controls.Add(this.GetInputFileStatusLabel);
            this.Controls.Add(this.chooseInputFileButton);
            this.Controls.Add(this.testGenStatusLabel);
            this.Controls.Add(this.testButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "CodeIT: Puzzle Visualizer";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.MessedUpPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.OriginalPucture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NextMoveInterval)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog testGenGetImageDialog;
        private System.Windows.Forms.Button testButton;
        private System.Windows.Forms.Label testGenStatusLabel;
        private System.Windows.Forms.Button chooseInputFileButton;
        private System.Windows.Forms.OpenFileDialog GetInputFileDialog;
        private System.Windows.Forms.Label GetInputFileStatusLabel;
        private System.Windows.Forms.PictureBox MessedUpPicture;
        private System.Windows.Forms.PictureBox OriginalPucture;
        private System.Windows.Forms.Button chooseOutputFileButton;
        private System.Windows.Forms.Label GetOutputFileStatusLabel;
        private System.Windows.Forms.OpenFileDialog GetOutputFileDialog;
        private System.Windows.Forms.Button StartVisualisationButton;
        private System.Windows.Forms.NumericUpDown NextMoveInterval;
        private System.Windows.Forms.Label UIText1;
        private System.Windows.Forms.Button NextMoveButton;
        private System.Windows.Forms.Label PointsValue;
        private System.Windows.Forms.Label ResultText;
        private System.Windows.Forms.Label ExecutionStatusLabel;
        private System.Windows.Forms.Button StopExecutionButton;
        private System.Windows.Forms.Button PauseButton;
        private System.Windows.Forms.Timer MoveIntervalTimer;
        private System.Windows.Forms.Label EmptySquareText;
        private System.Windows.Forms.Label XText;
        private System.Windows.Forms.Label XValue;
        private System.Windows.Forms.Label YText;
        private System.Windows.Forms.Label YValue;
        private System.Windows.Forms.Label MoveNumberText;
        private System.Windows.Forms.Label MoveNumber;
        private System.Windows.Forms.Button ReplayButton;
        private System.Windows.Forms.Button RunSolutionButton;
        private System.Windows.Forms.OpenFileDialog ChooseSolutionFileDialog;
        private System.Windows.Forms.Label RunSolutionStatusLabel;
    }
}

