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


FILE *fp;
int s;

struct donorsList
{
    int id;
    char name[20];
    char bloodGroup[20];
    int numberOfBloodD;
    int dd,mm,yy;
    long long int phNumber;
    char email[30];
    char *cat;
};
struct donorsList a;


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
    gotoxy(20,19);
    printf("------------------------------------------");
    gotoxy(20,21);
    printf("Enter your choice:");
        gotoxy(38,21);
 scanf("%d",&s);
    if(s==4)
    mainMenu() ;

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
void addNewDonors(void)    //funtion that add donors
{
    system("cls");
    int i;

    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is sucessfully saved");
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
        mainMenu();
    else
        system("cls");
        addNewDonors();
    }
}
int getdata()
{
    int storeId;
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2");gotoxy(66,5);printf("\xB2");
    gotoxy(20,6);
    printf("\xB2");gotoxy(66,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(66,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(66,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(66,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(66,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(66,11);printf("\xB2");
    gotoxy(20,12);
    printf("\xB2");gotoxy(66,12);printf("\xB2");
    gotoxy(20,13);
    printf("\xB2");gotoxy(66,13);printf("\xB2");
    gotoxy(20,14);
    printf("\xB2");gotoxy(66,14);printf("\xB2");
    gotoxy(20,18);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,5);
    printf("Information of donors:");
    gotoxy(31,5);
    gotoxy(21,6);
    printf("Donar Id ID:\t");
    gotoxy(33,6);
    scanf("%d",&storeId);
    if(checkid(storeId) == 0)
    {
        gotoxy(21,13);
        printf("\aThe book id already exists\a");
        getch();
        mainMenu();
        return 0;
    }
    a.id=storeId;
    gotoxy(21,7);
    printf("Donor Name:");gotoxy(33,7);
    scanf("%s",a.name);
    gotoxy(21,8);
    printf("Blood Group:");gotoxy(34,8);
    scanf("%s",a.bloodGroup);
    gotoxy(21,9);
    printf("Number Of Blood Donation:");gotoxy(46,9);
    scanf("%d",&a.numberOfBloodD);
  /*  gotoxy(21,10);
    printf("Last Date of Blood Donation:");gotoxy(50,10);
    scanf("%d ",&a.dd);
    gotoxy(51,10);
    printf("/");
    gotoxy(52,10);
    scanf("%d ",&a.mm);
    gotoxy(53,10);
    printf("/");
    gotoxy(54,10);
    scanf("%d ",&a.yy);*/
    gotoxy(21,11);
    printf("Enter Phone number:");gotoxy(40,11);
    scanf("%lld",&a.phNumber);
    gotoxy(21,12);
    printf("Enter your email:");gotoxy(39,12);
    scanf("%s",&a.email);
    return 1;
}
int checkid(int storeId)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==storeId)
    return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
void viewListOfDonor(void)    //funtion that add books
{
    system("cls");
    printf("This is view list of donors");
    getch();
    mainMenu() ;
}
void searchDonor(void)    //funtion that add books
{
    system("cls");
    printf("This is search donors");
    getch();
    mainMenu() ;
}

