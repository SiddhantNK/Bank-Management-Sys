#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <shellapi.h> 

#define RESET   "\033[0m"
#define BOLD    "\033[1m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void show_about_image() {
    ShellExecuteA(NULL, "open","C:/Users/Siddhant Kale/Pictures/fordp.jpg",NULL,NULL,SW_SHOWNORMAL);

printf("\n-----------------------------------------------\n");
printf("About Our Team:\n");
printf("A group of motivated individuals committed to innovation,\n");
printf("learning, and delivering effective solutions through teamwork.\n");
printf("-----------------------------------------------\n");

    printf("Press Enter to continue...");
    getchar();
    getchar(); 
}
struct users
{
  int custId;
  char username[100];
  char password[100];
  char time_buffer[80];
  char email[100];
  float balance;
};

struct loan {
  char type[20];
  int tenure;
  int id;
  float rate;
  float emi;
  float remaining;
  int emiPaid;
  char status[10];
  float principal;
};

float calculateEMI(float P, float R, int N)
{
  float r = R / 12 / 100;
  float emi = (P * r * pow(1 + r, N)) / (pow(1 + r, N) - 1);
  return emi;
}

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
  char department[50];
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
  printf(BLUE"Enter your password: "RESET);
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
      printf(BOLD RED "Low account balance, can't proceed!" RESET);
      getch();
      return 1;
    }
    printf("\e[1;1H\e[2J");
    printf(MAGENTA"Choose how do you want to send money"RESET);
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
        printf(GREEN"\n=>1.By username"RESET);
        printf(WHITE"\n  2.By user ID\n 3.Cancel transaction"RESET);
        break;
      case '2':
        choice = 2;
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n  1.By username");
        printf(GREEN "\n=>2.By user ID"RESET);
        printf("\n  3.Cancel transaction");
        break;
      case '3':
        choice = 3;
        printf("\e[1;1H\e[2J");
        printf("Choose how do you want to send money");
        printf("\n  1.By username \n  2.By user ID\n");
        printf(RED"=>3.Cancel transaction"RESET);
        break;
      case '\r':
        if (choice == 1)
        {
          struct users recieverUser;

          char to_user[64];
          float send_amt;
          printf("\e[1;1H\e[2J");
          printf(BLUE"Enter username: "RESET);
          scanf("%s", to_user);
          if (strcmp(to_user, current_user_details.username) == 0) {
            printf("\e[1;1H\e[2J");
            printf(BOLD RED"You cannot transfer money to yourself!"RESET);
            getch();
            return 1;
          }
          printf(BLUE"Enter the amount of money you want to transfer: "RESET);
          scanf("%f", &send_amt);
          if (send_amt <= 0 || send_amt > current_user_details.balance)
          {
            printf("Invalid amount!");
            getch();
            return 1;
          }
          else if (send_amt > 50000)
          {
            printf(BOLD RED"🚨 FRAUD ALERT: High value transaction detected!\n"RESET);
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
                FILE *new = fopen("transfer.txt", "w");
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
                rename("transfer.txt", "users.txt");
                printf("\e[1;1H\e[2J");
                printf(BOLD GREEN"✅ Money has been transfered successfully."RESET);
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
          printf(BLUE"Enter user ID: "RESET);
          scanf("%d", &to_user);
          printf(BLUE"Enter the amount of money you want to transfer: "RESET);
          scanf("%f", &send_amt);
          if (send_amt <= 0 || send_amt > current_user_details.balance)
          {
            printf(RED"Invalid amount!"RESET);
            getch();
            return 0;
          }

          FILE *fp = fopen("users.txt", "r");

          while (fscanf(fp, "%s %s %s %d %f", recieverUser.username, recieverUser.password, recieverUser.email, &recieverUser.custId, &recieverUser.balance) != EOF)
          {
            if (to_user == recieverUser.custId)
            {
              printf("\e[1;1H\e[2J");
              printf(YELLOW"Transfering money... "RESET);
              fclose(fp);
              Sleep(3000);

              current_user_details.balance -= send_amt;
              recieverUser.balance += send_amt;

              FILE *old = fopen("users.txt", "r");
              FILE *new = fopen("transfer.txt", "w");
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
              rename("transfer.txt", "users.txt");
              printf("\e[1;1H\e[2J");
              printf(BOLD GREEN"✅ Money has been transfered successfully."RESET);
              getch();
              return 0;
            }
          }
          printf(RED"No such user found!!"RESET);
          return 1;
          fclose(fp);
          getch();
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
    printf(RED"Wrong password, transaction cancelled."RESET);
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
  printf(BLUE"Enter your new email: "RESET);
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
        printf(BOLD GREEN"Verification successfull!\n"RESET);
        getch();
        authorized = 1;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf(RED"You have ran out of attempts. Try again later"RESET);
        getch();
        --attempts;
        return 0;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf(RED"Wrong OTP, please try again.\n"RESET);
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf(RED"There is an error sending the mail, please try again later"RESET);
    return 0;
  }

  printf("\e[1;1H\e[2J");
  printf(YELLOW"Changing your email..."RESET);
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
  printf(BOLD GREEN"✅ Your email has been changed successfully."RESET);
  fetch_user(current_user_details.username);
  getch();
}

