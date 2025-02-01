CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -lgtest -lgtest_main -pthread

SRC = StringUtils.cpp StringUtilsTest.cpp
OBJ = $(SRC:.cpp=.o)
BIN = bin/teststrutils

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(BIN)
	./$(BIN)

clean:
	rm -rf obj bin *.o
