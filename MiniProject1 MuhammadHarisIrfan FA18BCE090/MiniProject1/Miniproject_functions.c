///------------Muhammad Haris Irfan--FA18-BCE-090---------MINI PROJECT 1-----------------------------------------------------------------///

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Student.h"
#include "Miniproject_headers.h"


void inputEmployeeData(struct employee * emp)
{
    fflush(stdin);
    printf("\nEnter the First name of the employee: ");
    fgets(emp->first_name, 50, stdin);
fflush(stdin);
    printf("\nEnter the Surname of the employee: ");
    fgets(emp->surname, 50, stdin);
fflush(stdin);
    printf("\nEnter the Session of the employee: ");
    fgets(emp->session, 50, stdin);
fflush(stdin);
    printf("\nEnter the program of the employee: ");
    fgets(emp->program, 50, stdin);
fflush(stdin);
    printf("\nEnter the Intake year of the employee: ");
    scanf("%d", &(emp->intake_year));
fflush(stdin);
    printf("\nEnter the Roll Number of the employee: ");
    scanf("%d", &(emp->roll_no));
fflush(stdin);
    printf("\nRecord entered !\n");
}


void printEmployeeData(struct employee * emp)
{
    printf("\n---------------------------------------\n");

    printf("\nFirst Name:\t %s", emp->first_name);
    printf("Surname:\t %s", emp->surname);
    printf("Intake year:\t %d\n", emp->intake_year);
    printf("Session:\t %s", emp->session);
    printf("Program:\t %s", emp->program);
    printf("Roll Number:\t %d\n", emp->roll_no);

    printf("\n---------------------------------------\n");
}


void inputNodeData(struct node * node_x)
{
   inputEmployeeData(& node_x->data);
}

void printNodeData(struct node * node_x)
{
   printEmployeeData(& node_x->data);
}


void printList(struct node * head)
{
    struct node * ptr = head;
    printf("\nStart of list: \n");

    //start from the beginning
    while(ptr != NULL)
    {
       printNodeData(ptr);
       ptr = ptr->next;
    }

    printf("\nEnd of list.\n");
}


void  insertNodeAtEnd(struct node ** head)
{

   struct node * temp = *head;

   ///create a new node
   struct node * new_node = (struct node *) malloc(sizeof(struct node));

   inputNodeData(new_node);  /// get data for the newly created node from the user.

   ///point its next pointer to NULL
   new_node->next = NULL;

   if(isListEmpty(*head))    /// if currently the list is empty
   {
    *head = new_node;
   }
   else
   {
    while((temp->next) != NULL)
        temp = temp->next;      /// scroll to the end of the list
    temp->next = new_node;
   }


}


bool isListEmpty(struct node * head)
{
    return (head == NULL);
}


int getListLength(struct node * head)
{
    int length = 0;
    struct node * current;

    for(current = head; current != NULL; current = current->next)
    {
      length++;
    }

   return length;
}


int searchNodeByData(struct node * head, int field_num)
{
    int idx = 1;
    switch(field_num)
    {
        case EMP_NAME:
        {
            printf("\nEnter a name to search: ");
            char searchName[50];
            fgets(searchName, 50, stdin);
            idx = searchDataByName(head, searchName);

            if(idx == -1)
                printf("\nName searched for is not found!!\n");
            else
                printf("\nThe name exists at index %d\n", idx);

            break;
        }

        case EMP_ROLL:
        {
            printf("\nEnter an age to search: ");
            int roll=0;
            scanf("%d", &roll);
            idx = searchDataByroll(head, roll);

            if(idx == -1)
                printf("\nRoll number searched for is not found!!\n");
            else
                printf("\nThe roll number exists at index %d\n", idx);

            break;
        }

        case EMP_IntakeY:
        {
            printf("\nEnter a Basic Salary to search: ");
            float searchInt;
            scanf("%f", &searchInt);
            idx = searchDataByIntakeYear(head, searchInt);

            if(idx == -1)
                printf("\nIntake Year searched for is not found!!\n");
            else
                printf("\nThe Intake Year exists at index %d\n", idx);


            break;
        }

    }
    return(idx);
}

int searchDataByName(struct node* head, char * name)
{

    struct node * temp = head;
    int index = 1;

    while((strcmp(temp->data.first_name,name) != 0) && ((temp->next) != NULL))
    {
        temp = temp->next;

        index ++;
    }
    if((temp->next == NULL) && (strcmp(temp->data.first_name,name) != 0))
        return(-1);

    return (index);
}

int searchDataByroll(struct node* head, int roll)
{

    struct node * temp = head;
    int index = 1;

    while(((temp->data.roll_no) != roll) && ((temp->next) != NULL))
    {
        temp = temp->next;

        index ++;
    }
    if((temp->next == NULL) && ((temp->data.roll_no) != roll))
        return(-1);

    return (index); /// name found at index
}

