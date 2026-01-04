#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#define RESET "\033[0m" 
  #define RED "\033[31m"   // warnings, exit option
  #define CYAN "\033[36m"  
    #define GREEN "\033[32m" // success/selection
    #define YELLOW "\033[33m" // in progress
      #define WHITE "\033[37m" //normal text
      #define BLUE "\033[34m"  // input prompts
        #define BOLD "\033[1m" // title
      
struct users
{
  char username[100];
  char password[100];
};
 char time_buffer[80];
  
 struct employee
 {
    int emp_code;
    char emp_name[50];
    float salary;
    char department[50];

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
  printf(WHITE"What do you wanna do today?\nPress number keys to select between options and then press Enter\n"RESET);
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
      printf(WHITE"What do you wanna do today?\nPress number keys to select between options and then press Enter\n"RESET);
      printf(GREEN"=>1.See account information\n"RESET);
      printf (WHITE"2.Transfer money\n"RESET);
      printf (BLUE"3.Change password\n"RESET);
      printf(BLUE"4.Change email\n"RESET);
      printf (RED"5.Back to Login/Sign Up"RESET);
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
  printf("\e[1;1H\e[2J");
  struct users userLogin;

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

  printf(YELLOW"\nYour user name is: %s"RESET, userLogin.username);
  printf(YELLOW"\nYour password is: %s"RESET, userLogin.password);
  account_info(userLogin.username);
  return 0;
}

int signup()
{
  struct users userSignIn;
  printf("\e[1;1H\e[2J");
  printf(BLUE"Enter your username: "RESET);
  scanf("%s", userSignIn.username);
  // getch();

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
 

  FILE *new = fopen("users1.txt", "a"); // open  modes: "rb", "ab", "wb"
  fprintf(new, "%s %s\n", userSignIn.username, userSignIn.password);
  

  printf(YELLOW"\nYour user name is: %s \n"RESET, userSignIn.username); 
  printf(YELLOW"Your password is: %s \n"RESET, userSignIn.password);

  fclose(new);
  printf(GREEN"\nYour account has been created succesfully."RESET);
  getch();
  account_info(userSignIn.username);
  return 0;
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
      printf(GREEN">1.Login\n"RESET);
        printf(WHITE"2.Create an account\n"RESET);
        printf (RED"3.Exit to main screen"RESET);
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(WHITE" 1.Login\n"RESET);
      printf(GREEN">2.Create an account\n"RESET);
      printf (RED"3.Exit to main screen"RESET);
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(WHITE"\n 1.Login\n"RESET);
      printf (WHITE"2.Create an account\n"RESET);
      printf(RED">3.Exit to main screen"RESET);
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
      printf(WHITE"Press number keys to select between options and then press Enter\n"RESET);
      printf("\n 1.Login\n 2.Create an account\n 3.Exit to main screen");
      break;
    }
  }
  return 0;
}
int create_id(){

  printf("\e[1;1H\e[2J");
  struct employee emp;
  FILE *emp_file = fopen("employees.txt", "a");
  printf(BLUE"Enter Employee Code: "RESET);
  scanf("%d", &emp.emp_code);
  printf(BLUE"Enter Employee Name: "RESET);
  scanf("%s", emp.emp_name);
  printf(BLUE"Enter Employee Salary: "RESET);
  scanf("%f", &emp.salary);
  printf(BLUE"Enter Employee Department: "RESET);
  scanf("%s", emp.department);

  fprintf(emp_file, "%d %s %.2f %s\n", emp.emp_code, emp.emp_name, emp.salary, emp.department);
  fclose(emp_file);
  printf(GREEN"\nEmployee ID created successfully.\n"RESET);
  getch();
  return 0;
}
int emp_login(){
  struct employee emp;
  int code, found = 0;
  printf("\e[1;1H\e[2J");
  printf(BLUE"Enter your Employee ID: "RESET);
  scanf("%d", &code);
  FILE *emp_file = fopen("employees.txt", "r");
  while (fscanf(emp_file, "%d %s %f %s", &emp.emp_code, emp.emp_name, &emp.salary, emp.department) != EOF)
  {
    if (emp.emp_code == code)
    {
      found = 1;
      break;
    }
  }
  fclose(emp_file);
  if (found)
  {
    printf(GREEN"\nLogin successful. Welcome, %s!\n"RESET, emp.emp_name);
    printf("Employee Code: %d\n", emp.emp_code);
    printf("Salary: %.2f\n", emp.salary);
    printf("Department: %s\n", emp.department);
  }
  else
  {
    printf(RED"\nEmployee ID not found. Please try again.\n"RESET);
  }

 
  getch();
  return 0;
}
int employee_menu()
{ int enter = 0, menu = 0,i=0;
  char ch;
  printf("\e[1;1H\e[2J");
  // printf(YELLOW"In Progress...Please come back later\nPress any key to return"RESET);
  // printf(WHITE"\nPress number keys to select between options and then press Enter\n"RESET);
  printf("1.Login in with your employee ID\n");
  printf("2.Create new Employee ID\n");
  printf("3.Exit to main screen\n");
  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      menu = 1;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(GREEN">1.Login in with your employee ID\n"RESET);
        printf(WHITE"2.Create new Employee ID\n"RESET);
        printf (RED"3.Exit to main screen"RESET);
      break;
    case '2':
      menu = 2;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(WHITE"1.Login in with your employee ID\n"RESET);
      printf(GREEN">2.Create new Employee ID\n"RESET);
      printf (RED"3.Exit to main screen"RESET);
      break;
    case '3':
      menu = 3;
      printf("\e[1;1H\e[2J");
      printf("Press number keys to select between options and then press Enter\n");
      printf(WHITE"\n 1.Login in with your employee ID\n"RESET);
      printf (WHITE"2.Create new Employee ID\n"RESET);
      printf(RED">3.Exit to main screen"RESET);
      break;
    case '\r':
      if (menu == 1)
      {
        emp_login();
      }
      else if (menu == 2)
      {
        create_id();
      }
      else
      {
        enter = 1;
      }
    default:
      printf("\e[1;1H\e[2J");
      printf(WHITE"Press number keys to select between options and then press Enter\n"RESET);
      printf("\n .Login in with your employee ID\n 2.Create new Employee ID\n 3.Exit to main screen");
      break;
    }
  }


  getch();
  return 0;
}

