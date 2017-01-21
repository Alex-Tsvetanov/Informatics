//
//  GSM.cs
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
using System.Collections.Generic;

namespace HW1
{
	public class GSM
	{
		private float? _price;

//--------------------Fields & Proprties---------------------------------
		public string model, manufacturer;

		public float? price {
			get{ 
				return this._price;
			}
			set {
				if (value >= 0)
					_price = value;
				else
					throw new IndexOutOfRangeException ();
			}
		}

		public String owner;
		public battery_t Battery;
		public display_t Display;
		public List<Call> CallsHistory = new List<Call> ();
//----------------------------------------------------------------------
//--------------------Set Functions-------------------------------------
		public void set_model (string _model)
		{
			model = _model;
			return;
		}

		public void set_manufacturer (string _manufacturer)
		{
			manufacturer = _manufacturer;
			return;
		}

		public void set_price (float _price)
		{
			price = _price;
			return;
		}
//----------------------------------------------------------------------
//--------------------Constructors--------------------------------------
		public GSM (string model = "", string manufacturer = "", float? price = null, String owner = null, battery_t Battery = null, display_t Display = null)
		{
			this.model = model;
			this.manufacturer = manufacturer;
			this.owner = owner;
			this.price = price;
			this.Battery = Battery;
			this.Display = Display;
		}
//----------------------------------------------------------------------
//--------------------Member Functions----------------------------------
		public override String ToString()
		{
			return String.Format("{6}\"model\":{0},\"manufacturer\":{1},\"price\":{2},\"owner\":{3},\"Battery\":{4},\"Display\":{5}{7}",
				model, manufacturer, price, owner, Battery, Display, '{', '}');
		}

		public void AddCallToHistory (Call thatcall)
		{
			this.CallsHistory.Add (thatcall);
			return;
		}

		public GSM RemoveCallFromHistory (Call thatcall)
		{
			this.CallsHistory.Remove (thatcall);
			return this;
		}
//----------------------------------------------------------------------
//--------------------Static Members------------------------------------
		public static GSM IPhone4S = new GSM ("IPhone4S", "", 0, "Apple", new battery_t ("Stupid Model", 0, 0, BatteryType.LiIon), new display_t (new display_t.size_t (10, 10), 1));
	}
}
