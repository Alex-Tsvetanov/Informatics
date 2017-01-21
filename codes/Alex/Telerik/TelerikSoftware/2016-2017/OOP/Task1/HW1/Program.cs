//
//  Program.cs
//
//  Author:
//       Alex Tsvetanov <alex@tsalex.tk>
//
//  Copyright (c) 2016 Alex Tsvetanov
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
using System;

namespace HW1
{
	class GSMTest
	{
		public static void Main (string[] args)
		{
			GSM[] a = new GSM[]{
				new GSM ("asdf0", "asdf5", 0, "", new battery_t ("asdf6", 15, 13, BatteryType.LiIon), new display_t (new display_t.size_t (1920, 1200), 256)),
				new GSM ("asdf1", "asdf4", 0, "", new battery_t ("asdf7", 15, 13, BatteryType.LiIon), new display_t (new display_t.size_t (1920, 1200), 256)),
				new GSM ("asdf2", "asdf3", 0, "", new battery_t ("asdf8", 15, 13, BatteryType.LiIon), new display_t (new display_t.size_t (1920, 1200), 256)),
			};
			foreach (var item in a) {
				Console.WriteLine (item.ToString());
			}
			Console.WriteLine (GSM.IPhone4S.ToString());

			GSM testcall = new GSM ("asdf0", "asdf5", 0, "", new battery_t ("asdf6", 15, 13, BatteryType.LiIon), new display_t (new display_t.size_t (1920, 1200), 256));
			Call calltoadd = new Call (DateTime.Now, new PhoneNumber ("Bai Pesho", "+359-666-99-69-99", "Mobile Tel"), new TimeSpan (0, 1, 5));
			testcall.AddCallToHistory (calltoadd);
			foreach (var item in testcall.CallsHistory) {
				Console.WriteLine (item.ToString ());
				Console.WriteLine (item.Cost ());
			}
			testcall.RemoveCallFromHistory (calltoadd);
			foreach (var item in testcall.CallsHistory) {
				Console.WriteLine (item.ToString ());
			}
		}
	}
}
