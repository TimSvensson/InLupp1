CC=gcc

all: main

warehouse: main.c b.o
	$(CC) -Wall -std=c11 -ggdb main.c menu.o IO.o database.o -o main

menu.o: menu.c
	$(CC) -Wall -std=c11 -ggdb menu.c -c

IO.o: IO.c
	$(CC) -Wall -std=c11 -ggdb IO.c -c

database.o: database.c
	$(CC) -Wall -std=c11 -ggdb database.c -c

run: main #run är beroende av warehouse
	@echo "Running program, woho!"

	@./main #om man inte vill att terminalen skriver ut ./warehouse kan man lägga till @ innan

clean:
	rm -f main #-f betyder att om filen inte existerar händer ingenting
	rm *.o
	rm -r *.dSYM
