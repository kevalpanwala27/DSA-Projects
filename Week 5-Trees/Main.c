#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char student_name[40];
    char roll_no[12];
    char email_ID[40];
    char phone[11];

    struct node*left;
    struct node*right;
};

struct node*head=NULL;
char temp_name[40];
char temp_rollno[12];
char temp_email_ID[40];
char temp_phone[11];
FILE *fp;

struct node* createNode(char *student_name,char *roll_no,char *email_ID,char *phone)
{
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    strcpy(new_node->student_name,student_name);
    strcpy(new_node->roll_no,roll_no);
    strcpy(new_node->email_ID,email_ID);
    strcpy(new_node->phone,phone);
    
    new_node->left=new_node->right=NULL;
    return new_node;
}


void insert(char *student_name,char *roll_no,char *email_ID,char *phone)
{
    struct node*root=head;
    struct node *prev = NULL;

    if(root==NULL){
        struct node*new_node=createNode(student_name,roll_no,email_ID,phone);
        head=new_node;
        return;
    }
    while(root!=NULL){
        prev = root;
        if(strcmp(root->roll_no,roll_no)==0){
            printf("Roll no.  is already present !");
            return;
        }
        else if(strcmp(root->roll_no,roll_no)>0){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(student_name,roll_no,email_ID,phone);
    if(strcmp(prev->roll_no,roll_no)>0){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct node* inorderpre(struct node* node)
{
    while (node->right != NULL)
        node = node->right;
 
    return node;
}

struct node* deleteNode(struct node* root, char*roll_no)
{
    if (root == NULL)
        return root;
 
    if (strcmp(root->roll_no,roll_no)>0)
        root->left = deleteNode(root->left, roll_no);
 
    else if (strcmp(root->roll_no,roll_no)<0)
        root->right = deleteNode(root->right, roll_no);

    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = inorderpre(root->left);
        strcpy(root->roll_no,temp->roll_no);
        root->left = deleteNode(root->left, temp->roll_no);
    }
    return root;
}

void search(struct node*root,char *roll){
    if(root!=NULL){
        search(root->left,roll);
        if(strstr(root->roll_no,roll)){
            printf(" Student Name : %-12s | Roll No: %-10s | Email ID: %-15s  |  Phone no:%-10s\n",root->student_name,root->roll_no,root->email_ID,root->phone);
        }
        search(root->right,roll);
    }
}

void show_ascending(struct node*root){
    if(root!=NULL){
        show_ascending(root->left);
        printf(" Student Name : %-12s | Roll No: %-10s | Email ID: %-15s  |  Phone no:%-10s\n",root->student_name,root->roll_no,root->email_ID,root->phone);
        show_ascending(root->right);
    }
}

void show_descending(struct node*root){
    if(root!=NULL){
        show_descending(root->right);
        printf(" Student Name : %-12s | Roll No: %-10s | Email ID: %-15s  |  Phone no:%-10s\n",root->student_name,root->roll_no,root->email_ID,root->phone);
        show_descending(root->left);
    }
}

int main(){
	printf("\n\n<--------------STUDENT RECORDS USING TREES-------------->\n\n");
    menu:    
    printf("1. Insert New Student\n");
    printf("2. Delete Student\n");
    printf("3. Search Student\n");
    printf("4. Show in Ascending Order\n");
    printf("5. Show in Descending Order\n");
    //printf("6. Exit Program\n");
    int choice;
    int i=1;
    printf("Enter Choice : \n");
    scanf("%d",&choice);
    printf("\n");
    if(choice==1){
        printf("Enter Student Name : ");
        while((getchar())!='\n');
        scanf("%[^\n]%*c",temp_name);

        printf("Enter Roll no. : ");
        scanf("%[^\n]%*c",temp_rollno);

        printf("Enter email ID . : ");
        scanf("%[^\n]%*c",temp_email_ID);

        printf("Enter Phone no. : ");
        scanf("%[^\n]%*c",temp_phone);
        insert(temp_name,temp_phone,temp_email_ID,temp_phone);
    }
    else if(choice==2){
        if(head==NULL){
            printf("No entry to delete !\n");
            goto menu;
        }
        printf("Enter Roll no to delete : ");
        while((getchar())!='\n');
        scanf("%[^\n]%*c",temp_rollno);
        head=deleteNode(head,temp_rollno);
        printf("Record deleted successfully ");
    }
    else if(choice==3){
        struct node*root=head;
        if(root==NULL){
            printf("\nNo Record to search !\n");
            goto menu;
        }
        printf("Enter Roll no. : ");
        while((getchar())!='\n');
        scanf("%[^\n]%*c",temp_rollno);
        printf("\n");
        search(root,temp_rollno);
        printf("\n");
    }
    else if(choice==4){
        struct node*root=head;
        if(root==NULL){
            printf("\nNo Contacts are there !\n");
            goto menu;
        }
        printf("\nPrinting in Ascending Order :\n");
        show_ascending(root);
        printf("\n");
       //do
		//{		
	        fp = fopen("myfile4.txt", "w");
	      //  fprintf(fp, "%s",root);
	        fprintf(fp,"%d ->  Student's name  = %s | Roll no: %s | EmailID: %s | Phone : %s ",i,temp_name,temp_rollno,temp_email_ID,temp_phone); 
	        fclose(fp);
	     //   i++;
       // }while (root!=NULL);
    }
    else if(choice==5){
        struct node*root=head;
        if(root==NULL){
            printf("\nNo Contacts are there !\n");
            goto menu;
        }
        printf("\nPrinting in Descending Order :\n");
        show_descending(root);
        printf("\n");
    }
   // else if(choice==6){
        //exit(0);
   // }
    else{
        printf("Enter correct choice !\n");
    }
    goto menu;
    return 0;
}









