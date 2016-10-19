using System;

class ChangeBit
{
    static void Main ()
    {
        int integer = int.Parse (Console.ReadLine ());
        int p = int.Parse (Console.ReadLine ());
        int q = int.Parse (Console.ReadLine ());
        int k = int.Parse (Console.ReadLine ());
		for (int i = 0 ; i < k ; i ++)
		{
			int f = ((integer & (1 << p)) / (1 << p));
			int s = ((integer & (1 << q)) / (1 << q));
			integer -= f << p;
			integer -= s << q;
			integer += f << q;
			integer += s << p;
			p ++;
			q ++;
		}
		Console.WriteLine (integer);

    }
}
