using System;

namespace Project
{
	class Program
	{
		static void Main ()
		{
			Int64 a = Int64.Parse (Console.ReadLine ());
			Int64 num1 = 0;
			Int64 num2 = 1;
			Int64 sum = 1;
			Console.Write(num1);
			if (a > 1)
				Console.Write(", {0}", num2);
			a -= 3;
			while (0 <= a)
			{
				sum = num1 + num2;
				num1 = num2;
				num2 = sum;
				Console.Write(", {0}", num2);
				a --;
			}
            Console.WriteLine ();
		}
	}
}
