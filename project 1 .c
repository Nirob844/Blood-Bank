#include <windows.h>
#include<stdio.h>
#include<time.h>


void Password();
void mainMenu(void);
void addNewDonors(void);
void viewListOfDonor(void);
void searchDonor(void);
void gotoxy (int x, int y);


COORD coord = {0, 0}; // sets coordinates to 0,0
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char password[10]={"project"};


int main()

{
      Password();
      getch();
   return 0;

}
void mainMenu()
{
    system("cls");
    system("COLOR F2");
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add New Donors ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View List Of Donors ");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Donors");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Close Application");
    gotoxy(20,19);
    printf("------------------------------------------");
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        addNewDonors();
        break;
    case '2':
        viewListOfDonor();
        break;
        case '3':
        searchDonor();
        break;
        case '4':
        {
        system("cls");
        gotoxy(16,3);
        printf("Thanks for using the Program..");
        gotoxy(10,7);
        exit(0);
        }
        default:
        {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
        mainMenu();
        }

    }
}


void Password(void) //for password option
{

   system("cls");
   char ch,pass[10];
   int i=0;
   gotoxy(10,4);
   printf("******************** Password Protected ********************");
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	mainMenu();
   }
   else
   {
	 gotoxy(15,16);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 Password();
   }
}
void addNewDonors(void)    //funtion that add books
{
    system("cls");
    printf("This is add new donors");
}
void viewListOfDonor(void)    //funtion that add books
{
    system("cls");
    printf("This is view list of donors");
}
void searchDonor(void)    //funtion that add books
{
    system("cls");
    printf("This is search donors");
}

