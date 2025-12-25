#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct users
{
  char username[100];
  char password[100];
  char time_buffer[80];
  char email[100];
};

int in_prog()
{
  printf("\e[1;1H\e[2J");
  printf("In progress...\n Press any key to return");
  getch();
}

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
        in_prog();
      }
      else if (act == 2)
      {
        in_prog();
      }
      else if (act == 3)
      {
        in_prog();
      }
      else if (act == 4)
      {
        in_prog();
      }
      else
      {
        enter = 1;
      }

    default:
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Change password\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    }
  }
  return 0;
}

int login()
{
  int ver = 0;
  while (ver != 1)
  {
    printf("\e[1;1H\e[2J");
    struct users userLogin;

    printf("Enter your username: ");
    scanf("%s", userLogin.username);

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

    FILE *fp = fopen("users.txt", "r");

    char ent_user[64], ent_pass[64], ent_email[64];
    while (fscanf(fp, "%s %s %s", ent_user, ent_pass, ent_email) != EOF)
    {
      if (strcmp(userLogin.username, ent_user) == 0 && strcmp(userLogin.password, ent_pass) == 0)
      {
        printf("\nLogin Succesfull! ");
        getch();
        account_info(userLogin.username);
        ver = 1;
      }
      else
      {
        printf("Try again");
        getch();
      }
    }
    return 0;
  }
}

int signup()
{
  struct users userSignIn;

  printf("\e[1;1H\e[2J");
  printf("Enter your username: ");
  scanf("%s", userSignIn.username);

  printf("Enter your email address to get the OTP: ");
  scanf("%s", userSignIn.email);

  FILE *fp1 = fopen("temp.txt", "w");
  fprintf(fp1, "%s", userSignIn.email);
  fclose(fp1);

  FILE *fp2 = popen("python send_otp.py", "r");
  int auth;
  fscanf(fp2, "%d", &auth);
  fclose(fp2);
  if (auth == 0)
  {
    int authorized = 0, attempts = 4;
    while (!authorized || attempts == 0)
    {
      int otp;
      FILE *fp3 = fopen("temp.txt", "r");
      fscanf(fp3, "%d", &otp);
      fclose(fp3);
      int u_otp;
      printf("Enter OTP: ");
      scanf("%d", &u_otp);
      if (otp == u_otp)
      {
        printf("Verification successfull!\n");
        getch();
        authorized = 1;
        // return 0;
      }
      else if (attempts == 1) {
        printf("You have ran out of attempts. Try again later");
        attempts--;
        return 0;
      }
      else
      {
        printf("Wrong OTP, please try again.\n");
        getch();
        attempts--;
      }
    }
  }
  else
  {
    printf("There is an error sending the email, please try again later");
    return 0;
  }

  remove("temp.txt");

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

  FILE *fp4 = fopen("users.txt", "a"); // open  modes: "rb", "ab", "wb"
  fprintf(fp4, "%s %s %s", userSignIn.username, userSignIn.password, userSignIn.email);

  printf("\nYour account has been created succesfully.");
  fclose(fp4);

  getch();
  account_info(userSignIn.username);
}

int user_menu()
{
  int enter = 0, menu = 0;
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
      }
      else if (menu == 2)
      {
        signup();
      }
      else
      {
        enter = 1;
      }
    default:
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n 1.Login\n 2.Create an account\n 3.Exit to main screen");
      break;
    }
  }
  return 0;
}

int employee_menu()
{
  in_prog();
  return 0;
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
        employee_menu();
        choice = 1;
      }
      else if (choice == 2)
      {
        user_menu();
        choice = 2;
      }
      else
      {
        enter = 1;
      }

    default:
      printf("\e[1;1H\e[2J");
      printf("-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n");
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");
      break;
    }
  }
}