#include "database.h"
#include "IO.h"

void print_shelf(shelf *shelf);
void print_name(shelf *shelf);
void print_description(shelf *shelf);	    
void print_price(shelf *shelf);	  
void print_shelf_num(shelf *shelf);	   
void print_num_items (shelf *shelf);
void print_box_shelf(char *name, char *description, int price, char *shelf_num, int num_items);
void print_box_shelf_num(char *name, char *description, int price, char *shelf_num, int num_items);
shelf * print_20(warehouse *warehouse_list, shelf *shelf_start);

void edit_shelf_IO_aux(warehouse* warehouse_list, shelf* choosed_shelf);


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
  return strdup(str);
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
  printf("%s\n> ", question);
  char reply[256];
  fgets(reply, sizeof(reply), stdin);
  char* answer = reply;
  answer = strip (reply);
  return answer; // anropa free någon gång i framtiden...
}


int ask_int_q (char *question)
{
  printf("%s\n> ", question);
  char reply[128];
  int ok_ans;
  char* answer;
  fgets(reply, sizeof(reply), stdin);
  answer = strip (reply);
  bool cont = true;
  
  while(cont)
    {
      while (atoi(answer) == 0)
	{
	  if (strcmp(answer, "0"))
	    {
	      cont = false;
	    }
	  else
	    {
	      char* message = "Please answer the question with digits and not letters";
	      printf("%s\n> ", message);
	      fgets(reply, sizeof(reply), stdin);
	      answer = strip (reply);
	    }
	}

  /*  printf("reply: %s \tanswer: %s", reply, answer);

      for (int i=0; i<strlen(answer); ++i)
      {   
      ok_ans = isdigit(answer[i]);
      
      if (ok_ans == 0)
	{
	  char* message = "Please answer the question with digits and not letters";
	  printf("%s\n> ", message);
	  fgets(reply, sizeof(reply), stdin);
	  answer = strip (reply);
	  printf("loop reply: %s \tloop answer: %s\n", reply, answer);
	  i=0;
	  //ok_ans = isdigit(answer[i]);
	  printf("ok_ans är %d\n", ok_ans);
	 
	}
      printf("still in loop");

   
      puts("out of loop"); */
    }
  ok_ans = atoi(answer);
  return ok_ans;
}


