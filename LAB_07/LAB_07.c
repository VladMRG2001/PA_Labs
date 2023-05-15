#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct N Node;
struct N
{
    Data val;
    struct N *left,*right;
};

typedef struct elem stackNode;

struct elem
{
    Node *val; //adresa nod arbore
    struct elem *next;
};

Node* CreateBalanced(int N)
{
    Data val;
    if (N>0)
    {
        Node* root= (Node*)malloc(sizeof(Node));
        //printf("Val nod ");
        scanf("%d", &val);
        (root->val)=val;
        root->left= CreateBalanced (N/2);
        root->right= CreateBalanced(N-1-N/2);
        return root;
    }
    else return NULL;
}

void push(stackNode**top, Node* v)
{
    stackNode* newNode=(stackNode*)malloc(sizeof(stackNode));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;
}
int isEmpty(stackNode*top)
{
    return top==NULL;
}
Node* pop(stackNode**top)
{
    if (isEmpty(*top)) return NULL;
    stackNode *temp=(*top);
    Node* d=temp->val;
    *top=(*top)->next;
    free(temp);
    return d;
}

void deleteStack(stackNode** top)
{
    stackNode* topCopy=*top, *temp;
    while (topCopy!=NULL)
    {
        temp=topCopy;
        topCopy=topCopy->next;
        printf("%d",temp->val);
        free(temp);
    }
    *top=NULL;
}

void inorderNRec(Node*root)
{
    stackNode *S = NULL;
    while (1)
    {
        while (root)
        {
            push(&S, root);
            root=root->left;
        }
        if (isEmpty(S)) break;
        root = pop(&S);
        printf ("%d ", root->val);
        root = root ->right;
    }
    deleteStack(&S);
}

Node* findLCA(Node* root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == n1 || root->val == n2)
    {
        return root;
    }
    else
    {
        Node  *left = findLCA(root->left, n1, n2);
        Node *right = findLCA(root->right, n1, n2);
        if(left && right)
        {
            return root;
        }
        if(left)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

void free_tree(Node * node)
{
    if (node != NULL)
    {
        free_tree(node->right);
        free(node->val);
        free_tree(node->left);
        free(node);
    }
}

int main()
{
    int N;
    printf("Cate noduri? ");
    scanf("%d",&N);
    Node *root=NULL;
    printf("Nodurile sunt: ");
    root= CreateBalanced (N);
    //preorderNRec(root);
    printf("Nodurile in inordine: ");
    inorderNRec(root);
    int a,b;
    printf("\nCele doua noduri pt care se calc LCA: ");
    scanf("%d %d", &a, &b);
    printf("LCA: %d\n",
           findLCA(root, a, b)->val);
    //findLCA(root, 60, 43)->val);

    free_tree(root);
    return 0;
}
