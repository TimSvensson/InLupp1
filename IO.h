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
