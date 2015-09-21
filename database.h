#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Creates a new warehouse
warehouse * new_warehouse();

// adds a new item to the shelf
void add_item(warehouse *warehouse_list, char *name, char *description, int price,
	      char *shelf_num, int quantity);

// removes an item, based on index in list.
void remove_item(warehouse *warehouse_list, int index);

// edit item, selected by index
void edit_item(shelf *shelf, char *name, char *description, int price,
	       char *shelf_num, int quantity);

shelf * get_shelf(warehouse *warehouse_list, int index);

// undos the latest action
void undo_action(warehouse *warehouse_list);

// free up memory used by program
void destroy_warehouse();
