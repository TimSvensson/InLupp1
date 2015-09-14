#include "backend.h"

//-----

struct warehouse_header
{
  warehouse_t *ptr_top;
  warehouse_t *ptr_end;
};

struct warehouse
{
  struct item
  {
    char *name;
    char *description;
    int price;
  }item_t;

  char *ware_loc;
  int quantity;
  struct warehouse *ptr_next_item;
  
};

//-----

struct warehouse_header *warehouse_list =
  (struct warehouse_header*) malloc(sizeof(struct warehouse_header));

void init_list_head()
{

  assert(warehouse_list != NULL);

  warehouse_list -> ptr_top = NULL;
  warehouse_list -> ptr_end = NULL;

}
 
//-----

int warehouse_empty()
{
  return warehouse_list -> ptr_top == NULL;
}

void append_to_tail(struct warehouse *new_item)
{
  struct warehouse *prev_item = warehouse_list -> ptr_end;
  prev_item -> ptr_next_item = new_item;
}

void add_item(char *name, char *description, int price,
	      char *ware_loc, int quantity)
{
  struct warehouse *new_item = (struct warehouse*) malloc(sizeof(struct warehouse));
  assert(new_item != NULL);

  new_item -> item_t.name = strdup(name);
  new_item -> item_t.description = strdup(description);
  new_item -> item_t.price = price;
  new_item -> ware_loc = strdup(ware_loc);
  new_item -> quantity = quantity;
  new_item -> ptr_next_item = NULL;
  
  if(!warehouse_empty())
    {
      append_to_tail(new_item);
      
    } else
    {
      warehouse_list -> ptr_top = new_item;
    }

  warehouse_list -> ptr_end = new_item;
}

//-----

void remove_item(char *name);
void edit_item();

//---

void print_item(struct warehouse *item)
{
  assert(item != NULL);

  printf("\n----------\n");
  printf("Name\n\t%s\n", item -> item_t.name);
  printf("Description\n\t%s\n", item -> item_t.description);
  printf("Price\n\t%d\n", item -> item_t.price);
  printf("Location\n\t%s\n", item -> ware_loc);
  printf("Quantity\n\t%d\n", item -> quantity);
}

void print_warehouse()
{
  struct warehouse *crnt_item = warehouse_list -> ptr_top;

  while(1)
    {
      assert(crnt_item != NULL);

      print_item(crnt_item);

      if(crnt_item -> ptr_next_item == NULL)
	{
	  break;
	}

      crnt_item = crnt_item -> ptr_next_item;
    }
}

//---

void destroy_item(struct warehouse *item)
{
  assert(item != NULL);

  free(item);
}

void destroy_warehouse()
{
  struct warehouse *crnt_item = NULL;
  struct warehouse *next_item = warehouse_list -> ptr_top;
  
  while(1)
    {
      assert(next_item != NULL);
      
      crnt_item = next_item;
      next_item = crnt_item -> ptr_next_item;

      destroy_item(crnt_item);

      if(crnt_item -> ptr_next_item == NULL)
	{
	  free(warehouse_list);
	  break;
	}
    }
}

//-----

int main(int argc, char* argv[])
{

  init_list_head();

  add_item("Test", "Test", 123, "A23", 12);
  add_item("Test2", "Another test", 234, "B34", 23);

  print_warehouse();

  destroy_warehouse();
  
  return 0;
}
