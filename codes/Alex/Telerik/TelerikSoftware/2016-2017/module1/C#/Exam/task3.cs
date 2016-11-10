using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			string input;
			int line = 1;
			while ((input = Console.ReadLine ()) != "end")
			{
				int S = int.Parse (input);
				int E = int.Parse (input = Console.ReadLine ());
				string text = Console.ReadLine ();
				while (S < 0)
					S += text.Length;
				while (E < 0)
					E += text.Length;

				if (line % 2 == 1)
				for (int i = S ; i <= E ; i += 3)
					Console.Write (text [i]);
				if (line % 2 == 0)
				for (int i = S ; i <= E ; i += 4)
					Console.Write (text [i]);
				line ++;
			}
			Console.WriteLine ();
		}
	}
}
