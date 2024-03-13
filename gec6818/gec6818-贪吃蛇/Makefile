BUILD_PATH = ./build-arm/
CC = arm-linux-g++
SRC = $(wildcard *.cpp)
DEPEND = $(patsubst %.cpp, $(BUILD_PATH)%.o, $(SRC))
project: $(DEPEND)
	$(CC) $^ -o $@ -pthread


$(BUILD_PATH)%.o: %.cpp
	$(CC) $< -c -o $@ -std=c++11


clean:
	rm $(BUILD_PATH)*.o -rf
	rm b.out -rf 		

