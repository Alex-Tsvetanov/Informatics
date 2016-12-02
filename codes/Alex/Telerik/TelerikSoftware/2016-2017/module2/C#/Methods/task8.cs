using System;
using System.Numerics;

namespace Methods
{
	class LargerThan
	{
		static BigInteger Parse (string a)
		{
			BigInteger b = 0;
			foreach (var item in a) 
			{
				b = b * 10 + (item - '0');
			}
			return b;
		}
		static int Main (string[] args)
		{
			Console.ReadLine ();
			BigInteger b = Parse (String.Join ("", Array.Reverse (Console.ReadLine ().Split (' '))));
			BigInteger c = Parse (String.Join ("", Array.Reverse (Console.ReadLine ().Split (' '))));
			Console.WriteLine ("{0}", String.Join (" ", (b + c).ToString ().ToCharArray ()));
			return 0;
		}	
	}
}
