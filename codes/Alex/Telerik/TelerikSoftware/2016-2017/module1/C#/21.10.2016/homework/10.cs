using System;

namespace Project
{
	class Program
	{
		static void Main ()
		{
			Int64 a = Int64.Parse (Console.ReadLine ());
			Int64 b = Int64.Parse (Console.ReadLine ());
			Int64 n = 0;
			for (Int64 i = a + 1 ; i < b ; i ++)
				n = n + ((i % 5 == 0)?1l:0l);
            Console.WriteLine (n);
		}
	}
}
