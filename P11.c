#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int n;
struct connetion
{
    int gate;
    int in1;
    int in2;
    int out;
    struct connection *next;
};
struct connetion *head = NULL;
struct connetion *current = NULL;
struct connetion *current1 = NULL;

void insertgates(int n1)
{
    int i,g;
    printf("\nFor NOT  1 \nFor AND  2\nFor OR   3\nFor NAND 4\nFor NOR  5\n");
    for(i=0;i<n1;i++)
    {
        printf("\nWhat is gate no %d: ",i);
        scanf("%d",&g);
        struct connetion *temp = (struct connetion*)malloc(sizeof(struct connetion));
        temp->gate=g;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            current=head;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }
    }
}

void traverselist()
{
    if(head!=NULL)
    {
        int i=0;
        current=head;
        while(current!=NULL)
        {
            printf("\ngate %d IN1: %d IN2: %d OUT: %d\n",i,current->in1,current->in2,current->out);
            current=current->next;
            i=i+1;
        }
    }
}
void initialization()
{
    if(head!=NULL)
    {
        int i=0;
        current=head;
        while(current!=NULL)
        {
            current->in1=2;
            current->in2=2;
            current->out=2;
            if(current->gate==1)
            {
                current->in2=1;
            }
            current=current->next;
            i=i+1;
        }
    }
}
void inputinitialization(int a)
{
    int i=0;
    char c='n';
    current=head;
    while(current!=NULL)
    {
        printf("\nDoes gate %d has direct input(y/n): ",i);
        getchar();
        scanf("%c",&c);
        if(c=='y')
        {
            c='n';
            printf("\nDoes both terminal has direct input(y/n): ");
            getchar();
            scanf("%c",&c);
            if(c=='y')
            {
                current->in1=1;
                current->in2=0;
                current->out=gateoperation(current->gate,current->in1,current->in2);
                c='n';
            }
            else
            {
                current->in1=0;
            }
        }
        current=current->next;
        i=i+1;
    }

}
int gateoperation(int ga,int i1,int i2)
{
    switch (ga)
    {
        case 1 :    if(i1==0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
        case 2 :    if(i1==0 || i2==0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                    break;
        case 3 :    if(i1==1 || i2==1)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
        case 4 :    if(i1==0 || i2==0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                    break;
        case 5 :    if(i1==1 || i2==1)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                    break;
        default :   break;
    }
}
void createconnection1(int i,int j)
{
    int t1,t2;
    current=head;
    current1=head;
    for(t1=0;t1<i;t1++)
    {
        current=current->next;
    }
    for(t2=0;t2<j;t2++)
    {
        current1=current1->next;
    }
    if(current->in1==2)
    {
        current->in1=current1->out;
    }
    else if(current->in2==2)
    {
        current->in2=current1->out;
    }
    else
    {

    }
    if(current->in1!=2 && current->in2!=2)
    {
        current->out=gateoperation(current->gate,current->in1,current->in2);
    }
}
void createconnection(int n1)
{
    int i,j;
    char c='n';
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n1;j++)
        {
            if(j!=i)
            {
                printf("\nDoes gate %d has input from gate %d (y/n): ",i,j);
                getchar();
                scanf("%c",&c);
                if(c=='y')
                {
                    createconnection1(i,j);
                    c='n';
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

void main()
{
    int g,i;
    int a;
    char c='n';
    printf("\nEnter total number of gates : ");
    scanf("%d",&n);
    insertgates(n);
    initialization(n);
    printf("\nEnter total number of input : ");
    scanf("%d",&a);
    inputinitialization(a);
    createconnection(n);
    printf("\nDo you want to see gates (y/n) : ");
    getchar();
    scanf("%c",&c);
    if(c=='y')
    {
        traverselist();
        c='n';
    }
}
