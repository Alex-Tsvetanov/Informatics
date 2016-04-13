using System;

namespace Min.Distance.Edit
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] first_line = Console.ReadLine ().Split (new char []{' '}, 3);
			int remove_cost = int.Parse (first_line [0]);
			int insert_cost = int.Parse (first_line [1]);
			int replace_cost = int.Parse (first_line [2]);
			string[] second_line = Console.ReadLine ().Split (new char []{' '}, 2);
			EditDistanceCalculator input = new EditDistanceCalculator (replace_cost, insert_cost, remove_cost);
			var path = input.CalcEditDistance (second_line [0], second_line [1]);
			int cost = 0;
			foreach (var item in path.Value)
			{
				if (item == Move.Insert) {
					cost += insert_cost;
				}
				if (item == Move.Delete) {
					cost += remove_cost;
				}
				if (item == Move.Substitute) {
					cost += replace_cost;	
				}
			}
			Console.WriteLine ("{0}", cost);
			int ind1 = 0, ind2 = 0;
			foreach (var item in path.Value)
			{
				if (item == Move.Insert) {
					Console.WriteLine ("Insert ({1}, {0})", second_line [1] [ind2], ind2);
					ind2++;
				}
				if (item == Move.Delete) {
					Console.WriteLine ("Delete {0}", ind1);
					//ind1++;
				}
				if (item == Move.Substitute) {
					Console.WriteLine ("Replace ({0}, {1})", ind1, second_line [1] [ind2]);
					ind2++;
					ind1++;
				}
				if (item == Move.Match) {
					ind2++;
					ind1++;
				}
				//Console.WriteLine ("{0}", item);
			}
		}
	}
}
