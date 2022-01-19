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
FILE *file1, *file2; // File Pointer variable
char querybook, findbook;
char password[50] = "5741", username[50] = "bishal"; //User Credentials
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
    int rackno;
    struct date issued;
    struct date duedate;
} booklist;

// FUNCTION PROTOTYPE DECLARATION -------------
void CONSOLE_XY(int x, int y);
void LOADER();
void PASSWORD();
void MAINPROGRAM();
void ADDBOOKS();
int CHECK_BOOK(int t);
void AVAILABLE_BOOKS();
void EDITBOOK();
void SEARCH_BOOKS();
void EXINTRO();
void DELETEBOOK();
void BOOK_ISSUE();

// MAIN FUNCTION ----------------------------------------
int main()
{
    EXINTRO();
    PASSWORD();
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
    printf("\033[0;37m");
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
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 2. Edit Book's Record\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 3. Issue Books\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 4. Search Books\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 5. View Book list\n");
    printf("\n");
    printf("\t\t\t\033[0;31m\xDB\xDB\xDB\xDB\xB2 \033[0;37m 6. Delete books\n");
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
        EDITBOOK();
        break;
    case '3':
        BOOK_ISSUE();
        break;
    case '4':
        SEARCH_BOOKS();
        break;
    case '5':
        AVAILABLE_BOOKS();
        break;
    case '6':
        DELETEBOOK();
        break;
    case '7':
    {
        EXINTRO();
        system("cls");
        printf("\033[0;37m");
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
{
    system("cls");
    int t;
    printf("\t\t\033[0;36m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ADD BOOK  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("\n\t\t\t\033[0;33m------ ENTER INFORMATION HERE ------\n");
    printf("\t\t\t\033[0;37mEnter BOOK ID -> \033[0;32m");
    scanf("%d", &t);
    file1 = fopen("Books.txt", "ab+");
    if (CHECK_BOOK(t) == 0)
    {
        printf("\t\t\t\a\033[0;31mThe book id already exists\a\n");
        getch();
        MAINPROGRAM();
    }
    booklist.id = t;
    printf("\t\t\t\033[0;37mEnter BOOK TITLE -> \033[0;32m");
    scanf("%s", &booklist.name);
    printf("\t\t\t\033[0;37mEnter AUTHOR'S NAME -> \033[0;32m");
    scanf("%s", &booklist.Author);
    printf("\t\t\t\033[0;37mEnter QUANTITY -> \033[0;32m");
    scanf("%d", &booklist.quantity);
    printf("\t\t\t\033[0;37mEnter PRICE Per BOOK -> \033[0;32m");
    scanf("%f", &booklist.Price);
    printf("\t\t\t\033[0;37mEnter The RACK NUMBER -> \033[0;32m");
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

int CHECK_BOOK(int t)
{
    rewind(file1);
    while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        if (booklist.id == t)
            return 0;
    return 1;
}

void AVAILABLE_BOOKS()
{
    int total = 0, money = 0, j = 6;
    system("cls");
    printf("\033[0;33m\n\n\t          - - - - - - - - - - - - - - - - - - - - - AVAILABLE BOOKS - - - - - - - - - - - - - - - - - - - -");
    CONSOLE_XY(20, 5);
    printf("\033[0;34m              ID     BOOK NAME     AUTHOR       QTY     PRICE     RackNo \033[0;37m");
    file1 = fopen("Books.txt", "r");
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
        money += booklist.Price * booklist.quantity;
        total = total + booklist.quantity;
    }
    CONSOLE_XY(20, j + 5);
    printf("\033[0;31m Total Books = \033[0;37m%d\n", total);
    CONSOLE_XY(20, j + 6);
    printf("\033[0;31m Total Cost Of Books = Rs \033[0;37m%d", money);
    fclose(file1);
    CONSOLE_XY(20, j + 8);
    printf("\033[0;33m Press Any Key....");
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
        file1 = fopen("Books.txt", "r+");
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (booklist.id == d)
            {
                int j = 5;
                okay = 1;
                printf("\n\t\t\t\033[0;34m          ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo \033[0;37m\n");
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
                printf("\t\t\t\t\033[0;32mEnter New TITLE : \033[0;37m");
                scanf("%s", booklist.name);
                printf("\t\t\t\t\033[0;32mEnter New AUTHOR'S NAME: \033[0;37m");
                scanf("%s", booklist.Author);
                printf("\t\t\t\t\033[0;32mEnter New QUANTITY : \033[0;37m");
                scanf("%d", &booklist.quantity);
                printf("\t\t\t\t\033[0;32mEnter New PRICE : \033[0;37m");
                scanf("%f", &booklist.Price);
                printf("\t\t\t\t\033[0;32mEnter New RACK NUMBER : \033[0;37m");
                scanf("%d", &booklist.rackno);
                printf("\n\t\t\t\t\033[0;31mThe record is modified");
                fseek(file1, ftell(file1) - sizeof(booklist), 0);
                fwrite(&booklist, sizeof(booklist), 1, file1);
                fclose(file1);
                c = 1;
            }
        }
        if (c == 0)
        {
            printf("");
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
    printf("\033[0;33m\n\t\t################################## SEARCH BOOK ##################################\n\n");
    printf("\033[0;34m\t\t\t1. Search By ID\n\n");
    printf("\t\t\t2. Search By Name\n\n");
    printf("\t\t\033[0;37mEnter Your Choice -> ");
    file1 = fopen("Books.txt", "r+");
    rewind(file1);
    switch (getch())
    {
    case '1':
    {
        system("cls");
        printf("\033[0;33m\t+++++++++++++++++++++++ Search Books By ID ++++++++++++++++++++++\n\n");
        printf("\033[0;37m\t\tEnter BOOK ID -> \033[0;35m");
        scanf("%d", &d);
        printf("\n\t\tSearching........\n\n");
        int flag = 1;
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (booklist.id == d)
            {
                Sleep(2);
                printf("\t\t\t\033[0;31mThe Book is available\n\n");
                printf("\t\t\t\033[0;37mID :-> \033[0;35m%d \n", booklist.id);
                printf("\t\t\t\033[0;37mName :-> \033[0;35m%s \n", booklist.name);
                printf("\t\t\t\033[0;37mAuthor :-> \033[0;35m%s  \n", booklist.Author);
                printf("\t\t\t\033[0;37mQuantity :-> \033[0;35m%d  \n", booklist.quantity);
                printf("\t\t\t\033[0;37mPrice :-> \033[0;35mRs.%.2f \n", booklist.Price);
                printf("\t\t\t\033[0;37mRack No :-> \033[0;35m%d  \n", booklist.rackno);
                flag = 0;
            }
        }
        if (flag != 0)
        {
            flag = 1;
            printf("\t\t\a\033[0;31mNo Record Found\n");
        }
        printf("\n\t\t\033[0;37mTry another search?\033[0;33m(Y/N)");
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
        printf("\t\033[0;33m +++++++++++++++++++++++++ Search Books By Name +++++++++++++++++++++++\n\n");
        printf("\t\t\033[0;37mEnter Book Name -> \033[0;35m");
        scanf("%s", s);
        int d = 1;
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (strcmp(booklist.name, (s)) == 0)
            {
                printf("\n\t\t\033[0;31mThe Book is available\n\n");
                printf("\t\t\t\033[0;37mID :-> \033[0;35m%d \n", booklist.id);
                printf("\t\t\t\033[0;37mName :-> \033[0;35m%s \n", booklist.name);
                printf("\t\t\t\033[0;37mAuthor :-> \033[0;35m%s  \n", booklist.Author);
                printf("\t\t\t\033[0;37mQuantity :-> \033[0;35m%d  \n", booklist.quantity);
                printf("\t\t\t\033[0;37mPrice :-> \033[0;35mRs.%.2f \n", booklist.Price);
                printf("\t\t\t\033[0;37mRack No :-> \033[0;35m%d  \n", booklist.rackno);
                d = 0;
                break;
            }
        }
        if (d != 0)
        {
            d = 1;
            printf("\n\t\t\a\033[0;31mNo Record Found\n");
        }
        printf("\n\t\t\033[0;37mTry another search?\033[0;33m(Y/N)");
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

void EXINTRO()
{
    system("cls");
    printf("\033[0;35m");
    printf("\t\t\t***************************************************\n");
    printf("\t\t\t*\033[0;33m                       SRMIST                    \033[0;35m*\n");
    printf("\t\t\t*\033[0;31m        Programming For Problem Solving E-Lab    \033[0;35m*\n");
    printf("\t\t\t*\033[0;33m             LIBRARY MANAGEMENT SYSTEM           \033[0;35m*\n");
    printf("\t\t\t*\033[0;37m               Project On C Language             \033[0;35m*\n");
    printf("\t\t\t*                                                 \033[0;35m*\n");
    printf("\t\t\t*                                                 \033[0;35m*\n");
    printf("\t\t\t* \033[0;33m                                by- Bishal De   \033[0;35m*\n");
    printf("\t\t\t***************************************************\n");
    Sleep(2000);
}

void DELETEBOOK()
{
    int i, j = 5, flag = 0;
    char c;
    system("cls");
    printf("\t\t******************** DELETE SECTION********************\n\n");
    printf("\t\t\tEnter Book ID :-> ");
    scanf("%d", &i);
    file1 = fopen("Books.txt", "r+");
    while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
    {
        if (booklist.id == i)
        {
            CONSOLE_XY(34, j - 1);
            printf("\033[0;34mID     BOOK NAME     AUTHOR       QTY     PRICE     RackNo \033[0;37m");
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
            flag = 1;
            printf("\t\t\t\033[0;33mDo you want to delete it?\033[0;37m(Y/N):");
            c = getch();
            if (c == 'y' || c == 'Y')
            {
                file2 = fopen("temporary.txt", "w+");
                rewind(file1);
                while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
                {
                    if (booklist.id != i)
                    {
                        fseek(file2, 0, SEEK_CUR);
                        fwrite(&booklist, sizeof(booklist), 1, file2);
                    }
                }
                fclose(file1);
                fclose(file2);
                remove("Books.txt");
                rename("temporary.txt", "Books.txt");
                file1 = fopen("Books.txt", "rb+");
                printf("\n\t\t\t\033[0;31mThe record is sucessfully deleted\n\n");
                printf("\t\t\t\033[0;37mDelete another record?\033[0;33m(Y/N)");
                c = getch();
                if (c == 'y' || c == 'Y')
                {
                    DELETEBOOK();
                }
                else
                {
                    MAINPROGRAM();
                }
            }
            else
            {
                MAINPROGRAM();
            }
        }
    }
    if (!flag)
    {
        printf("Nothing Found");
        getch();
        DELETEBOOK();
    }
}

void BOOK_ISSUE(void)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int z, date = tm.tm_mday, month = tm.tm_mon + 1, year = tm.tm_year + 1900;
    system("cls");
    printf("\t\t\033[0;33m******************************** ISSUE SECTION **************************\n\n");
    printf("\t\t\t\033[0;37m1. Issue a Book               2. View Issued Book\n");
    printf("\t\t\t3. Search Issued Book         4. Submit Book\n");
    printf("\t\t\t\033[0;37m5. Back to Main Menu\n\n");
    printf("\t\t\033[0;33mEnter Your Choice -> ");
    switch (getch())
    {
    case '1':
    {
        system("cls");
        int c = 0;
        char another = 'y';
        while (another == 'y')
        {
            system("cls");
            printf("\t\t\033[0;33m******************************** ISSUE BOOK SECTION **************************\n\n\n");
            printf("\t\t\t\033[0;37mEnter The Book Id:\033[0;32m");
            scanf("%d", &z);
            file1 = fopen("Books.txt", "r");
            file2 = fopen("Issue.txt", "a+");
            if (CHECK_BOOK(z) == 0)
            {
                printf("\n\t\t\t\033[0;31mThe Book Is Available\n");
                printf("\t\t\t\033[0;36mThe Book Title Is ->\033[0;37m %s\n", booklist.name);

                printf("\t\t\t\033[0;36mEnter Student Name -> \033[0;37m");
                scanf("%s", booklist.stname);
                printf("\t\t\t\033[0;33mIssued date -> \033[0;36m %d-%d-%d\n\n", date, month, year);
                printf("\t\t\t\033[0;33mThe Book With ID \033[0;37m%d\033[0;33m is issued to \033[0;37m%s\033[0;33m\n", booklist.id, booklist.stname);
                booklist.issued.date = date;
                booklist.issued.month = month;
                booklist.issued.year = year;
                booklist.duedate.date = booklist.issued.date + 15;
                booklist.duedate.month = booklist.issued.month;
                booklist.duedate.year = booklist.issued.year;
                if (booklist.duedate.date > 30)
                {
                    booklist.duedate.month += booklist.duedate.date / 30;
                    booklist.duedate.date -= 30;
                }
                if (booklist.duedate.month > 12)
                {
                    booklist.duedate.year += booklist.duedate.month / 12;
                    booklist.duedate.month -= 12;
                }

                printf("\t\t\t\033[0;34mTo Be Returned On -> \033[0;37m %d-%d-%d\n", booklist.duedate.date, booklist.duedate.month, booklist.duedate.year);
                fseek(file2, sizeof(booklist), SEEK_END);
                fwrite(&booklist, sizeof(booklist), 1, file2);
                fclose(file2);
                c = 1;
            }
            if (c == 0)
            {

                printf("\n\t\t\t\033[0;31mNo record found\n");
            }
            printf("\t\t\t\033[0;37mIssue any more\033[0;33m(Y/N):");
            fflush(stdin);
            another = getche();
            fclose(file1);
            if (another != 'y' || another != 'Y')
                BOOK_ISSUE();
        }
    }
    break;
    case '2':
    {
        system("cls");
        int j = 4;
        printf("\t\033[0;33m ******************************* ISSUED BOOK LIST *******************************\n");
        CONSOLE_XY(2, 2);
        printf("\t\033[0;35m STUDENT NAME        ID         BOOK NAME         ISSUED DATE         RETURN DATE\033[0;37m");
        file1 = fopen("Issue.txt", "r");
        int flag1 = 0;
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            CONSOLE_XY(2 + 7, j);
            printf("%s", booklist.stname);
            CONSOLE_XY(22 + 7, j);
            printf("%d", booklist.id);
            CONSOLE_XY(33 + 7, j);
            printf("%s", booklist.name);
            CONSOLE_XY(52 + 7, j);
            printf("%d-%d-%d", booklist.issued.date, booklist.issued.month, booklist.issued.year);
            CONSOLE_XY(72 + 7, j);
            printf("%d-%d-%d", booklist.duedate.date, booklist.duedate.month, booklist.duedate.year);
            j++;
            flag1 = 1;
        }
        if (flag1 != 1)
        {
            printf("\n\n\n\n\n\n\t\t\033[0;31mNo Record Found\n\n");
        }
        fclose(file1);
        CONSOLE_XY(1, j+3);
        printf("\n\n\033[0;33m\t\tPress Any Key....");
        getch();
        BOOK_ISSUE();
    }
    break;
    case '3':
    {
        system("cls");
        printf("\t\t\033[0;33m******************************** SEARCH ISSUE BOOK SECTION **************************\n\n\n");
        printf("\t\t\t\033[0;34mEnter Book ID : \033[0;37m");
        int p, c = 0;
        char another = 'y';
        while (another == 'y')
        {

            scanf("%d", &p);
            file1 = fopen("Issue.txt", "r");
            int j = 8;
            while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
            {
                if (booklist.id == p)
                {
                    CONSOLE_XY(10, j);
                    printf("\t\t\033[0;35mThe Book has taken by :\033[0;37m %s", booklist.stname);
                    CONSOLE_XY(10, j + 1);
                    printf("\t\t\033[0;35mIssued Date : \033[0;37m %d-%d-%d", booklist.issued.date, booklist.issued.month, booklist.issued.year);
                    CONSOLE_XY(10, j + 2);
                    printf("\t\t\033[0;35mReturning Date : \033[0;37m%d-%d-%d", booklist.duedate.date, booklist.duedate.month, booklist.duedate.year);
                    printf("\n\t\t---------------------------------------------------------\n");
                    c = 1;
                    j += 5;
                }
            }
            fflush(stdin);
            fclose(file1);
            if (c == 0)
            {
                printf("\n\t\t\t\033[0;31mNo Record Found\n");
            }
            printf("\n\n\t\t\t\033[0;37mTry Another Search?\033[0;33m(Y/N)");
            another = getch();
            (another == 'y' || another == 'Y') ? BOOK_ISSUE() : MAINPROGRAM();
        }
    }
    break;

    case '4':
    {
        system("cls");
        int b = 0;
        char studentname[50];
        FILE *file3;
        printf("\t\t\033[0;33m******************************** SUBMIT ISSUE BOOK SECTION **************************\n\n\n");
        printf("\t\t\t\033[0;37mEnter book id to remove : \033[0;32m");
        scanf("%d", &b);
        printf("\t\t\t\033[0;37mEnter Student Name : \033[0;32m");
        scanf("%s", &studentname);
        file1 = fopen("Issue.txt", "r+");
        while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
        {
            if (booklist.id == b && strcmp(booklist.stname, studentname) == 0)
            {
                b = 1;
                printf("\n\t\t\t\033[0;37mThe Book has taken by \033[0;33m %s\n", booklist.stname);
                printf("\t\t\t\033[0;37mIssued Date : \033[0;33m%d-%d-%d\n", booklist.issued.date, booklist.issued.month, booklist.issued.year);
                printf("\t\t\t\033[0;37mReturning Date : \033[0;33m%d-%d-%d\n", booklist.duedate.date, booklist.duedate.month, booklist.duedate.year);
                printf("\n\t\t\t\033[0;37mDo You Want to Remove it?\033[0;33m(Y/N)");
                if (getch() == 'y')
                {
                    file3 = fopen("record.dat", "wb+");
                    rewind(file1);
                    while (fread(&booklist, sizeof(booklist), 1, file1) == 1)
                    {
                        if (booklist.id != b && strcmp(booklist.stname, studentname) != 0)
                        {
                            fseek(file1, 0, SEEK_CUR);
                            fwrite(&booklist, sizeof(booklist), 1, file3);
                        }
                    }
                    fclose(file1);
                    fclose(file3);
                    remove("Issue.txt");
                    rename("record.dat", "Issue.txt");
                    CONSOLE_XY(10, 14);
                    printf("\n\t\t\t\033[0;31mThe issued book is removed from list\n");
                }
            }
        }
        if (b != 1)
        {
            b = 0;
            printf("\n\t\t\t\033[0;31mNo record found\n");
        }
        printf("\n\t\t\t\033[0;37mDelete any more\033[0;33m(Y/N):");
        fflush(stdin);
        char another = getche();
        fclose(file1);
        if (another != 'y' || another != 'Y')
            BOOK_ISSUE();
        else
        {
            MAINPROGRAM();
        }
    }
    case '5':
    {
        MAINPROGRAM();
    }
    break;
    default:
    {
        CONSOLE_XY(10, 18);
        printf("\t\t\033[0;31m\aWrong Entry!!");
        getch();
        BOOK_ISSUE();
        break;
    }
    }
    CONSOLE_XY(1, 30);
}
