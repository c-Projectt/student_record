#include <stdio.h>
#include <stdlib.h>

unsigned int ord;

 struct grades
{
   int math;
   int electronics;
   int circuits;
   int programming;
   int lang;
};

struct student {
    char first[12];
    char last[12];
    char id[15];
    struct grades studentgrades;
    struct student *nextPtr; // pointer to next node
    };

    typedef struct student Student;
     typedef Student *StudentPtr;

void instructions(void);

void quit();

void insert(StudentPtr *sptr);

void printlist(StudentPtr currentptr);

//StudentPtr srh(StudentPtr *sptr,char f[],char n[]);

void search(StudentPtr *sptr,char f[],char n[]);

void addgrades(StudentPtr *sptr,char f[],char n[]);

int stringsz(char s[]);

void update_inst(void);

void update(StudentPtr *sptr,char f[],char n[]);

int main()
{
    StudentPtr startptr=NULL;
    char name[12],nick[12];
    //int t;
    instructions();
    while (ord !=7)
    {
        switch (ord)
        {
        case 1:

            insert(&startptr);
            break;
        case 2:
            printf("enter student name: ");
            scanf("%s %s",name,nick);
            addgrades(&startptr,name,nick);
            break;
        case 3:
            printf("enter student name: ");
            scanf("%s %s",name,nick);
            update(&startptr,name,nick);
            break;
        case 4:
            printlist(startptr);
            break;
        case 5:
            printf("enter student name: ");
            scanf("%s %s",name,nick);
            search(&startptr,name,nick);
            break;
        case 6:
            break;
        default:
            printf("\t \t \t \t invalid choice \n");
            break;
        }
        instructions();
    }

    return 0;
}
void instructions(void){
    int i;
    printf("\t \t ");
    for(i=0;i<60;i++)printf("~");

    printf("\n \t \t \t enter 1 to add new student record"
           "\n \t \t \t enter 2 to add  or reinsert grades for existing student record"
           "\n \t \t \t enter 3 to update an existing  record"
           "\n \t \t \t enter 4 to display all available records"
           "\n \t \t \t enter 5 to search for an existing  record"
           "\n \t \t \t enter 6 to delete student record"
           "\n \t \t \t enter 7 to exit and save records \n \t \t ");
    for(i=0;i<60;i++)printf("~");
    printf("\n");
    scanf("%u",&ord);
}

 void insert(StudentPtr *sPtr)
 {
     StudentPtr newptr=malloc(sizeof(Student));
     if(newptr!=NULL)
     {
        int t=0;
        printf("enter student name: ");
            scanf("%s %s",newptr->first,newptr->last);
         printf("enter id: ");
         scanf("%s",newptr->id);

         printf("do you want to add grades 1 to add 0 to continue without adding?");
         scanf("%d",&t);
         if(t==1){
       printf("enter student math grade: ");
         scanf("%d",&newptr->studentgrades.math);
        printf("enter student electronics grade: ");
         scanf("%d",&newptr->studentgrades.electronics);
        printf("enter student programming grade: ");
         scanf("%d",&newptr->studentgrades.programming);
        printf("enter student circuits grade: ");
         scanf("%d",&newptr->studentgrades.circuits);
           printf("enter student technical language grade: ");
         scanf("%d",&newptr->studentgrades.lang);
         }
       //setting the values to zero
         else
         {
             newptr->studentgrades.lang=0;
             newptr->studentgrades.programming=0;
             newptr->studentgrades.circuits=0;
             newptr->studentgrades.electronics=0;
             newptr->studentgrades.math=0;
         }

         newptr->nextPtr=NULL;

         StudentPtr previousPtr=NULL;
         StudentPtr currentPtr=*sPtr;

        //program will continue with the current pointer till finding the first character in the new node less than that of the node pointed at by the current ptr
         while (currentPtr != NULL && newptr->first[0] >= currentPtr->first[0])
         {
             int i=1,j=0;
             // هشوف ده مش شغال ليه لسا

             /*if((newptr->first[0]==currentPtr->first[0])&&((newptr->first[1]<currentPtr->first[1])||(newptr->first[2]<currentPtr->first[2]&&newptr->first[1]==currentPtr->first[1])||(newptr->first[3]<currentPtr->first[3]&&newptr->first[1]==currentPtr->first[1]&&newptr->first[2]==currentPtr->first[2])))break;
            else if((newptr->first[0]==currentPtr->first[0])&&(newptr->last[0]<currentPtr->last[0]||(newptr->last[1]<currentPtr->last[1]&&newptr->last[0]==currentPtr->last[0])||(newptr->last[2]<currentPtr->last[2]&&newptr->last[1]==currentPtr->last[1]&&newptr->last[0]==currentPtr->last[0])))break;
             */

             //I thought of that one after the meeting try it!!
             // عشان ميدخلش كل مرة علي الفاضي if
             if(newptr->first[0] == currentPtr->first[0]){
                    //commentالماعمول  conditionانا جربته و شغال من غير ال
                    //for compare every character for the first name of each node and will close when they are not equal
                for(i=1;/*((newptr->first[i]!=0)&&(currentPtr->first[i]!=0))&&*/(newptr->first[i]==currentPtr->first[i]);i++);

             //if the program end the for because they reached end of string and all character are equal it will enter that if condition
             if((stringsz(newptr->first)==i-1)&&(stringsz(currentPtr->first)==i-1))
             {
                 // this if is to check the last name by the same method as the first one if the first name of the two nodes are identical
                 for(j=0;/*((newptr->last[j]!=0)&&(currentPtr->last[j]!=0))&&*/(newptr->last[j]==currentPtr->last[j]);j++);
                 //لو طلعوا قد بعض هنعمل ايه بقى هيحط اي واحد قبل التانى
                 if((stringsz(newptr->first)==j-1)&&(stringsz(currentPtr->first)==j-1))break;
                 //if the character we break the for loop on the last name of new node is less than that of current node it will break through the while loop giving us the pointer where we need
                 else if (currentPtr->last[j]>newptr->last[j])break;
             }
             // the same to that of the last name if it break through the because the two characters arent equal so it will break through the while loop if the last name of new node is less than that of current node
                else if (currentPtr->first[i]>newptr->first[i])break;
             }
             previousPtr = currentPtr;
             currentPtr = currentPtr->nextPtr;
         }
         if (previousPtr == NULL) {
                newptr->nextPtr = *sPtr;
                *sPtr = newptr;
         }
         else
         {
             previousPtr->nextPtr=newptr;
             newptr->nextPtr=currentPtr;
         }
     }
      else {
            printf("student not inserted. No memory available.\n");
      }
 }
