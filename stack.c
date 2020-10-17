#include <stdio.h>
#include <stdlib.h>


// FUNCTION DECLARATIONS
void push();
void pop();
void display();


// NODE DEFINITION
struct node
{
int value;
struct node *next;
};


// DECLARING HEAD NODE
struct node *head;


void main()
{
    int option=0;
    printf("\n=== STACK USING LINKED LIST ===\n");
    while(option != 4)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\nEnter an option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Program Finished... ");
                break;
            }
            default:
            {
                printf("Enter a valid character!");
            }
        };
    }
}


void push ()
{
    int value;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("PUSH FAILED!");
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d",&value);
        if(head==NULL)
        {
            ptr->value = value;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->value = value;
            ptr->next = head;
            head=ptr;

        }
        printf("PUSH COMPLETED!\n");

    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        item = head->value;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("POP COMPLETED!\n");

    }
}

void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("Displaying Stack...\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->value);
            ptr = ptr->next;
        }
    }
}

