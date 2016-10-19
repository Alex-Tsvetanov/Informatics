using System;

class ChangeBit
{
    static void Main ()
    {
        int integer = int.Parse (Console.ReadLine ());
		int  _3 = ((integer & (1 <<  3)) / (1 <<  3));
		int  _4 = ((integer & (1 <<  4)) / (1 <<  4));
		int  _5 = ((integer & (1 <<  5)) / (1 <<  5));
		int _24 = ((integer & (1 << 24)) / (1 << 24));
		int _25 = ((integer & (1 << 25)) / (1 << 25));
		int _26 = ((integer & (1 << 26)) / (1 << 26));
		integer -=  _3 <<  3;
		integer -=  _4 <<  4;
		integer -=  _5 <<  5;
		integer -= _24 << 24;
		integer -= _25 << 25;
		integer -= _26 << 26;
		integer +=  _3 << 24;
		integer +=  _4 << 25;
		integer +=  _5 << 26;
		integer += _24 <<  3;
		integer += _25 <<  4;
		integer += _26 <<  5;
		Console.WriteLine (integer);

    }
}