int apply_loan()
{
  struct loan newLoan;

  printf("\e[1;1H\e[2J");
  printf(BLUE"Enter loan type (Home/Car/Education/Personal): "RESET);
  scanf("%s", newLoan.type);

  printf(BLUE"Enter principal amount: "RESET);
  scanf("%f", &newLoan.principal);

  printf(BLUE"Enter interest rate (annual %%): "RESET);
  scanf("%f", &newLoan.rate);

  printf(BLUE"Enter tenure (in months): "RESET);
  scanf("%d", &newLoan.tenure);

  newLoan.emi = calculateEMI(newLoan.principal, newLoan.rate, newLoan.tenure);
  newLoan.remaining = newLoan.principal;
  newLoan.emiPaid = 0;
  strcpy(newLoan.status, "ACTIVE");

  FILE *fp = fopen("loans.txt", "a");
  fprintf(fp, "%d %s %f %f %d %f %f %d %s\n",
          current_user_details.custId,
          newLoan.type,
          newLoan.principal,
          newLoan.rate,
          newLoan.tenure,
          newLoan.emi,
          newLoan.remaining,
          newLoan.emiPaid,
          newLoan.status);
  fclose(fp);

  printf(BOLD GREEN"\n✅ Loan applied successfully!"RESET);
  printf(BLUE"\nMonthly EMI: %.2f"RESET, newLoan.emi);
  getch();
  return 0;
}

int view_loan_status()
{
  struct loan loanStatus;
  int c_id;
  int found = 0;

  FILE *fp = fopen("loans.txt", "r");
  if (fp == NULL)
  {
    printf("\nNo loans found.");
    getch();
    return 0;
  }

  while (fscanf(fp, "%d %s %f %f %d %f %f %d %s",
                &c_id, loanStatus.type, &loanStatus.principal, &loanStatus.rate,
                &loanStatus.tenure, &loanStatus.emi, &loanStatus.remaining,
                &loanStatus.emiPaid, loanStatus.status) != EOF)
  {
    if (c_id == current_user_details.custId)
    {
      printf("\e[1;1H\e[2J");
      printf("Loan Type     : %s\n", loanStatus.type);
      printf("Principal     : %f\n", loanStatus.principal);
      printf("Interest Rate : %f%%\n", loanStatus.rate);
      printf("Tenure        : %d months\n", loanStatus.tenure);
      printf("EMI           : %f\n", loanStatus.emi);
      printf("Remaining     : %f\n", loanStatus.remaining);
      printf("EMIs Paid     : %d\n", loanStatus.emiPaid);
      printf("Status        : %s\n", loanStatus.status);
      found = 1;
      break;
    }
  }

  fclose(fp);

  if (!found)
    printf(RED"\n❌ No active loan found."RESET);

  getch();
  return 0;
}

