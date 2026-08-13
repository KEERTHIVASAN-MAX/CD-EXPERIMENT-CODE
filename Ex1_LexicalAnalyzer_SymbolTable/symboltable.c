/*
 * EX.NO: 1
 * Using the LEX tool, develop a lexical analyzer to recognize a few patterns
 * in C (identifiers, constants, comments, operators etc.).
 * Create a symbol table, while recognizing identifiers.
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct table
{
    char var[10];
    int value;
};

struct table tbl[20];
int i,j,n;

void create();
void modify();
int search(char variable[],int n);
void insert();
void display();

void main()
{
    int ch,result=0;
    char v[10];
    clrscr();
    do
    {
        printf("Enter your choice\n1.Create\n2.Insert\n3.Modify\n4.Search\n5.Display\n6.Exit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                modify();
                break;
            case 4:
                printf("Enter the variable to be searched for:\n");
                scanf("%s",&v);
                result=search(v,n);
                if(result==0)
                    printf("The variable does not belong to the table\n");
                else
                    printf("The location of the variable is %d\nThe value of %s is %d\n",result,tbl[result].var,tbl[result].value);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
        }
    }
    while(ch!=6);
    getch();
}

void create()
{
    printf("Enter the no. of entries:");
    scanf("%d",&n);
    printf("Enter the variable and the value:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%s%d",tbl[i].var,&tbl[i].value);
        check:
        if(tbl[i].var[0]>='0'&&tbl[i].var[0]<='9')
        {
            printf("The variable should start with an alphabet\nEnter correct variable name:\n");
            scanf("%s%d",tbl[i].var,&tbl[i].value);
            goto check;
        }
        check1:
        for(j=1;j<i;j++)
        {
            if(strcmp(tbl[i].var,tbl[j].var)==0)
            {
                printf("The variable already exists.Enter another variable\n");
                scanf("%s%d",tbl[i].var,&tbl[i].value);
                goto check1;
            }
        }
    }
    printf("The table after creation is:\n");
    display();
}

void insert()
{
    if(i>=20)
        printf("Cannot insert.Table is full\n");
    else
    {
        n++;
        printf("Enter the value and variable\n");
        scanf("%s%d",tbl[n].var,&tbl[n].value);
        check:
        if(tbl[i].var[0]>='0'&&tbl[i].var[0]<='9')
        {
            printf("The variable should start with an alphabet\nEnter correct variable name:\n");
            scanf("%s%d",tbl[i].var,&tbl[i].value);
            goto check;
        }
        check1:
        for(j=1;j<n;j++)
        {
            if(strcmp(tbl[j].var,tbl[i].var)==0)
            {
                printf("The variable already exist.Enter another variable\n");
                scanf("%s%d",tbl[i].var,&tbl[i].value);
                goto check1;
            }
        }
        printf("The table after insertion is:\n");
        display();
    }
}

void modify()
{
    char variable[10];
    int result=0;
    printf("Enter the variable to be modified\n");
    scanf("%s",&variable);
    result=search(variable,n);
    if(result==0)
        printf("%s does not belong to table\n",variable);
    else
    {
        printf("The current value of the variable %s is %d\nEnter the new variable and its value\n",tbl[result].var,tbl[result].value);
        scanf("%s%d",tbl[result].var,&tbl[result].value);
        check:
        if(tbl[i].var[0]>='0'&&tbl[i].var[0]<='9')
        {
            printf("The variable should start with an alphabet\nEnter correct variable name:\n");
            scanf("%s%d",tbl[i].var,&tbl[i].value);
            goto check;
        }
    }
    printf("The table after modification is:\n");
    display();
}

int search(char variable[],int n)
{
    int flag=0;
    for(i=1;i<=n;i++)
    {
        if(strcmp(tbl[i].var,variable)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        return i;
    else
        return 0;
}

void display()
{
    printf("VARIABLE\t VALUE\n");
    for(i=1;i<=n;i++)
        printf("%s\t\t%d\n",tbl[i].var,tbl[i].value);
}

/*
OUTPUT
Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:1
Enter the no. of entries:3
Enter the variable and the value: AIM 45
ASK 34
BALL 56
The table after creation is:
VARIABLE VALUE
AIM 45
ASK 34
BALL 56

Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:2
Enter the value and variable SIM 25
The table after insertion is:
VARIABLE VALUE
AIM 45
ASK 34
BALL 56
SIM 25

Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:3
Enter the variable to be modified ASK
The current value of the variable ASK is 34
Enter the new variable and its value RIM 40
The table after modification is:
VARIABLE VALUE
AIM 45
RIM 40
BALL 56
SIM 25

Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:4
Enter the variable to be searched for: RIM
The location of the variable is 2 The value of RIM is 40

Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:5
VARIABLE VALUE
AIM 45
RIM 40
BALL 56
SIM 25

Enter your choice 1.Create 2.Insert 3.Modify 4.Search 5.Display 6.Exit:6

RESULT: Thus the C program to implement Symbol Table was executed and verified successfully.
*/
