#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct warehouse_header warehouse_header_t;
typedef struct warehouse warehouse_t;
typedef struct item item_t;


void add_item(char *name, char *description, int price,
	      char *ware_loc, int quantity);
void remove_item(char *name);
void edit_item();
void print_warehouse();
