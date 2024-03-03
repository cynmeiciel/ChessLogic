# Set the compiler and flags
CXX=g++
CXXFLAGS="-std=c++17 -Wall -Wextra -g"

# Set the source file and output file
SOURCE_FILES_1="*.cpp"
SOURCE_FILES_2="piece/*.cpp"
OUTPUT_FILE="a.out"

# Compile the source file
$CXX $CXXFLAGS $SOURCE_FILES_1 $SOURCE_FILES_2 -o $OUTPUT_FILE