#include "menu.h"


void print_main_menu()
{
  puts("\n----- MAIN MENU ----------------------");
  puts("--------------------------------------\n");
  puts("1. Add an item");
  puts("2. Remove an item");
  puts("3. Edit an item");
  puts("4. Undo the last action");
  puts("5. List all items in the database");
  puts("6. Exit program");

}

void main_menu()
{

  warehouse *warehouse_list = new_warehouse();
  
  int cont = 1;
  
  while (cont)
    {
      print_main_menu();

      int answer;
      answer = ask_int_q("\nWhat would you like to do?");
    
      while (answer > 6 || answer < 1)
	{
	  answer = ask_int_q("That's not an option. Please try again with a number between 1-6.");  
	}
      
      switch (answer)
	{
	case 1:
	  add_shelf_IO(warehouse_list);
	  break;

	case 2:
	  remove_shelf_IO(warehouse_list);
	  break;

	case 3:
	  edit_shelf_IO(warehouse_list);
	  break;

	case 4:
	  puts("undo_action anropas");
	  break;

	case 5:
	  print_warehouse(warehouse_list);
	  break;

	case 6:
	  {
	    cont = exit_warehouse();
	  }
	  break;
	default: puts ("defaaaaauuuuuult");	    
	}
    }

  destroy_warehouse(warehouse_list);
}
