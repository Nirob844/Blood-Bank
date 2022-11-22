#include <windows.h>
#include <stdio.h>
#include <time.h>

void mainMenu(void);
void AdminPassword();
void userPassword(void);
void Password();
void adminMenu(void);
void userMenu(void);
void donarRegistration(void);
void viewListOfDonor(void);
void searchDonor(void);
void editDonar(void);
void deleteDonors(void);
void bloodRequest(void);
void viewListOfRequestBlood(void);
void approveBloodRequest(void);
void gotoxy(int x, int y);

COORD coord = {0, 0}; // sets coordinates to 0,0
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char apassword[10] = {"admin"};
char upassword[10] = {"user"};
char password[10] = {"nirob"};
char findDonar;

FILE *fp, *ft, *fr, *fa;
int s;

struct donorsList
{
    int id;
    char name[20];
    char bloodGroup[20];
    int numberOfBloodD;
    char date[20];
    long long int phNumber;
    char email[30];
    char address[30];
    char *cat;
};
struct donorsList a;

int main()

{
    mainMenu();
    getch();
    return 0;
}
void mainMenu()
{
    system("cls");
    // system("COLOR F2");
    int i;
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Admin ");
    gotoxy(20, 7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. User ");
    gotoxy(20, 9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Close Application");
    gotoxy(20, 19);
    printf("------------------------------------------");
    gotoxy(20, 21);
    printf("Enter your choice:");
    gotoxy(38, 21);

    switch (getch())
    {
    case '1':
        adminPassword();
        break;
    case '2':
        userPassword();
        break;
    case '3':
    {
        system("cls");
        gotoxy(16, 3);
        printf("Thanks for using the Program..");
        gotoxy(10, 7);
        exit(0);
    }
    default:
    {
        gotoxy(10, 23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if (getch())
            mainMenu();
    }
    }
}
void adminPassword(void) // for password option
{

    system("cls");
    char ch, pass[10];
    int i = 0;
    gotoxy(10, 4);
    printf("******************** Password Protected ********************");
    gotoxy(15, 7);
    printf("Enter Password:");

    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, apassword) == 0)
    {

        gotoxy(15, 9);
        printf("Password match");
        gotoxy(17, 10);
        printf("Press any key to countinue.....");
        getch();
        adminMenu();
    }
    else
    {
        gotoxy(15, 16);
        printf("\aWarning!! Incorrect Password");
        getch();
        adminPassword();
    }
}
void userPassword(void) // for password option
{

    system("cls");
    char ch, pass[10];
    int i = 0;
    gotoxy(10, 4);
    printf("******************** Password Protected ********************");
    gotoxy(15, 7);
    printf("Enter Password:");

    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, upassword) == 0)
    {

        gotoxy(15, 9);
        printf("Password match");
        gotoxy(17, 10);
        printf("Press any key to countinue.....");
        getch();
        userMenu();
    }
    else
    {
        gotoxy(15, 16);
        printf("\aWarning!! Incorrect Password");
        getch();
        userPassword();
    }
}
void adminMenu()
{
    system("cls");
    // system("COLOR F2");
    int i;
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADMIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Donar Registration ");
    gotoxy(20, 7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View List Of Donors ");
    gotoxy(20, 9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Donors");
    gotoxy(20, 11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Edit Donar");
    gotoxy(20, 13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Delete Donar");
    gotoxy(20, 15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. View Blood Request");
    gotoxy(20, 17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Approve Blood Request");
    gotoxy(20, 19);
    printf("\xDB\xDB\xDB\xDB\xB2 8. mainMenu Application");
    gotoxy(20, 21);
    printf("------------------------------------------");
    gotoxy(20, 23);
    printf("Enter your choice:");
    gotoxy(38, 23);

    switch (getch())
    {
    case '1':
        donarRegistration();
        break;
    case '2':
        viewListOfDonor();
        break;
    case '3':
        searchDonor();
        break;
    case '4':
        editDonar();
        break;
    case '5':
        deleteDonors();
        break;
    case '6':
        viewListOfRequestBlood();
        break;
    case '7':
        approveBloodRequest();
        break;
    case '8':
        mainMenu();
        break;

    default:
    {
        gotoxy(10, 23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if (getch())
            adminMenu();
    }
    }
}

void userMenu()
{
    system("cls");
    // system("COLOR F2");
    int i;
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 USER MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Donar Registration ");
    gotoxy(20, 7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Donar available Now ");
    gotoxy(20, 9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Request Blood ");
    gotoxy(20, 11);
    printf("\xDB\xDB\xDB\xDB\xB2 4.Main Menu Application");
    gotoxy(20, 13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Close Application");
    gotoxy(20, 19);
    printf("------------------------------------------");
    gotoxy(20, 21);
    printf("Enter your choice:");
    gotoxy(38, 21);

    switch (getch())
    {
    case '1':
        donarRegistration();
        break;
    case '2':
        viewListOfDonor();
    case '3':
        bloodRequest();
        break;
    case '4':
        mainMenu();
        break;
    case '5':
    {
        system("cls");
        gotoxy(16, 3);
        printf("Thanks for using the Program..");
        gotoxy(10, 7);
        exit(0);
    }
    default:
    {
        gotoxy(10, 23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if (getch())
            userMenu();
    }
    }
}

void donarRegistration(void) // funtion that add donors
{
    system("cls");
    int i;
    system("cls");
    fp = fopen("Donar.dat", "ab+");
    if (getdata() == 1)
    {
        fseek(fp, 0, SEEK_END);
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
        gotoxy(21, 14);
        printf("The record is sucessfully saved");
        gotoxy(21, 15);
        printf("Save any more?(Y / N):");
        if (getch() == 'n')
            mainMenu();
        else
            system("cls");
        donarRegistration();
    }
}
int getdata()
{
    int t;
    gotoxy(20, 3);
    printf("Enter the Information Below");
    gotoxy(20, 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xB2");
    gotoxy(66, 5);
    printf("\xB2");
    gotoxy(20, 6);
    printf("\xB2");
    gotoxy(66, 6);
    printf("\xB2");
    gotoxy(20, 7);
    printf("\xB2");
    gotoxy(66, 7);
    printf("\xB2");
    gotoxy(20, 8);
    printf("\xB2");
    gotoxy(66, 8);
    printf("\xB2");
    gotoxy(20, 9);
    printf("\xB2");
    gotoxy(66, 9);
    printf("\xB2");
    gotoxy(20, 10);
    printf("\xB2");
    gotoxy(66, 10);
    printf("\xB2");
    gotoxy(20, 11);
    printf("\xB2");
    gotoxy(66, 11);
    printf("\xB2");
    gotoxy(20, 12);
    printf("\xB2");
    gotoxy(66, 12);
    printf("\xB2");
    gotoxy(20, 13);
    printf("\xB2");
    gotoxy(66, 13);
    printf("\xB2");
    gotoxy(20, 14);
    printf("\xB2");
    gotoxy(66, 14);
    printf("\xB2");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(26, 5);
    printf("Information of donors:");
    gotoxy(31, 5);
    gotoxy(22, 6);
    printf("Donar  ID:\t");
    gotoxy(33, 6);
    scanf("%d", &t);
    if (checkid(t) == 0)
    {
        gotoxy(21, 13);
        printf("\aThe donor id already exists\a");
        getch();
        adminMenu();
        return 0;
    }
    a.id = t;
    gotoxy(22, 7);
    printf("Donor Name:");
    gotoxy(33, 7);
    scanf("%s", a.name);
    gotoxy(22, 8);
    printf("Blood Group:");
    gotoxy(34, 8);
    scanf("%s", a.bloodGroup);
    gotoxy(22, 9);
    printf("Number Of Blood Donation:");
    gotoxy(47, 9);
    scanf("%d", &a.numberOfBloodD);
    gotoxy(22, 10);
    printf("Last Date of Blood Donation:");
    gotoxy(50, 10);
    scanf("%s", a.date);
    gotoxy(22, 11);
    printf("Enter Phone number:");
    gotoxy(41, 11);
    scanf("%lld", &a.phNumber);
    gotoxy(22, 12);
    printf("Enter your email:");
    gotoxy(39, 12);
    scanf("%s", &a.email);
    return 1;
}
int checkid(int t) // check whether the donor is exist in list or not
{
    rewind(fp);
    while (fread(&a, sizeof(a), 1, fp) == 1)
        if (a.id == t)
            return 0; // returns 0 if donor exits
    return 1;         // return 1 if it not
}

void viewListOfDonor(void) // funtion that view donor
{
    int i = 0, j;
    system("cls");
    gotoxy(1, 1);
    printf("*********************************Donor List*****************************");
    gotoxy(2, 2);
    printf("     ID    DONAR NAME  BLOOD GROUP  N.OF DONATION  Last Date  PH.NUMBER    EMAIL ");
    j = 4;
    fp = fopen("Donar.dat", "rb");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        gotoxy(3, j);
        gotoxy(8, j);
        printf("%d", a.id);
        gotoxy(15, j);
        printf("%s", a.name);
        gotoxy(27, j);
        printf("%s", a.bloodGroup);
        gotoxy(42, j);
        printf("%d", a.numberOfBloodD);
        gotoxy(54, j);
        printf("%s", a.date);
        gotoxy(64, j);
        printf("%lld", a.phNumber);
        gotoxy(77, j);
        printf("%s", a.email);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(35, 25);
    returnFunction();
}
void returnFunction(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if (getch() == 13) // allow only use of enter
        mainMenu();
    else
        goto a;
}
void searchDonor(void) // funtion that add donors
{
    system("cls");
    int d;
    printf("*****************************Search donors*********************************");
    gotoxy(20, 10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20, 14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy(15, 20);
    printf("Enter Your Choice");
    fp = fopen("Donar.dat", "rb+"); // open file for reading propose
    rewind(fp);                     // move pointer at the begining of file
    switch (getch())
    {
    case '1':
    {
        system("cls");
        gotoxy(25, 4);
        printf("****Search Donors By Id****");
        gotoxy(20, 5);
        printf("Enter the Donar id:");
        scanf("%d", &d);
        gotoxy(20, 7);
        printf("Searching........");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                gotoxy(20, 7);
                printf("The Donar is available");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(57, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Name:%s", a.name);
                gotoxy(57, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Blood Group:%s ", a.bloodGroup);
                gotoxy(57, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Number Of Blood Donation:%d ", a.numberOfBloodD);
                gotoxy(57, 12);
                printf("\xB2");
                gotoxy(57, 11);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Last Date Donation:%s ", a.date);
                gotoxy(57, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Phone Number:%.lld ", a.phNumber);
                gotoxy(57, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2 Email::%s ", a.email);
                gotoxy(57, 15);
                printf("\xB2");
                gotoxy(20, 16);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                findDonar = 't';
            }
        }
        if (findDonar != 't') // checks whether conditiion enters inside loop or not
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aNo Record Found");
        }
        gotoxy(20, 17);
        printf("Try another search?(Y/N)");
        if (getch() == 'y')
            searchDonor();
        else
            adminMenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        gotoxy(25, 4);
        printf("****Search donors By Name****");
        gotoxy(20, 5);
        printf("Enter Donor Name:");
        scanf("%s", s);
        int d = 0;
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.name, (s)) == 0) // checks whether a.name is equal to s or not
            {
                gotoxy(20, 7);
                printf("The donor is available");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(57, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Name:%s", a.name);
                gotoxy(57, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Blood Group:%s ", a.bloodGroup);
                gotoxy(57, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Number Of Blood Donation:%d ", a.numberOfBloodD);
                gotoxy(57, 12);
                printf("\xB2");
                gotoxy(57, 11);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Last Date Donation:%s ", a.date);
                gotoxy(57, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Phone Number:%.lld ", a.phNumber);
                gotoxy(57, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2 Email::%s ", a.email);
                gotoxy(57, 15);
                printf("\xB2");
                gotoxy(20, 16);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                d++;
            }
        }
        if (d == 0)
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aNo Record Found");
        }
        gotoxy(20, 17);
        printf("Try another search?(Y/N)");
        if (getch() == 'y')
            searchDonor();
        else
            adminMenu();
        break;
    }
    default:
        getch();
        searchDonor();
    }
    fclose(fp);
}
void editDonar(void) // funtion that add Donars
{

    system("cls");
    int c = 0;
    int d, e;
    gotoxy(20, 4);
    printf("****Edit Donors Section****");
    char another = 'y';
    while (another == 'y')
    {
        system("cls");
        gotoxy(15, 6);
        printf("Enter Donar Id to be edited:");
        scanf("%d", &d);
        fp = fopen("Donar.dat", "rb+");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (checkid(d) == 0)
            {
                gotoxy(15, 7);
                printf("The donar is availble");
                gotoxy(15, 8);
                printf("The Donar ID:%d", a.id);
                gotoxy(15, 9);
                printf("Enter new name:");
                scanf("%s", a.name);
                gotoxy(15, 10);
                printf("Enter new blood group:");
                scanf("%s", a.bloodGroup);
                gotoxy(15, 11);
                printf("Enter new n.of blood donation:");
                scanf("%d", &a.numberOfBloodD);
                gotoxy(15, 12);
                printf("Enter last date of blood donation:");
                scanf("%s", &a.date);
                gotoxy(15, 13);
                printf("Enter new phone number:");
                scanf("%lld", &a.phNumber);
                gotoxy(15, 14);
                printf("enter new email:");
                gotoxy(31, 14);
                scanf("%s", &a.email);
                gotoxy(15, 15);
                printf("The record is modified");
                fseek(fp, ftell(fp) - sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, fp);
                fclose(fp);
                c = 1;
            }
            if (c == 0)
            {
                gotoxy(15, 9);
                printf("No record found");
            }
        }
        gotoxy(15, 16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another = getch();
    }
    returnFunction();
}
void deleteDonors(void) // funtion that delete donor
{
    system("cls");
    int d;
    char another = 'y';
    while (another == 'y') // infinite loop
    {
        system("cls");
        gotoxy(10, 5);
        printf("Enter the Donar ID to  delete:");
        scanf("%d", &d);
        fp = fopen("Donar.dat", "rb+");
        rewind(fp);
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {

                gotoxy(10, 7);
                printf("The Donor record is available");
                gotoxy(10, 8);
                printf("Donor name is %s", a.name);
                findDonar = 't';
            }
        }
        if (findDonar != 't')
        {
            gotoxy(10, 10);
            printf("No record is found modify the search");
            if (getch())
                adminMenu();
        }
        if (findDonar == 't')
        {
            gotoxy(10, 9);
            printf("Do you want to delete it?(Y/N):");
            if (getch() == 'y')
            {
                ft = fopen("test.dat", "wb+"); // temporary file for delete
                rewind(fp);
                while (fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (a.id != d)
                    {
                        fseek(ft, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, ft); // write all in tempory file except that
                    }                                 // we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("Donar.dat");
                rename("test.dat", "Donar.dat"); // copy all item from temporary file to fp except that
                fp = fopen("Donar.dat", "rb+");  // we want to delete
                if (findDonar == 't')
                {
                    gotoxy(10, 10);
                    printf("The record is sucessfully deleted");
                    gotoxy(10, 11);
                    printf("Delete another record?(Y/N)");
                }
            }
            else
                adminMenu();
            fflush(stdin);
            another = getch();
        }
    }
    gotoxy(10, 15);
    adminMenu();
}
void bloodRequest(void)
{
    system("cls");
    int i;
    system("cls");
    fr = fopen("request.dat", "ab+");
    gotoxy(20, 3);
    printf("Enter the Information Below");
    gotoxy(20, 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xB2");
    gotoxy(66, 5);
    printf("\xB2");
    gotoxy(20, 6);
    printf("\xB2");
    gotoxy(66, 6);
    printf("\xB2");
    gotoxy(20, 7);
    printf("\xB2");
    gotoxy(66, 7);
    printf("\xB2");
    gotoxy(20, 8);
    printf("\xB2");
    gotoxy(66, 8);
    printf("\xB2");
    gotoxy(20, 9);
    printf("\xB2");
    gotoxy(66, 9);
    printf("\xB2");
    gotoxy(20, 10);
    printf("\xB2");
    gotoxy(66, 10);
    printf("\xB2");
    gotoxy(20, 11);
    printf("\xB2");
    gotoxy(66, 11);
    printf("\xB2");
    gotoxy(20, 12);
    printf("\xB2");
    gotoxy(66, 12);
    printf("\xB2");
    gotoxy(20, 13);
    printf("\xB2");
    gotoxy(66, 13);
    printf("\xB2");
    gotoxy(20, 14);
    printf("\xB2");
    gotoxy(66, 14);
    printf("\xB2");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(26, 5);
    printf("Information of patient:");
    gotoxy(22, 7);
    printf("Patient Name:");
    gotoxy(35, 7);
    scanf("%s", a.name);
    gotoxy(22, 8);
    printf("Blood Group:");
    gotoxy(34, 8);
    scanf("%s", a.bloodGroup);
    gotoxy(22, 9);
    printf("Hospital Name:");
    gotoxy(36, 9);
    scanf("%s", &a.address);
    gotoxy(22, 10);
    printf("Required Date:");
    gotoxy(36, 10);
    scanf("%s", a.date);
    gotoxy(22, 11);
    printf("Enter contact number:");
    gotoxy(43, 11);
    scanf("%lld", &a.phNumber);
    gotoxy(22, 12);
    printf("Enter contact email:");
    gotoxy(42, 12);
    scanf("%s", &a.email);

    fseek(fr, 0, SEEK_END);
    fwrite(&a, sizeof(a), 1, fr);
    fclose(fr);
    gotoxy(21, 14);
    printf("The record is sucessfully saved");
    gotoxy(21, 15);
    printf("Save any more?(Y / N):");
    if (getch() == 'n')
        mainMenu();
    else
        system("cls");
    bloodRequest();
}
void viewListOfRequestBlood(void)
{
    int i = 0, j;
    system("cls");
    gotoxy(1, 1);
    printf("*********************************Blood Request List*****************************");
    gotoxy(2, 2);
    printf("    PATIENT NAME  BLOOD GROUP  HOSPITAL NAME  REQUIRED DATE  CONTACT NUMBER    EMAIL ");
    j = 4;
    fr = fopen("request.dat", "rb");
    while (fread(&a, sizeof(a), 1, fr) == 1)
    {
        gotoxy(3, j);
        gotoxy(10, j);
        printf("%s", a.name);
        gotoxy(25, j);
        printf("%s", a.bloodGroup);
        gotoxy(35, j);
        printf("%s", a.address);
        gotoxy(50, j);
        printf("%s", a.date);
        gotoxy(64, j);
        printf("%lld", a.phNumber);
        gotoxy(79, j);
        printf("%s", a.email);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(35, 25);
    returnFunction();
}
void approveBloodRequest(void)
{
    system("cls");
    int d = 0;
    char s[20];
    char another = 'y';
    while (another == 'y') // infinite loop
    {
        system("cls");
        gotoxy(10, 5);
        printf("Enter the patient Name to  Approve Request:");
        scanf("%s", &s);
        fr = fopen("request.dat", "rb+");
        rewind(fr);
        while (fread(&a, sizeof(a), 1, fr) == 1)
        {
            if (strcmp(a.name, (s)) == 0)
            {

                gotoxy(10, 7);
                printf("The patient request is available");
                gotoxy(10, 8);
                printf("patient blood group is %s", a.bloodGroup);
                d++;
            }
        }
        if (d == 0)
        {
            gotoxy(10, 10);
            printf("No record is found modify the search");
            if (getch())
                adminMenu();
        }
        if (strcmp(a.name, (s)) == 0)
        {
            gotoxy(10, 9);
            printf("Do you approve it?(Y/N):");
            if (getch() == 'y')
            {
                fa = fopen("approve.dat", "wb+"); // temporary file for delete
                rewind(fr);
                while (fread(&a, sizeof(a), 1, fr) == 1)
                {
                    if (strcmp(a.name, (s)) == 0)
                    {
                        fseek(fa, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, fa); // write all in tempory file except that
                    }                                 // we want to delete
                }
                fclose(fa);
                fclose(fr);
                remove("request.dat");
                rename("approve.dat", "request.dat"); // copy all item from temporary file to fp except that
                fr = fopen("request.dat", "rb+");     // we want to delete
                if (strcmp(a.name, (s)) == 0)
                {
                    gotoxy(10, 10);
                    printf("The record is sucessfully approve");
                    gotoxy(10, 11);
                    printf("approve another record?(Y/N)");
                }
            }
            else
                adminMenu();
            fflush(stdin);
            another = getch();
        }
    }
    gotoxy(10, 15);
    adminMenu();
}
