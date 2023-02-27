#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void insert();
void delete();
void show();
struct node
{
    int data;
    struct node *link;
}*head,*ptr,*temp;

void main()
{
    int i;
    head=(struct node*) malloc (sizeof(struct node));
    head->link=NULL;
    while(1)
    {
        printf("\n1. Insert   2. Delete   3. Show   4. Exit\nEnter The Process: ");
        scanf("%d",&i);
        switch (i)
        {
        case 1: insert();
            break;
        case 2: delete();
            break;
        case 3: show();
            break;
        case 4: exit(0);
        default:printf("\n!!--Enter A Valid Value--!! ");
            break;
        }
    }
}

void insert()
{
    int i,j;
    printf("1.insertback\n2.insertbeg\n3.insert anywhere\nselect one option:" );
    scanf("%d",&j);
    printf("Enter The Element: ");
    scanf("%d",&i);
    
    if(j==2)
    {
        temp=(struct node *)malloc(sizeof(struct node));
         if(temp==NULL)
         printf("memory underflow,no insertion");
        else
        {
            temp->data=i;
            temp->link=head->link;
            head->link=temp;
        }
    }

    else if(j==1)
    {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=i;
    temp->link=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    ptr=ptr->link;
    ptr->link=temp;
    }

    else if(j==3)
    {
     int key;
     temp=(struct node *)malloc(sizeof(struct node));
     show();
     printf("enter the key value:");
     scanf("%d",&key);
     temp->data=i;
     ptr=head;
     while(ptr->data!=key && ptr->link!=NULL)
     ptr=ptr->link;
     if(ptr->link==NULL)
     printf("SEARCH FAILS");
     else
     {
        temp->link=ptr->link;
        ptr->link=temp;
     }
     
    }
    

}