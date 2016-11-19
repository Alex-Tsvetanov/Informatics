using System;

namespace Methods
{
	class LargerThan
	{
		static int larger (string[] arr1)
		{
			int[] arr = new int [arr1.Length];
			int br = 0;
			for (int i = 0 ; i < arr.Length - 2 ; i ++)
			{
				arr [i] = int.Parse (arr1 [i]);
				arr [i + 1] = int.Parse (arr1 [i + 1]);
				arr [i + 2] = int.Parse (arr1 [i + 2]);
				if (arr [i] < arr [i + 1] && arr [i + 1] > arr [i + 2])
				{
					br ++;
				}
			}
			return br;
		}
		static int Main (string[] args)
		{
			Console.ReadLine ();
			Console.WriteLine ("{0}", larger (Console.ReadLine ().Split (' ')));
			return 0;
		}	
	}
}

