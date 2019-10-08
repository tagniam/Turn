# Fina all source files
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

# Link WinMM required for PlaySound
if (WIN32)
	target_link_libraries(Turn winmm.lib)
endif (WIN32)

if (UNIX)
	target_link_libraries(Turn SDL2 SDL2_mixer pthread)
endif (UNIX)
