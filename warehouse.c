#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "warehouse.h"

void strip (char* str)
{
  int len = strlen (str);
  for (int i = 0; i<len; ++i)
    {
      if (str[i] == '\n')
	{
	  str[i] = '\0';
	  return;
	}
    }
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
  char reply[256];
  fgets(reply, sizeof(reply), stdin);
  strip (reply);
  return strdup(reply); // anropa free någon gång i framtiden...
}


int ask_int_q (char *question)
{
  puts(question);
  int reply;
  scanf("%d", &reply);
  clear();
  return reply;
}


int ask_yn()
{
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

  
void add_item_aux(void)
{
  puts("---------------------------------");
  char* name;
  char* description;
  char* ware_loc; 
  int price; 
  int quantity;
  
  name = ask_str_q ("Name: ");
  description = ask_str_q ("Description: ");
  ware_loc = ask_str_q ("Warehouse location: ");
  price = ask_int_q ("Price:");
  quantity = ask_int_q ("Quantity:");

  puts("---------------------------------");
  printf("Ware: %s\n", ware);
  printf("Description: %s\n", description);
  printf("Storage Location: %s\n", ware_loc);
  printf("Price: %i\n", price);
  printf("Amount: %i\n", quantity);
  puts("Save this ware? y/n");

  if (ask_yn() == 1)
    {
      add_item(name, description, ware_loc, price, quantity);
      puts("Ware added");
     
	}
  else
    {
      puts("Ware NOT added");
      } 
  
}


void remove_ware(void)
{
  char* del_ware = ask_str_q("Which ware would you like to remove?");
  // leta upp varan
  printf("Remove %s?", del_ware);
    
}
void edit_ware(void)
{
  puts("hej hej");
}
void undo(void)
{
  puts("hej hej");
}
  
void list_all_wares(void)
{
  puts("hej hej");
}

int exit_warehouse()
{
  char ans;
  puts("Are you sure you would like to exit the warehouse? y/n");
  ans = ask_yn();

  if (ans == 1) 
    {
      return 0; //exit
    }
  else
    {
      return 1; //stay in program
    }
}

void main_menu()
{ 
  bool cont = true;
  
  while (cont)
    {
      puts("\n----- MAIN MENU ----------------------");
      puts("--------------------------------------");
      puts("What would you like to do?");
      puts("1. Add a ware");
      puts("2. Remove a ware");
      puts("3. Edit a ware");
      puts("4. Undo the last action");
      puts("5. List all wares in the database");
      puts("0. Exit program\n");

      int answer;
      scanf("%d", &answer);
      clear();
      switch (answer)
	{
	case 1:  add_item_aux(); break;
	case 2:  remove_ware(); break;
	case 3:  edit_ware(); break;
	case 4:  undo(); break;
	case 5:  list_all_wares(); break;
	case 0:
	  if (exit_warehouse() == 0)
	    {
	      cont = false;
	    }
	  else
	    {
	      cont = true;
	    }
	  break;
	default: puts ("defaaaaauuult");
	}
    }
  
}


int main(void)
{
  puts("\nWelcome to our warehouse program!");
  main_menu();
  return 0;
}
