#include "database.h"
#include "IO.h"

void print_shelf(shelf *shelf);

void print_name(shelf *shelf);

shelf * print_20(warehouse *warehouse_list, shelf *shelf_start);

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
  
  *reply = *strip (reply);
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

/* <<<<<<< Updated upstream
======= */
/* ------------------------------------------------------------------------
------------------------------------------------------------------------ 
------------------------------------------------------------------------  */


/*
>>>>>>> Stashed changes */

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


  
void remove_shelf_IO(void) //den här funktionen är sjukt oklar
{
  if (ask_yn("Remove this item? y/n") == 1)
    {
      puts("Item removed!");
      //remove_item (del_item);
    }
  else
    {
      puts("Item is still in warehouse");
    }    
}



void edit_shelf_IO_aux(warehouse* warehouse_list, shelf* choosed_shelf) 
{  int cont = 1;
  char* name;
  char* description;
  int price;
  char* shelf_num;
  int num_items;
  {while (cont == 1)
      {
	print_shelf(choosed_shelf);
	int edit;
	edit =  ask_int_q("What would you like to edit?");
  
	while (edit < 1 || edit > 5)
	  {edit = ask_int_q("That's not an option. Please try again with a number between 1-5");
	  }
	switch (edit)
	  {
	  case 1: {name = ask_str_q("Name: ");} break;
	  case 2: {description = ask_str_q("Description: ");} break;
	  case 3: {price = ask_int_q("Price");} break;
	  case 4: {shelf_num = ask_str_q("Warehouse Location: ");} break;
	  case 5: {num_items = ask_int_q("Quantity: ");} break;
	  default: puts("defaaaauultttt");
	  }
	cont = ask_yn("Continue edit this item? y/n ");
      }
    edit_shelf (warehouse_list, choosed_shelf, name, description, price, shelf_num, num_items);
    puts("Item successfully updated");
  }
}




void edit_shelf_IO(warehouse* warehouse_list, shelf* shelf)
{
  int continue_edit = 1;
  while (continue_edit)
    {
      shelf = NULL;
      int answer;
      int cont = 1;
      // shelf* next_shelfs;
      int index;
      int page = 0;
      //   shelf* choosed_shelf;
      shelf = print_20(warehouse_list, shelf);
  
      while (cont)
	{
	  answer = ask_int_q ("Which item would you like to edit? Answer with a number between 1-20. If you would like to see the next 20 items, answer '21' ");
  
	  while (answer < 1 || 21 < answer)
	    {answer = ask_int_q("That's not an option. Please try again with a number between 1-21");
	    }    

	  if (answer == 21)
	    {
	      page = page +1;
	      shelf = print_20(warehouse_list, shelf);
	    }
	  else
	    {
	      index = page * 20 + answer - 1;
	      cont = 0;
	      shelf = get_shelf (warehouse_list, index); 
	    }
	  edit_shelf_IO_aux(warehouse_list, shelf);
	  continue_edit = ask_yn("Edit another item? y/n");
	}  
    }
}
 



  
void undo(void)
{
  puts("hej hej");
  //undo_action(warehouse_list);
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
  printf("\n");
  printf("Name\t\t%s\n", get_name(shelf));
  printf("Description\t%s\n", get_description(shelf));
  printf("Price\t\t%d\n", get_price(shelf));
  printf("Shelf number\t%s\n", get_shelf_num(shelf));
  printf("Number of items\t%d\n", get_num_items(shelf));
}

void print_name(struct shelf *shelf)
{
  printf("Name\t%s", get_name(shelf));
}

shelf * print_20(struct warehouse *warehouse_list, struct shelf *shelf_start)
{
  shelf* shelf = NULL;
  
  //If we are to start from the begining of the warehouse
  if(shelf_start == NULL)
    {
      shelf = get_first(warehouse_list);
    }
  else
    {
      shelf = shelf_start;
    }
  
  for(int i = 0; i < 20; ++i)
    {
      printf("%d ", i+1);
      print_name(shelf);
      printf("\n");

      shelf = get_next_shelf(shelf);
    }

  return shelf;
}
