using System;
using System.IO;
using _03_Graphs;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _03_Graphs_Tests
{
    [TestClass]
    public class UnitTest1
    {
        const string testsFolder = "../../Tests/";

        [TestMethod]
        public void Graphs_Test_000_001()
        {
            string inputFile = "test.000.001.in.txt";
            string outputFile = "test.000.001.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_000_002()
        {
            string inputFile = "test.000.002.in.txt";
            string outputFile = "test.000.002.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_000_003()
        {
            string inputFile = "test.000.003.in.txt";
            string outputFile = "test.000.003.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_000_004()
        {
            string inputFile = "test.000.004.in.txt";
            string outputFile = "test.000.004.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_001()
        {
            string inputFile = "test.001.in.txt";
            string outputFile = "test.001.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_002()
        {
            string inputFile = "test.002.in.txt";
            string outputFile = "test.002.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_003()
        {
            string inputFile = "test.003.in.txt";
            string outputFile = "test.003.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_004()
        {
            string inputFile = "test.004.in.txt";
            string outputFile = "test.004.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_005()
        {
            string inputFile = "test.005.in.txt";
            string outputFile = "test.005.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_006()
        {
            string inputFile = "test.006.in.txt";
            string outputFile = "test.006.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_007()
        {
            string inputFile = "test.007.in.txt";
            string outputFile = "test.007.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_008()
        {
            string inputFile = "test.008.in.txt";
            string outputFile = "test.008.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_009()
        {
            string inputFile = "test.009.in.txt";
            string outputFile = "test.009.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Graphs_Test_010()
        {
            string inputFile = "test.010.in.txt";
            string outputFile = "test.010.out.txt";

            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder + outputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = "";
                do
                {
                    line = sr.ReadLine();
                    if (string.IsNullOrEmpty(line))
                    {
                        break;
                    }
                    else
                    {
                        expectedOutputList.Add(line);
                    }
                }
                while (!string.IsNullOrEmpty(line));
            }

            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }
    }
}