int pay_emi()
{
  printf("\e[1;1H\e[2J");
  struct loan loanEMI;
  int c_id, found = 0;

  FILE *fp = fopen("loans.txt", "r");
  FILE *temp = fopen("emi.txt", "w");

  if (fp == NULL || temp == NULL) {
    printf(RED"There is an error fetching the loans, please try again later."RESET);
    getch();
    return 0;
  }

  while (fscanf(fp, "%d %s %f %f %d %f %f %d %s",
                &c_id, loanEMI.type, &loanEMI.principal, &loanEMI.rate,
                &loanEMI.tenure, &loanEMI.emi, &loanEMI.remaining,
                &loanEMI.emiPaid, loanEMI.status) != EOF)
  {
    if (c_id == current_user_details.custId && strcmp(loanEMI.status, "ACTIVE") == 0)
    {
      found = 1;

      if (current_user_details.balance < loanEMI.emi)
      {
        printf(BOLD RED"\n❌ Insufficient balance to pay EMI."RESET);
        getch();
        fclose(fp);
        fclose(temp);
        return 0;
      }

      current_user_details.balance -= loanEMI.emi;
      loanEMI.remaining -= loanEMI.emi;
      loanEMI.emiPaid++;

      if (loanEMI.remaining <= 0) {
        printf(GREEN"✅ Loan closed"RESET);
        strcpy(loanEMI.status, "CLOSED");
      }

      fprintf(temp, "%d %s %f %f %d %f %f %d %s\n",
              c_id, loanEMI.type, loanEMI.principal, loanEMI.rate, loanEMI.tenure,
              loanEMI.emi, loanEMI.remaining, loanEMI.emiPaid, loanEMI.status);
    }
    else
    {
      fprintf(temp, "%d %s %f %f %d %f %f %d %s\n",
              c_id, loanEMI.type, loanEMI.principal, loanEMI.rate, loanEMI.tenure,
              loanEMI.emi, loanEMI.remaining, loanEMI.emiPaid, loanEMI.status);
    }
  }

  fclose(fp);
  fclose(temp);

  remove("loans.txt");
  rename("temp.txt", "loans.txt");

  printf(GREEN"\n✅ EMI paid successfully."RESET);
  getch();
  return 0;
}

int loan_section() {
  int choice = 0, enter = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("    LOAN SECTION\n");
  printf("Press number keys to select between options and then press Enter\n");
  printf("  1.Apply for Loan \n  2.View loan status\n  3.Pay EMI\n  4.Exit");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      choice = 1;
      printf("\e[1;1H\e[2J");
      printf("    LOAN SECTION\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf(GREEN"=>1.Apply for Loan"RESET);
      printf("\n  2.View loan status\n  3.Pay EMI\n  4.Exit");
      break;
    case '2':
      choice = 2;
      printf("\e[1;1H\e[2J");
      printf("    LOAN SECTION\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1.Apply for Loan ");
      printf(GREEN"\n=>2.View loan status"RESET);
      printf("\n  3.Pay EMI\n  4.Exit");
      break;
    case '3':
      choice = 3;
      printf("\e[1;1H\e[2J");
      printf("    LOAN SECTION\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1.Apply for Loan \n  2.View loan status");
        printf(GREEN"\n=>3.Pay EMI"RESET);
        printf("\n  4.Exit");
      break;
    case '4':
      choice = 4;
      printf("\e[1;1H\e[2J");
      printf("    LOAN SECTION\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1.Apply for Loan \n  2.View loan status\n  3.Pay EMI");
        printf(RED"\n=>4.Exit"RESET);
      break;
    case '\r':
      if (choice == 1)
      {
        apply_loan();
        choice = 1;
      }
      else if (choice == 2)
      {
        view_loan_status();
        choice = 2;
      }
      else if (choice == 3)
      {
        pay_emi();
        choice = 3;
      }
      else
      {
        enter = 1;
      }

    default:
      printf("\e[1;1H\e[2J");
      printf("    LOAN SECTION\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1.Apply for Loan \n  2.View loan status\n  3.Pay EMI\n  4.Exit");
      break;
    }
  }
}

