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

void delete()
{
    int i,j;
    if(head->link==NULL)
    printf("\n!!--EMPTY LIST--!!\n");
    else
    {
        printf("\nDELETE\n1. First Element\n2. Last Element\n3. Particular Element\nEnter The Value: ");
        scanf("%d",&i);
        ptr=head->link;
        if(i==1)
        {
            ptr=ptr->link;
            head->link=ptr;
            printf("\n---Element Deleted---\n");
        }
        else if(i==2)
        {
            while(ptr->link!=NULL)
            {
                temp=ptr;
                ptr=ptr->link;
            }
            temp->link=NULL;
            printf("\n---Element Deleted---\n");
        }
        else if(i==3)
        {
            show();
            ptr=head->link;
            printf("Enter The Element: ");
            scanf("%d",&j);
            while(ptr->data!=j&&ptr->link!=NULL)
            {
                temp=ptr;
                ptr=ptr->link;
            }
            if(ptr->data==j)
            {
                temp->link=ptr->link;
                printf("\n---Element Deleted---\n");
            }
            else
            printf("\n---Element Not Found---\n");
        }
    }
}
void show()
{
    if(head->link!=NULL)
    {
        ptr=head;
        printf("Your List Items Are: ");
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
            printf("   %d",ptr->data);
        }
        printf("\n");
    }
    else
    printf("!!--LIST EMPTY--!!\n");
}