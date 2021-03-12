CFLAGS =-Wall -Wextra -Werror
all: prog

prog: main.o
	g++ main.o $(CFLAGS) -o prog.exe
	./prog.exe

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o *.exe