using System;
using System.Text;
/*
public class Pair <T, U> 
{
    public Pair () 
	{
    }

    public Pair (T first, U second) 
	{
        this.First = first;
        this.Second = second;
    }

    public T First { get; set; }
    public U Second { get; set; }
};
*/

public class Program
{
	static string decoder (string a)
	{
		string ans = "";
		for (int i = 0 ; i < a.Length ; i ++)
		{
			if (char.IsDigit (a [i]))
			{
				string NUM = string.Empty;
				for ( ; char.IsDigit (a [i]) ; i ++)
				{ NUM = NUM + a [i]; }
				
				ans = ans + (new string (a [i], int.Parse (NUM)));
			}
			else
			{
				ans = ans + a [i];
			}	
		}
		return ans;
	}

	static string split (string a)
	{
		string split_length = "";
		int i;
		for (i = a.Length - 1 ; i >= 0 && char.IsDigit (a [i]) ; i --)
		{ split_length = a [i] + split_length; }

		string decoded = decoder (a.Substring (0, i + 1));

		int split_length_int = int.Parse (split_length);
		string message_text = decoded.Substring (0, decoded.Length - split_length_int);
		string split_text = decoded.Substring (decoded.Length - split_length_int, split_length_int);

		return message_text + " " + split_text;
	}
	
	static void Swap<T>(ref T lhs, ref T rhs)
	{
		T temp;
		temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
	
	static string decrypt (string a, string b)
	{
//		Console.WriteLine (a);
//		Console.WriteLine (b);
		StringBuilder c = new StringBuilder(a);
		int max_length = Math.Max (a.Length, b.Length);

		for (int i = 0 ; i < max_length ; i ++)
		{
			c [i % a.Length] = (char)(65 + ((int)(c [i % a.ToString ().Length] - 'A') ^ (int)(b [i % b.Length] - 'A')));
//			Console.WriteLine ("{0} {1} 65 + {2} = {3}", new_char, (int)(new_char), (int)(a [i] - 'A') ^ (int)(b [i % b.Length] - 'A'), 65 + ((int)(a [i] - 'A') ^ (int)(b [i % b.Length] - 'A')));
		}
		return c.ToString ();
	}

	static void Main(string[] args)
	{
		string encoded_crypted_message = Console.ReadLine();
		string crypted_message = split (encoded_crypted_message).Split (' ') [0];
		string cypher = split (encoded_crypted_message).Split (' ') [1];
	//	Console.WriteLine (crypted_message);
	//	Console.WriteLine (cypher);
		Console.WriteLine (decrypt (crypted_message, cypher));
	}
}
