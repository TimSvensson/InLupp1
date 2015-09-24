#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "database.h"

#ifndef IO_H 
#define IO_H


//funktioner som menu kallar på

void add_shelf_IO(warehouse *warehouse_list);

void remove_shelf_IO(warehouse *warehouse_list);

void edit_shelf_IO(warehouse *warehouse_list);

int exit_warehouse();

int ask_int_q(char* question);



//Tim
// prints a shelf to the console
void print_shelf(shelf *shelf);

// prints all shelves in the warehouse
void print_warehouse(warehouse *warehouse_list);

// prints 20 shelfs and numbers them starting from zero. Returns the last element printed
shelf * print_20(warehouse *warehouse_list, shelf *shelf_start);

#endif /* IO_H */
