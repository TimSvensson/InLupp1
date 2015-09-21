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
	case 1:  add_item_IO(); break;
	case 2:  remove_item_IO(); break;
	case 3:  edit_item_IO (); break;
	case 4:  puts("undo_action anropas"); break;
	case 5:  puts("här ska varor listas"); break;
	case 0:
	  if (exit_warehouse() == 0)
	    {
	      cont = false;
	    }
	  /*  else
	    {
	      cont = true;
	      } */
	  break;
	default: puts ("defaaaaauuuuuult");	    
	}
    } 
}
