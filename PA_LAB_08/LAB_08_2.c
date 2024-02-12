#include <stdio.h>
#include <stdlib.h>

typedef int Data;

//typedef struct N Node;

struct Node
{
    Data val; // datele efective memorate
    struct Node *left,*right; // legaturi catre (adresele) subarborii din stanga si dreapta
};

struct Node* newNode(Data data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int key)
{
    // daca (sub)arborele e gol – se creaza un nod
//si se returneaza adresa, altfel continua cautarea pozitiei
//si se returneaza adresa nodului investigat
    if (node == NULL) return newNode(key);
//practic, nodul adaugat va fi mereu nod frunza
//altfel se coboara la stanga sau dreapta in arbore
    if (key < node->val) node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node; // pointerul node se intoarce nemodificat pe acest return
} //nu se adauga elemente egale

void inorder(struct Node*root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

struct Node* kthSmallest(struct Node* root, int* counter, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct Node* left = kthSmallest(root->left, counter, k);
    if (left != NULL)
    {
        return left;
    }
    if (++(*counter) == k)
    {
        return root;
    }
    return kthSmallest(root->right, counter, k);
}

struct Node* findKthSmallest(struct Node* root, int k)
{
    int counter = 0;
    return kthSmallest(root, &counter, k);
}

int main()
{
    struct Node *root=NULL;
    int i=0;
    printf("Introduceti noduri (val>0): ");
    while (i>-1)
    {
        scanf("%d",&i);
        if (i>-1)
            root=insert(root,i);
    }
    printf("Afisare in inordine: ");
    inorder(root);

    int k;
    printf("\nAl catelea cel mai mic nod? ");
    scanf("%d",&k);
    struct Node* result = findKthSmallest(root, k);

    if (result)
    {
        printf("Al %d-lea cel mai mic nod este %d", k, result->val);
    }
    else
    {
        printf("Al %d-lea cel mai mic nod nu exista", k);
    }
    return 0;
}
