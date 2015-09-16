#include "backend.h"

//-----

// the header of the list
struct warehouse_header
{
  warehouse_t *ptr_top; // first element of te list
  warehouse_t *ptr_end; // last element of the list
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

// global declaration of the header list
struct warehouse_header *warehouse_list =
  (struct warehouse_header*) malloc(sizeof(struct warehouse_header));

// set up the list pointers
void init_list_head()
{
  assert(warehouse_list != NULL);

  warehouse_list -> ptr_top = NULL;
  warehouse_list -> ptr_end = NULL;
}



//----------



// check if the warehouse is empty
int warehouse_empty()
{
  if (warehouse_list -> ptr_top == NULL)
    {
      return 1;
    }

  return 0;
}

// puts item in the last position of the list
void append_to_tail(struct warehouse *new_item)
{
  struct warehouse *prev_item = warehouse_list -> ptr_end;
  prev_item -> ptr_next_item = new_item;
}

// adds an item to the warehouse
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

	  // if crnt_item is the top of the list
	  if(prev_item == NULL)
	    {
	      warehouse_list -> ptr_top = crnt_item -> ptr_next_item;
	    }

	  // crnt_item is the last item in list
	  if(crnt_item -> ptr_next_item == NULL)
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



struct warehouse *find_item(char *find_name)
{
  if(warehouse_empty())
    {
      return NULL;
    }

  struct warehouse *crnt_item = warehouse_list -> ptr_top;

  

}

//TODO: implement edit_item
void edit_item()
{
  // find item

  // get item
  
  // change item
}



//-----

// Prints an item
void print_item(struct warehouse *item)
{
  assert(item != NULL);

  //TODO: Make output prettier
  printf("\n----------\n");
  printf("Name\t\t%s\n", item -> item_t.name);
  printf("Description\t%s\n", item -> item_t.description);
  printf("Price\t\t%d\n", item -> item_t.price);
  printf("Location\t%s\n", item -> ware_loc);
  printf("Quantity\t%d\n", item -> quantity);
}

// Prints all items inside the warehouse
void print_warehouse() {
  
  // As long as the warehouse is not empty
  if(!warehouse_empty()) {
    
    struct warehouse *crnt_item = warehouse_list -> ptr_top;

    // go through the warehouse
    while(1) {
      assert(crnt_item != NULL);

      print_item(crnt_item);

      // if crnt_item is last in the list
      if(crnt_item -> ptr_next_item == NULL) {
	break;
      }

      // traverse the list one item
      crnt_item = crnt_item -> ptr_next_item;
    }
  }

  else {
    printf("\n----------\nWAREHOUSE IS EMPTY\n----------\n");
  }
}

//-----

// free up memory
void destroy_item(struct warehouse *item)
{
  assert(item != NULL);

  free(item);
}

//TODO: Hunt for bugs, here!
// free up all memory taken by the program
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

      // if crnt_item is the last in the list
      if(crnt_item -> ptr_next_item == NULL)
	{
	  // set all pointers to NULL
	  warehouse_list -> ptr_top = NULL;
	  warehouse_list -> ptr_end = NULL;
	  // free up memory taken på list header
	  free(warehouse_list);
	  break; // exit loop
	}
    }
}

//-----

void test()
{
  add_item("t1", "A", 1, "A11", 11);
  add_item("t2", "B", 2, "B22", 22);
  add_item("t3", "C", 3, "C33", 33);
  add_item("t4", "D", 4, "D44", 44);
  add_item("t5", "E", 5, "E55", 55);

  print_warehouse();

  remove_item("t3");
  remove_item("t5");
  remove_item("t1");

  print_warehouse();
}