// i think this function is better on samar's code
void printlist(StudentPtr currentptr)
{
    if(currentptr==NULL)
    {
        printf("no records found ");
    }
    else
    {
        printf("\t %-25s %-14s %-12s %-12s %-12s %-12s     %-12s \n","studentname","id","math","electronics","circuits","programming","lang" );
        int i;
        for(i=1;currentptr!=NULL;i++)
        {
        printf("%-5d %s  %-17s %-15s %-13d %-13d %-13d %-13d %-12d \n",i,currentptr->first,currentptr->last,currentptr->id,currentptr->studentgrades.math,currentptr->studentgrades.electronics,currentptr->studentgrades.circuits,currentptr->studentgrades.programming,currentptr->studentgrades.lang );
        currentptr=currentptr->nextPtr;
        }
    }
}

//search by student name
void search(StudentPtr *sPtr,char f[],char n[])
{

     StudentPtr currentPtr=*sPtr;
     //go till the end of the linked list
         while (currentPtr != NULL )
         {

             if(f[0]==currentPtr->first[0])
             {
                 int i,j;
                 //counting number of identical character in the first name if their is non equal it will break
                 for(i=1;f[i]!=0;i++)if(f[i]!=currentPtr->first[i])break;
                 //counting number of identical character in the last name if their is non equal it will break
                 for(j=0;n[j]!=0;j++)if(n[j]!=currentPtr->last[j])break;
                 // if the number of identical characters are equal to size of the name it will break the while loop giving us the current ptr
                 if(i==stringsz(f)-1&&j==stringsz(n)-1)break;
             }
             currentPtr=currentPtr->nextPtr;
         }

        if(currentPtr!=NULL)
        {
            printf("student id :%s \n student math grades:%d \n student electronics grades:%d \n student circuits grades:%d \n student programming grades:%d \n student lang grades:%d \n",currentPtr->id,currentPtr->studentgrades.math,currentPtr->studentgrades.electronics,currentPtr->studentgrades.circuits,currentPtr->studentgrades.programming,currentPtr->studentgrades.lang);

        }
        else{
            puts("student not found\n");
        }
}
//string size function cuz im too lazy to search for the built-in one :);
int stringsz(char s[])
{
    int i;
    for(i=1;s[i-1]!=0;i++);
    return i;
}
//this is better at samar's code.it is the instructions to for what the user want to update
void update_inst(void)
{
    int i;
    printf("\n \n \t ");
    for(i=0;i<60;i++)printf("x");

    printf("\n \t \t  enter 1 to update id"
           "\n \t \t  enter 2 to update math record"
           "\n \t \t  enter 3 to update electronics record"
           "\n \t \t  enter 4 to update circuits record"
           "\n \t \t  enter 5 to update programming record"
           "\n \t \t  enter 6 to update technical language record \n \t \t ");
    for(i=0;i<60;i++)printf("x");
    printf("\n");
}

