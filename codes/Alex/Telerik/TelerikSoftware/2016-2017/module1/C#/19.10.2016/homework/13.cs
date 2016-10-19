using System;
class ChangeBit
{
    static void Main()
    {
        ulong integer = ulong.Parse (Console.ReadLine ());
        int position = int.Parse (Console.ReadLine ());
        ulong value = ulong.Parse (Console.ReadLine ());
		const ulong _1 = 1;
		ulong bit = ((integer & (_1 << position)) / (_1 << position));
		integer = integer - (bit << position);
		integer = integer + (value << position);
		Console.WriteLine (integer);
    }
}
