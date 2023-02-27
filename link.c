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