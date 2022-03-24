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
	tab[n] = fibonacci(n-1) + fibonacci(n-2);
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
	// 0 cree stack -> ajouter root a stack
	/*1 verifier si ma stack est vide, sinon on pop l'element du top

	2 Dans un algorithme de recherche on aurait une comparaison, comme exemple, si le character est F on
	a trouver le noeud puis on retournerais le noeud

	3 apres la comparaison, on considere ce noeud comme le noeud courant et on push le right puis le left,
	on push le left en dernier puisque l'on veut
	aller en profondeur avant d'aller latteralement. On recommence*/
	long long count = 0;
	Stack s = stack_init(MAX);
	Stack* stack = &s;
	stack_push(stack, root);
	while (stack != NULL)
	{
		TreeNode* node = stack_pop(stack);
		if (node->data == key)
		{
			return count;
		}
		count++;
		stack_push(stack, node->right);
		stack_push(stack, node->left);
	}

}

int bfs(TreeNode* root, void* key)
{
	/*1 verifier si ma queue est vide sinon on pop l'element de fin

	2 dans un algorithme de recheche on aurait une comparaison, comme exemple, si le character est F on a trouver le noeud
	puis on retournerais le noeud

	3 apres la comparaison, on cnsidere ce noeud comme le noeud courant et on push le left puis le right.On recommence.*/

	/*q->push(a)
		while (q->prev != NULL)
		{
			TreeNode* n = pop(a)
				if (n->data == "F") return n;
			push(q, n->left);
			push(q, n->right);
		}*/

}
