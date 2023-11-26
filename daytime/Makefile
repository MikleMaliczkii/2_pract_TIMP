.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG
DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  = task1
DEBUG_EXEC    = task1-dbg
SOURCE        = task1.cpp

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): task1.cpp
	g++ $(DEBUG_FLAGS) task1.cpp -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): task1.cpp
	g++ $(RELEASE_FLAGS) task1.cpp -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
