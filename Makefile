CC = g++
CFLAGS = -std=c++11
TARGETS = a3a a3b


all: $(TARGETS)

a3a: a3a.cpp
	$(CC) $(CFLAGS) -o a3a a3a.cpp

a3b: a3b.cpp
	$(CC) $(CFLAGS) -o a3b a3b.cpp

clean:
	rm -rf $(TARGETS)
