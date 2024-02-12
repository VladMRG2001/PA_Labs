#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Elem
{
    Data val;
    struct Elem* next;
};
typedef struct Elem Node;

void afisare(Node *head)
{
    Node *temp;

    temp = head;
    printf("%d  ", temp->val);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d  ", temp->val);
        temp = temp->next;
    }
    //printf("%d   ", temp->val);
    printf("\n");
}

int eliminare(Node **head, int n)
{
    Node *headcopy,*aux;
    int i;
    headcopy = *head;
    aux = headcopy;
    while(headcopy->next!=headcopy)
    {
        for(i=-0;i<n-1;i++)
        {
            aux=headcopy;
            headcopy=headcopy->next;
        }
        aux->next = headcopy->next;
        printf("%d a fost eliminat\n", headcopy->val);
        free(headcopy);
        headcopy=aux->next;
    }
    *head=headcopy;

    return (headcopy->val);
}

void addAtPos(Node**head, int val, Node* pos)
{
    Node *headcopy=*head;
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
    if (*head==NULL)
    {
        newNode->next=newNode;
        *head=newNode;
    }
    else
    {
        newNode->next=pos->next;
        pos->next=newNode;
    }
}

int main()
{
    int castigator, salt;
    int i;
    Node* head = NULL;

    for (i=0;i<7;i++)
    {
        addAtPos(&head,i,head);
    }

    printf("Lista circulara:\n");
    afisare(head);
    printf("Peste cate persoane se sare: ");
    scanf("%d", &salt);
    castigator = eliminare(&head, salt);
    printf("Castigatorul este: %d\n", castigator);
    free(head);

    return 0;
}
