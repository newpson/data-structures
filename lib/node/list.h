#ifndef NODE_LIST_H
#define NODE_LIST_H

typedef struct node
{
	void *val;
	struct node_list *next;
} node_list_t;

#endif /* NODE_LIST_H */
