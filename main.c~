#include "menu.h"

void test ()
{
  warehouse *warehouse_list = new_warehouse();
  
  add_shelf(warehouse_list, "Karro", "cool tjej", 999, "a2", 1);
  add_shelf(warehouse_list, "Tim", "stark kille", 9999999, "a3", 1);
  add_shelf(warehouse_list, "katt", "svart", 300, "k1", 3);
  add_shelf(warehouse_list, "hund", "brun och lurvig", 500, "h1", 2);
  add_shelf(warehouse_list, "gurka", "grön", 15, "g2", 17);
  add_shelf(warehouse_list, "tomat", "röd och möglig", 7, "t2", 13);

  print_20(warehouse_list, NULL);

}

int main(void)
{
  test();
  puts("\nWelcome to our warehouse program!");
  main_menu();
  return 0;
}
