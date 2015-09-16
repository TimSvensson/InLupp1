#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "backend.h"


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
  char reply[256];
  char* stripped_reply;
  fgets(reply, sizeof(reply), stdin);
  
  printf("Reply = %s", reply);
  stripped_reply = strip (reply);
  printf("Stripped = %s \n", stripped_reply);
  return strdup(stripped_reply); // anropa free någon gång i framtiden...
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

void print_add_item(char* name, char* description, int price, char* ware_loc, int quantity)
{
  printf("Ware: %s\n", name);
  printf("Description: %s\n", description);
  printf("Price: %i\n", price);
  printf("Storage Location: %s\n", ware_loc);
  printf("Amount: %i\n", quantity);
}

void add_item_aux(void)
{
  puts("---------------------------------");
  char* name;
  char* description;
  int price;
  char* ware_loc; 
  int quantity;
  
  name = ask_str_q ("Name/Ware: ");
  description = ask_str_q ("Description: ");
  price = ask_int_q ("Price:");
  ware_loc = ask_str_q ("Warehouse location: ");
  quantity = ask_int_q ("Quantity:");

  puts("---------------------------------");

  print_add_item (name, description, price, ware_loc, quantity);

  if (ask_yn("\nSave this ware? y/n") == 1)
    {
      //add_item(name, description, price, ware_loc, quantity);
      puts("Item added!");
     
    }
  else
    {
      puts("Item NOT added");
      } 
  
}


  
void remove_item_aux(void)
{
  int del_item = ask_int_q("Which ware would you like to remove?");
  
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

void edit_item_aux(warehouse_t* item)
{
  
  print_item_numbers(item);
  int edit;
  edit =  ask_int_q("Which item would you like to edit?");
  
  while (edit < 1 || edit > 5)
    {edit = ask_int_q("That's not an option. Please try again with a number between 1-5");
    }
  switch (edit)
    {
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    default: puts("defaaaauultttt");
    }
  
}
void undo(void)
{
  puts("hej hej");
}
  
void list_all_items(void)
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

void print_main_menu()
{
  puts("\n----- MAIN MENU ----------------------");
  puts("--------------------------------------");
  puts("What would you like to do?");
  puts("1. Add a ware");
  puts("2. Remove a ware");
  puts("3. Edit a ware");
  puts("4. Undo the last action");
  puts("5. List all wares in the database");
  puts("0. Exit program");

}

void main_menu()
{ 
  bool cont = true;
  
  while (cont)
    {
      print_main_menu();
      int answer;
      answer = ask_int_q("");
      while (answer > 5 || answer < 0)
	{
	  answer = ask_int_q("That's not an option. Please try again with a number between 0-5.");
	}
      switch (answer)
	{
	case 1:  add_item_aux(); break;
	case 2:  remove_item_aux(); break;
	case 3:  puts("edit_item anropas")/*edit_item ()*/; break;
	case 4:  puts("undo_action anropas") /*undo_action()*/; break;
	case 5:  puts("print_warehouse anropas")/* print_warehouse()*/; break;
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
	default: puts ("defaaaaauuuuuult");	    
	}
    } 
}


int main(void)
{
  puts("\nWelcome to our warehouse program!");
  main_menu();
  return 0;
}