//update function by student name
void update(StudentPtr *sPtr,char f[],char n[])
{
    int k;
    StudentPtr currentPtr=*sPtr;
         while (currentPtr != NULL )
         {

             // the same as in the search function i try to make it a function that returns a pointer but it didnt work
               if(f[0]==currentPtr->first[0])
             {
                 int i,j;
                 for(i=1;f[i]!=0;i++)if(f[i]!=currentPtr->first[i])break;
                 for(j=0;n[j]!=0;j++)if(n[j]!=currentPtr->last[j])break;
                 if(i==stringsz(f)-1&&j==stringsz(n)-1)break;
             }
             currentPtr=currentPtr->nextPtr;
         }

         if(currentPtr != NULL){
         do{
    update_inst();
    scanf("%d",&k);
    switch(k)
    {
    case 1:
          printf("enter id: ");
         scanf("%s",currentPtr->id);
        break;
    case 2:
        printf("enter student math grade: ");
         scanf("%d",&currentPtr->studentgrades.math);
        break;
    case 3:
        printf("enter student electronics grade: ");
         scanf("%d",&currentPtr->studentgrades.electronics);
        break;
    case 4:
        printf("enter student circuits grade: ");
         scanf("%d",&currentPtr->studentgrades.circuits);
        break;
    case 5:
        printf("enter student programming grade: ");
         scanf("%d",&currentPtr->studentgrades.programming);
        break;
    case 6:
        printf("enter student technical language grade: ");
         scanf("%d",&currentPtr->studentgrades.lang);
        break;
    default:
        printf("invalid choice\n");
        break;
    }
         }while(k>7&&k<1);
         }
         else{
              puts("student not found\n");

         }
}

/*
StudentPtr srh(StudentPtr *sPtr,char f[],char n[])
{
    StudentPtr currentPtr=*sPtr;
         while (currentPtr != NULL )
         {
               if(f[0]==currentPtr->first[0])
             {
                 int i,j;
                 for(i=1;f[i]!=0;i++)if(f[i]!=currentPtr->first[i])break;
                 for(j=0;n[j]!=0;j++)if(n[j]!=currentPtr->last[j])break;
                 if(i==stringsz(f)-1&&j==stringsz(n)-1)break;
             }
             currentPtr=currentPtr->nextPtr;
         }
         return &currentPtr;
}
*/
// add grades function to add or change all the grades of existing student
void addgrades(StudentPtr *sPtr,char f[],char n[])
{
     StudentPtr currentPtr=*sPtr;
     //the same searching method
         while (currentPtr != NULL )
         {
               if(f[0]==currentPtr->first[0])
             {
                 int i,j;
                 for(i=1;f[i]!=0;i++)if(f[i]!=currentPtr->first[i])break;
                 for(j=0;n[j]!=0;j++)if(n[j]!=currentPtr->last[j])break;
                 if(i==stringsz(f)-1&&j==stringsz(n)-1)break;
             }
             currentPtr=currentPtr->nextPtr;
         }

         if(currentPtr != NULL){
       printf("enter student math grade: ");
         scanf("%d",&currentPtr->studentgrades.math);
        printf("enter student electronics grade: ");
         scanf("%d",&currentPtr->studentgrades.electronics);
        printf("enter student programming grade: ");
         scanf("%d",&currentPtr->studentgrades.programming);
        printf("enter student circuits grade: ");
         scanf("%d",&currentPtr->studentgrades.circuits);
           printf("enter student technical language grade: ");
         scanf("%d",&currentPtr->studentgrades.lang);
         }

        else{
              puts("student not found\n");
        }

}