int account_info(char username[])
{
  fetch_user(username);
  int act = 0, enter = 0;
  char ch;
  printf("\e[1;1H\e[2J");
  printf("Welcome, %s!\n", username);
  printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
  printf("  1.See account information\n  2.Transfer money\n  3.Loan Section\n  4.Change email\n  5.Back to Login/Sign Up");

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
      printf(GREEN"=>1.See account information"RESET);
      printf("\n  2.Transfer money\n  3.Loan Section\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '2':
      act = 2;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information");
      printf(GREEN"\n=>2.Transfer money"RESET);
      printf("\n  3.Loan Section\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '3':
      act = 3;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money");
       printf(GREEN"\n=>3.Loan Section"RESET);
    printf("\n  4.Change email\n  5.Back to Login/Sign Up");
      break;
    case '4':
      act = 4;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Loan Section"); 
      printf(GREEN"\n=>4.Change email"RESET);
      printf("\n  5.Back to Login/Sign Up");
      break;
    case '5':
      act = 5;
      printf("\e[1;1H\e[2J");
      printf("Welcome, %s!\n", username);
      printf("What do you wanna do today?\nPress number keys to select between options and then press Enter\n");
      printf("  1.See account information\n  2.Transfer money\n  3.Loan Section\n  4.Change email");
      printf(YELLOW"\n=>5.Back to Login/Sign Up"RESET);
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
        // in_prog();
        loan_section();
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
      printf("  1.See account information\n  2.Transfer money\n  3.Loan Section\n  4.Change email\n  5.Back to Login/Sign Up");
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
      printf(RED"\nNo users found!\n"RESET);
      getch();
      return 0;
    }

    printf(BLUE"Enter your username: "RESET);
    scanf("%s", userLogin.username);

    int i = 0;
    char ch;
    printf(BLUE"Enter your password: "RESET);
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
        printf(GREEN"\nLogin Succesfull! "RESET);
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
      printf(BOLD RED"\nToo many attempts, try again later."RESET);
      getch();
      fclose(fp);
      for(int i = 30; i >0;i-- ) {
        printf("\e[1;1H\e[2J");
        printf(YELLOW"Try again in %d seconds.."RESET, i);
        Sleep(1000);
      }
      return 0;
    }
    else
    {
      printf(RED"\nWrong credentials! Please try again"RESET);
      getch();
    }
  }
}

int signup()
{
  struct users userSignIn;

  printf("\e[1;1H\e[2J");
  printf(BLUE"Enter your username: "RESET);
  scanf("%s", userSignIn.username);

  printf(BLUE"Enter your email address to get the OTP: "RESET);
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
      printf(BLUE"Enter OTP: "RESET);
      scanf("%d", &u_otp);
      if (otp == u_otp)
      {
        printf("\e[1;1H\e[2J");
        printf(GREEN"Verification successfull!\n"RESET);
        getch();
        authorized = 1;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf(RED"You have ran out of attempts. Try again later"RESET);
        getch();
        --attempts;
        return 1;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf(RED"Wrong OTP, please try again.\n"RESET);
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf(RED"There is an error sending the mail, please try again later"RESET);
    return 1;
  }

  int i = 0;
  char en;
  printf(BLUE"Enter your password: "RESET);
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

  printf(GREEN"\n✅ Your account has been created succesfully."RESET);
  printf("\nYour unique id is: %d", userSignIn.custId);
  printf("\nKindly remember this as you require this ID for future transactions.");
  fclose(fp4);

  getch();
  fetch_user(userSignIn.username);
  account_info(userSignIn.username);
  return 0;
}

