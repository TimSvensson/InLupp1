#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct warehouse_header
{
  struct warehouse *ptr_first_item;
} warehouse_header_t;

typedef struct warehouse
{
  typedef struct item
  {
    char *name;
    char *description;
    int price;
  } item_t;

  char *ware_loc;
  int quantity;
  struct warehouse *ptr_next_item;
} warehouse_t;


void add_item(char *name, char *description, int price,
	      char *ware_loc, int quantity);
void remove_item(char *name);
void edit_item();
void print_warehouse();
void undo_action();
void exit_warehouse();
