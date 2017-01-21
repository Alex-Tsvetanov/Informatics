//
//  Call.cs
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
	public class Call
	{
		DateTime date_and_time;
		PhoneNumber dialled_phone_number; 
		TimeSpan duration;
		public Call (DateTime date_and_time = new DateTime (), PhoneNumber dialled_phone_number = null, TimeSpan duration = new TimeSpan ())
		{
			this.date_and_time = date_and_time;
			this.dialled_phone_number = dialled_phone_number;
			this.duration = duration;
		}
		public override string ToString ()
		{
			return string.Format ("{0}\"date_and_time\": {2}, \"dialled_phone_number\": {3}, \"duration\": {4}{1}", '{', '}', date_and_time, dialled_phone_number, duration);
		}
		public double Cost ()
		{
			return duration.TotalMinutes * 0.37;
		}
	}
}

