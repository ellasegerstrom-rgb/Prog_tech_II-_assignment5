CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = src/main.cpp src/TrainingData.cpp src/SmallLanguageModel.cpp src/TextGenerator.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = slm

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
