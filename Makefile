CC = g++
CFLAGS = -Iinclude -std=c++11
LDFLAGS = -lpq
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = cpp-postgresql-app

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)