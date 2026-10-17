CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude_headers

TARGET = slm

OBJS = main_codes/main.o main_codes/slm.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main_codes/main.o: main_codes/main.cpp include_headers/slm.h
	$(CXX) $(CXXFLAGS) -c main_codes/main.cpp -o main_codes/main.o

main_codes/slm.o: main_codes/slm.cpp include_headers/slm.h
	$(CXX) $(CXXFLAGS) -c main_codes/slm.cpp -o main_codes/slm.o

clean:
	rm -f main_codes/*.o $(TARGET)

.PHONY: all clean