int emp_daily()
{
  int enter = 0, menu = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("Employee Daily with Customers \n");
  printf("Press number keys to select between options and then press Enter\n");
  printf("  1. View All Customers\n");
  printf("  2. Search Customer by ID\n");
  printf("  3. Delete Customer\n");
  printf("  4. Exit\n");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
    menu = 1; 
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(GREEN"=>1. View All Customers\n"RESET);
      printf("  2. Search Customer by ID\n");
      printf("  3. Delete Customer\n");
      printf("  4. Exit\n");

    break;
    case '2':
     menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. View All Customers\n");
      printf(GREEN"=>2. Search Customer by ID\n"RESET);
      printf("  3. Delete Customer\n");
      printf("  4. Exit\n");

     break;
    case '3':
    menu = 3;
         printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. View All Customers\n");
      printf("  2. Search Customer by ID\n");
      printf(RED"=>3. Delete Customer\n"RESET);
      printf("  4. Exit\n");
     break;
    case '4':
     menu = 4; 
        printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. View All Customers\n");
      printf("  2. Search Customer by ID\n");
      printf("  3. Delete Customer\n");
      printf(RED"=>4. Exit\n"RESET);
     break;

    case '\r':

      if (menu == 1)
      {
        FILE *fp;
        char username[64], password[64], email[64];
        int custId;
        float balance;

        printf("\e[1;1H\e[2J");
        fp = fopen("users.txt", "r");
        if (fp == NULL)
        {
          printf(YELLOW"No customer data found.\n"RESET);
          getch();
          break;
        }

               while (fscanf(fp, "%63s %63s %63s %d %f",
                username, password, email, &custId, &balance) == 5)
                {
                  printf("%s\t%s\t%d\t%.2f\n",
                    username, email, custId, balance);
                }

        fclose(fp);
        printf("\nPress any key to return to menu...");
        getch();
        menu=0;

      }

      else if (menu == 2)
      {
        FILE *fp;
        int id, found = 0;
        char username[64], password[64], email[64];
        int custId;
        float balance;

        printf("\e[1;1H\e[2J");
        printf(BLUE"Enter Customer ID: "RESET);
        scanf("%d", &id);

        fp = fopen("users.txt", "r");
        if (fp == NULL)
        {
          printf(" File not found.\n");
          getch();
          break;
        }

        while (fscanf(fp, "%s %s %s %d %f",
                      username, password, email, &custId, &balance) != EOF)
        {
          if (custId == id)
          {
            printf(GREEN"\nCustomer Found\n"RESET);
            printf("-----------------\n");
            printf("Username : %s\n", username);
            printf("Email    : %s\n", email);
            printf("ID       : %d\n", custId);
            printf("Balance  : %.2f\n", balance);
            found = 1;
            printf("\nPress any key to return to menu...");
            break;
          }
        }

        fclose(fp);

        if (!found)
          printf(RED"\n Customer not found!"RESET);

        getch();
      }

      else if (menu == 3)
      {
        FILE *fp, *temp;
        int id, found = 0;
        char username[64], password[64], email[64];
        int custId;
        float balance;

        printf("\e[1;1H\e[2J");
        printf(BLUE"Enter Customer ID to delete: "RESET);
        scanf("%d", &id);

        fp = fopen("users.txt", "r");
        temp = fopen("temp.txt", "w");

        if (fp == NULL || temp == NULL)
        {
          printf(" File error.\n");
          getch();
          break;
        }

        while (fscanf(fp, "%s %s %s %d %f",
                      username, password, email, &custId, &balance) != EOF)
        {
          if (custId != id)
          {
            fprintf(temp, "%s %s %s %d %.2f\n",
                    username, password, email, custId, balance);
          }
          else
          {
            found = 1;
          }
        }

        fclose(fp);
        fclose(temp);

        remove("users.txt");
        rename("temp.txt", "users.txt");

        if (found)
          printf(GREEN"\n✅ Customer deleted successfully."RESET);
        else
          printf(RED"\n❌ Customer ID not found."RESET);
          printf("\nPress any key to return to menu...");
        getch();
      }

     
      else if (menu == 4)
      {
        enter = 1;
      }
      break;

    default:
      printf("\e[1;1H\e[2J");
      printf("Employee Daily Operations\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. View All Customers\n");
      printf("  2. Search Customer by ID\n");
      printf("  3. Delete Customer\n");
      printf("  4. Exit\n");
      break;
    }
  }
  return 0;
}

int emp_login()
{
  printf("\e[1;1H\e[2J");
  struct employee employeeLogin;

  FILE *fp = fopen("employees.txt", "r");
  int ent_id;
  char ent_user[64], ent_pass[64], ent_email[64];
  int found = 0;

  if (fp == NULL)
  {
    printf(RED"No employee found!\n"RESET);
    getch();
    return 1;
  }

  printf(BLUE"Enter Employee ID: "RESET);
  scanf("%d", &employeeLogin.empId);

  int i = 0;
  char ch;
  printf(BLUE"Enter your password: "RESET);
  while ((ch = getch()) != '\r')
  {
    if (ch == 8 && i > 0)
    {
      printf("\b \b");
      employeeLogin.password[--i] = '\0';
    }
    else
    {
      printf("*");
      employeeLogin.password[i++] = ch;
    }
  }
  employeeLogin.password[i] = '\0';

  while (fscanf(fp, "%s %s %s %d",
                ent_user, ent_pass, ent_email, &ent_id) != EOF)
  {
    if (employeeLogin.empId == ent_id &&
        strcmp(employeeLogin.password, ent_pass) == 0)
    {
      found = 1;
      break;
    }
  }

  fclose(fp);

  if (found)
  {
    printf(GREEN"\n✅ Login Successful!"RESET);
    getch();
    emp_daily();   
    return 0;
  }
  else
  {
    printf(RED"\n❌ Invalid Employee ID or Password"RESET);
    getch();
    return 1;
  }
}

