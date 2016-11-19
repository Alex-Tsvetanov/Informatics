using System;

namespace Methods
{
	class EnglishDigit
	{
		static string[] EN_Dic = {
			"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
		};

		static string toEn (string arr)
		{
			return EN_Dic [arr [arr.Length - 1] - '0'];
		}
		static int Main (string[] args)
		{
			Console.WriteLine ("{0}", toEn (Console.ReadLine ()));
			return 0;
		}	
	}
}
