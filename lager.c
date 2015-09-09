#include "lager.h"

int main()
{

  // Allokerar utrymme för en ware_t.
  ware_t test =(ware_t) malloc (sizeof(ware_t));

  test->name = "Apple";
  
  
  ware_t apple =
    (ware_t)
    {
      .name = "Apple",
      .descrition = "Red, delicious.",
      .warehouse_location = "A12",
      .price = 120,
      .amount = 3
    };

  printf("Ware:\t%s\n", apple.name);
  printf("Description:\t%s\n", apple.description);
  printf("Warehouse location:\t%s\n", apple.warehouse_location);
  printf("Price:\t%d öre\n", apple.price);
  printf("Amount:\t%d\n", apple.amount);

  return 0;
}
