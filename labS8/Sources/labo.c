#include "labo.h"
#include "labo.h"
#define MAX 100

static long long tab[MAX] = { 0 };

long long fibonacci(int n)
{
    if (n == 0) return 0; //condition de fin
    if (n == 1) return 1;
    if (tab[n] != 0) // Regarde si le calcul de fibonacci(n) a deja ete fait
    {
        return tab[n]; // S'il est fait retourne le calcule
    }
    tab[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return tab[n];
}

TreeNode* tree_create_node(void* data)
{
    TreeNode* treeNode = allocate(sizeof(TreeNode));
    treeNode->data = data;
    treeNode->right = NULL;
    treeNode->left = NULL;
    return treeNode;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
    if (root->left == NULL)
    {
        root->left = node;
    }
    else if (root->right == NULL && root->left != NULL)
    {
        root->right = node;
    }
    else
    {

    }
}

int dfs(TreeNode* root, void* key)
{
    //dans l'exemple donnee il en a 6(l'image de l'arbre en classe A,B,C,D,E,F), faque je prend ce numero car aucun n'a ete donner
    Stack stack = stack_init(6);
    stack_push(&stack, root);
    int count = 0;
    while (stack.top > -1)
    {
        TreeNode* info = stack_pop(&stack);
        count++;
        if (info->data == key)
        {
            return count;
        }
        else
        {
            if (info->right != NULL)
            {
                stack_push(&stack, info->right);
            }
            if (info->left != NULL)
            {
                stack_push(&stack, info->left);
            }
        }
    }
}

int bfs(TreeNode* root, void* key)
{
    Queue* q = allocate(sizeof(Queue));
    queue_init(q);
    queue_push(q, root);
    int count = 0;
    while (q != NULL)
    {
        TreeNode* info = queue_pop(q);
        if (info->data == key)
        {
            count++;
            return count;
        }
        else
        {
            count++;
            if (info->left != NULL)
            {
                queue_push(q, info->left);
            }
            if (info->right != NULL)
            {
                queue_push(q, info->right);
            }

        }
    }
}