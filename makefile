CXX = g++
CXXFLAGS = -std=c++11 -O2 -I/src/utils

# Get fileDirname and filename from command-line arguments
fileDirname := $(fileDirname)
filename := $(filename)

# Construct the target name (executable in the bin folder)
TARGET = bin/a.out
SRCS = $(fileDirname)/$(filename).cpp \
    src/utils/tree.cpp  

HEADERS = src/utils/tree.h

OBJS = $(patsubst $(fileDirname)/%.cpp, bin/%.o, $(SRCS)) 
# you can append .o files to this OBJS as an alternate to appending headers and SRCS
all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "fileDirname: $(fileDirname)"  # Echo fileDirname
	@echo "filename: $(filename)"  # Echo filename
	@echo "workspaceFolder: $(workspaceFolder)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

bin/%.o: $(fileDirname)/%.cpp $(HEADERS) 
	$(CXX) $(CXXFLAGS) -I$(dir $(HEADERS)) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET) < $(fileDirname)/input.txt