int ask_yn(char* question)
{
  printf("%s\n> ", question);
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


char ask_3alt(char* question, char alt1, char alt2, char alt3)
{
  printf("%s\n> ", question);
  char ans;
  ans = getchar();
  clear();
 
  while ((ans != alt1) && (ans != alt2) && (ans !=alt3))
    {
      printf("Please answer '%c' or '%c' or '%c'\n> ", alt1, alt2, alt3);
      ans = getchar();
      clear();
    }
  return ans;
}


void print_add_shelf(char *name, char *description, int price, char *shelf_num, int num_items)
{
  printf("\n\n");
  printf("    Your new item\n");
  print_box_shelf(name, description, price, shelf_num, num_items);
}

void add_shelf_IO(warehouse *warehouse_list)
{
  puts("\n-----ADD AN ITEM--------------------");
  shelf* shelf;
  char* name;
  char* description;
  int price;
  char* shelf_num; 
  int num_items;
  
  name = ask_str_q("Name");
  description = ask_str_q("Description");
  price = ask_int_q("Price (kr)");
  shelf_num = ask_str_q("Shelf number ");
  num_items = ask_int_q("Number of items ");

  puts("---------------------------------");

  print_add_shelf(name, description, price, shelf_num, num_items);
  char ans = ask_3alt("[s]ave this item / [d]on't save / [e]dit", 's', 'd', 'e');
  if  (ans == 's')
    {
      add_shelf(warehouse_list, name, description, price, shelf_num, num_items);
      printf("\n%s added to the warehouse!\n", name);
    }
  else if (ans == 'd')
    {
      puts("Item NOT added");
    }
  else
    {
      add_shelf(warehouse_list, name, description, price, shelf_num, num_items);
      edit_shelf_IO_aux(warehouse_list, get_last_shelf(warehouse_list));
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
  
  char* name = get_name(choosed_shelf);
  char* description = get_description(choosed_shelf);
  int price = get_price(choosed_shelf);
  char* shelf_num = get_shelf_num(choosed_shelf);
  int num_items = get_num_items(choosed_shelf);
 
  
  {while (cont)
      {
	puts("\n-----EDIT ITEM-------------");
	print_box_shelf_num(name, description, price, shelf_num, num_items);
	int edit;
	edit =  ask_int_q("What would you like to edit?");
  
	while (edit < 1 || edit > 5)
	  {edit = ask_int_q("That's not an option. Please try again with a number between 1-5");
	  }
	switch (edit)
	  {
	  case 1: {
	    print_name(choosed_shelf);
	    name = ask_str_q("\nNew name: ");} break;
	  case 2: {
	    print_description(choosed_shelf);
	    description = ask_str_q("\nNew description: ");} break;
	  case 3: {
	    print_price(choosed_shelf);
	    price = ask_int_q("\nNew price");} break;
	  case 4: {
	    print_shelf_num(choosed_shelf);
	    shelf_num = ask_str_q("\nNew shelf number: ");} break;
	  case 5: {
	    print_num_items(choosed_shelf);
	    num_items = ask_int_q("\nNew num_items: ");} break;
	  default: puts("defaaaauultttt");
	  }
	cont = ask_yn("Continue edit this item? y/n ");
        edit_shelf(choosed_shelf, name, description, price, shelf_num, num_items);
      }
   
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
      printf("\n----- EDIT AN ITEM -----------" );
      printf("\nItems in warehouse:\n");
      shelf = print_20(warehouse_list, shelf);
      puts("------------------------------");
      while (cont)
	{
	  answer = ask_int_q("\nWhat would you like to do? \n1. Choose an item to edit\n2. See next 20 items\n0. Exit and go back to main menu");

	  while (answer < 0 || 2 < answer)
	    {
	      answer = ask_int_q("That's not an option. Please try again with a number between 0-2"); 
	    }
	
	  if (answer == 1)
	    {
	      answer = ask_int_q ("Which item would you like to edit? Answer with a number between 1-20. Press 0 to exit.");
	 
	      while (answer < 1 || 20 < answer)
		{
		  answer = ask_int_q("That's not an option. Please try again with a number between 1-20");
		}
	      index = page * 20 + answer - 1;
	      cont = 0;
	      shelf = get_shelf (warehouse_list, index);
	      edit_shelf_IO_aux(warehouse_list, shelf);
	      continue_edit = ask_yn("Edit another item? y/n");
	  
	    }

	  else if (answer == 2)
	    {
	      page = page +1;
	      shelf = print_20(warehouse_list, shelf);
	    }

	  else
	    {
	      puts("EXIIIIT");
	      cont = 0;
	      continue_edit = 0;
	    }
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
  printf("1. Name\t\t%s\n", get_name(shelf));
  printf("2. Description\t%s\n", get_description(shelf));
  printf("3. Price\t\t%d kr\n", get_price(shelf));
  printf("4. Shelf number\t%s\n", get_shelf_num(shelf));
  printf("5. Number of items\t%d\n", get_num_items(shelf));
}

void print_name(shelf *shelf)
{
  printf("Name:\t\t%s", get_name(shelf));
}

void print_description(shelf *shelf)
{
  printf("Description:\t%s", get_description(shelf));
}
	    
void print_price(shelf *shelf)
{
  printf("Price:\t\t%d kr", get_price(shelf));
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
      printf("%d. ", i+1);
      printf("%s", get_name(shelf));
      printf("\n");
      if (shelf == get_last_shelf(warehouse_list) )
	{ 
	  return shelf;
	}
      shelf = get_next_shelf(shelf);
    }
  return shelf;
}

void print_box_shelf(char *name, char *description, int price, char *shelf_num, int num_items)
{
  printf("=====\t\t=====\n");
  printf(" Name\t\t%s\n", name);
  printf(" Description\t%s\n", description);
  printf(" Price\t\t%d\n", price);
  printf(" Shelf number\t%s\n", shelf_num);
  printf(" Number of items\t%d\n", num_items);
  printf("=====\t\t=====\n\n");
}

void print_box_shelf_num(char *name, char *description, int price, char *shelf_num, int num_items)
{
  printf("=====\t\t=====\n");
  printf("1. Name\t\t%s\n", name);
  printf("2. Description\t%s\n", description);
  printf("3. Price\t\t%d\n", price);
  printf("4. Shelf number\t%s\n", shelf_num);
  printf("5. Number of items\t%d\n", num_items);
  printf("=====\t\t=====\n\n");
}
