#include "backend.h"

int main(int argc, char *argv[])
{
  
  init_list_head(); //TODO: Try to get rid of this function.

  print_warehouse();

  add_item("t1", "A", 1, "A11", 11);
  add_item("t2", "B", 2, "B22", 22);
  add_item("t3", "C", 3, "C33", 33);
  add_item("t4", "D", 4, "D44", 44);
  add_item("t5", "E", 5, "E55", 55);
  
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);

  print_warehouse();
  
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  add_item("tt", "T", 0, "T00", 00);
  
  add_item("tt1", "T", 0, "T00", 00);
  add_item("tt2", "T", 0, "T00", 00);
  add_item("tt3", "T", 0, "T00", 00);
  add_item("tt4", "T", 0, "T00", 00);
  add_item("tt5", "T", 0, "T00", 00);

  //  remove_item("t3");
  //  remove_item("t5");
  //  remove_item("t1");

  print_warehouse();
  
  destroy_warehouse();

  //TODO: make sure that printing warehouse without a warehouse doesn't crash the program.
  // print_warehouse();
  
  return 0;
}
