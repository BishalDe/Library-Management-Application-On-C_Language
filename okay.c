/* 
    LIBRARY MANAGEMENT SYSTEM 
         On C Language
           SRMIST
  Programming For Problem Solving
                -RA2111026010231
                -Bishal De
                -CSE with AI And ML
*/

// HEADER FILES ---------------------------
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <direct.h>
#include <time.h>
#include <windows.h>

// GLOBAL VARIABLES ----------------------
FILE *file1, *file2;                                              // File Pointer variable
char querybook, findbook, password[50] = "z", username[50] = "z"; //User Credentials
COORD coordinates = {0, 0};

struct date
{
    int date, month, year;
} issued, duedate;

struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct date issued;
    struct date duedate;
} booklist;

// FUNCTION PROTOTYPE DECLARATION -------------
void CONSOLE_XY(int x, int y);
void LOADER();
void PASSWORD();
void MAINPROGRAM();
void ADDBOOKS();
int checkid(int t);
void AVAILABLE_BOOKS();
void EDITBOOK();
void SEARCH_BOOKS();

// MAIN FUNCTION ----------------------------------------
int main()
{
    MAINPROGRAM();
    return 0;
}

void CONSOLE_XY(int x, int y)
{
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void LOADER()
{
    int loader;
    CONSOLE_XY(15, 12);
    printf("LOADING........");
    printf("\n\n");
    CONSOLE_XY(15, 13);
    for (loader = 1; loader < 30; loader++)
    {
        Sleep(100);
        printf("%c", 222);
    }
}

void PASSWORD()
{
    system("cls");
    char ch, pass[50], user[50];
    int i = 0, j;
    CONSOLE_XY(10, 4);
    for (j = 0; j < 20; j++)
    {
        Sleep(40);
        printf("%c", 223);
    }
    printf("\033[0;34m");
    printf("%s", "\033[0;33m ENTER CREDENTIALS \033[0;37m");
    for (j = 0; j < 20; j++)
    {
        Sleep(40);
        printf("%c", 223);
    }
    CONSOLE_XY(10, 16);
    printf("\033[0;37m");
    for (j = 0; j < 60; j++)
    {
        printf("%c", 223);
    }
    CONSOLE_XY(15, 7);
    printf("\033[0;34mEnter Username :-> \033[0;37m");
    scanf("%s", user);
    CONSOLE_XY(15, 8);
    printf("\033[0;34mEnter Password :-> \033[0;37m");
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
    if (strcmp(user, username) == 0)
    {
        if (strcmp(pass, password) == 0)
        {
            CONSOLE_XY(15, 11);
            printf("\aPASSWORD MATCHED");
            Sleep(50);
            CONSOLE_XY(17, 12);
            LOADER();
            MAINPROGRAM();
        }
        else
        {
            CONSOLE_XY(15, 11);
            printf("\a \033[0;31mWarning!! Incorrect Password \033[0;37m");
            getch();
            PASSWORD();
        }
    }
    else
    {
        CONSOLE_XY(15, 11);
        printf("\a\033[0;31mWarning!! Incorrect Username\033[0;3m");
        getch();
        PASSWORD();
    }
}

void MAINPROGRAM()
{
    system("cls");
    int i;
    printf("\n\n\n");
    printf("\t\t\033[0;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 1. Add Books   \n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 2. Delete books\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 3. Search Books\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 4. Issue Books\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 5. View Book list\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 6. Edit Book's Record\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 7. Close Application\n\n");
    printf("\t\t\033[0;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> XxxxxxxxxxxxxxxxX <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t\033[0;35mEnter your choice : \033[0;37m");
    switch (getch())
    {
    case '1':
        ADDBOOKS();
        break;
    case '2':
        //DELETEBOOK();
        break;
    case '3':
        SEARCH_BOOKS();
        break;
    case '4':
        //ISSUE();
        break;
    case '5':
        AVAILABLE_BOOKS();
        break;
    case '6':
        EDITBOOK();
        break;
    case '7':
    {
        system("cls");
        printf("\033[0;35m");
        CONSOLE_XY(10, 5);
        printf("\t\t\t***************************************************\n");
        CONSOLE_XY(10, 6);
        printf("\t\t\t*\033[0;33m             LIBRARY MANAGEMENT SYSTEM           \033[0;35m*\n");
        CONSOLE_XY(10, 7);
        printf("\t\t\t*\033[0;37m               Project On C Language             \033[0;35m*\n");
        CONSOLE_XY(10, 8);
        printf("\t\t\t*                                                 \033[0;35m*\n");
        CONSOLE_XY(10, 9);
        printf("\t\t\t*                                                 \033[0;35m*\n");
        CONSOLE_XY(10, 10);
        printf("\t\t\t* \033[0;33m                                by- Bishal De   \033[0;35m*\n");
        CONSOLE_XY(10, 11);
        printf("\t\t\t***************************************************\n");
        CONSOLE_XY(10, 12);
        Sleep(3000);
        exit(0);
    }
    default:
    {
        CONSOLE_XY(10, 23);
        printf("\aWrong Entry...!");
        if (getch())
            MAINPROGRAM();
    }
    }
}

void ADDBOOKS()
{   system("cls");
    int t;
    printf("\t\t\033[0;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ADD BOOK  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t\t\033[0;33m**** ENTER INFORMATION HERE ****\n");
    printf("\t\t\t\033[0;37mBook ID:- \033[0;32m");
    scanf("%d", &t);
    file1 = fopen("Books.dat", "ab+");
    if (checkid(t) == 0)
    {
        printf("\t\t\t\a\033[0;31mThe book id already exists\a\n");
        getch();
        MAINPROGRAM();
    }
    booklist.id = t;
    printf("\t\t\t\033[0;37mBook Title:- \033[0;32m");
    scanf("%s", &booklist.name);
    printf("\t\t\t\033[0;37mAuthor:- \033[0;32m");
    scanf("%s", &booklist.Author);
    printf("\t\t\t\033[0;37mQuantity:- \033[0;32m");
    scanf("%d", &booklist.quantity);
    printf("\t\t\t\033[0;37mPrice:- \033[0;32m");
    scanf("%f", &booklist.Price);
    printf("\t\t\t\033[0;37mRack No:- \033[0;32m");
    scanf("%d", &booklist.rackno);
    fseek(file1, 0, SEEK_END);
    fwrite(&booklist, sizeof(booklist), 1, file1);
    fclose(file1);
    printf("\t\t\t\033[0;35mThe record is sucessfully saved\n");
    printf("\t\t\t\033[0;35mSave any more?\033[0;33m(Y / N):\033[0;35m");
    if (getch() == 'n')
        MAINPROGRAM();
    else
        system("cls");
    ADDBOOKS();
}

int checkid(int t) 
{
    rewind(file1);
    while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        if (booklist.id == t)
            return 0;
    return 1;
}

void AVAILABLE_BOOKS()
{
    int total = 0,money=0, j = 6;
    system("cls");
    printf("\033[0;33m\n\n\t          - - - - - - - - - - - - - - - - - - - - - AVAILABLE BOOKS - - - - - - - - - - - - - - - - - - - -");
    CONSOLE_XY(20, 5);
    printf("\033[0;34m              ID     BOOK NAME     AUTHOR       QTY     PRICE     RackNo \033[0;37m");
    file1 = fopen("Books.dat", "rb");
    while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
    {
        CONSOLE_XY(34, j);
        printf("%d", booklist.id);
        CONSOLE_XY(41, j);
        printf("%s", booklist.name);
        CONSOLE_XY(54, j);
        printf("%s", booklist.Author);
        CONSOLE_XY(68, j);
        printf("%d", booklist.quantity);
        CONSOLE_XY(75, j);
        printf("%.2f", booklist.Price);
        CONSOLE_XY(88, j);
        printf("%d", booklist.rackno);
        printf("\n\n");
        j++;
        money+=booklist.Price*booklist.quantity;
        total = total + booklist.quantity;
    }
    CONSOLE_XY(20, j + 5);
    printf("\033[0;31m Total Books = \033[0;37m%d\n", total);
    CONSOLE_XY(20, j + 6);
    printf("\033[0;31m Total Cost Of Books = Rs \033[0;37m%d", money);
    fclose(file1);
    getch();
    MAINPROGRAM();
}

void EDITBOOK()
{
    system("cls");
    int c = 0;
    int d, e;
    printf("\t\t\033[0;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> EDIT BOOK  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    char another = 'y';
    while (another == 'y' || another == 'Y')
    {
        int okay = 0;
        printf("\t\t\t\033[0;32mEnter The Book Id To Be Edited :- \033[0;37m");
        scanf("%d", &d);
        file1 = fopen("Books.dat", "rb+");
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (booklist.id == d)
            {
                int j = 4;
                okay = 1;
                printf("\t\t\t\033[0;34m          ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo \033[0;37m\n");
                CONSOLE_XY(34, j);               
                printf("%d", booklist.id);
                CONSOLE_XY(41, j);
                printf("%s", booklist.name);
                CONSOLE_XY(54, j);
                printf("%s", booklist.Author);
                CONSOLE_XY(68, j);
                printf("%d", booklist.quantity);
                CONSOLE_XY(75, j);
                printf("%.2f", booklist.Price);
                CONSOLE_XY(88, j);
                printf("%d", booklist.rackno);
                printf("\n\n");
                printf("\n\t\t\t\033[0;36mThe Book Is Available..!\n");
                printf("\t\t\t\t\033[0;32mThe Book ID : \033[0;37m%d\n", booklist.id);
                printf("\t\t\t\t\033[0;32mEnter new name : \033[0;37m");
                scanf("%s", booklist.name);
                printf("\t\t\t\t\033[0;32mEnter new Author: \033[0;37m");
                scanf("%s", booklist.Author);
                printf("\t\t\t\t\033[0;32mEnter new quantity : \033[0;37m");
                scanf("%d", &booklist.quantity);
                printf("\t\t\t\t\033[0;32mEnter new price : \033[0;37m");
                scanf("%f", &booklist.Price);
                printf("\t\t\t\t\033[0;32mEnter new rackno : \033[0;37m");
                scanf("%d", &booklist.rackno);
                printf("\t\t\t\t\033[0;31mThe record is modified");
                fseek(file1, ftell(file1) - sizeof(booklist), 0);
                fwrite(&booklist, sizeof(booklist), 1, file1);
                fclose(file1);
                c = 1;
            }
        }
        if (c == 0)
        {
            printf("\t\t\t\t\033[0;31m\n\aNo record found\n");
        }
        printf("\n\n");
        printf("\t\t\t\t\033[0;355mModify another Record?(Y/N)");
        fflush(stdin);
        another = getch();
        if (another == 'y' || another == 'Y')
            system("cls");
    }
    MAINPROGRAM();
}

void SEARCH_BOOKS()
{
    system("cls");
    int d;
    CONSOLE_XY(20, 8);
    printf("\033[0;33m################################## SEARCH BOOK ##################################");
    CONSOLE_XY(20, 12);
    printf("\033[0;34m1. Search By ID");
    CONSOLE_XY(20, 13);
    printf("2. Search By Name");
    CONSOLE_XY(20, 15);
    printf("\033[0;37mEnter Your Choice : ");
    file1 = fopen("Books.dat", "rb+");
    rewind(file1);
    switch (getch())
    {
    case '1':
    {
        system("cls");
        CONSOLE_XY(25, 3);
        printf("\033[0;33m ************** Search Books By ID **************");
        CONSOLE_XY(20, 5);
        printf("\033[0;37mEnter the book id : \033[0;35m");
        scanf("%d", &d);
        CONSOLE_XY(20, 7);
        printf("Searching........");
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (booklist.id == d)
            {
                Sleep(2);
                CONSOLE_XY(20, 7);
                printf("The Book is available");
                CONSOLE_XY(20, 9);
                printf("\033[0;37mID :-> \033[0;35m%d", booklist.id);
                CONSOLE_XY(20, 10);
                printf("\033[0;37mName :-> \033[0;35m%s", booklist.name);
                CONSOLE_XY(20, 11);
                printf("\033[0;37mAuthor :-> \033[0;35m%s ", booklist.Author);
                CONSOLE_XY(20, 12);
                printf("\033[0;37mQantity :-> \033[0;35m%d ", booklist.quantity);
                CONSOLE_XY(20, 13);
                printf("\033[0;37mPrice :-> \033[0;35mRs.%.2f", booklist.Price);
                CONSOLE_XY(20, 14);
                printf("\033[0;37mRack No :-> \033[0;35m%d ", booklist.rackno);
                querybook = 't';
            }
        }
        if (querybook != 't')
        {
            CONSOLE_XY(22, 9);
            printf("\aNo Record Found");
        }
        CONSOLE_XY(20, 17);
        printf("\033[0;37mTry another search?(Y/N)");
        if (getch() == 'y')
            SEARCH_BOOKS();
        else
            MAINPROGRAM();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        CONSOLE_XY(25, 4);
        printf("\033[0;33m ************** Search Books By Name **************");
        CONSOLE_XY(20, 5);
        printf("\033[0;37mEnter Book Name : \033[0;35m");
        scanf("%s", s);
        int d = 0;
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (strcmp(booklist.name, (s)) == 0)
            {
                CONSOLE_XY(20, 7);
                printf("The Book is available");
                CONSOLE_XY(20, 9);
                printf("\033[0;37mID :-> \033[0;35m%d", booklist.id);
                CONSOLE_XY(20, 10);
                printf("\033[0;37mName :-> \033[0;35m%s", booklist.name);
                CONSOLE_XY(20, 11);
                printf("\033[0;37mAuthor :-> \033[0;35m%s ", booklist.Author);
                CONSOLE_XY(20, 12);
                printf("\033[0;37mQantity :-> \033[0;35m%d ", booklist.quantity);
                CONSOLE_XY(20, 13);
                printf("\033[0;37mPrice :-> \033[0;35mRs.%.2f", booklist.Price);
                CONSOLE_XY(20, 14);
                printf("\033[0;37mRack No :-> \033[0;35m%d ", booklist.rackno);
                d++;
            }
        }
        if (d == 0)
        {
            CONSOLE_XY(22, 9);
            printf("\aNo Record Found");
        }
        CONSOLE_XY(20, 17);
        printf("\033[0;37mTry another search?(Y/N)");
        if (getch() == 'y')
            SEARCH_BOOKS();
        else
            MAINPROGRAM();
        break;
    }
    default:
        getch();
        SEARCH_BOOKS();
    }
    fclose(file1);
}














