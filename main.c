#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
struct node *start=NULL;

void push()
{
    int dat;
    scanf("%d", &dat);
    struct node *temp=start, *temp2;
    if(start==NULL)
    {

        struct node *temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=dat;
        temp1->prev=NULL;
        temp1->next=NULL;
        start=temp1;
        return;
    }
   while(temp!=NULL)
   {
       temp2=temp;
       temp=temp->next;
   }

   struct node *temp1=(struct node*)malloc(sizeof(struct node));
   temp1->data=dat;
   temp2->next=temp1;
   temp1->prev=temp2;
   temp1->next=NULL;
   return;

}
void pop()
{
    struct node *temp;
    temp=start;
  while(temp->next !=NULL)
  {
      temp=temp->next;
  }
  temp->prev->next=NULL;
      free(temp);

}

void del()
{
    int dat;
    printf("Which uh want to delete\n");
    scanf("%d", &dat);
    struct node* temp;
    temp=start;
    while(temp!=NULL)
    {
        if(temp==start && temp->data==dat)
        {
            start=temp->next;
            free (temp);
            break;
        }
        if(temp->next==NULL && temp->data==dat)
        {
            temp->prev->next=NULL;
            free(temp);
        }
        if(temp->data==dat)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            break;

        }
        else{
            temp=temp->next;
        }

    }

}
void insaf()
{
  int dat,count=0,dd;
  printf("After which uh want to insert\n");
  scanf("%d", &dat);
  printf("Enter number uh want to insert\n");
  scanf("%d", &dd);
  struct node* temp;
  temp=start;
  while(temp!=NULL)
  {
    if((temp->next==NULL) && (temp->data==dat))
      {
         struct node *ins=(struct node*)malloc(sizeof(struct node));
         ins->data=dd;
         ins->prev=temp;
         ins->next=NULL;
         temp->next=ins;
         break;
      }

     else if(temp->data==dat)
      {
          struct node* ins=(struct node*)malloc(sizeof(struct node));

          ins->data=dd;
          ins->prev=temp;
          ins->next=temp->next;
          temp->next->prev=ins;
          temp->next=ins;
          count++;
          break;
      }
    temp=temp->next;
}




}

void sort()
{

   while(1)
   {
       int swap=0;
       struct node *temp=start;
       while(temp->next!=NULL)
       {
           if(temp->data > temp->next->data)
           {
               int var=temp->data;
               temp->data=temp->next->data;
               temp->next->data=var;
               swap++;
           }
           temp=temp->next;
       }
       if(swap==0)
       {
           break;
       }

   }
}

int main()
{
   printf("Number of push uh want initially\n");
   int a;
   scanf("%d", &a);
   int i;
   for( i=0;i<a;i++)
   {
       push();

   }

   struct node *temp;
   temp=start;
   while(temp!=NULL)
   {
       printf("%d ", temp->data);
       temp=temp->next;

   }
   printf("\n");
   int chang,k;
   printf("How many times uh want to modify\n");
   scanf("%d", &chang);
   for(k=0;k<chang;k++)
   {
    printf("1-push, 2-pop, 3-delete, 4-insert_after, 5-sort\n");
    int cas;
   scanf("%d", &cas);
   switch(cas)
   {
   case 1:
    printf("Number you want to push\n");
    push();
    break;

   case 2:
    pop();
    break;

   case 3:
    del();
    break;

   case 4:
    insaf();
    break;

   case 5:
    sort();
    break;
   }
      temp=start;
    printf("\n");
   while(temp!=NULL)
   {
       printf("%d ", temp->data);
       temp=temp->next;

   }
   printf("\n");
   }
   return 0;




}