int emp_signup()
{
  struct employee employeeSignUp;
  printf("\e[1;1H\e[2J");

  // printf("\nEnter Employee ID: ");
  // scanf("%d", &e.empId);

  printf( BLUE"Enter name: " RESET);
  scanf("%s", employeeSignUp.name);

  printf(BLUE "Enter your email address to get the OTP: "RESET);
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
        printf(GREEN"Verification successfull!\n"RESET);
        getch();
        authorized = 1;
        // return 0;
      }
      else if (attempts == 0)
      {
        printf("\e[1;1H\e[2J");
        printf(RED"❌ You have ran out of attempts. Try again later"RESET);
        getch();
        --attempts;
        return 0;
      }
      else
      {
        printf("\e[1;1H\e[2J");
        printf(RED"Wrong OTP, please try again.\n"RESET);
        // getch();
        // printf("\e[1;1H\e[2J");
        --attempts;
      }
    }
  }
  else
  {
    printf("\e[1;1H\e[2J");
    printf(RED"There is an error sending the mail, please try again later"RESET);
    return 0;
  }

  int i = 0;
  char en;
  printf(BLUE "Enter your password: "RESET);
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

  int enter = 0, menu = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf("Please choose department\n");
  printf("Press number keys to select between options and then press Enter\n");
  printf("  1. HR Department\n");
  printf("  2. IT Department\n");
  printf("  3. Credits / Loan Operations\n");
  printf("  4. Treasury & Finance\n");
  printf("  5. Front Office / Retail Banking\n");
  printf("  6. Back Office Operations\n");
  printf("  7. Risk Management Department\n");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      menu = 1;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf(BLUE"=>1. HR Department"RESET);
      printf("\n  2. IT Department\n  3. Credits / Loan Operations\n  4. Treasury & Finance\n  5. Front Office / Retail Banking\n  6. Back Office Operations\n  7. Risk Management Department\n");
      break;

    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n");
      printf(BLUE"=>2. IT Department"RESET);
      printf("\n  3. Credits / Loan Operations\n  4. Treasury & Finance\n  5. Front Office / Retail Banking\n  6. Back Office Operations\n  7. Risk Management Department\n");
      break;

    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n  2. IT Department\n");
        printf(BLUE"=>3. Credits / Loan Operations\n"RESET);
        printf("  4. Treasury & Finance\n  5. Front Office / Retail Banking\n  6. Back Office Operations\n  7. Risk Management Department\n");
      break;

    case '4':
      menu = 4;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n  2. IT Department\n  3. Credits / Loan Operations");
      printf(BLUE"\n=>4. Treasury & Finance"RESET);
      printf("\n  5. Front Office / Retail Banking\n  6. Back Office Operations\n  7. Risk Management Department\n");
      break;

    case '5':
      menu = 5;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n  2. IT Department\n  3. Credits / Loan Operations\n  4. Treasury & Finance");
      printf(BLUE"\n=>5. Front Office / Retail BankingRESET");
      printf("\n  6. Back Office Operations\n  7. Risk Management Department\n");
      break;

    case '6':
      menu = 6;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n  2. IT Department\n  3. Credits / Loan Operations\n  4. Treasury & Finance\n  5. Front Office / Retail Banking");
      printf(BLUE"\n=>6. Back Office Operations");
      printf(" 7. Risk Management Department\n");
      break;

    case '7':
      menu = 7;
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n  2. IT Department\n  3. Credits / Loan Operations\n  4. Treasury & Finance\n  5. Front Office / Retail Banking\n  6. Back Office Operations\n");
      printf(BLUE"=>7. Risk Management Department\n"RESET);
      break;

    case '\r':
      if (menu == 1)
      {
        strcpy(employeeSignUp.department, "HR_Department");
      }
      else if (menu == 2)
      {
        strcpy(employeeSignUp.department, "IT_Department");
      }
      else if (menu == 3)
      {
        strcpy(employeeSignUp.department, "Credits_Loan_Operations");
      }
      else if (menu == 4)
      {
        strcpy(employeeSignUp.department, "Treasury_&_Finance");
      }
      else if (menu == 5)
      {
        strcpy(employeeSignUp.department, "Front_Office_Retail_Banking");
      }
      else if (menu == 6)
      {
        strcpy(employeeSignUp.department, "Back_Office_Operations");
      }
      else if (menu == 7)
      {
        strcpy(employeeSignUp.department, "Risk_Management_Department");
      }
      else
      {
        strcpy(employeeSignUp.department, "Not_Assigned");
      }
      enter = 1;
      break;

    default:
      printf("\e[1;1H\e[2J");
      printf("Please choose department\n");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. HR Department\n");
      printf("  2. IT Department\n");
      printf("  3. Credits / Loan Operations\n");
      printf("  4. Treasury & Finance\n");
      printf("  5. Front Office / Retail Banking\n");
      printf("  6. Back Office Operations\n");
      printf("  7. Risk Management Department\n");
      break;
    }
  }

  srand(time(NULL));
  employeeSignUp.empId = rand();

  FILE *fp4 = fopen("employees.txt", "a");
  fprintf(fp4, "%s %s %s %d %s\n", employeeSignUp.name, employeeSignUp.password, employeeSignUp.email, employeeSignUp.empId, employeeSignUp.department);
  fclose(fp4);

  printf(GREEN"\n✅ Your account has been created succesfully."RESET);
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
      printf(GREEN"\n>1.Login"RESET);
      printf("\n 2.Create an account\n 3.Exit to main screen");
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n 1.Login");
      printf(GREEN"\n>2.Create an account"RESET);
      printf("\n 3.Exit to main screen");
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("\n 1.Login\n 2.Create an account\n");
      printf(YELLOW">3.Exit to main screen"RESET);
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
      printf(GREEN"=>1. Add Employee (Admin)"RESET);
      printf("\n  2. Employee Login\n  3. Exit");
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. Add Employee (Admin)");
        printf(GREEN"\n=>2. Employee Login"RESET);
        printf("\n  3. Exit");
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf("  1. Add Employee (Admin)\n  2. Employee Login\n");
      printf(RED"=>3. Exit"RESET);
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

