#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct users
{
  char username[64];
  char password[64];
};

int main()
{
  int choice;
  // while (choice != 3)
  // {
  //   printf("\e[1;1H\e[2J");
  //   printf("-*-*-*-*- Laxmi Chit Fund -*-*-*-*-\n");
  //   printf("What do you wanna do? \n");
  //   printf("1.Employee Platform\n2.Customer Platform\n3.Exit Application");
  // }

  int choice_c;
  while (choice_c != 3)
  {
    printf("\e[1;1H\e[2J");
    printf("-*-*-*-*- Laxmi Chit Fund -*-*-*-*-\n");
    printf("What do you wanna do? \n");
    printf("1.Login\n2.Create an account\n3.Exit to main screen");

    printf("\nEnter your choice: ");

    scanf("%d", &choice_c);
    getchar(); // echo
    // getch(); // no echo

    switch (choice_c)
    {
    case 1:
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
        printf("*"); // enter is '\r'
        userLogin.password[i++] = ch;
        // i = i++;
      }
      userLogin.password[i] = '\0'; // string terminate with \0 so we remove it by ts
      FILE *log = fopen("user1.txt", "r");
      while (fscanf("%s %s", userLogin.username, userLogin.password) != EOF)
      {
      }
      // printf("\nYour user name is: %s", userLogin.username);
      // printf("\nYour password is: %s", userLogin.password);
      getch();
      break;

    case 2:
      struct users userSignIn;
      printf("Enter your username: ");
      scanf("%s", &userSignIn.username);
      // getch();

      i = 0;
      printf("Enter your password: ");
      while ((ch = getch()) != '\r')
      {
        printf("*");
        userSignIn.password[i++] = ch;
      }
      userSignIn.password[i] = '\0';

      FILE *new = fopen("user1.txt", "a"); // open  modes: "rb", "ab", "wb"
      fprintf(new, "%s %s\n", userSignIn.username, userSignIn.password);

      printf("\nYour user name is: %s \n", userSignIn.username);
      printf("Your password is: %s \n", userSignIn.password);

      fclose(new);
      printf("Your account has been created succesfully.");
      getch();
      break;

    case 3:
      break;

    default:
      break;
    }
  }
}