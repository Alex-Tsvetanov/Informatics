using System;
using System.Globalization;

namespace Homework
{
	class MainProgram
	{
		public static void Main (string[] args)
		{
			string date = Console.ReadLine ();
			var dutchCulture = CultureInfo.CreateSpecificCulture("nl-NL");
			DateTime birthday = DateTime.ParseExact(date, "MM.dd.yyyy", dutchCulture);
			var today = DateTime.Today;
			var age = today.Year - birthday.Year;
			today = new DateTime (birthday.Year, today.Month, today.Day, 0, 0, 0);
			if (birthday > today) age--;

			Console.WriteLine ("{0}\n{1}", age, age + 10);
		}
	}
}
