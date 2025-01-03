CC = g++
COMPILER_FLAGS = -std=c++17
SRC_DIR = src
SRC_FILES = Main.cpp $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS = -Iinclude
BUILD_DIR = build
OBJ_NAME = outfile

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(SRC_FILES) -o $(OBJ_NAME)