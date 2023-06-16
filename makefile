all:
	g++ -c -o main.o main.cpp
	g++ -c -o snake.o snake.cpp
	g++ -c -o network.o network.cpp
	g++ -o main main.o snake.o network.o -lsfml-graphics -lsfml-window -lsfml-system
	./main 