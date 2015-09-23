#include "database.h"
#include "IO.h"

void print_shelf(shelf *shelf);

void print_name(shelf *shelf);
void print_description(shelf *shelf);	    
void print_price(shelf *shelf);	  
void print_shelf_num(shelf *shelf);	   
void print_num_items (shelf *shelf);

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



void print_add_shelf(char *name, char *description, int price, char *ware_loc, int num_items)
{
  printf("\n\n");
  printf("=====\t\t=====");
  printf("\tYour new Item\n");
  printf(" Name\t\t%s\n", name);
  printf(" Description\t%s\n", description);
  printf(" Price\t\t%d\n", price);
  printf(" Shelf number\t%s\n", ware_loc);
  printf(" Number of items\t%d\n", num_items);
  printf("\n");
  printf("=====\t\t=====\n\n");
}

void add_shelf_IO(warehouse *warehouse_list)
{
  puts("---------------------------------");
  
  char* name;
  char* description;
  int price;
  char* ware_loc; 
  int num_items;

  name = ask_str_q("Name\n> ");
  description = ask_str_q("Description\n> ");
  price = ask_int_q("Price\n> ");
  ware_loc = ask_str_q("Warehouse location\n> ");
  num_items = ask_int_q("Num_Items\n> ");

  puts("---------------------------------");

  print_add_shelf(name, description, price, ware_loc, num_items);

  if (ask_yn("\nSave this ware? y/n") == 1)
    {
      add_shelf(warehouse_list, name, description, price, ware_loc, num_items);
      printf("%s added to the warehouse!\n", name);
     
    }
  else
    {
      puts("Item NOT added");
    }
  
}


  
void remove_shelf_IO(warehouse *warehouse_list)
{
  // find shelf to be removed
  // remove item
}



void edit_shelf_IO_aux(warehouse* warehouse_list, shelf* choosed_shelf) 
{
  int cont = 1;
  
  char* name;
  char* description;
  int price;
  char* shelf_num;
  int num_items;

  {while (cont)
      {
	print_shelf(choosed_shelf);
	int edit;
	edit =  ask_int_q("What would you like to edit?");
  
	while (edit < 1 || edit > 5)
	  {edit = ask_int_q("That's not an option. Please try again with a number between 1-5");
	  }
	switch (edit)
	  {
	  case 1: {
	    print_name(choosed_shelf);
	    name = ask_str_q("New name: ");} break;
	  case 2: {
	    print_description(choosed_shelf);
	    description = ask_str_q("New description: ");} break;
	  case 3: {
	    print_price(choosed_shelf);
	    price = ask_int_q("New price");} break;
	  case 4: {
	    print_shelf_num(choosed_shelf);
	    shelf_num = ask_str_q("New shelf number: ");} break;
	  case 5: {
	    print_num_items(choosed_shelf);
	    num_items = ask_int_q("New num_items: ");} break;
	  default: puts("defaaaauultttt");
	  }
	cont = ask_yn("Continue edit this item? y/n ");
      }
    edit_shelf (choosed_shelf, name, description, price, shelf_num, num_items);
    puts("Item successfully updated");
  }
}




void edit_shelf_IO(warehouse* warehouse_list)
{
  int continue_edit = 1;
  while (continue_edit)
    {
      shelf *shelf = NULL;
      int answer;
      int cont = 1;
      int index;
      int page = 0;
      shelf = print_20(warehouse_list, shelf);
  
      while (cont)
	{
	  answer = ask_int_q("What would you like to do? \n1. Choose an item to edit\n 2. See next 20 items\n3. Exit and go back to main menu");
	  while (answer < 1 || 3 < answer)
	    {
	      answer = ask_int_q("That's not an option. Please try again with a number between 1-3"); }
	}
      if (answer == 1)
	{
	  ask_int_q ("Which item would you like to edit? Answer with a number between 1-20.");

	  while (answer < 1 || 20 < answer)
	    {
	      answer = ask_int_q("That's not an option. Please try again with a number between 1-20"); }

	  {
	    index = page * 20 + answer - 1;
	    cont = 0;
	    shelf = get_shelf (warehouse_list, index);
	    edit_shelf_IO_aux(warehouse_list, shelf);
	    continue_edit = ask_yn("Edit another item? y/n");
	  }
	}
      else if (answer == 2)
	{
	  page = page +1;
	  shelf = print_20(warehouse_list, shelf);
	}
      else
	    {
	      break;
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


// PRINT FUNCTIONS -----------------------------------

void print_shelf(shelf *shelf)
{ 
  printf("\n");
  printf("Name\t\t%s\n", get_name(shelf));
  printf("Description\t%s\n", get_description(shelf));
  printf("Price\t\t%d\n", get_price(shelf));
  printf("Shelf number\t%s\n", get_shelf_num(shelf));
  printf("Number of items\t%d\n", get_num_items(shelf));
}

void print_name(shelf *shelf)
{
  printf("Name\t\t%s", get_name(shelf));
}

void print_description(shelf *shelf)
{
  printf("Description:\t%s", get_description(shelf));
}
	    
void print_price(shelf *shelf)
{
  printf("Price:\t\t%d", get_price(shelf));
}
	  
void print_shelf_num(shelf *shelf)
{
  printf("Shelf number:\t%s", get_shelf_num(shelf));
}
	   
void print_num_items(shelf *shelf)
{
  printf("Number of items:\t%d", get_num_items(shelf));
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
