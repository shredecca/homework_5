// How to compile and the flags

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude_headers

TARGET = slm

SRCS = main_codes/main.cpp main_codes/model.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS))
$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
rm -f main_codes/*.o $(TARGET)

.PHONY: all clean