
#include "database.h" //behövs detta? JA!!! /Tim
#include "IO.h"

struct warehouse_header *warehouse_list =
  (struct warehouse_header*) malloc(sizeof(struct warehouse_header));

char* strip (char* str)
{
  int len = strlen (str);
  for (int i = 0; i<len; ++i)
    {
      if (str[i] == '\n')
	{
	  str[i] = '\0'; 
	}
    }
  return str;
}
void clear (void)
{
  bool newline_found; 
  do {
    newline_found = getchar() != '\n';
  } while (newline_found);
}


char* ask_str_q (char *question)
{
  puts(question);
  char *reply;
  fgets(reply, sizeof(reply), stdin);
  
  reply = strip (reply);
  return strdup(reply); // anropa free någon gång i framtiden...
}


int ask_int_q (char *question)
{
  puts(question);
  char reply[256];
  int ok_ans;
  fgets(reply, sizeof(reply), stdin);
  *reply = *strip (reply);
  
  for (int i=0; i<strlen(reply); ++i)
    { 
      ok_ans = isdigit(reply[i]);
      if (ok_ans == 0)
	{
	  puts("Please answer the question with digits and not letters");
	  fgets(reply, sizeof(reply), stdin);
	  *reply = *strip (reply);
	  i = 0;
	}
    }			   
  ok_ans = atoi(reply);
  return ok_ans;
}


int ask_yn(char* question)
{
  puts(question);
  char ans;
  ans = getchar();
  clear();
 
  while ((ans !='y') && (ans !='n'))
    {
      puts ("Please answer 'y' or 'n'");
      ans = getchar();
      clear();
    }
  if (ans == 'y')
    {
      return 1;}
  else
    {
      return 0;}
}

<<<<<<< Updated upstream
=======
/* ------------------------------------------------------------------------
------------------------------------------------------------------------ 
------------------------------------------------------------------------  */

void print_shelf(shelf* shelf)
{
  item* item = shelf -> item;
  
  printf("Ware: %s\n", item -> name);
  printf("Description: %s\n", item -> description);
  printf("Price: %i\n", item -> price);
  printf("Storage Location (shelf): %s\n", shelf -> shelf_num);
  printf("Number of items: %i\n", shelf -> num_items);
}

/*
>>>>>>> Stashed changes
void print_add_item(char* name, char* description, int price, char* ware_loc, int quantity)
{
  printf("Ware: %s\n", name);
  printf("Description: %s\n", description);
  printf("Price: %i\n", price);
  printf("Warehouse Location: %s\n", ware_loc);
  printf("Amount: %i\n", quantity);
  } */

void add_item_IO(void)
{
  puts("---------------------------------");
  char* name;
  char* description;
  int price;
  char* ware_loc; 
  int quantity;
  
  name = ask_str_q ("Name: ");
  description = ask_str_q ("Description: ");
  price = ask_int_q ("Price:");
  ware_loc = ask_str_q ("Warehouse location: ");
  quantity = ask_int_q ("Quantity:");

  puts("---------------------------------");

  //print_add_item (name, description, price, ware_loc, quantity);

  if (ask_yn("\nSave this ware? y/n") == 1)
    {
      //add_item(name, description, price, ware_loc, quantity);
      printf("%s added to the warehouse!\n", name);
     
    }
  else
    {
      puts("Item NOT added");
      } 
  
}


  
void remove_item_IO(void) //den här funktionen är sjukt oklar
{
  if (ask_yn("Remove this ware? y/n") == 1)
    {
      puts("Item removed!");
      //remove_item (del_item);
    }
  else
    {
      puts("Item is still in warehouse");
    }    
}

void edit_item_IO()
{
  int cont = 1;

  char* name;
  char* description;
  int price;
  char* shelf_num;
  int num_items;
  
  while (cont == 1)
    {
      print_item_numbers(item);
      int edit;
      edit =  ask_int_q("What would you like to edit?");
  
      while (edit < 1 || edit > 5)
	{edit = ask_int_q("That's not an option. Please try again with a number between 1-5");
	}
      switch (edit)
	{
	case 1: {name = {ask_str_q("Name: ");} break;
	  case 2: {description = ask_str_q("Description: ");} break;
	  case 3: {price = ask_int_q("Price");} break;
	  case 4: {shelf_num = ask_str_q("Warehouse Location: ");} break;
	  case 5: {num_items = ask_int_q("Quantity: ");} break;
	  default: puts("defaaaauultttt");
	}
	  cont = ask_yn("Continue edit this item? y/n ");
	}
      puts("Item successfully updated");
      // ask_yn("Edit another item? y/n ");
    }
}





  
void undo(void)
{
  puts("hej hej");
}





 

int exit_warehouse()
{
  char ans;
  ans = ask_yn("Are you sure you would like to exit the warehouse? y/n");

  if (ans == 1) 
    {
      return 0; //exit
    }
  else
    {
      return 1; //stay in program
    }
}


// ----- TIM -----

void print_shelf(shelf *shelf)
{
  item = shelf -> item;
  
  printf("\n");
  printf("Name\t\t%s\n", item -> name);
  printf("Description\t%s\n", item -> description);
  printf("Price\t\t%d\n", item -> prics);
  printf("Shelf number\t%s\n", shelf -> shelf_num);
  printf("Number of items\t%d\n", shelf -> num_items);
}

void print_name(shelf *shelf)
{
  item = shelf -> item;
  printf("Name\t%s", item -> name);
}

shelf * print_20(warehouse *warehouse_list, shelf *shelf_start)
{
  void* shelf;
  
  //If we are to start from the begining of the warehouse
  if(shelf_start == NULL)
    {
      start == warehouse_list -> first_shelf;
    }
  else
    {
      shelf = shelf_start;
    }
  
  for(int i = 0; i < 20; ++i)
    {
      printf("%d ", i);
      print_name(shelf);
      printf("\n");

      shelf = shelf -> next_shelf;
    }

  return shelf;
}
