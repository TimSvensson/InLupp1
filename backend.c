#include "backend.h"



//-----



struct warehouse_header *warehouse_list =
  (struct warehouse_header*) malloc(sizeof(struct warehouse_header));

void init_list_head()
{
  assert(warehouse_list != NULL);

  warehouse_list -> ptr_top = NULL;
}

int warehouse_empty()
{
  return warehouse_list -> ptr_top == NULL;
}

void print_empty()
{
  printf("------------------\n");
  printf("WAREHOUSE IS EMPTY\n");
  printf("------------------\n\n");
}

void print_end_of_list()
{
  printf("-----------\n");
  printf("END OF LIST\n");
  printf("-----------\n\n");
}

warehouse_t * find_item(int i);
warehouse_t * print_20(warehouse_t *item);
void print_item(warehouse_t *item);
void print_item_name(warehouse_t *item, int i);
void destroy_item(warehouse_t *item);



//===============
//----- ADD -----
//===============



void append_to_tail(struct warehouse *new_item)
{
  warehouse_t *crnt_item = warehouse_list -> ptr_top;
  
  while(1)
    {
      if(crnt_item -> ptr_next_item == NULL)
	{
	  crnt_item -> ptr_next_item = new_item;
	  break;
	}

      crnt_item = crnt_item -> ptr_next_item;
    }
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
      
    }
  else
    {
      warehouse_list -> ptr_top = new_item;
    }
}


//==================
//----- REMOVE -----
//==================


//TODO
void remove_item(int i);



//================
//----- EDIT -----
//================



//TODO: implement edit_item
warehouse_t * edit_item()
{
  warehouse_t * ret_item = NULL; //return value
  
  //print items
  warehouse_t * crnt_item = warehouse_header -> ptr_top;

  if(warehouse_empty())
    {
      return NULL;
    }
  
  while(1)
    {
      print_20(crnt_item);
      printf("\n");

      // choose item
    }

  return ret_item;
}


//=================
//----- PRINT -----
//=================


int get_y()
{
  printf("Print next 20? (y/n) \n> ");
  char ans;
  scanf(" %c", &ans);
  printf("\n");

  if(ans == 'y')
    {
      return 1;
    }

  return 0;
}

// print items in intervals of 20
void print_warehouse()
{
  if(warehouse_empty())
    {
      print_empty();
    }
  else
    {
      warehouse_t *item = warehouse_list -> ptr_top;

      while(1)
	{
	  item = print_20(item);
	  printf("\n");

	  //if item == NULL: end of list, break loop
	  if(item == NULL)
	    {
	      print_end_of_list();
	      break;
	    }	  	 
	  
	  if(!get_y())
	    {
	      break;
	    }
	}
    }
}

warehouse_t * print_20(warehouse_t *item)
{
  
  for(int i = 1; i <= 20; ++i, item = item -> ptr_next_item)
    {
      print_item_name(item, i);
      
      if(item -> ptr_next_item == NULL)
	{
	  return NULL;
	}
    }

  return item;
}

void print_item_name(warehouse_t *item, int i)
{
  printf("%d\t%s\n", i, item -> item_t.name);
}

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

void print_item_numbers(struct warehouse *item)
{
  assert(item != NULL);

  //TODO: Make output prettier
  printf("1. Name\t\t%s\n", item -> item_t.name);
  printf("2. Description\t%s\n", item -> item_t.description);
  printf("3. Price\t\t%d\n", item -> item_t.price);
  printf("4. Location\t%s\n", item -> ware_loc);
  printf("5. Quantity\t%d\n", item -> quantity);
}


//===================
//----- DESTROY -----
//===================



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
	  free(warehouse_list);
	  break;
	}
    }
}
