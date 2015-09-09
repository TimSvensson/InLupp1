#include <stdio.h>

typedef struct ware
{
  char *name;
  char *description;
  char *warehouse_location;
  int price;
  int amount;
} ware_t;

// ware_t warehouse[10];

void add_ware();
void remove_ware();
void edit_ware();
void print_warehouse();
void undo_action();
void exit_warehouse();
