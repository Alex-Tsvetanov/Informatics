using System;

namespace Methods
{
	class GetMaxElement
	{
		static int GetMax (string[] arr)
		{
			int Max = int.MinValue;
			for (int i = 0 ; i < arr.Length ; i ++)
			{
				Max = Math.Max (Max, int.Parse (arr [i]));
			}
			return Max;
		}
		static int Main (string[] args)
		{
			Console.WriteLine ("{0}", GetMax (Console.ReadLine ().Split (' ')));
			return 0;
		}	
	}
}