int about_us(){
  int choice;
    int aboutUs;
    int team;


      printf("\e[1;1H\e[2J");
    printf("\n=================================================\n");
    printf(BOLD CYAN"        NEXUS BANK - INFORMATION MENU\n"RESET);
    printf("=================================================\n");
  
    printf("1. About Us\n");
    printf("2. Meet Our Team\n\n");

    printf(BLUE"Enter your choice: "RESET);
    scanf("%d", &choice);
    getchar();  


    switch (choice) {

        case 1:
      printf("\e[1;1H\e[2J");
    printf("\n===================================================================\n");
    printf("                            ABOUT US\n");
    printf("=====================================================================\n\n");

    printf(MAGENTA"Welcome to NEXUS BANK...!!!\n\n"RESET);
    printf("Experience transparent and seamless banking with security at every step.\n");

    printf("We aim to provide superior and proactive banking services while delivering cost-\n");
    printf("effective and responsive solutions.\n");
    printf("We work for you 24x7 to make your future better, smarter, and goal-oriented.\n\n");

    printf("1. Vision and Values\n");
    printf("2. Safe Banking\n");
    printf(BLUE"Enter your choice: "RESET);
    scanf("%d", &aboutUs);
    getch();

    switch (aboutUs) {


        case 1:

      printf("\e[1;1H\e[2J");
    printf("---------------------------------------------------------------------\n");
    printf("                            OUR MISSION\n");
    printf("---------------------------------------------------------------------\n\n");

    printf("To provide superior and proactive banking services to niche markets globally while\n");
    printf("delivering cost-effective and responsive solutions, meeting stakeholder needs.\n\n");

    printf("---------------------------------------------------------------------\n");
    printf("                             OUR VISION\n");
    printf("---------------------------------------------------------------------\n\n");

    printf("To become the bank of choice for corporates,medium businesses, retail customers,\n");
    printf("and to support rural and mass-market banking.\n\n");

    printf("---------------------------------------------------------------------\n");
    printf("                          OUR CORE VALUES\n");
    printf("---------------------------------------------------------------------\n\n");

    printf("Ethical Banking:\n");
    printf("We believe in transparency, simplified communication, and fair practices.\n\n");

    printf("Customer-Friendly Banking:\n");
    printf("We follow a customer-first approach and aim to make banking simple and accessible.\n\n");

    printf("Integrity:\n");
    printf("A bank operates with honesty, transparency, and strong ethical principles in all financial dealings.\n\n");

    printf("Trust & Reliability:\n");
    printf("Building and maintaining customer trust by safeguarding money, data, and financial interests.\n\n");

    printf("Accountability:\n");
    printf("Taking responsibility for decisions, actions, and outcomes while ensuring regulatory compliance.\n\n");

    printf("Confidentiality & Security:\n");
    printf("Protecting customer information and ensuring secure transactions at all times.\n\n");
      getch();
    break;
        case 2:
        printf("\e[1;1H\e[2J");
    printf("---------------------------------------------------------------------\n");
    printf("                           SAFE BANKING\n");
    printf("---------------------------------------------------------------------\n\n");
      printf("Beat the Fear. Beat the Greed. Beat the Cheats.\n");
    printf("Fraudsters are getting smarter, but awareness keeps you protected.\n\n");

    printf("Stay smart. Stay alert. Stay safe.\n");
    printf("Follow safe banking practices always.\n");

    printf("------------------------------------------------------------------------\n");
    printf("                   RULES AND REGULATIONS OF SAFE BANKING\n");
    printf("------------------------------------------------------------------------\n\n");

    printf("# Keep your PIN, passwords, and OTP private\n");
    printf("# Use strong passwords and official bank apps only\n");
    printf("# Avoid public Wi-Fi for transactions\n");
    printf("# Log out after online banking sessions\n");
    printf("# Log out after online banking sessions\n");
    printf("# Use only official bank websites and apps\n");
    printf("# Check alerts and report suspicious activity immediately\n\n\n");
      getch();
    break;

    default:
            printf(RED"\nInvalid choice! Please enter a number between 1 and 2.\n"RESET);
              getch();
          }


    break;


    case 2:
    printf("\e[1;1H\e[2J");
    printf("-----------------------------------------------------------------\n");
    printf(MAGENTA"                         MEET OUR TEAM\n"RESET);
    printf("----------------------------------------------------------------\n\n");
    
    printf("1. Display Info\n");
    printf("2. Display image\n");
    printf("Enter your choice: ");
    scanf("%d", &team);

    switch (team) {

        case 1:
    
    printf(MAGENTA"Janvhi Kardure\n"RESET);
    printf(MAGENTA"Janhavi Pawar\n"RESET);
    printf(MAGENTA"Himali Deshmukh\n"RESET);
    printf(MAGENTA"Mohammed Fahim Jamadar\n"RESET);
    printf(MAGENTA"Siddhant Kale\n"RESET);
    printf("");
        getch();
    break;

    case 2:
      show_about_image();   
       break;

    default:
            printf(RED"\nInvalid choice! Please enter a number between 1 and 2.\n"RESET);
              getch();
          }
    break;

     
    default:
              printf("\nInvalid choice! Please enter a number between 1 and 2.\n");
                getch();
    
          }



    printf("\n====================================================================\n");
    return 0;


}

