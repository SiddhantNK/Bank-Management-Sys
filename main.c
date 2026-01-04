#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct users
{
  int custId;
  char username[100];
  char password[100];
  char time_buffer[80];
  char email[100];
  float balance;
};

struct users current_user_details;

int fetch_user(char username[])
{
  FILE *fp = fopen("users.txt", "r");
  while (fscanf(fp, "%s %s %s %d %f", current_user_details.username, current_user_details.password, current_user_details.email, &current_user_details.custId, &current_user_details.balance) != EOF)
  {
    if (strcmp(current_user_details.username, username) == 0)
    {
      fclose(fp);
      return 0;
    }
  }
}

struct employee
{
  int empId;
  char name[30];
  char password[20];
  char email[64];
  char domain[30];
};

int in_prog()
{
  printf("\e[1;1H\e[2J");
  printf("In progress...\n Press any key to return");
  getch();
}

int transfer_money(char username[])
{
  int i = 0;
  char ch, pass[64];
  printf("\e[1;1H\e[2J");
  printf("Enter your password: ");
  while ((ch = getch()) != '\r')
  {
    if (ch == 8)
    {
      if (i > 0)
      {
        printf("\b \b");
        pass[i--] = '\0';
      }
    }
    else
    {
      printf("*"); // enter is '\r'
      pass[i++] = ch;
    }
  }
  pass[i] = '\0';

  if (strcmp(pass, current_user_details.password) == 0)
  {
    char ch;
    int choice, enter;
    if (current_user_details.balance == 0.0) {
      printf("\e[1;1H\e[2J");
      printf("You have no money to transfer!");
      getch();
      return 1;
    }
    printf("\e[1;1H\e[2J");
    printf("Choose how do you want to send money");
    printf("\n  1.By username \n  2.By user ID\n  3.Cancel transaction");
    while (enter != 1)
    {
      ch = getch();
      switch (ch)
      {
      case '1':
        choice = 1;
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n=>1.By username \n  2.By user ID\n  3.Cancel transaction");
        break;
      case '2':
        choice = 2;
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n  1.By username \n=>2.By user ID\n  3.Cancel transaction");
        break;
      case '3':
        choice = 3;
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n  1.By username \n  2.By user ID\n=>3.Cancel transaction");
        break;
      case '\r':
        if (choice == 1)
        {
          struct users recieverUser;

          char to_user[64];
          float send_amt;
          printf("\e[1;1H\e[2J");
          printf("Enter username: ");
          scanf("%s", to_user);
          if (strcmp(to_user, current_user_details.username) == 0) {
            printf("\e[1;1H\e[2J");
            printf("You cannot transfer money to yourself!");
            getch();
            return 1;
          }
          printf("Enter the amount of money you want to transfer: ");
          scanf("%f", &send_amt);
          if (send_amt <= 0 || send_amt > current_user_details.balance)
          {
            printf("Invalid amount!");
            getch();
            return 1;
          }

          FILE *fp = fopen("users.txt", "r");

          while (fscanf(fp, "%s %s %s %d %f", recieverUser.username, recieverUser.password, recieverUser.email, &recieverUser.custId, &recieverUser.balance) != EOF)
          {
            if (strcmp(to_user, recieverUser.username) == 0)
            {
              printf("\e[1;1H\e[2J");
              printf("Transfering money... ");
              fclose(fp);
              Sleep(3000);

              current_user_details.balance -= send_amt;
              recieverUser.balance += send_amt;

              FILE *old = fopen("users.txt", "r");
              FILE *new = fopen("temp.txt", "w");
              struct users del;

              while (fscanf(old, "%s %s %s %d %f", del.username, del.password, del.email, &del.custId, &del.balance) != EOF)
              {
                if (strcmp(del.username, username) != 0 && strcmp(del.username, recieverUser.username) != 0)
                  fprintf(new, "%s %s %s %d %f\n",
                          del.username, del.password, del.email, del.custId, del.balance);
              }

              fprintf(new, "%s %s %s %d %f\n",
                      current_user_details.username, current_user_details.password, current_user_details.email, current_user_details.custId, current_user_details.balance);
              fprintf(new, "%s %s %s %d %f\n",
                      recieverUser.username, recieverUser.password, recieverUser.email, recieverUser.custId, recieverUser.balance);

              fclose(old);
              fclose(new);

              remove("users.txt");
              rename("temp.txt", "users.txt");
              printf("\e[1;1H\e[2J");
              printf("✅ Money has been transfered successfully.");
              getch();
              return 0;
            }
          }
          printf("No such user found!!");
          getch();
          fclose(fp);
          return 0;
        }
        else if (choice == 2)
        {
          choice = 2;
          struct users recieverUser;

          int to_user;
          float send_amt;
          printf("\e[1;1H\e[2J");
          printf("Enter user ID: ");
          scanf("%d", &to_user);
          printf("Enter the amount of money you want to transfer: ");
          scanf("%f", &send_amt);
          if (send_amt <= 0 || send_amt > current_user_details.balance)
          {
            printf("Invalid amount!");
            getch();
            return 0;
          }

          FILE *fp = fopen("users.txt", "r");

          while (fscanf(fp, "%s %s %s %d %f", recieverUser.username, recieverUser.password, recieverUser.email, &recieverUser.custId, &recieverUser.balance) != EOF)
          {
            if (to_user == recieverUser.custId)
            {
              printf("\e[1;1H\e[2J");
              printf("Transfering money... ");
              fclose(fp);
              Sleep(3000);

              current_user_details.balance -= send_amt;
              recieverUser.balance += send_amt;

              FILE *old = fopen("users.txt", "r");
              FILE *new = fopen("temp.txt", "w");
              struct users del;

              while (fscanf(old, "%s %s %s %d %f", del.username, del.password, del.email, &del.custId, &del.balance) != EOF)
              {
                if (strcmp(del.username, username) != 0 && strcmp(del.username, recieverUser.username) != 0)
                  fprintf(new, "%s %s %s %d %f\n",
                          del.username, del.password, del.email, del.custId, del.balance);
              }

              fprintf(new, "%s %s %s %d %f\n",
                      current_user_details.username, current_user_details.password, current_user_details.email, current_user_details.custId, current_user_details.balance);
              fprintf(new, "%s %s %s %d %f\n",
                      recieverUser.username, recieverUser.password, recieverUser.email, recieverUser.custId, recieverUser.balance);

              fclose(old);
              fclose(new);

              remove("users.txt");
              rename("temp.txt", "users.txt");
              printf("\e[1;1H\e[2J");
              printf("✅ Money has been transfered successfully.");
              getch();
              return 0;
            }
          }
          printf("No such user found!!");
          fclose(fp);
          return 0;
        }
        else
        {
          enter = 1;
        }

      default:
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n  1.By username \n  2.By user ID\n  3.Cancel transaction");
        break;
      }
    }
  }
  else
  {
    printf("Wrong password, transaction cancelled.");
    return 0;
  }
}

