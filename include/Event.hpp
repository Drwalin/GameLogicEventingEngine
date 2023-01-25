/*
 *  This file is part of GameLogicEventingEngine.
 *  Copyright (C) 2023 Marek Zalewski aka Drwalin
 *
 *  ICon3 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ICon3 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef GAME_LOGIC_EVENTING_ENGINE_HPP
#define GAME_LOGIC_EVENTING_ENGINE_HPP

#include <cinttypes>

#include <functional>

namespace geeng {
	class Event {
	public:
		
		void Execute();
		
	private:
		
		uint64_t timeCreated;
		uint64_t priority;
		
		std::function<void(void*args, uint64_t deltaTimeMs)> code;
		void* args;
		
		Event();
		~Event();
	};
	
};

#endif

