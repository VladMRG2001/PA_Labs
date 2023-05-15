#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INT_MIN -1000
//typedef int Data;
typedef char Data;

struct Elem
{
    Data val;
    struct Elem* next;
};

typedef struct Elem Node;

struct Q
{
    Node *front, *rear;
};

typedef struct Q Queue;

Queue* createQueue()
{
    Queue *q;
    q=(Queue *)malloc(sizeof(Queue));
    if (q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}

void enQueue(Queue*q, Data v)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=NULL;
    if (q->rear==NULL) q->rear=newNode;
    else
    {
        (q->rear)->next=newNode;
        (q->rear)=newNode;
    }
    if (q->front==NULL) q->front=q->rear;
    //printf("%c",newNode->val);
}

void push(Node**top, Data v)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;
}

int isEmpty(Node*top)
{
    return (top==NULL);
}

int isFull(Node*top)
{
    return (top!=NULL);
}

Data pop(Node**top)
{
    Node *temp; Data aux;
    if (isEmpty(*top)) return INT_MIN;
    temp=(*top);
    aux=temp->val;
    *top=(*top)->next;
    free(temp);
    return aux;
}

Data top(Node *top)
{
    if (isEmpty(top)) return INT_MIN;
    return top->val;
}

int main()
{
    int i;
    char s[20]="stop";
    for(int j=0;;j++)
    {
        char v[20];
    scanf("%s", v);
    if(strcmp(v,s)==0) return 7;
    //printf("%d \n", strlen(v));
    Queue* q;
    q=createQueue();
    for (i=0;i<strlen(v)+1;i++)
    enQueue(q,v[i]);
   // printf("\n");

    Node* stackTop = NULL;
    for (i=0;i<strlen(v);i++)
    push(&stackTop,v[i]);
    while(!isEmpty(stackTop))
        printf("%c",pop(&stackTop));

    printf("\n");
    }
    return 0;
}
