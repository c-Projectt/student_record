#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void menu();
int check(int);
void checkrepeat(int, int);
void gotoxy(int, int);
int stringsz(char s[]);
int is_BN(char s[]);
int pw(int x, int y);
void add(int bn);
void addgrades(int bn);
void display();
void recase(char cs[]);
void delete_record(int bn,char q);
void search();
void modify(int bn);
void clear();
void exit();

struct grades {
    int math;
    int electronics;
    int circuits;
    int programming;
    int lang;
    int totalMarks;
};
struct studentNode {
    int BN;
    char id[15];
  /*  char firstName[15];
    char lastName[15];*/
    char fullName[30];
    struct grades studentgrades;
    struct studentNode* next;
};

struct studentNode* head = NULL;

int main() {
    gotoxy(20, 10);
    printf("<< Students Database Management System >>");
    gotoxy(40, 15);
    printf("Press any key to continue");
    _getch();               // pauses the Output Console untill a key is pressed & is defined in conio.h header file
    menu();
    return 0;
}
void menu() {
    int choice;
    system("cls");          // to clear the output screen & is defined in stdlib.h header file
    gotoxy(5, 3);
    puts("<< MENU >>");
    gotoxy(10, 5);
    puts("Choose a number to perform the task you want");
    gotoxy(15, 7);
    puts("1 : Add Record");
    gotoxy(15, 8);
    puts("2 : Delete Record");
    gotoxy(15, 9);
    puts("3 : Search and modify");
    gotoxy(15, 10);
    puts("4 : Display all students records");
    gotoxy(15, 11);
    puts("5 : show status");
    gotoxy(15, 12);
    puts("6 : Clear");
    gotoxy(15, 13);
    puts("7 : Exit");
    gotoxy(10, 15);
    printf("Enter your choice : ");
 while(scanf("%d",&choice) != 1)
    {
        while(getchar() != '\n');
    }
    switch (choice) {
    case 1:
        add(0);
        break;
    case 2:
        delete_record(0,'s');
        break;
    case 3:
        search();
        break;
    case 4:
        display();
        break;
    /*case 5:
        modify();
        break;
    case 6:
        clear();
        break;
    case 7:
        exit();
        break;*/
    default:
       /* gotoxy(25, 17);
        puts("Invalid Choice .. Choose a number from 1 to 7.");
        scanf("%d",&choice);*/
        menu();
    }
}/*
int check(int i) {
    struct studentNode* checkptr = malloc(sizeof(struct studentNode));
    checkptr = head;
    if (head == NULL) {
        return 3;         // does not exist
    }
    while (checkptr != NULL) {
        if (checkptr->id == i) {
            return 2;    // exist
        }
        checkptr = checkptr->next;
    }
    return 3;
}*/
void checkrepeat(int x, int y) {
    gotoxy(x, y);
    int c;
    printf("Enter 1 to perform another task or 0 to exit: ");
    scanf("%d", &c);
    if (c == 1) menu();
    //else exit();
}
void gotoxy(int x, int y) {                // is defined in windows.h header file
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int stringsz(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
int is_BN(char s[])
{
    if(s[0]<64)
    {
        int i,x=0;
        for (i=0;s[i]!='\0';i++)x+=(s[i]-48)*pw(10,(stringsz(s)-i));
        return x;
    }
    else return 0;
}
int pw(int x,int y)
{
    int i,z=1;
    for(i=1;i<y;i++)
    {
        z*=x;
    }
    return z;
}

void recase(char cs[30])
{
    int i, j;
    if (cs[0] >= 97) cs[0] -= 32;
    for (int i = 1; cs[i] != NULL; i++) {
        if (cs[i] < 97 && cs[i] != ' ')cs[i] += 32;
        else if (cs[i] == ' ' && (cs[i + 1] != NULL && cs[i + 1] >= 97)) cs[i + 1] -= 32, i++ ;
    }
}
void add(int bn) {
    int ch;
    char fullName[30],id[15];
    gotoxy(25, 17);
    printf("Enter the student name:");
    fflush(stdin);
    gets(fullName);
    recase(fullName);
    if(bn<=0){
        gotoxy(25, 18);
        printf("Enter the student ID: ");
        scanf("%14s",id);
           }
/*
    if (check(id) == 2) {
        gotoxy(10, 21);
        puts("The student with this ID is already exist.");
        checkrepeat(25, 23);
    }
*/
    //else {
        struct studentNode* newNode = malloc(sizeof(struct studentNode));
    if (newNode != NULL) {
                  int x = 20;
        if(bn<=0){
            newNode->studentgrades.lang = 0;
            newNode->studentgrades.programming = 0;
            newNode->studentgrades.circuits = 0;
            newNode->studentgrades.electronics = 0;
            newNode->studentgrades.math = 0;
            newNode->studentgrades.totalMarks = 0;
            newNode->BN=1;
            strcpy(newNode->id, id);
            strcpy(newNode->fullName, fullName);
            newNode->next = NULL;
            gotoxy(25, 19);
            printf("Enter 1 to add student grades or 0 to continue without adding: ");
            scanf("%d", &ch);

            if (ch == 1) {
                gotoxy(25, 20);
                printf("Enter Mathematics grade: ");
                scanf("%d", &newNode->studentgrades.math);
                gotoxy(25, 21);
                printf("Enter Electronics grade: ");
                scanf("%d", &newNode->studentgrades.electronics);
                gotoxy(25, 22);
                printf("Enter Programming grade: ");
                scanf("%d", &newNode->studentgrades.programming);
                gotoxy(25, 23);
                printf("Enter Circuits grade: ");
                scanf("%d", &newNode->studentgrades.circuits);
                gotoxy(25, 24);
                printf("Enter Language grade: ");
                scanf("%d", &newNode->studentgrades.lang);
                newNode->studentgrades.totalMarks = newNode->studentgrades.math + newNode->studentgrades.electronics + newNode->studentgrades.programming + newNode->studentgrades.circuits + newNode->studentgrades.lang;
                x = 25;
            }
        }
        else
        {
            struct studentNode* current = head;
            while (current != NULL && current->BN != bn)current = current->next;
            newNode->studentgrades.lang = current->studentgrades.lang;
            newNode->studentgrades.programming = current->studentgrades.programming;
            newNode->studentgrades.circuits = current->studentgrades.circuits;
            newNode->studentgrades.electronics = current->studentgrades.electronics;
            newNode->studentgrades.math = current->studentgrades.math;
            newNode->studentgrades.totalMarks = current->studentgrades.totalMarks;
            newNode->BN=1;
            strcpy(newNode->id, current->id);
            strcpy(newNode->fullName, fullName);
            newNode->next = NULL;
            delete_record(bn,"a");
        }


            if (head == NULL) head = newNode;
            else {
                int i = 1, j = 0;
                struct studentNode* current = head, * previous = NULL;

                while (current != NULL && newNode->fullName[0] >= current->fullName[0]) {
                    if (newNode->fullName[0] == current->fullName[0]) {
                        for (i = 1; (newNode->fullName[i] == current->fullName[i]) && (newNode->fullName[i] != '\0') && (current->fullName[i] != '\0'); i++);     // to compare every character for the first name of each node and will close when they are not equal

                         //if the program end the for because they reached end of string and all character are equal, it will enter that if condition
                        if ((stringsz(newNode->fullName) == i) && (stringsz(current->fullName) == i))break;
                        else if (newNode->fullName[i]=='\0')break;
                        else if (current->fullName[i] > newNode->fullName[i]) break;                // the same to that of the last name if it break through the because the two characters arent equal so it will break through the while loop if the last name of new node is less than that of current node
                    }
                    previous = current;
                    current = current->next;
                }

                if (previous == NULL) {
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    previous->next = newNode;
                    newNode->next = current;
                }

          current = head;
                int b=1;
            while(current!=NULL)
            {
                current->BN=b;
                b++;
                current=current->next;
            }

            }

            if(bn==0)
                {
                gotoxy(10, x + 2);
               if(bn==0) puts("The record is added successfully.");
                checkrepeat(25, x + 4);
                }

        }
        else {
            gotoxy(10, 21);
            puts("student is not inserted. No memory available.");
        }
   // }
}
void display() {
    gotoxy(3, 17);
    if (head == NULL) {
        puts("The system is empty.");
        checkrepeat(25, 19);
        return;
    }
    struct studentNode* print = head;
    printf("%-3s %-16s %-15s %-13s %-13s %-13s %-13s %-13s %s\n", "BN", "Name", "ID", "Electronics", "Circuits", "Programming", "Mathematics", "Language", "TOTAL");
    int x = 19;
    while (print != NULL) {
        gotoxy(3, x++);
        printf("%-3d %-22s %-15s %-13d %-13d %-13d %-13d %-13d %d\n", print->BN, print->fullName, print->id, print->studentgrades.electronics, print->studentgrades.circuits, print->studentgrades.programming, print->studentgrades.math, print->studentgrades.lang, print->studentgrades.totalMarks);
        print = print->next;
    }
    checkrepeat(25, 25);
}
void delete_record(int bn, char q) {
     char full[30];
    if(!bn){
     printf("enter student name or BN:");
     fflush(stdin);
     gets(full);
     recase(full);
     struct studentNode* current = head;
     bn=is_BN(full);
    }
        struct studentNode* current = head;
        struct studentNode* previous = head;
    if (head == NULL) {
        gotoxy(10, 19);
        puts("Record does not exist.");
    }


    else if(bn==0)
    {
         while (current != NULL )
         {
               if(full[0]==current->fullName[0])
             {
                 int i;
                 for(i=1;full[i]!=0;i++)if(full[i]!=current->fullName[i])break;
                 if(i==stringsz(full))break;
             }
             previous = current;
             current=current->next;
         }
        }
    else {

        while (current != NULL && current->BN != bn) {
            previous = current;
            current = current->next;
        }
    }
        if (current == NULL) {
            gotoxy(10, 19);
            puts("Record does not exist.");
        }
         else if(current->BN==1)
    {
         current = head;
        head=head->next;
        free(current);
        gotoxy(10, 19);
       if(q=='s') puts("Record is deleted successfully.");
        current = head;
                int b=1;
            while(current!=NULL)
            {
                current->BN=b;
                b++;
                current=current->next;
            }

    }
        else {
            previous->next = current->next;
            free(current);
            gotoxy(10, 19);
           if(q=='s') puts("Record is deleted successfully.");

            current = head;
                int b=1;
            while(current!=NULL)
            {
                current->BN=b;
                b++;
                current=current->next;
            }

        }
if(q=='s')checkrepeat(25, 21);
}


void search()
 {
     int bn;
     char full[30];
     printf("enter student name or BN:");
     fflush(stdin);
     gets(full);
     recase(full);
     struct studentNode* current = head;
     bn=is_BN(full);
     if(bn)
     {
         while(current!=NULL && current->BN!=bn)current = current->next;
     }
     else
     {
         while (current != NULL )
         {
               if(full[0]==current->fullName[0])
             {
                 int i;
                 for(i=1;full[i]!=0;i++)if(full[i]!=current->fullName[i])break;
                 if(i==stringsz(full))break;
             }
             current=current->next;
         }
     }
     int it;
     if(current!=NULL)
        {
     printf("%-3s %-20s %-15s %-13s %-13s %-13s %-13s %-13s %s\n", "BN", "Name", "ID", "Electronics", "Circuits", "Programming", "Mathematics", "Language", "TOTAL");
   /* int x = 19;
        gotoxy(3, x++);*/
        printf("%-3d %-20s %-15s %-13d %-13d %-13d %-13d %-13d %d\n", current->BN, current->fullName, current->id, current->studentgrades.electronics, current->studentgrades.circuits, current->studentgrades.programming, current->studentgrades.math, current->studentgrades.lang, current->studentgrades.totalMarks);
       printf("1- to add grades \t 2- to modify id or name \t 3- to go to menu");
       scanf("%d",&it);
        }
        else
        {
            printf("student not found");
        }
        if(it==1)addgrades(current->BN);
        else if(it==2)modify(current->BN);

    checkrepeat(25, 25);
 }
 void addgrades(int bn)
{
     struct studentNode* current = head;
        while (current != NULL && current->BN != bn)current = current->next;

         if(current != NULL){
       printf("enter student math grade: ");
         scanf("%d",&current->studentgrades.math);
        printf("enter student electronics grade: ");
         scanf("%d",&current->studentgrades.electronics);
        printf("enter student programming grade: ");
         scanf("%d",&current->studentgrades.programming);
        printf("enter student circuits grade: ");
         scanf("%d",&current->studentgrades.circuits);
           printf("enter student technical language grade: ");
         scanf("%d",&current->studentgrades.lang);
        current->studentgrades.totalMarks = current->studentgrades.math + current->studentgrades.electronics + current->studentgrades.programming + current->studentgrades.circuits + current->studentgrades.lang;
         puts("grades add successfully");
         }

        else{
              puts("student not found\n");
        }

}

void modify(int bn) {
    int mr=0;
      struct studentNode* current = head;
    while (current != NULL && current->BN != bn)current = current->next;
    printf("1- to modify id \t 2- to modify name \t 3- to modify all 4-to out");
    scanf("%d",&mr);
    if(mr==1)scanf("%s",current->id);
   else if(mr==2)add(current->BN);
    else if(mr==3)
    {
        delete_record(current->BN,"a");
        add(-1);
    }
    puts("record modified successfully");
}
/*
void clear() {
}
void exit() {
}
*/
