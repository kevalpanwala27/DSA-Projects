// CALL MANAGEMENT SYSTEM //
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Stack
{
    char *s;
    int top;
    int size;
};

int call()
{

    char c;
    printf("\nDO YOU WANT TO CALL ANYONE y/n: ");
    scanf("%c",&c);
    if(c=='y')
    return 1;
    else if(c=='n')
    return 0;

}

void create(struct Stack *st)
{
    printf("\nEnter Size Of Phone Number: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(char *)malloc(st->size*sizeof(char));
}

void push (struct Stack *st)
{
        printf("Enter Phone Number\n");
        scanf("%s",st->s);
        st->top=st->size;
}

void display(struct Stack *st,char *ch[][10],int *p)
{
        printf("CALL HISTORY\n");
        int x=*p-1;
                for(int i=0+x;i<*p;i++)
        {
            for(int j=0;j<10;j++)
            {
                ch[x][j]=st->s[j];
            }
        }
        for(int i=0;i<*p;i++)
        {
            for(int j=0;j<10;j++)
            {
                printf("%c",ch[i][j]);
            }
            printf("\n");
        }
        *p=*p+1;
}

int main()
{
    struct Stack st;
    printf("=====================================\n");
    printf("WELCOME TO OUR CALL MANAGEMENT SYSTEM");
    printf("\n=====================================");
    char ch[10][10];
    int p=1;
    int calling=1;
    while (calling!=0)
    {
    calling=call();
    if(calling==1)
    {
    create(&st);

    push(&st);
    display(&st,ch,&p);
    continue;
    }
    else if(calling==0)
    {
        printf("Closing System...");
        break;
    }
    }
    return 0;
}