int see_info(char username[])
{
  fetch_user(username);
  printf("\e[1;1H\e[2J");
  printf("Username: %s\n", current_user_details.username);
  printf("Email: %s\n", current_user_details.email);
  printf("ID: %d\n", current_user_details.custId);
  printf("Current balance: %f\n", current_user_details.balance);
  getch();
  return 0;
}

int change_email()
{
  char new_mail[64];
  printf("\e[1;1H\e[2J");
  printf("Enter your new email: ");
  scanf("%s", new_mail);

  FILE *fp1 = fopen("temp.txt", "w");
  fprintf(fp1, "%s", new_mail);
  fclose(fp1);

  FILE *fp2 = popen("python send_otp.py", "r");
  int auth;
  fscanf(fp2, "%d", &auth);
  pclose(fp2);

  int otp;
  FILE *fp3 = fopen("temp.txt", "r");
  fscanf(fp3, "%d", &otp);
  fclose(fp3);
  remove("temp.txt");

  int u_otp;
  if (auth == 0)
  {
    int authorized = 0, attempts = 2;
    while (!authorized || attempts == 0)
    {
      printf("Enter OTP: ");
      scanf("%d", &u_otp);
      if (otp == u_otp)
      {
        printf("\e[1;1H\e[2J");
        printf("Verification successfull!\n");
        getch();
        authorized = 1;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf("You have ran out of attempts. Try again later");
        getch();
        --attempts;
        return 0;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf("Wrong OTP, please try again.\n");
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf("There is an error sending the mail, please try again later");
    return 0;
  }

  printf("\e[1;1H\e[2J");
  printf("Changing your email...");
  Sleep(3000);
  FILE *old = fopen("users.txt", "r");
  FILE *new = fopen("temp.txt", "w");
  struct users del;

  while (fscanf(old, "%s %s %s %d %f",
                del.username, del.password, del.email, &del.custId, &del.balance) != EOF)
  {
    if (strcmp(del.username, current_user_details.username) != 0)
      fprintf(new, "%s %s %s %d %f\n",
              del.username, del.password, del.email, del.custId, del.balance);
  }

  fprintf(new, "%s %s %s %d %f\n",
          current_user_details.username, current_user_details.password, new_mail, current_user_details.custId, current_user_details.balance);

  fclose(old);
  fclose(new);

  remove("users.txt");
  rename("temp.txt", "users.txt");
  printf("\e[1;1H\e[2J");
  printf("✅ Your email has been changed successfully.");
  fetch_user(current_user_details.username);
  getch();
}

int account_info(char username[])
{
  fetch_user(username);
  int act = 0, enter = 0;
  char ch;
  printf("\e[1;1H\e[2J");
  printf("Welcome, %s!\n", username);
  printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
  printf("  1.See account information\n  2.Transfer money\n  3.Apply for loan\n  4.Change email\n  5.Back to Login/Sign Up");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      act = 1;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("=>1.See account information\n  2.Transfer money\n  3.Apply for loan\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '2':
      act = 2;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n=>2.Transfer money\n  3.Apply for loan\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '3':
      act = 3;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n=>3.Apply for loan\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '4':
      act = 4;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Apply for loan\n=>4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '5':
      act = 5;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Apply for loan\n  4.Change email\n=>5.Back to Login/Sign Up");
      break;
    case '\r':
      if (act == 1)
      {
        see_info(username);
      }
      else if (act == 2)
      {
        transfer_money(username);
      }
      else if (act == 3)
      {
        in_prog();
      }
      else if (act == 4)
      {
        change_email();
      }
      else
      {
        enter = 1;
      }

    default:
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Apply for loan\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    }
  }
  return 0;
}

int login()
{
  int ver = 0, attempts = 3;
  while (ver != 1 || attempts == 0)
  {
    printf("\e[1;1H\e[2J");
    struct users userLogin;

    FILE *fp = fopen("users.txt", "r");

    if (fp == NULL)
    {
      printf("\nNo users found!\n");
      getch();
      return 0;
    }

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

    struct users userLoginCheck;
    while (fscanf(fp, "%s %s %s %d %f", userLoginCheck.username, userLoginCheck.password, userLoginCheck.email, &userLoginCheck.custId, &userLoginCheck.balance) != EOF)
    {
      if (strcmp(userLogin.username, userLoginCheck.username) == 0 && strcmp(userLogin.password, userLoginCheck.password) == 0)
      {
        printf("\nLogin Succesfull! ");
        fetch_user(userLogin.username);
        fclose(fp);
        getch();
        ver = 1;
        account_info(userLogin.username);
        return 0;
      }
    }
    --attempts;

    if (attempts == 0)
    {
      printf("\nToo many attempts, try again later.");
      getch();
      fclose(fp);
      return 0;
    }
    else
    {
      printf("\nWrong credentials! Please try again");
      getch();
    }
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
  pclose(fp2);
  if (auth == 0)
  {
    int authorized = 0, attempts = 2;
    while (!authorized || attempts == 0)
    {
      int otp;
      FILE *fp3 = fopen("temp.txt", "r");
      fscanf(fp3, "%d", &otp);
      fclose(fp3);
      remove("temp.txt");
      int u_otp;
      printf("Enter OTP: ");
      scanf("%d", &u_otp);
      if (otp == u_otp)
      {
        printf("\e[1;1H\e[2J");
        printf("Verification successfull!\n");
        getch();
        authorized = 1;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf("You have ran out of attempts. Try again later");
        getch();
        --attempts;
        return 1;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf("Wrong OTP, please try again.\n");
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf("There is an error sending the mail, please try again later");
    return 1;
  }

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

  srand(time(NULL));
  userSignIn.custId = rand();

  FILE *fp4 = fopen("users.txt", "a");
  fprintf(fp4, "%s %s %s %d 10000.0\n", userSignIn.username, userSignIn.password, userSignIn.email, userSignIn.custId);

  printf("\n✅ Your account has been created succesfully.");
  printf("\nYour unique id is: %d", userSignIn.custId);
  printf("\nKindly remember this as you require this ID for future transactions.");
  fclose(fp4);

  getch();
  fetch_user(userSignIn.username);
  account_info(userSignIn.username);
  return 0;
}

int emp_login()
{
  printf("\e[1;1H\e[2J");
  struct employee employeeLogin;

  FILE *fp = fopen("employees.txt", "r");
  int ent_id;
  char ent_user[64], ent_pass[64], ent_email[64];

  if (fp == NULL)
  {
    printf("No employee found!\n");
    getch();
    return 0;
  }

  printf("Enter Employee ID: ");
  scanf("%d", &employeeLogin.empId);

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
        employeeLogin.password[i--] = '\0';
      }
    }
    else
    {
      printf("*");
      employeeLogin.password[i++] = ch;
    }
  }
  employeeLogin.password[i] = '\0';

  while (fscanf(fp, "%s %s %s %d", ent_user, ent_pass, ent_email, &ent_id) != EOF)
  {
    if (employeeLogin.empId == ent_id && strcmp(employeeLogin.password, ent_pass) == 0)
    {
      printf("\n✅ Login Successfull!");
      fclose(fp);
      getch();
      return 0;
    }
  }
  printf("\n❌ Invalid Employee ID or Password\n");
  fclose(fp);
  getch();
  return 1;
}

int emp_signup()
{
  struct employee employeeSignUp;
  printf("\e[1;1H\e[2J");

  // printf("\nEnter Employee ID: ");
  // scanf("%d", &e.empId);

  printf("Enter name: ");
  scanf("%s", employeeSignUp.name);

  printf("Enter your email address to get the OTP: ");
  scanf("%s", employeeSignUp.email);

  FILE *fp1 = fopen("temp.txt", "w");
  fprintf(fp1, "%s", employeeSignUp.email);
  fclose(fp1);

  FILE *fp2 = popen("python send_otp.py", "r");
  int auth;
  fscanf(fp2, "%d", &auth);
  fclose(fp2);
  if (auth == 0)
  {
    int authorized = 0, attempts = 2;
    while (!authorized || attempts == 0)
    {
      int otp;
      FILE *fp3 = fopen("temp.txt", "r");
      fscanf(fp3, "%d", &otp);
      fclose(fp3);
      remove("temp.txt");
      int u_otp;
      printf("Enter OTP: ");
      scanf("%d", &u_otp);
      if (otp == u_otp)
      {
        printf("\e[1;1H\e[2J");
        printf("Verification successfull!\n");
        getch();
        authorized = 1;
        // return 0;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf("❌ You have ran out of attempts. Try again later");
        getch();
        --attempts;
        return 0;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf("Wrong OTP, please try again.\n");
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf("There is an error sending the mail, please try again later");
    return 0;
  }

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
        employeeSignUp.password[i--] = '\0';
      }
    }
    else
    {
      printf("*"); // enter is '\r'
      employeeSignUp.password[i++] = en;
    }
  }
  employeeSignUp.password[i] = '\0';
  srand(time(NULL));
  employeeSignUp.empId = rand();

  FILE *fp4 = fopen("employees.txt", "a");
  fprintf(fp4, "%s %s %s %d\n", employeeSignUp.name, employeeSignUp.password, employeeSignUp.email, employeeSignUp.empId);
  fclose(fp4);

  printf("\n✅ Your account has been created succesfully.");
  printf("\nYour unique id is: %d", employeeSignUp.empId);
  printf("\nKindly remember this as you require this ID for future logins.");

  getch();
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
  int enter = 0, menu = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("Press number keys to select between options and then press Enter\n");
  printf("  1. Add Employee (Admin)\n  2. Employee Login\n  3. Exit");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      menu = 1;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("=>1. Add Employee (Admin)\n  2. Employee Login\n  3. Exit");
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. Add Employee (Admin)\n=>2. Employee Login\n  3. Exit");
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. Add Employee (Admin)\n  2. Employee Login\n=>3. Exit");
      break;
    case '\r':
      if (menu == 1)
      {
        emp_signup();
      }
      else if (menu == 2)
      {
        emp_login();
      }
      else if (menu == 3)
      {
        menu = 0;
        enter = 1;
      }
      else
      {
        continue;
      }
    default:
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. Add Employee (Admin)\n  2. Employee Login\n  3. Exit");
      break;
    }
  }
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