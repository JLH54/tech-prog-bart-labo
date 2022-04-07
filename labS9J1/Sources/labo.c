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
	 while (s->top != -1)
    {
        stack_pop(s);
    }
    int nbChemin = 0;
    Queue* q = allocate(sizeof(Queue));
    queue_init(q);
    queue_push(q, root[0]);
    Node* n = root[0];
    while (n != NULL)
    {
        n = queue_pop(q);
        n->visited = 1;
        if (n->data == key)
        {
            break;
        }
        for (int i = 0; i < n->len; i++)
        {
            if (n->adj[i]->visited != 1)
            {
                queue_push(q, n->adj[i]);
                n->adj[i]->revPath->data = n;
            }
        }
    }
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        while (n != NULL)
        {
            stack_push(s, n);
            n = n->revPath->data;
            nbChemin++;
        }
    }
    return nbChemin;

	return 0;
}

