cmake_minimum_required(VERSION 3.8)
project(GameLogicEventingEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG -ggdb3)

option(BUILD_DEBUG "Build debug" ON)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_RELEASE "Build release" OFF)

include_directories(./include/game_logic_eventing_engine/core)
include_directories(./include/game_logic_eventing_engine/engine)
aux_source_directory(./include/game_logic_eventing_engine/core HEADER_FILES_CORE)
aux_source_directory(./include/game_logic_eventing_engine/engine HEADER_FILES_ENGINE)

add_library(GameLogicEventingEngine-Core SHARED)
target_link_libraries(GameLogicEventingEngine-Core pthread)

target_sources(GameLogicEventingEngine-Core
	${HEADER_FILES_CORE}
	
	src/core/EventsQueue
	src/core/Event
	
	src/Collider
	src/Terrain
	src/StaticObjects
	src/World

	src/EntityBase
	src/ComponentDataBase
	src/ComponentComputationBase
)

add_library(GameLogicEventingEngine SHARED
	${HEADER_FILES_ENGINE}
	src/ProcessingLoop
	src/ConnectionProxy
)

target_link_libraries(GameLogicEventingEngine GameLogicEventingEngine-Core)


add_compile_options(-fno-aliasing)

if(BUILD_DEBUG)
	add_compile_options(-ggdb3)
	add_compile_options(-ggdb)
	add_compile_options(-pg)
	add_compile_options(--coverage)
	# gcov file.cpp
	# geninfo ./ -b ./ -o ./coverage.info
	# genhtml ./coverage.info -o /tmp/html
else()
endif()


if(BUILD_RELEASE)
	add_compile_options(-Ofast)
	add_compile_options(-s)
else()
endif()


if(BUILD_TESTS)
	aux_source_directory(tests/ TESTS_SOURCE)
	add_executable(test
		${TESTS_SOURCE}
	)
	target_link_libraries(test GameLogicEventingEngine)
endif()


if(UNIX)
elseif(WIN32)
else()
	# print error message: not tested platform
endif()

