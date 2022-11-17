//---------------------------------------DEMO HOSPITAL APPOINTMENTS system-------------------------------------------------------

        // Implementing appointment queue in a hospital by using Linked List

#include<stdio.h>
#include<malloc.h>
#include<conio.h>
//#include<stdlib.h>
void clrscr()
{
    system("@cls||clear");
}

struct node         // creating structure for storing the info of patients
{
    char *name[100];    //name of patient
    int age;            //AGE OF patient
    char *address[100]; //addressof patient
    int phone;          //phone no.pf patient
    char bloodgroup[100];   // bloodGroup of patient
    int reg;            //registration no.
    int disease_no;       //  disease no. of patient from table
    struct node *next;  //created a pointer for pointing the next element
};
struct node *start= NULL;   // intializing start as NULL


struct node *insert(struct node *start)         //function to insert the patient's info in our appointment system
{
    int val2,val4,val6,pri;         //creating temparary variablesfor storing inputs
    char val1,val3,val5;
    struct node *ptr,*p;
    ptr=(struct node*)malloc(sizeof(struct node));  //allocating dynamic memory for storing the patient's info
    // inputting values
    printf("--> Input patient Name:  ");
    scanf(" %s",ptr-> name);
    printf("--> Input the patient's age:  ");
    scanf("%d",&val2);
    printf("--> INput paitent's home address:  ");
    scanf(" %s",ptr->address);
    printf("--> Input your phone number:  ");
    scanf("%d",&val4);
    printf("--> Input the blood group of Patient:  ");
    scanf(" %s",ptr->bloodgroup);
    printf("--> Input the registration no:  ");
    scanf("%d",&val6);
    printf("--> Input Patient's disease Number:  ");
    table();
    scanf("%d",&pri);
    //ptr->name=name;
    ptr->age=val2;
    //ptr->address=address;
    ptr->phone=val4;
    ptr->reg=val6;
    ptr->disease_no=pri;
    if(start==NULL)     //checking start is null or not
    {                   //if yes, then changing the start to ptr of. first node
        ptr->next=start;
        start=ptr;
    }
    else
        {                    // if not , 
            p=start;        //applying "Insert at Tail" operation of linked list
            while(p->next!=NULL)
                p=p->next;
            ptr->next=p->next;
            p->next=ptr;
        }
    return start;       // returning the start of our linked list
}

void display(struct node *start)            //function to display all appointments from start
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)                         //checking whether the linked list have no element i.e our appointments queue has no member left
        printf("\n\t<---------NO PATIENT IN A QUEUE--------->");
    else
    {
        printf("<----------FIFO wise appointments are: ------------>\n\n");
                                    //printing operation of Lineked list
        while(ptr!=NULL)            //printing the queue members fom start uptill our pointer is not equal to NULL i.e. end of queue
        {
            printf("--> The name of patient is:%s\n",ptr->name);
            printf("--> The age of patient is:%d\n",ptr->age);
            printf("--> The address of patient is : %s\n",ptr->address);
            printf("--> Phone Number of patient:%d\n",ptr->phone);
            printf("--> The blood group of patient is:%s\n",ptr->bloodgroup);
            printf("    ______________\n");
            ptr=ptr->next;
        }
    }
    getchar();
}

struct node *delete(struct node *start)     // function to remove the first element of the queue
{
    struct node *ptr;
    if(start==NULL)                 //checking whether the queue is empty or not
    {                               // if yes, then print no RECORD to delete
        printf("\n\t<---------NO PATIENT RECORD TO DELETE--------->\n\n");
        return;
    }
    else
    {                               //if not, 
        ptr= start;
        printf("\n |--> Deleted Record is :  %d\n",ptr->reg);
        start=start->next;          // then just shift our start to the next node,
        free(ptr);                  //and free the pointer which is previously pointing to start
    }
    return start;       // return the new start
};

void table()            // function to print table for disease selection
{
    printf("\n  Please Select the disease from the below table!\n");
    printf(" 1-> Mononucleosis\n");
    printf(" 2-> Conjunctivitis (pink eye)\n");
    printf(" 3-> Cancer\n");
    printf(" 4-> Chest pain\n");
    printf(" 5-> Fracture\n");
    printf(" 6-> Diabetes Checkup\n");
    printf(" 7-> Viral Infection\n");
    printf(" 8-> Common cold \n");
    printf(" 9-> Diarrhea\n");
}


int main()
{
    clrscr();
    int option;
    //printing main interface
    do{
        printf("\t_________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
       
        printf("\t>---------- Welcome to Demo Hospital ----------<\n");
        //printf("\t\t\t\t\t\t\t\t\t\t\n");
        
        printf("\t_________________\n\n");
        printf("\t 1. TO INSERT NEW PATIENT IN APPOINTMENT'S QUEUE\n\n");
        printf("\t 2. TO DELETE THE APPOINTMENTS IN A QUEUE\n\n");
        printf("\t 3. DISPLAY ALL APPOINTMENTS FROM THE QUEUE\n\n");
        printf("\t 4. Exit the PROGRAM\n\n");
        printf("\tEnter your preference:\n\n\t");
        scanf("%d",&option);        //scannig the option
    switch(option)
    {
    case 1:
        start= insert(start);       //calling insert function to insert new queue member 
        getchar();
        break;
    case 2:
        start= delete(start);       //calling delete function to remove the first element of a queue
        getchar();
        break;
    case 3:
        display(start);             //calling function to displaying all the APPOINTMENTS
        getchar();
        break;
    case 4:
        exit(0);                    //exit the program
        break;
    }
}while(option!=4);
}


