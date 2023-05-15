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
	Node *aux = head;
	printf("Noduri: ");
	while(aux!=NULL)
    {
		printf("%d ",aux->val);
		aux = aux->next;
	}
	printf("\n");
}

Node* Inserare(Node *head, Data v)
{
	Node *aux;
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=NULL;

	if(head==NULL)
    {
		head = newNode;
	}
	else if(newNode->val <= head->val)
        {
		newNode->next = head;
		head = newNode;
        }
	else
    {
		aux = head;
		while(aux->next!=NULL&&aux->next->val<newNode->val)
		{
			aux = aux->next;
        }
		newNode->next = aux->next;
		aux->next = newNode;
	}
	return head;
}

void printR(Node*head)
{
    if (head!=NULL)
    {
        printR(head->next);
        printf("%d " ,head->val);
    }
}

void Elim_Dub(Node* head)
{
    Node *p1,*p2,*dub;
    p1=head;
    while(p1!=NULL && p1->next!=NULL)
    {
        p2=p1;
        while(p2->next!=NULL)
        {
            if (p1->val==p2->next->val)
            {
                dub=p2->next;
                p2->next=p2->next->next;
            }
            else
                p2=p2->next;
        }
        p1=p1->next;
    }
}

void print(Node*head)
{
    while(head!=NULL)
    {
        printf("%d " , head->val);
        head=head->next;
    }
}

int main()
{
	Node *head = NULL;
	head = Inserare(head,2);
	head = Inserare(head,3);
	head = Inserare(head,1);
	head = Inserare(head,9);
    head = Inserare(head,3);
	head = Inserare(head,8);

	afisare(head);

	printf("Lista invers: ");
    printR(head);
    printf ("\n");

	printf("Dublurile eliminate: ");
    Elim_Dub(head);
    print(head);
}
