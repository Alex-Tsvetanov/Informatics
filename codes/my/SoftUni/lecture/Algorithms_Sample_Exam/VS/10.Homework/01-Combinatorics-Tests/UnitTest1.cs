using System;
using System.IO;
using _01_Combinatorics;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _01_Combinatorics_Tests
{
    [TestClass]
    public class UnitTest1
    {
        const string testsFolder = "../../Tests/";

        [TestMethod]
        public void Combinatorics_Test_000_001_zero()
        {
            // Arrange
            string input = "ABC\n";

            // Act
            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            // Assert
            string[] expectedOutput = new string[]
            {
                "ABC",
                "ACB",
                "BAC",
                "BCA",
                "CBA",
                "CAB"
            };
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_002_zero()
        {
            // Arrange
            string input = "BCABACB\n";

            // Act
            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            // Assert
            string[] expectedOutput = new string[]
            {
                "AABBBCC",
                "AACCBBB",
                "BBBAACC",
                "BBBCCAA",
                "CCAABBB",
                "CCBBBAA"
            };
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_003_zero()
        {
            // Arrange
            string input = "SSDVLKG\n";

            // Act
            var inputReader = new StringReader(input);
            var outputWriter = new StringWriter();
            using (outputWriter)
            {
                Console.SetIn(inputReader);
                Console.SetOut(outputWriter);
                Program.Main();
            }
            string output = outputWriter.ToString();

            // Assert
            string[] expectedOutput = new string[]
            {
                "SSDVLKG", "SSDVLGK", "SSDVKLG", "SSDVKGL", "SSDVGKL", "SSDVGLK", "SSDLVKG", "SSDLVGK", "SSDLKVG", "SSDLKGV", "SSDLGKV", "SSDLGVK", "SSDKLVG", "SSDKLGV", "SSDKVLG", "SSDKVGL", "SSDKGVL", "SSDKGLV", "SSDGLKV", "SSDGLVK", "SSDGKLV", "SSDGKVL", "SSDGVKL", "SSDGVLK", "SSVDLKG", "SSVDLGK", "SSVDKLG", "SSVDKGL", "SSVDGKL", "SSVDGLK", "SSVLDKG", "SSVLDGK", "SSVLKDG", "SSVLKGD", "SSVLGKD", "SSVLGDK", "SSVKLDG", "SSVKLGD", "SSVKDLG", "SSVKDGL", "SSVKGDL", "SSVKGLD", "SSVGLKD", "SSVGLDK", "SSVGKLD", "SSVGKDL", "SSVGDKL", "SSVGDLK", "SSLVDKG", "SSLVDGK", "SSLVKDG", "SSLVKGD", "SSLVGKD", "SSLVGDK", "SSLDVKG", "SSLDVGK", "SSLDKVG", "SSLDKGV", "SSLDGKV", "SSLDGVK", "SSLKDVG", "SSLKDGV", "SSLKVDG", "SSLKVGD", "SSLKGVD", "SSLKGDV", "SSLGDKV", "SSLGDVK", "SSLGKDV", "SSLGKVD", "SSLGVKD", "SSLGVDK", "SSKVLDG", "SSKVLGD", "SSKVDLG", "SSKVDGL", "SSKVGDL", "SSKVGLD", "SSKLVDG", "SSKLVGD", "SSKLDVG", "SSKLDGV", "SSKLGDV", "SSKLGVD", "SSKDLVG", "SSKDLGV", "SSKDVLG", "SSKDVGL", "SSKDGVL", "SSKDGLV", "SSKGLDV", "SSKGLVD", "SSKGDLV", "SSKGDVL", "SSKGVDL", "SSKGVLD", "SSGVLKD", "SSGVLDK", "SSGVKLD", "SSGVKDL", "SSGVDKL", "SSGVDLK", "SSGLVKD", "SSGLVDK", "SSGLKVD", "SSGLKDV", "SSGLDKV", "SSGLDVK", "SSGKLVD", "SSGKLDV", "SSGKVLD", "SSGKVDL", "SSGKDVL", "SSGKDLV", "SSGDLKV", "SSGDLVK", "SSGDKLV", "SSGDKVL", "SSGDVKL", "SSGDVLK", "DSSVLKG", "DSSVLGK", "DSSVKLG", "DSSVKGL", "DSSVGKL", "DSSVGLK", "DSSLVKG", "DSSLVGK", "DSSLKVG", "DSSLKGV", "DSSLGKV", "DSSLGVK", "DSSKLVG", "DSSKLGV", "DSSKVLG", "DSSKVGL", "DSSKGVL", "DSSKGLV", "DSSGLKV", "DSSGLVK", "DSSGKLV", "DSSGKVL", "DSSGVKL", "DSSGVLK", "DVSSLKG", "DVSSLGK", "DVSSKLG", "DVSSKGL", "DVSSGKL", "DVSSGLK", "DVLSSKG", "DVLSSGK", "DVLKSSG", "DVLKGSS", "DVLGKSS", "DVLGSSK", "DVKLSSG", "DVKLGSS", "DVKSSLG", "DVKSSGL", "DVKGSSL", "DVKGLSS", "DVGLKSS", "DVGLSSK", "DVGKLSS", "DVGKSSL", "DVGSSKL", "DVGSSLK", "DLVSSKG", "DLVSSGK", "DLVKSSG", "DLVKGSS", "DLVGKSS", "DLVGSSK", "DLSSVKG", "DLSSVGK", "DLSSKVG", "DLSSKGV", "DLSSGKV", "DLSSGVK", "DLKSSVG", "DLKSSGV", "DLKVSSG", "DLKVGSS", "DLKGVSS", "DLKGSSV", "DLGSSKV", "DLGSSVK", "DLGKSSV", "DLGKVSS", "DLGVKSS", "DLGVSSK", "DKVLSSG", "DKVLGSS", "DKVSSLG", "DKVSSGL", "DKVGSSL", "DKVGLSS", "DKLVSSG", "DKLVGSS", "DKLSSVG", "DKLSSGV", "DKLGSSV", "DKLGVSS", "DKSSLVG", "DKSSLGV", "DKSSVLG", "DKSSVGL", "DKSSGVL", "DKSSGLV", "DKGLSSV", "DKGLVSS", "DKGSSLV", "DKGSSVL", "DKGVSSL", "DKGVLSS", "DGVLKSS", "DGVLSSK", "DGVKLSS", "DGVKSSL", "DGVSSKL", "DGVSSLK", "DGLVKSS", "DGLVSSK", "DGLKVSS", "DGLKSSV", "DGLSSKV", "DGLSSVK", "DGKLVSS", "DGKLSSV", "DGKVLSS", "DGKVSSL", "DGKSSVL", "DGKSSLV", "DGSSLKV", "DGSSLVK", "DGSSKLV", "DGSSKVL", "DGSSVKL", "DGSSVLK", "VDSSLKG", "VDSSLGK", "VDSSKLG", "VDSSKGL", "VDSSGKL", "VDSSGLK", "VDLSSKG", "VDLSSGK", "VDLKSSG", "VDLKGSS", "VDLGKSS", "VDLGSSK", "VDKLSSG", "VDKLGSS", "VDKSSLG", "VDKSSGL", "VDKGSSL", "VDKGLSS", "VDGLKSS", "VDGLSSK", "VDGKLSS", "VDGKSSL", "VDGSSKL", "VDGSSLK", "VSSDLKG", "VSSDLGK", "VSSDKLG", "VSSDKGL", "VSSDGKL", "VSSDGLK", "VSSLDKG", "VSSLDGK", "VSSLKDG", "VSSLKGD", "VSSLGKD", "VSSLGDK", "VSSKLDG", "VSSKLGD", "VSSKDLG", "VSSKDGL", "VSSKGDL", "VSSKGLD", "VSSGLKD", "VSSGLDK", "VSSGKLD", "VSSGKDL", "VSSGDKL", "VSSGDLK", "VLSSDKG", "VLSSDGK", "VLSSKDG", "VLSSKGD", "VLSSGKD", "VLSSGDK", "VLDSSKG", "VLDSSGK", "VLDKSSG", "VLDKGSS", "VLDGKSS", "VLDGSSK", "VLKDSSG", "VLKDGSS", "VLKSSDG", "VLKSSGD", "VLKGSSD", "VLKGDSS", "VLGDKSS", "VLGDSSK", "VLGKDSS", "VLGKSSD", "VLGSSKD", "VLGSSDK", "VKSSLDG", "VKSSLGD", "VKSSDLG", "VKSSDGL", "VKSSGDL", "VKSSGLD", "VKLSSDG", "VKLSSGD", "VKLDSSG", "VKLDGSS", "VKLGDSS", "VKLGSSD", "VKDLSSG", "VKDLGSS", "VKDSSLG", "VKDSSGL", "VKDGSSL", "VKDGLSS", "VKGLDSS", "VKGLSSD", "VKGDLSS", "VKGDSSL", "VKGSSDL", "VKGSSLD", "VGSSLKD", "VGSSLDK", "VGSSKLD", "VGSSKDL", "VGSSDKL", "VGSSDLK", "VGLSSKD", "VGLSSDK", "VGLKSSD", "VGLKDSS", "VGLDKSS", "VGLDSSK", "VGKLSSD", "VGKLDSS", "VGKSSLD", "VGKSSDL", "VGKDSSL", "VGKDLSS", "VGDLKSS", "VGDLSSK", "VGDKLSS", "VGDKSSL", "VGDSSKL", "VGDSSLK", "LDVSSKG", "LDVSSGK", "LDVKSSG", "LDVKGSS", "LDVGKSS", "LDVGSSK", "LDSSVKG", "LDSSVGK", "LDSSKVG", "LDSSKGV", "LDSSGKV", "LDSSGVK", "LDKSSVG", "LDKSSGV", "LDKVSSG", "LDKVGSS", "LDKGVSS", "LDKGSSV", "LDGSSKV", "LDGSSVK", "LDGKSSV", "LDGKVSS", "LDGVKSS", "LDGVSSK", "LVDSSKG", "LVDSSGK", "LVDKSSG", "LVDKGSS", "LVDGKSS", "LVDGSSK", "LVSSDKG", "LVSSDGK", "LVSSKDG", "LVSSKGD", "LVSSGKD", "LVSSGDK", "LVKSSDG", "LVKSSGD", "LVKDSSG", "LVKDGSS", "LVKGDSS", "LVKGSSD", "LVGSSKD", "LVGSSDK", "LVGKSSD", "LVGKDSS", "LVGDKSS", "LVGDSSK", "LSSVDKG", "LSSVDGK", "LSSVKDG", "LSSVKGD", "LSSVGKD", "LSSVGDK", "LSSDVKG", "LSSDVGK", "LSSDKVG", "LSSDKGV", "LSSDGKV", "LSSDGVK", "LSSKDVG", "LSSKDGV", "LSSKVDG", "LSSKVGD", "LSSKGVD", "LSSKGDV", "LSSGDKV", "LSSGDVK", "LSSGKDV", "LSSGKVD", "LSSGVKD", "LSSGVDK", "LKVSSDG", "LKVSSGD", "LKVDSSG", "LKVDGSS", "LKVGDSS", "LKVGSSD", "LKSSVDG", "LKSSVGD", "LKSSDVG", "LKSSDGV", "LKSSGDV", "LKSSGVD", "LKDSSVG", "LKDSSGV", "LKDVSSG", "LKDVGSS", "LKDGVSS", "LKDGSSV", "LKGSSDV", "LKGSSVD", "LKGDSSV", "LKGDVSS", "LKGVDSS", "LKGVSSD", "LGVSSKD", "LGVSSDK", "LGVKSSD", "LGVKDSS", "LGVDKSS", "LGVDSSK", "LGSSVKD", "LGSSVDK", "LGSSKVD", "LGSSKDV", "LGSSDKV", "LGSSDVK", "LGKSSVD", "LGKSSDV", "LGKVSSD", "LGKVDSS", "LGKDVSS", "LGKDSSV", "LGDSSKV", "LGDSSVK", "LGDKSSV", "LGDKVSS", "LGDVKSS", "LGDVSSK", "KDVLSSG", "KDVLGSS", "KDVSSLG", "KDVSSGL", "KDVGSSL", "KDVGLSS", "KDLVSSG", "KDLVGSS", "KDLSSVG", "KDLSSGV", "KDLGSSV", "KDLGVSS", "KDSSLVG", "KDSSLGV", "KDSSVLG", "KDSSVGL", "KDSSGVL", "KDSSGLV", "KDGLSSV", "KDGLVSS", "KDGSSLV", "KDGSSVL", "KDGVSSL", "KDGVLSS", "KVDLSSG", "KVDLGSS", "KVDSSLG", "KVDSSGL", "KVDGSSL", "KVDGLSS", "KVLDSSG", "KVLDGSS", "KVLSSDG", "KVLSSGD", "KVLGSSD", "KVLGDSS", "KVSSLDG", "KVSSLGD", "KVSSDLG", "KVSSDGL", "KVSSGDL", "KVSSGLD", "KVGLSSD", "KVGLDSS", "KVGSSLD", "KVGSSDL", "KVGDSSL", "KVGDLSS", "KLVDSSG", "KLVDGSS", "KLVSSDG", "KLVSSGD", "KLVGSSD", "KLVGDSS", "KLDVSSG", "KLDVGSS", "KLDSSVG", "KLDSSGV", "KLDGSSV", "KLDGVSS", "KLSSDVG", "KLSSDGV", "KLSSVDG", "KLSSVGD", "KLSSGVD", "KLSSGDV", "KLGDSSV", "KLGDVSS", "KLGSSDV", "KLGSSVD", "KLGVSSD", "KLGVDSS", "KSSVLDG", "KSSVLGD", "KSSVDLG", "KSSVDGL", "KSSVGDL", "KSSVGLD", "KSSLVDG", "KSSLVGD", "KSSLDVG", "KSSLDGV", "KSSLGDV", "KSSLGVD", "KSSDLVG", "KSSDLGV", "KSSDVLG", "KSSDVGL", "KSSDGVL", "KSSDGLV", "KSSGLDV", "KSSGLVD", "KSSGDLV", "KSSGDVL", "KSSGVDL", "KSSGVLD", "KGVLSSD", "KGVLDSS", "KGVSSLD", "KGVSSDL", "KGVDSSL", "KGVDLSS", "KGLVSSD", "KGLVDSS", "KGLSSVD", "KGLSSDV", "KGLDSSV", "KGLDVSS", "KGSSLVD", "KGSSLDV", "KGSSVLD", "KGSSVDL", "KGSSDVL", "KGSSDLV", "KGDLSSV", "KGDLVSS", "KGDSSLV", "KGDSSVL", "KGDVSSL", "KGDVLSS", "GDVLKSS", "GDVLSSK", "GDVKLSS", "GDVKSSL", "GDVSSKL", "GDVSSLK", "GDLVKSS", "GDLVSSK", "GDLKVSS", "GDLKSSV", "GDLSSKV", "GDLSSVK", "GDKLVSS", "GDKLSSV", "GDKVLSS", "GDKVSSL", "GDKSSVL", "GDKSSLV", "GDSSLKV", "GDSSLVK", "GDSSKLV", "GDSSKVL", "GDSSVKL", "GDSSVLK", "GVDLKSS", "GVDLSSK", "GVDKLSS", "GVDKSSL", "GVDSSKL", "GVDSSLK", "GVLDKSS", "GVLDSSK", "GVLKDSS", "GVLKSSD", "GVLSSKD", "GVLSSDK", "GVKLDSS", "GVKLSSD", "GVKDLSS", "GVKDSSL", "GVKSSDL", "GVKSSLD", "GVSSLKD", "GVSSLDK", "GVSSKLD", "GVSSKDL", "GVSSDKL", "GVSSDLK", "GLVDKSS", "GLVDSSK", "GLVKDSS", "GLVKSSD", "GLVSSKD", "GLVSSDK", "GLDVKSS", "GLDVSSK", "GLDKVSS", "GLDKSSV", "GLDSSKV", "GLDSSVK", "GLKDVSS", "GLKDSSV", "GLKVDSS", "GLKVSSD", "GLKSSVD", "GLKSSDV", "GLSSDKV", "GLSSDVK", "GLSSKDV", "GLSSKVD", "GLSSVKD", "GLSSVDK", "GKVLDSS", "GKVLSSD", "GKVDLSS", "GKVDSSL", "GKVSSDL", "GKVSSLD", "GKLVDSS", "GKLVSSD", "GKLDVSS", "GKLDSSV", "GKLSSDV", "GKLSSVD", "GKDLVSS", "GKDLSSV", "GKDVLSS", "GKDVSSL", "GKDSSVL", "GKDSSLV", "GKSSLDV", "GKSSLVD", "GKSSDLV", "GKSSDVL", "GKSSVDL", "GKSSVLD", "GSSVLKD", "GSSVLDK", "GSSVKLD", "GSSVKDL", "GSSVDKL", "GSSVDLK", "GSSLVKD", "GSSLVDK", "GSSLKVD", "GSSLKDV", "GSSLDKV", "GSSLDVK", "GSSKLVD", "GSSKLDV", "GSSKVLD", "GSSKVDL", "GSSKDVL", "GSSKDLV", "GSSDLKV", "GSSDLVK", "GSSDKLV", "GSSDKVL", "GSSDVKL", "GSSDVLK"
            };
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_001()
        {
            // Arrange
            string inputFile = "test.001.in.txt";
            string outputFile = "test.001.out.txt";

            // Act
            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder  + inputFile))
            {
                // Read the stream to a string, and write the string to the console.
                String line = sr.ReadToEnd();
                input = line;
            }

            List<string> expectedOutputList = new List<string>();
            using (StreamReader sr = new StreamReader(testsFolder  + outputFile))
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_002()
        {
            // Arrange
            string inputFile = "test.002.in.txt";
            string outputFile = "test.002.out.txt";

            // Act
            string input = "";
            using (StreamReader sr = new StreamReader(testsFolder  + inputFile))
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_003()
        {
            // Arrange
            string inputFile = "test.003.in.txt";
            string outputFile = "test.003.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_004()
        {
            // Arrange
            string inputFile = "test.004.in.txt";
            string outputFile = "test.004.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_005()
        {
            // Arrange
            string inputFile = "test.005.in.txt";
            string outputFile = "test.005.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_006()
        {
            // Arrange
            string inputFile = "test.006.in.txt";
            string outputFile = "test.006.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_007()
        {
            // Arrange
            string inputFile = "test.007.in.txt";
            string outputFile = "test.007.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_008()
        {
            // Arrange
            string inputFile = "test.008.in.txt";
            string outputFile = "test.008.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_009()
        {
            // Arrange
            string inputFile = "test.009.in.txt";
            string outputFile = "test.009.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }

        [TestMethod]
        public void Combinatorics_Test_000_010()
        {
            // Arrange
            string inputFile = "test.010.in.txt";
            string outputFile = "test.010.out.txt";

            // Act
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

            // Assert
            string[] expectedOutput = expectedOutputList.ToArray();
            output = output.Replace("\r\n", "\n").Trim();
            string[] actualOutput = output.Split('\n');
            CollectionAssert.AreEquivalent(expectedOutput, actualOutput);
        }
    }
}
