cmake_minimum_required (VERSION 3.12)
project (Turn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

# Find all source files
include(src/sourcelist.cmake)

add_executable(Turn)

# Include Directories
target_include_directories(Turn PRIVATE
	"include/"
	)

# Bind source files to target
target_sources(Turn PRIVATE
	${SOURCES}
	)

# Add warnings
target_compile_options(Turn PRIVATE
					   $<$<CXX_COMPILER_ID:MSVC>:/W3 /EHsc>
					   $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Wpedantic>
					   )

# Link WinMM required for PlaySound
if (WIN32)
	target_link_libraries(Turn winmm.lib)
endif (WIN32)

if (UNIX)
	target_link_libraries(Turn SDL2 SDL2_mixer pthread)
endif (UNIX)
