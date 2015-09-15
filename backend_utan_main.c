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

void destroy_item(struct warehouse *item);
 
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

void remove_item(char *name)
{
  //find_item
  struct warehouse *crnt_item = warehouse_list -> ptr_top;
  struct warehouse *prev_item = NULL;

  while(1)
    {
      // find the item
      if(strcmp(crnt_item -> item_t.name, name) == 0)
	{
	  if(prev_item == NULL) // if crnt_item is the top of the list
	    {
	      warehouse_list -> ptr_top = crnt_item -> ptr_next_item;
	    }
	  if(crnt_item -> ptr_next_item == NULL) // crnt_item is the last item in list
	    {
	      warehouse_list -> ptr_end = crnt_item -> ptr_next_item;
	      if(prev_item != NULL)
		{
		  prev_item -> ptr_next_item = NULL;
		}
	    }
	  if(prev_item != NULL && crnt_item -> ptr_next_item != NULL)
	    {
	      prev_item -> ptr_next_item = crnt_item -> ptr_next_item;
	    }
	  
	  destroy_item(crnt_item);
	  printf("\n----------\nITEM FOUND AND DESTROYED\n----------\n");
	  break;
	}
      else if(crnt_item -> ptr_next_item != NULL)
	{
	  prev_item = crnt_item;
	  crnt_item = crnt_item -> ptr_next_item;
	}
      else
	{
	  printf("\n----------\nITEM NOT FOUND\n----------\n");
	  break;
	} 
    }
}

//-----

//TODO: implement edit_item
void edit_item();

//-----

void print_item(struct warehouse *item)
{
  assert(item != NULL);

  //TODO: Make output prettier
  printf("\n----------\n");
  printf("Name\n\t%s\n", item -> item_t.name);
  printf("Description\n\t%s\n", item -> item_t.description);
  printf("Price\n\t%d\n", item -> item_t.price);
  printf("Location\n\t%s\n", item -> ware_loc);
  printf("Quantity\n\t%d\n", item -> quantity);
}

void print_warehouse()
{
  if(!warehouse_empty())
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
  else
    {
      printf("\n----------\nWAREHOUSE IS EMPTY\n----------\n");
    }
}

//---

void destroy_item(struct warehouse *item)
{
  assert(item != NULL);

  free(item);
}

//TODO: Hunt for bugs, here!
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
	  warehouse_list -> ptr_top = NULL;
	  warehouse_list -> ptr_end = NULL;
	  free(warehouse_list);
	  break;
	}
    }
}
