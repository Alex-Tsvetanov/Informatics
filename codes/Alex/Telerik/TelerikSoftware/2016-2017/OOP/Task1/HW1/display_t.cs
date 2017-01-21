//
//  display_t.cs
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
	public class display_t
	{
		public class size_t
		{
			int? width;
			int? height;

			public size_t (int? width = null, int? height = null)
			{
				this.height = height;
				this.width = width;
			}
			public override string ToString ()
			{
				return string.Format ("{2}\"width\":{0},\"height\":{1}{3}", width, height, '{', '}');
			}
		}
		size_t size;
		int? number_of_colors;
		public display_t (size_t s = null, int? num = null)
		{
			this.size = s;
			this.number_of_colors = num;
		}		
		public override string ToString ()
		{
			return string.Format ("{2}\"size\":{0},\"number_of_colors\":{1}{3}", size, number_of_colors, '{', '}');
		}
	}
}
	