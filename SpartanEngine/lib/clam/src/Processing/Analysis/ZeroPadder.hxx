/*
 * Copyright (c) 2004 MUSIC TECHNOLOGY GROUP (MTG)
 *                         UNIVERSITAT POMPEU FABRA
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __ZEROPADDER__
#define __ZEROPADDER__

#include "Processing.hxx"
#include "ProcessingConfig.hxx"
#include "Audio.hxx"
#include "AudioInPort.hxx"
#include "AudioOutPort.hxx"

namespace CLAM
{
	class ZeroPadderConfig
		: public ProcessingConfig
	{
		DYNAMIC_TYPE_USING_INTERFACE( ZeroPadderConfig, 0, ProcessingConfig );
	};

	class ZeroPadder : public Processing
	{
	protected: // attributes

		ZeroPadderConfig   mConfig;

		AudioInPort mInput;
		AudioOutPort mOutput;

		bool ConcreteStart();
		bool ConcreteStop();

	public:
		ZeroPadder();
		virtual ~ZeroPadder();

		bool Do();	       

		const char* GetClassName() const
		{
			return "ZeroPadder";
		}

		const ProcessingConfig& GetConfig() const 
		{
			return mConfig;
		}

	protected:
		bool ConcreteConfigure( const ProcessingConfig& c );
		
	};

}

#endif // ZeroPadder.hxx
