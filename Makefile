CC=gcc

all: warehouse

warehouse: warehouse.c exempel.o
	$(CC) -Wall -std=c11 -ggdb warehouse.c -o warehouse

exempel.o: exempel.c
	$(CC) -Wall -std=c11 -ggdb exempel.c -c
run: warehouse #run är beroende av warehouse
	@./warehouse #om man inte vill att terminalen skriver ut ./warehouse kan man lägga till @ innan

clean:
	rm -f warehouse #-f betyder att om filen inte existerar händer ingenting
	rm *.o
	rm -r *.dSYM
