# Source Files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Turn ${SOURCES} ${HEADERS})

# Include Directories
target_include_directories(Turn PRIVATE "include")

# Link WinMM required for PlaySound
if (WIN32)
	target_link_libraries(Turn winmm.lib)
endif (WIN32)

if (UNIX)
	find_package(SDL2 REQUIRED)
	target_link_libraries(Turn SDL2 SDL2_mixer pthread)
endif (UNIX)
