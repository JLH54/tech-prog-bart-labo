#include "labo.h"

Node* create_node(void* data)
{
	Node* n = allocate(sizeof(Node));
	n->data = data;
	memset(&n->adj, 0, sizeof(n->adj));
	n->visited = 0;
	n->len = 0;
	n->revPath = allocate(sizeof(QNode));
	n->revPath->prev = NULL;
	n->revPath->next = NULL;
	n->revPath->count = 0;
	n->revPath->data = NULL;

	return n;
}

void add_adjacent_node(Node* root, Node* node)
{
	root->adj[root->len] = node;
	root->len++;
}

//dfs(list,len,NULL, "B",&s);
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	if (curr != NULL)
	{
		int count;
		//marquer comme vu(1)
		curr->visited = 1;
		//Pour son premier edge/lien
		//a. Est-ce que c'est le noeud viser
		if (curr->data == key)
		{
			return len;
		}
		else if(curr->visited = 1)
		for (int i = 0; i < curr->len; i++)
		{
			count = dfs(root, len++, curr->adj[i], key, s);
			if (count != 0)
			{
				return count;
			}
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			dfs(root, 0, root[i], key, s);
		}
	}
	return 0;
}

int bfs(Node* root[], void* key, Stack* s)
{
	////1. push premier dans la queue
	////2.
	//Node* n = root[0];
	//while (n != null)
	//{
	//	n = queue_pop(q)
	//		for (adjacente)
	//		{
	//			queue_push(adjacente)
	//		}
	//	n->visited = 1;
	//	if (n->data == key) break;

	//}
	//if (n == NULL)
	//{
	//	bad;
	//}
	//else {
	//	good;
	//}
	return 0;
}

