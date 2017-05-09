#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void removeNode( Node **head, int rm_data )
{
    for (Node **cur = head; *cur; )
    {
        Node *en = *cur;
        if (en->data == rm_data)
        {
            *cur = en->next;
            free(en);
        }
        else
            cur = &en->next;
    }
}
void create (Node **head)
{
    Node *rear;
    rear = *head;
    for (int i=0;i!=5; i++)
    {
        Node *t = (Node*)malloc(sizeof(Node));
        t->data = i%2;
        if(*head == NULL)
            *head = t;
        else
            rear->next = t;
        rear = t;
    }
    rear->next = NULL;
}
void print(Node **head)
{
    for(Node *cur = *head; cur;)
    {
        printf("%d", cur->data);
        cur = cur->next;
    }
}
int main()
{
    Node *head = NULL;
    create( &head );
    print( &head );
    removeNode(&head, 1);
    printf("\n");
    print(&head);
    return 0;
}
