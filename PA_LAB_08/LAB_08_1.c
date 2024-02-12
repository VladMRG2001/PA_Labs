#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Data;

typedef struct N Node;

struct N
{
    Data val;
    struct N *left,*right;
};

Node* Create ()  // datele citite in varianta de parcurgere preordine
{
    Data val;
    char c;
    Node* root= (Node*)malloc(sizeof(Node));
    printf("Dati valoarea pentru nod: ");
    scanf("%d", &val);
    root->val =val;
    printf("Nodul adaugat are subarbore stang? d/n ");
    scanf("%s", &c);
    if (c=='d') root->left= Create( );
    else root->left=NULL;
    printf(" Nodul adaugat are subarbore drept? d/n " );
    scanf("%s", &c);
    if (c=='d') root->right= Create( );
    else root->right=NULL;
    return root;
}

int verif_BST(Node* node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->val < min)
        return 0;
    if (node->val > max)
        return 0;
    return verif_BST(node->right, node->val, max) &&
           verif_BST(node->left, min, node->val);
}

int main()
{
    Node *root=NULL;
    root= Create();
    int min = INT_MIN;
    int max = INT_MAX;
    if(verif_BST(root, min, max))
    {
        printf("Arborele binar e BST.");
    }
    else
    {
        printf("Arborele binar nu e BST.");
    }
}
