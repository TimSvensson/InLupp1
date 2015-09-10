#include <stdio.h>

void clear (void)
{    
  while ( getchar() != '\n' );
}


char ask_str_q (char *question)
{
  clear();
  puts(question);
  char reply;
  fgets(&reply, sizeof(reply), stdin);
  return reply;
}

int ask_int_q (char *question)
{
  clear();
  puts(question);
  int reply;
  scanf("%d", &reply);
  return reply;
}

void add_ware(void)
{
  char *ware;
  char *description;
  char *sto_loc;
  int price;
  int amount;

  puts("---------------------------------");
  //ware = ask_str_q ("Ware: ");
  //description =  ask_str_q ("Description: ");
  //sto_loc =  ask_str_q ("Storage location: ");

  price =  ask_int_q ("Price:");
  amount =  ask_int_q ("Amount:");

  puts("---------------------------------");
  printf("Ware: %s\n", ware);
  printf("Description: %s\n", description);
  printf("Storage Location: %s\n", sto_loc);
  printf("Price: %i\n", price);
  printf("Amount: %i\n", amount);

}


void remove_ware(void)
{
  puts("hej hej");
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

void question_main_menu()
{
  int answer;
  scanf("%d", &answer);
  switch (answer)
    {
    case 1:  add_ware(); break;
    case 2:  remove_ware(); break;
    case 3:  edit_ware(); break;
    case 4:  undo(); break;
    case 5:  list_all_wares(); break;
    case 0:  break;
    default: puts ("defaaaaauuult");
    }
}
void main_menu()
{
  puts("What would you like to do?");
  puts("1. Add a ware");
  puts("2. Remove a ware");
  puts("3. Edit a ware");
  puts("4. Undo the last action");
  puts("5. List all wares in the database");
  puts("0. Exit program\n");
}


int main(void)
{
  puts("\nWelcome to our warehouse program!");
  puts("---------------------------------");
  main_menu();
  question_main_menu();
  return 0;
  
}
  