int searchDataByIntakeYear(struct node* head, float intake_year)
{

    struct node * temp = head;
    int index = 1;

    while(((temp->data.intake_year) != intake_year) && ((temp->next) != NULL))
    {
        temp = temp->next;

        index ++;
    }
    if((temp->next == NULL) && ((temp->data.intake_year) != intake_year))
        return(-1);

    return (index);
}



int  insertNodeAfter(struct node * head, int idx)
{
    int index = 0;

    struct node * temp = head;

    if(isListEmpty(head))
    {
        return(-1);
    }


    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    inputNodeData(new_node);


    while((index != idx) && (temp->next) != NULL)
    {
      index ++;
      temp = temp->next;
    }
    if((temp->next == NULL) && (index != idx))
    {
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return(-1);
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return(0);
}


void deleteNodeFromEnd(struct node * head)
{
    struct node * p1 = head, * p2;

    while(p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }

    free(p2->next);
    p2->next = NULL;
}


int loadListFromFile(struct node ** head, FILE * fptr)
{
    struct employee  new_record;

    struct node * temp = *head;

    while(fread(& new_record, sizeof(struct employee), 1, fptr) )
    {

        struct node * new_node = (struct node *) malloc(sizeof(struct node));

        new_node->data = new_record;

        new_node->next = NULL;

        if(*head == NULL)
        {
            *head = new_node;
            temp = *head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }

    }
    return(0);
}

int  insertNodeBefore(struct node * head, int idx)
{

   int index = 0;
    struct node * temp = head;

    if(isListEmpty(head))
    {
        return(-1);
    }

    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    inputNodeData(new_node);


    while((index != (idx-1) && (temp->next) != NULL))
    {
      index ++;
      temp = temp->next;
    }
    if((temp->next == NULL) && (index != (idx-1)) )
    {
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return(-1);
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return(0);
}


int  insertNodeAtStart(struct node ** head)
{

 if(head==NULL)
 {
 *head= (struct node *) malloc(sizeof(struct node));

 }
 struct node * new_node = (struct node *) malloc(sizeof(struct node));

  inputNodeData(new_node);

 new_node->next=*head;
 *head=new_node;

}


void deleteNodeFromStart(struct node ** head)
{

if(*head==NULL)
 {
 printf("\nthe list is already empty\n");

 }
 else
 {

 if((*head)->next==NULL)
 {
     free(*head);


 }

 else
    {
    *head=(*head)->next;


    }

printf("\nThe Node from the start is Deleted\n");
 }

}


int  deleteNodeAfter(struct node * head, int idx)
{


   int index=1;
    struct node * movinghead = head;
    struct node * del= head;
    struct node * last =head;


    if(head==NULL)
    {
        printf("\n The List is Empty\n");
        return;
    }

    for(index=1;index<idx;index++)
    {
     del=del->next;
     last=last->next;

    }
    last=last->next;
    del->next=last->next;

      free(last);


return(0);
}

int saveListToFile(struct node * head, FILE * fptr)
{

    struct node * temp = head;
    if(head == NULL)
        return(-1);

    while(temp != NULL)
    {
        fwrite(&(temp->data), sizeof(struct employee), 1,  fptr);
        temp = temp->next;
    }

    printf("Data Saved");
    return(0);

}


void sortbyIntake(struct node **h)
{
    int i,j,a;


    struct node *temp1;
    struct node *temp2;
    struct employee temp3;


    for(temp1=*h;temp1!=NULL;temp1=temp1->next)
      {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          {
            if(temp2->data.intake_year < temp1->data.intake_year)
              {

                temp3 = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp3;
              }
           }
       }
        printf("\n Data Sorted According to Intake year in Accending order\n");
    printf("\n Data after sorting is:\n");
    printList(*h);
}

void sortbyRollnumber(struct node **h)
{
    int i,j,a;

    struct node *temp1;
    struct node *temp2;
    struct employee temp3;


    for(temp1=*h;temp1!=NULL;temp1=temp1->next)
      {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          {
            if(temp2->data.roll_no< temp1->data.roll_no)
              {
                temp3 = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp3;
              }
           }
       }
        printf("\n Data Sorted According to RollNumber in Accending order\n");
    printf("\n Data after sorting is:\n");
    printList(*h);
}
void  Edit(struct node * head)
{
    int i = 1;
    int loc=0;

    struct node *right;
    right=head;

    printf("Enter location\n");
    scanf("%d",&loc);


    int len = getListLength(head);

    if (loc>len)
    {
        printf("Invalid location");

    }
    else
    {
        while (i  != loc  && right->next!=NULL)
        {
            right=right->next;
             i++;
        }

      inputNodeData(right);
    }
}
