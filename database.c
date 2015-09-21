#include "database.h"

typedef struct prev_state prev_state;
typedef enum enum_action enum_action;


// ==================
// ----- STRUCT -----
// ==================



// warehouse
struct warehouse
{
  shelf *first_shelf;
};

struct item
{
  char *name;
  char *description;
  int price;
};

// shelf, items are stored here
struct shelf
{
  item item;

  char *shelf_num;
  int num_shelfs;
  
  shelf *next_shelf;
};

struct prev_state
{
  enum_action prev_action;
  shelf_t prev_warehouse;
  int index;
};

// ----- ENUM -----

typedef enum
  {
    ADD_ACTION,
    REMOVE_ACTION,
    EDIT_ACTION,
    NO_ACTION
  } enum_action;



// ===============
// ----- AUX -----
// ===============



// Get the last element of warehouse_list
shelf * get_last_shelf(warehouse *warehouse_list)
{
  shelf = warehouse_list -> first_shelf;
  if(shelf == NULL)
    {
      return NULL;
    }
  
  while(1)
    {
      if(shelf -> next_shelf == NULL)
	{
	  return shelf;
	}
      else
	{
	  shelf = shelf -> next_shelf;
	}
    }
}

// Get shelf at index in warehouse_list
shelf * get_shelf(warehouse *warehouse_list, int index)
{
  shelf *shelf = warehouse_list -> first_shelf;
  
  for(int i = 0; i != index; ++i)
    {
      shelf = shelf -> next_shelf;
    }

  return shelf;
}



// =========================
// ----- NEW WAREHOUSE -----
// =========================



warehouse * new_warehouse()
{
  warehouse *warehouse_list =
    (warehouse*) malloc(sizeof(warehouse));

  return warehouse_list;
}



// ===============
// ----- ADD -----
// ===============



// Declarse the variables of item
void create_new_shelf_aux(shelf *item, char *name, char *description, int price)
{
  item -> name = name;
  item -> description = description;
  item -> price = price;
}

// Creates a new item
item * create_new_shelf(char *name, char *description, int price)
{
  item *new_shelf = (item *) malloc(sizeof(item));
  assert(new_shelf != NULL);

  create_new_shelf_aux(new_shelf, name, description, price);

  return new_shelf;
}

// -----

// Declares the variables of shelf
void create_new_shelf_aux(shelf *shelf, char *name, char *description, int price,
		  char *shelf_num, int num_shelfs)
{
  shelf -> item = create_new_shelf(name, description, price);
  shelf -> shelf_num = shelf_num;
  shelf -> num_shelfs = num_shelfs;
  shelf -> next_shelf = NULL;
}

// Creates a new shelf
shelf * create_new_shelf(char *name, char *description, int price,
		  char *shelf_num, int num_shelfs)
{
  shelf *shelf = (shelf*) malloc(sizeof(shelf));
  assert(shelf != NULL);

  create_new_shelf_aux(shelf, char *name, char *description, int price,
		       char *shelf_num, int num_shelfs);

  return shelf;
}


// -----


// adds a new item to warehouse_list
void add_shelf(warehouse *warehouse_list, char *name, char *description, int price,
	      char *shelf_num, int num_shelfs)
{
  // create new shelf
  new_shelf = create_new_shelf(name, description, price, shelf_num, num_shelfs);
  
  // check: is warehouse empty?
  if(warehouse_list -> first_shelf == NULL)
    {
      // yes: put first in list
      warehouse_list -> first_shelf = new_shelf;
    }
  else
    {
      // no: append to last element
      last_shelf = get_last_shelf(warehouse_list);
      last_shelf -> next_shelf = shelf;
    }
}



//==================
//----- REMOVE -----
//==================



// Remove shelf at index in warehouse_list
void remove_shelf(warehouse *warehouse_list, int index)
{
  prev_shelf = get_shelf(warehouse_list, index-1);
  shelf = prev_shelf -> next_shelf;
  
  prev_shelf -> next_shelf = shelf -> next_shelf;
  free(shelf);
}



//================
//----- EDIT -----
//================



void edit_shelf(shelf *shelf, char *name, char *description, int price,
	       char *shelf_num, int quantity)
{
  item = shelf -> item;

  item -> name = name;
  item -> description = description;
  item -> price = price;
  shelf -> shelf_num = shelf_num;
  shelf -> quantity = quantity;
}



//===================
//----- DESTROY -----
//===================



// destroys the entire warehouse
void destroy_warehouse(warehouse *warehouse_list)
{
  shelf = warehouse_list -> first_shelf;

  while(shelf != NULL)
    {
      tmp_shelf = shelf;
      shelf = shelf -> next_shelf;

      free(tmp_shelf);
    }

  free(warehouse_list);
}



// =======================
// ----- UNDO ACTION -----
// =======================



void undo_last_action()
{
  
}
