using System;

namespace Homework
{
	class MainProgram
	{
		public static void Main (string[] args)
		{
			for (int i = 2 ; i < 1002 ; i ++)
			{
				if (i % 2 == 1) i = -i;
				Console.WriteLine ("{0}", i);
				if (i < 0) i = -i;
			}
		}
	}
}
