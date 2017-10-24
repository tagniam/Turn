# Source Files
file(GLOB_RECURSE SOURCES 
	"src/*.cpp"
	)
file(GLOB_RECURSE HEADERS
	"src/*.h"
	"include/*.h"
	)

# Include Directories
include_directories(
	"include/"
	"src/"
	)
	
add_executable(Turn ${SOURCES} ${HEADERS})

# Link WinMM required for PlaySound
if (WIN32)
	target_link_libraries(Turn winmm.lib)
endif (WIN32)