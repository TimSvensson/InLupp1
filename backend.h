#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct warehouse_header warehouse_header_t;
typedef struct warehouse warehouse_t;
typedef struct item item_t;

// warehouse_list header, allways points to the first element of the list
struct warehouse_header
{
  warehouse_t *ptr_top;
};

// warehouse, items are stored here
struct warehouse
{
  struct item // the item type
  {
    char *name;
    char *description;
    int price;
  }item_t;

  char *ware_loc;
  int quantity;
  struct warehouse *ptr_next_item;
};

// adds a new item to the warehouse
void add_item(char *name, char *description, int price,
	      char *ware_loc, int quantity);

// removes an item, based on index in list.
void remove_item(int i);
// edit item, selected by index
warehouse_t * edit_item(int i);
// print item, base on index
void print_item(int i);
// displays the entire warehouse
void print_warehouse();
// free up memory used by program
void destroy_warehouse();
void init_list_head();
