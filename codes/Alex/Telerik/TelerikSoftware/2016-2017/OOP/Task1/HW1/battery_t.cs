//
//  battery_t.cs
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
	public enum BatteryType
	{
		Null = -1,
		LiIon = 0, 
		NiMH = 1, 
		NiCd = 2
	}
	public class battery_t
	{
		String model;
		float? hours_idle;
		float? hours_talk;
		BatteryType type;

		public battery_t (String model = null, float? hours_idle = null, float? hours_talk = null, BatteryType type = BatteryType.Null)
		{
			this.model = model;
			this.hours_idle = hours_idle;
			this.hours_talk = hours_talk;
			this.type = type;
		}
		public override string ToString ()
		{
			return string.Format ("{4}\"model\":{0},\"hours_idle\":{1},\"hours_talk\":{2},\"type\":{3}{5}", model, hours_idle, hours_talk, type, '{', '}');
		}
	}
}

