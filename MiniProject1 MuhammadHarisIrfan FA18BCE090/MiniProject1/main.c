///------------Muhammad Haris Irfan--FA18-BCE-090---------MINI PROJECT 1-----------------------------------------------------------------///
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Student.h"
#include "Miniproject_headers.h"

void flush();

int main()
{
    int choice;
    char load_choice;
    struct node * head = NULL;

    printf("------------Database Management System----------------");

    printf("\nDo you want to Access our Database? (y/n): ");
    load_choice = getchar();

    if(load_choice == 'y')
    {
        FILE * fptr = NULL;
        if((fptr=fopen("StudentDB.dat", "rb")) == NULL)
        {
            printf("\nCannot open file for loading Data!!\n\n");
            exit(1);
        }
        loadListFromFile(&head, fptr); ///this is loading of my database
        fclose(fptr);
    }
    system ("cls");
    while(1)
    {

         printf("------------Database Management System----------------\n\n");
        printf("\nWhat do you want to do now?\n");
        int op;

        printf("\n1. Add new data to Database?");
        printf("\n2. Delete data from Database?");
        printf("\n3. Print the Database.");
        printf("\n4. Search the Database by Data Field.");
        printf("\n5. Save data to Database.");
        printf("\n6. Sorting.");
        printf("\n7. Edit a Data in Database.");
        printf("\n8. Exit the menu.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add
            {
system ("cls");
            int op;
                printf("\nWhat do you want to do?\n\n");
           printf("\n1. Insert a new node at the end of the list.");
           printf("\n2. Insert a new node after index.");
           printf("\n3. Insert a Node before a Node.");
           printf("\n4. Insert a Node at Start.");

                scanf("%d", &op);
                flush();

                  switch(op)
                  {
                  case 1:
                    {
                printf("\nAdding a new node: \n\n");
                insertNodeAtEnd(&head);
                system ("cls");
                break;
            }


                  case 2:
                    {
                int idx = 0;
                printf("\nEnter the index after which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeAfter(head, idx) == 0)
                    printf("\nNode inserted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");

                break;
                    }
                    case 3:
                    {
                 printf("\nInserting a Node before a Node.\n\n");
               int idx = 0;
                printf("\nEnter the index after which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeBefore(head, idx) == 0)
                    printf("\nNode inserted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");
system ("cls");
                break;
                    }
                    case 4:
                    {
printf("\nInserting a Node at Start. \n\n");
                     insertNodeAtStart(&head);
                system ("cls");
                break;
                    }

                  }
system ("cls");

                break;
            }

             case    2:  /// Delete
        {

            int op;
                printf("\nWhat do you want to do?\n\n");
           printf("\n1. Delete the last item from the list.");
           printf("\n2. Delete a node from start.");
           printf("\n3. Delete a node after a node.");


                scanf("%d", &op);
                flush();

                  switch(op)
                  {
                  case 1:
                    {
                deleteNodeFromEnd(head);
                printf("\nLast node deleted!!\n");
                system ("cls");
                break;
                    }


                  case 2:
                    {
                printf("\nDeleting a node from start \n\n");
                deleteNodeFromStart(&head);
               system ("cls");
                break;

                    }
                    case 3:
                    {
              printf("\nDeleting a node after a node \n\n");
                 int idx = 1;
                printf("\nEnter the index after which you want to delete a node: ");
                scanf("%d",&idx);
                flush();
                if(deleteNodeAfter(head,idx) == 0)
                    printf("\nNode deleted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");
system ("cls");
                break;

                    }


                  }

                break;
            }

            case    3:  /// Print the list.
            {
                system ("cls");
                printList(head);
                break;
            }

             case    4:  /// Search the list for a Data Field
            {
                system ("cls");
                int field_choice, idx=0;
                printf("\nEnter a Data Field to search by: (1 - 3)\n");
                printf("\n\t1. Name \n");
                printf("\n\t2. Roll Number \n");
                printf("\n\t3. Intake Year \n");
                scanf("%d", &field_choice);
                flush();

                idx = searchNodeByData(head, field_choice);

                break;
            }

            case    5:   /// Save list to file
            {
                system ("cls");
                FILE * fptr = NULL;
                if((fptr=fopen("StudentDB.dat", "wb+")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(head, fptr);

                break;
            }

           case    6:   /// sorting.
            {
                system ("cls");
                int a;

printf("\n11. What do you want to sort by?\n1- Intake Year.\n2- Roll Number.\n.");
scanf("%d",&a);
switch(a)
{
case 1:
    {

        sortbyIntake(&head);

        break;
    }
case 2:
    {

        sortbyRollnumber(&head);
        break;
    }
}
                break;
            }
           case 7:       ///edit
                {
                system ("cls");
                    Edit(head);
                    break;
                }

            case    8:  /// Exit the program.
            {
                system ("cls");
                printf("\nExiting the Database on your request.\n\n");
                return(0);
            }
        }
    }
    return 0;
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
