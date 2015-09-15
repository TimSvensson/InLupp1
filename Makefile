CC=gcc

all: warehouse

warehouse: warehouse.c backend_utan_main.o
	$(CC) -Wall -std=c11 -ggdb warehouse.c backend_utan_main.o -o warehouse

backend_utan_main.o: backend_utan_main.c
	$(CC) -Wall -std=c11 -ggdb backend_utan_main.c -c

run: warehouse #run är beroende av warehouse
	@echo "Running program, woho!"

	@./warehouse #om man inte vill att terminalen skriver ut ./warehouse kan man lägga till @ innan

clean:
	rm -f warehouse #-f betyder att om filen inte existerar händer ingenting
	rm *.o
	rm -r *.dSYM
