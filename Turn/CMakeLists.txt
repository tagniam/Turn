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