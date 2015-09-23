#include "database.h"


// ==================
// ----- STRUCT -----
// ==================



// shelf, items are stored here
struct shelf
{
  struct item
  {
    char *name;
    char *description;
    int price;
  } item;

  char *shelf_num;
  int num_items;
  
  shelf *next_shelf;
};

enum prev_action_e
  {
    NONE,
    ADD,
    REMOVE,
    EDIT
  };

// previos state, used in undo
struct prev_state
{
  enum prev_action_e prev_action;
  shelf *old_shelf;
  int old_index;
};

// warehouse
struct warehouse
{
  shelf *first_shelf;
  prev_state *last_action;
};



// ===============
// ----- AUX -----
// ===============


// TODO!!!
shelf * copy_shelf(shelf *shelf)
{
  
}

// Get the last element of warehouse_list
shelf * get_last_shelf(warehouse *warehouse_list)
{
  shelf *shelf = warehouse_list -> first_shelf;
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

  return NULL;
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

char * get_name(shelf *shelf)
{
  return (shelf -> item.name);
}

char * get_description(shelf *shelf)
{
  return shelf -> item.description;
}

int get_price(shelf *shelf)
{
  return shelf -> item.price;
}

char * get_shelf_num(shelf *shelf)
{
  return shelf -> shelf_num;
}

int get_num_items(shelf *shelf)
{
  return shelf -> num_items;
}

shelf * get_next_shelf(shelf *shelf)
{
  return shelf -> next_shelf;
}

shelf * get_first(warehouse * warehouse_list)
{
  return warehouse_list -> first_shelf;
}



// =========================
// ----- NEW WAREHOUSE -----
// =========================



void init_prev_state(prev_state *prev_state)
{
  prev_state -> prev_action = NONE;
  prev_state -> old_shelf = NULL;
  prev_state -> old_index = 0;
}

prev_state * new_prev_State()
{
  prev_state *prev_state =
    (struct prev_state*) malloc(sizeof(struct prev_state));

  init_prev_state(prev_state);

  return prev_state;
}



void init_warehouse(warehouse *warehouse_list)
{
  warehouse_list -> first_shelf = NULL;
  warehouse_list -> last_action = new_prev_state();
}

warehouse * new_warehouse()
{
  warehouse *warehouse_list =
    (warehouse*) malloc(sizeof(warehouse));

  init_warehouse(warehouse_list);

  return warehouse_list;
}



// ===============
// ----- ADD -----
// ===============



// Declares the variables of shelf
void create_new_shelf_aux(shelf *shelf, char *name, char *description, int price,
		  char *shelf_num, int num_items)
{
  shelf -> item.name = name;
  shelf -> item.description = description;
  shelf -> item.price = price;
  
  shelf -> shelf_num = shelf_num;
  shelf -> num_items = num_items;

  shelf -> next_shelf = NULL;
}

// Creates a new shelf
shelf * create_new_shelf(char *name, char *description, int price,
		  char *shelf_num, int num_items)
{
  shelf *shelf = (struct shelf *) malloc(sizeof(struct shelf));
  assert(shelf != NULL);

  create_new_shelf_aux(shelf, name, description, price,
		        shelf_num, num_items);

  return shelf;
}


// -----


// adds a new item to warehouse_list
void add_shelf(warehouse *warehouse_list, char *name, char *description, int price,
	      char *shelf_num, int num_items)
{
  // create new shelf
  shelf *shelf = create_new_shelf(name, description, price, shelf_num, num_items);
  struct shelf *end_shelf = NULL;
  
  // check: is warehouse empty?
  if(warehouse_list -> first_shelf == NULL)
    {
      // yes: put first in list
      warehouse_list -> first_shelf = shelf;
    }
  else
    {
      // no: append to last element
      end_shelf = get_last_shelf(warehouse_list);
      end_shelf -> next_shelf = shelf;
    }
}



//==================
//----- REMOVE -----
//==================



// Remove shelf at index in warehouse_list
void remove_shelf(warehouse *warehouse_list, int index)
{
  shelf *prev_shelf = get_shelf(warehouse_list, index-1);
  shelf *shelf = prev_shelf -> next_shelf;
  
  prev_shelf -> next_shelf = shelf -> next_shelf;
  free(shelf);
}



//================
//----- EDIT -----
//================



void edit_shelf(shelf *shelf, char *name, char *description, int price,
	       char *shelf_num, int num_items)
{
  shelf -> item.name = name;
  shelf -> item.description = description;
  shelf -> item.price = price;
  shelf -> shelf_num = shelf_num;
  shelf -> num_items = num_items;
}



//===================
//----- DESTROY -----
//===================



// destroys the entire warehouse
void destroy_warehouse(warehouse *warehouse_list)
{
  shelf *shelf = warehouse_list -> first_shelf;
  struct shelf *tmp_shelf = NULL;

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



void undo_last_action(warehouse *warehouse_list)
{
  prev_state *prev_state = warehouse_list -> last_action;
  shelf *prev_shelf = NULL; // the shelf before the undo_shelf
  shelf *undo_shelf = NULL; // the shelf that was added, removed or edited
  
  switch(prev_state -> prev_action)
    {
    case ADD:
      // remove that which was added
      prev_shelf =
	get_shelf(warehouse_list, prev_state -> old_index - 1);

      // get the correct shelf
      undo_shelf = prev_shelf -> next_shelf;
      // set prev_shelf's next_shelf to the shelf after undo_shelf
      prev_shelf -> next_shelf = undo_shelf -> next_shelf;
      // free up the memory
      free(undo_shelf);

      prev_state -> prev_action = NONE;
      break;

    case REMOVE:
      // add that which was removed
      prev_shelf =
	get_shelf(warehouse_list, prev_state -> old_index - 1);

      // get the old shelf address
      undo_shelf = prev_state -> old_shelf;
      // set the correct next_shelf address in undo_shelf
      undo_shelf -> next_shelf = prev_shelf -> next_shelf;
      // set the correct address in prev_shelf
      prev_shelf -> next_shelf = undo_shelf;

      prev_state -> prev_action = NONE;
      break;

    case EDIT:
      // return an item to it's former glory
      prev_shelf =
	get_shelf(warehouse_list, prev_state -> old_index - 1);

      
      undo_shelf = prev_state -> old_shelf;
      undo_shelf -> next_shelf = prev_shelf -> next_shelf;

      // destroy "new" version
      free(prev_shelf -> next_shelf);
      prev_shelf -> next_shelf = prev_state -> old_shelf;

      prev_state -> prev_action = NONE;
      break;

    case NONE:
      // tell user there's nothing to undo
      break;
      
    default:
      // something went wrong
      break;
    }
}
