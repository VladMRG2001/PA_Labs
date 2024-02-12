#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct N Node;

struct N
    {
        Data val; // datele efective memorate
        struct N *left,*right; // legaturi catre (adresele) subarborii din stanga si dreapta
    };

Node* newNode(Data data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int key)
{ // daca (sub)arborele e gol – se creaza un nod
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

void inorder(Node*root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

void gasire_p_s(Node* root,int a, Node** p, Node** q)
{
    if(!root)
        return ;
    gasire_p_s(root->left, a, p, q);
    if(root&&root->val > a)
    {
        if((!*q) || (*q) && (*q)->val > root->val)
                *q = root;
    }
    else if(root && root->val < a)
    {
        *p = root;
    }
    gasire_p_s(root->right, a, p, q);
}

int main()
{
    Node *root=NULL;
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

    Node* p = NULL, *q = NULL;
    int a;
    printf("\nNodul cu cheia K: ");
    scanf("%d",&a);

    gasire_p_s(root, a, &p, &q);

    if(p!=NULL)
        printf("Predecesorul este %d \n",p->val);
        printf("Adresa predecesorului este %p\n",&p->val);
    if(q!=NULL)
        printf("Succesorul este %d \n",q->val);
        printf("Adresa succesorului este %p\n",&q->val);
    return 0;
}

