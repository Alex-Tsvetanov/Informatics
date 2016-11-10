using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			string digits = Console.ReadLine ();
			int pos = 0;
			while (0 <= pos && pos < digits.Length)
			{
				if ('a' <= digits [pos] && digits [pos] <= 'z')
					pos += digits [pos] - 'a' + 1;
				else if ('A' <= digits [pos] && digits [pos] <= 'Z')
					pos -= digits [pos] - 'A' + 1;
				else if (digits [pos] == '^')
					break;
			}
			if (0 <= pos && pos < digits.Length)
				Console.WriteLine ("Djor and Djano are at the party at {0}!", pos);
			else
				Console.WriteLine ("Djor and Djano are lost at {0}!", pos);
		}
	}
}