int main()  
{
  int choice = 0, enter = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
  printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
  printf("  1.Employee Platform \n  2.Customer Platform\n  3.About us\n  4.Exit Application");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      choice = 1;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf(GREEN"=>1.Employee Platform"RESET);
      printf(WHITE"\n  2.Customer Platform\n  3.About us\n  4.Exit Application"RESET);
      break;
    case '2':
      choice = 2;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n");
      printf(GREEN"=>2.Customer Platform\n"RESET);
      printf("  3.About us\n  4.Exit Application");
      break;
    case '3':
      choice = 3;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n  2.Customer Platform\n");
      printf(GREEN"=>3.About us\n"RESET);
      printf  ("  4.Exit Application");
      break;
      case '4':
      choice = 4;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n  2.Customer Platform\n  3.About us\n");
      printf(RED"=>4.Exit Application"RESET);
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
      else if(choice == 3)
      {
        about_us();
        choice =3;
      }
      else if (choice == 4)
      {
        enter = 1;
      }
      else
      {
        enter = 1;
      }

    default:
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- NEXUS BANK -*-*-*-*-\n"RESET);
      printf("What do you wanna do? \nPress number keys to select between options and then press Enter\n");
      printf("  1.Employee Platform \n  2.Customer Platform\n  3.About us\n  4.Exit Application");

      break;
    }
  }

}