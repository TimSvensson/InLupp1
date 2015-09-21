#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "database.h"


//funktioner som menu kallar på

void add_item_IO();

void remove_item_IO();

void edit_item_IO();

void exit_warehouse();

int ask_int_q(char* question);



//Tim
// prints a shelf to the console
void print_shelf(shelf *shelf);

// prints 20 shelfs and numbers them starting from zero. Returns the last element printed
shelf * print_20(warehouse *warehouse_list, shelf *shelf_start);
