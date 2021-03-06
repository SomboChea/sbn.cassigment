#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void add_first(int);
void add_last(int);
void traverse();
void remove_first();
void remove_last();
int count = 0;
void display_menu();

int main(void)
{
    printf("Welcome!\n");

    int selected, data;

    while (1)
    {
        printf("\n");

        // show menu
        display_menu();

        printf("Enter your option: ");
        scanf("%d", &selected);

        if (selected == 1)
        {
            printf("Enter you element to add first: ");
            scanf("%d", &data);
            add_first(data);
        }
        else if (selected == 2)
        {
            printf("Enter you element to add last: ");
            scanf("%d", &data);
            add_last(data);
        }
        else if (selected == 3)
        {
            traverse();
        }
        else if (selected == 4)
        {
            remove_first;
        }
        else if (selected == 5)
        {
            remove_last();
        }
        else
        {
            printf("\nGoodbye!");
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

void display_menu()
{
    printf("1. Add first element\n");
    printf("2. Add last element\n");
    printf("3. Traverse element\n");
    printf("4. Remove first element\n");
    printf("5. Remove last element\n");
    printf("Any to quite program\n");
}

void add_first(int element)
{
    // init node
    struct node *node;

    // allocate the node for linkedlist
    node = (struct node *)malloc(sizeof(struct node));

    // add the data into node
    node->data = element;

    // count the nodes, that added into data
    count++;

    // check the head, if null put the data into it
    if (head == NULL)
    {
        // replace the node into head
        head = node;

        // set the next of head into null
        head->next = NULL;

        printf("Element %d has been added into the first!", element);

        // return or end this process
        return;
    }

    // put the first element of the head
    // because we need the old head into the next of new head
    node->next = head;

    // replace the head node from current node
    head = node;

    printf("Element %d has been added into the first!", element);
}

void add_last(int element)
{
    struct node *node, *temp;

    node = (struct node *)malloc(sizeof(struct node));
    node->data = element;
    count++;

    if (head == NULL)
    {
        head = node;
        head->next = NULL;

        printf("Element %d has been add into first/last!\n", element);
        return;
    }

    // store current as tempo
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->next = NULL;
    head = temp;
}

void traverse()
{
    struct node *node;

    node = head;

    if (node == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Total elements count: %d in linked list.\n", count);

    while (node->next != NULL)
    {
        printf("%d\n", node->data);
        node = node->next;
    }

    printf("%d\n", node->data);
}

void remove_first()
{
    struct node *node;
    int data;

    if (head == NULL)
    {
        printf("No elements found!\n");
        return;
    }

    data = head->data;
    node = head->next;
    free(head);
    head = node;
    count--;

    printf("Element %d has been removed from first!\n", data);
}

void remove_last()
{
    struct node *node, *temp;
    int data;

    if (head == NULL)
    {
        printf("No elements found!\n");
        return;
    }

    count--;

    if (head->next == NULL)
    {
        data = head->data;
        free(head);
        head = NULL;
        printf("Element %d has been removed from last!\n");
        return;
    }

    node = head;

    while (node->next != NULL)
    {
        temp = node;
        node = node->next;
    }

    data = node->data;
    temp->next = NULL;
    free(node);

    printf("Element %d has been removed from last!\n");
}