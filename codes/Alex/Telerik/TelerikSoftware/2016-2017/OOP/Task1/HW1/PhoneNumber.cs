//
//  PhoneNumber.cs
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
	public class PhoneNumber
	{
		string name;
		string tel;
		string mobile_operator;

		public PhoneNumber (string name = null, string tel = null, string mobile_operator = null)
		{
			this.name = name;
			this.tel = tel;
			this.mobile_operator = mobile_operator;
		}
		public override string ToString ()
		{
			return string.Format ("{0}\"name\": {2}, \"tel\": {3}, \"mobile_operator\": {4}{1}", '{', '}', name, tel, mobile_operator);
		}
	}
}

