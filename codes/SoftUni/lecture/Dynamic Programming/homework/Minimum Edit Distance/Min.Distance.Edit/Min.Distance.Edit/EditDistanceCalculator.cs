using System.Collections.Generic;
using System;

namespace Min.Distance.Edit
{
	public class EditDistanceCalculator
	{
		public double SubstitutionCost { get; private set; }
		public double DeletionCost { get; private set; }
		public double InsertionCost { get; private set; }

		public EditDistanceCalculator() : this(1,1, 1)
		{
		}

		public EditDistanceCalculator(double substitutionCost, double insertionCost, double deletionCost)
		{
			InsertionCost = insertionCost;
			DeletionCost = deletionCost;
			SubstitutionCost = substitutionCost;
		}

		public KeyValuePair <double, Move[]> CalcEditDistance(string s, string t)
		{
			if (s == null) throw new ArgumentNullException("s");
			if (t == null) throw new ArgumentNullException("t");

			var distances = new Cell[s.Length + 1, t.Length + 1];
			for (int i = 0; i <= s.Length; i++)
				distances[i, 0] = new Cell(i, Move.Delete);
			for (int j = 0; j <= t.Length; j++)
				distances[0, j] = new Cell(j*InsertionCost, Move.Insert);

			for (int i = 1; i <= s.Length; i++)
				for (int j = 1; j <= t.Length; j++)
					distances[i, j] = CalcEditDistance(distances, s, t, i, j);

			return GetEdit(distances, s.Length, t.Length);
		}

		private Cell CalcEditDistance(Cell[,] distances, string s, string t, int i, int j)
		{
			var cell = s[i - 1] == t[j - 1]
				? new Cell(distances[i - 1, j - 1].Cost, Move.Match)
				: new Cell(SubstitutionCost + distances[i - 1, j - 1].Cost, Move.Substitute);
			double deletionCost = DeletionCost + distances[i - 1, j].Cost;
			if (deletionCost < cell.Cost)
				cell = new Cell(deletionCost, Move.Delete);

			double insertionCost = InsertionCost + distances[i, j - 1].Cost;
			if (insertionCost < cell.Cost)
				cell = new Cell(insertionCost, Move.Insert);

			return cell;
		}

		private static KeyValuePair <double, Move[]> GetEdit(Cell[,] distances, int i, int j)
		{
			double cost = 0.0;
			var moves = new Stack<Move>();
			while (i > 0 && j > 0)
			{
				var move = distances[i, j].Move;
				cost += distances [i, j].Cost;
				moves.Push(move);
				switch (move)
				{
				case Move.Match:
				case Move.Substitute:
					i--;
					j--;
					break;
				case Move.Insert:
					j--;
					break;
				case Move.Delete:
					i--;
					break;
				default:
					throw new ArgumentOutOfRangeException();
				}
			}
			for (int k = 0; k < i; k++)
				moves.Push(Move.Delete);
			for (int k = 0; k < j; k++)
				moves.Push(Move.Insert);

			return new KeyValuePair <double, Move[]> (cost, moves.ToArray());
		}

		class Cell
		{
			public double Cost { get; private set; }
			public Move Move { get; private set; }

			public Cell(double cost, Move move)
			{
				Cost = cost;
				Move = move;
			}
		}
	}

	public enum Move
	{
		Match,
		Substitute,
		Insert,
		Delete
	}
}
