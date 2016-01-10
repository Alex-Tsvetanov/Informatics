using System;
using System.Linq;

class Prg
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		for(int i = 0; i<n; i++)
		{
			string s1 = Console.ReadLine(), s2 = Console.ReadLine();
			var ss1 = s1.Split(new char[]{')', '(', ',', ' '});
			var ss2 = s2.Split(new char[]{')', '(', ',', ' '});
			ss1 = ss1.Where(x=>x!="").ToArray();
			ss2 = ss2.Where(x=>x!="").ToArray();
			double r=0, rX=0, rY=0, aX=0, aY=0, bX=0, bY=0;
			if(ss1[0]=="circle")
			{
				rX = double.Parse(ss1[1]);
				rY = double.Parse(ss1[2]);
				r = double.Parse(ss1[3]);
			}
			else
			{
				aX = double.Parse(ss1[1]);
				aY = double.Parse(ss1[2]);
				bX = double.Parse(ss1[3]);
				bY = double.Parse(ss1[4]);
			}
			if(ss2[0]=="circle")
			{
				rX = double.Parse(ss2[1]);
				rY = double.Parse(ss2[2]);
				r = double.Parse(ss2[3]);
			}
			else
			{
				aX = double.Parse(ss2[1]);
				aY = double.Parse(ss2[2]);
				bX = double.Parse(ss2[3]);
				bY = double.Parse(ss2[4]);
			}
			if((Math.Sqrt((aX - rX)*(aX-rX)+(aY-rY)*(aY-rY))<=r) || (Math.Sqrt((bX-rX)*(bX-rX) + (bY-rY)*(bY-rY))<=r) || (Math.Sqrt((aX-rX)*(aX-rX) + (bY-rY)*(bY-rY))<=r) || (Math.Sqrt((bX- rX) * (bX - rX) + (aY-rY)*(aY-rY))<=r))
			{
				Console.WriteLine("Rectangle and circle cross");
			}
			else
			{
				Console.WriteLine("Rectangle and circle do not cross");
			}
		}
	}
}