int main()
{
  int choice = 0, enter = 0;
  char ch;

  printf("\e[1;1H\e[2J");
  printf(BOLD CYAN "-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n"RESET);
  printf(WHITE"What do you wanna do? \n Press number keys to select between options and then press Enter\n"RESET);
  printf("  1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");

  while (enter != 1)
  {
    ch = getch();
    switch (ch)
    {
    case '1':
      choice = 1;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n"RESET);
      printf(WHITE"What do you wanna do? \nPress number keys to select between options and then press Enter\n"RESET);
      printf(GREEN"=>1.Employee Platform \n" RESET);
        printf(WHITE"2.Customer Platform\n" RESET);
          printf(RED"3.Exit Application"RESET);
      break;
    case '2':
      choice = 2;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n"RESET);
      printf(WHITE"What do you wanna do? \nPress number keys to select between options and then press Enter\n"RESET);
      printf(WHITE"  1.Employee Platform \n"RESET);
        printf(GREEN"=>2.Customer Platform\n"RESET);
          printf(RED"3.Exit Application"RESET);
      break;
    case '3':
      choice = 3;
      printf("\e[1;1H\e[2J");
      printf(BOLD CYAN"-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n"RESET);
      printf(WHITE"What do you wanna do? \nPress number keys to select between options and then press Enter\n"RESET);
      printf(WHITE"  1.Employee Platform \n"RESET);
       printf(WHITE"2.Customer Platform\n" RESET);
       printf(RED"=>3.Exit Application"RESET);
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
      printf(BOLD CYAN"-*-*-*-*- LAXMI CHIT FUND -*-*-*-*-\n"RESET);
      printf(WHITE"What do you wanna do? \nPress number keys to select between options and then press Enter\n"RESET);
      printf("  1.Employee Platform \n  2.Customer Platform\n  3.Exit Application");
      break;
    }
  }
}