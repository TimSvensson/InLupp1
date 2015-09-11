#include <stdio.h>
#include <stdbool.h>
#include <string.h>


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

typedef struct vara
{
  char* name;
  char* descr;
  char* sto;
  int pri;
  int amo;
} vara_t;

int ask_int_q (char *question)
{
  puts(question);
  int reply;
  scanf("%d", &reply);
  clear();
  return reply;
}

//denna funkar ej
void ask_yn(){
  char ans;
  ans = getchar();
  switch (ans)
    {
    case 'y': puts("Ware added!"); break;
    case 'n': puts("Ware not added"); break;
    default:
      puts ("Please answer 'y' or 'n'");
	ask_yn()
   
      ; break;
    }}


/*
void add_test(vara_t* newware)
  .name = "hej"
  .descr = "jknfgoingn"
  .sto = "A23"
  .pri = 124324
  .amo = 33333 */
  
  
void add_ware(void)
{
  puts("---------------------------------");
  char* ware;
  char* description;
  char* sto_loc; 
  int price; 
  int amount;
  
  ware = ask_str_q ("Ware: ");
  description = ask_str_q ("Description: ");
  sto_loc = ask_str_q ("Storage location: ");
  price = ask_int_q ("Price:");
  amount = ask_int_q ("Amount:");

  /* update ware
  vara_t newware =
    (vara_t)
    {
      newware.name = ware;
      newware.descr = description;
      newware.sto = sto_loc;
      newware.pri = price;
      newware.amo = amount;
    } */
  
  puts("---------------------------------");
  printf("Ware: %s\n", ware);
  printf("Description: %s\n", description);
  printf("Storage Location: %s\n", sto_loc);
  printf("Price: %i\n", price);
  printf("Amount: %i\n", amount);
  puts("Save this ware? y/n");

  ask_yn();

  
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

void question_main_menu()
{
  int answer;
  scanf("%d", &answer);
  clear();
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
  
