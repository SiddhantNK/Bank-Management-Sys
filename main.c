// hello
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

struct users
{
  char username[100];
  char password[100];
};
 char time_buffer[80];


int account_info(char username[])
{
  int act = 0, enter = 0;
  char ch;
  printf("\e[1;1H\e[2J");
  printf("Welcome, %s!\n", username);
  printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
  printf("  1.See account information\n  2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      act = 1;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s\n!", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("=>1.See account information\n  2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '2':
      act = 2;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n=>2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '3':
      act = 3;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n=>3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '4':
      act = 4;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Change password\n=>4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '5':
      act = 5;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Change password\n  4.Change email\n=>5.Back to Login/Sign Up");
      break;
    case '\r':
      if (act == 1)
      {
        printf("\e[1;1H\e[2J");
        printf("In progress...\n Press any key to return");
        getch();
        act = 1;
        printf("\e[1;1H\e[2J");
        printf("Welcome, %s\n", username);
        printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
        printf("=>1.See account information\n  2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      }
      else if (act == 2)
      {
        printf("\e[1;1H\e[2J");
        printf("In progress...\n Press any key to return");
        getch();
        printf("\e[1;1H\e[2J");
        printf("Welcome, %s\n", username);
        printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
        printf("  1.See account information\n=>2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      }
      else if (act == 3)
      {
        printf("\e[1;1H\e[2J");
        printf("In progress...\n Press any key to return");
        getch();
        printf("\e[1;1H\e[2J");
        printf("Welcome, %s\n", username);
        printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
        printf("  1.See account information\n  2.Transfer money\n=>3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      }
      else if (act == 4)
      {
        printf("\e[1;1H\e[2J");
        printf("In progress...\n Press any key to return");
        getch();
        printf("\e[1;1H\e[2J");
        printf("Welcome, %s\n", username);
        printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
        printf("  1.See account information\n  2.Transfer money\n  3.Change password\n=>4.Change email\n  5.Back to Login/Sign Up");
      }
      else
      {
        enter = 1;
      }
      break;
    default:
      break;
    }
  }
  // getch();
}

int login()
{
  printf("\e[1;1H\e[2J");
  struct users userLogin;

  // fgets(userLogin.username, sizeof(userLogin.username), stdin);

  printf("Enter your username: ");
  scanf("%s", userLogin.username);

  // getch();

  int i = 0;
  char ch;
  printf("Enter your password: ");
  while ((ch = getch()) != '\r')
  {
    if (ch == 8)
    {
      if (i > 0)
      {
        printf("\b \b");
        userLogin.password[i--] = '\0';
      }
    }
    else
    {
      printf("*"); // enter is '\r'
      userLogin.password[i++] = ch;
    }
  }
  userLogin.password[i] = '\0'; // string terminate with \0 so we remove it by ts

  printf("\nYour user name is: %s", userLogin.username);
  printf("\nYour password is: %s", userLogin.password);
  account_info(userLogin.username);
  return 0;
}

int signup()
{
  struct users userSignIn;
  printf("\e[1;1H\e[2J");
  printf("Enter your username: ");
  scanf("%s", userSignIn.username);
  // getch();

  int i = 0;
  char en;
  printf("Enter your password: ");
  while ((en = getch()) != '\r')
  {
    if (en == 8)
    {
      if (i > 0)
      {
        printf("\b \b");
        userSignIn.password[i--] = '\0';
      }
    }
    else
    {
      printf("*"); // enter is '\r'
      userSignIn.password[i++] = en;
    }
  }
  userSignIn.password[i] = '\0';
 

  FILE *new = fopen("user1.txt", "a"); // open  modes: "rb", "ab", "wb"
  fprintf(new, "%s %s\n", userSignIn.username, userSignIn.password);
  

  printf("\nYour user name is: %s \n", userSignIn.username); 
  printf("Your password is: %s \n", userSignIn.password);

  fclose(new);
  printf("Your account has been created succesfully.");
  getch();
  account_info(userSignIn.username);
  return 0;
}

int user_menu()
{
  int enter, menu = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("Press number keys to select between options and then press Enter\n");
  printf("\n 1.Login\n 2.Create an account\n 3.Exit to main screen");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      menu = 1;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n>1.Login\n 2.Create an account\n 3.Exit to main screen");
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n 1.Login\n>2.Create an account\n 3.Exit to main screen");
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n 1.Login\n 2.Create an account\n>3.Exit to main screen");
      break;
    case '\r':
      if (menu == 1)
      {
        login();
        menu = 1;
        printf("\e[1;1H\e[2J");
        printf("Press number keys to select between options and then press Enter\n");
        printf("\n>1.Login\n 2.Create an account\n 3.Exit to main screen");
      }
      else if (menu == 2)
      {
        signup();
        menu = 2;
        printf("\e[1;1H\e[2J");
        printf("Press number keys to select between options and then press Enter\n");
        printf("\n 1.Login\n>2.Create an account\n 3.Exit to main screen");
      }
      else
      {
        enter = 1;
      }
      break;
    default:
      break;
    }
  }
}

int main()
{
  int choice = 0, enter = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
  printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
  printf("  1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      choice = 1;
      printf("\e[1;1H\e[2J");
      printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("=>1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");
      break;
    case '2':
      choice = 2;
      printf("\e[1;1H\e[2J");
      printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n=>2.Customer Platform\n  3.Exit Application");
      break;
    case '3':
      choice = 3;
      printf("\e[1;1H\e[2J");
      printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n  2.Customer Platform\n=>3.Exit Application");
      break;
    case '\r':
      if (choice == 1)
      {
        choice = 1;
        printf("\e[1;1H\e[2J");
        printf("In Progress...Please come back later\nPress any key to return");
        getch();
        printf("\e[1;1H\e[2J");
        printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
        printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
        printf("=>1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");
      }
      else if (choice == 2)
      {
        user_menu();
        choice = 2;
        printf("\e[1;1H\e[2J");
        printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
        printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
        printf("  1.Employee Platform \n=>2.Customer Platform\n  3.Exit Application");
      }
      else
      {
        enter = 1;
      }

    default:
      break;
    }
  }
}