#pragma once
#include "DLList.hpp"
#include "Queue.hpp"

template <typename T>
class BTree
{
public:
	struct Node
	{
		T value;
		Node *left;
		Node *right;

		Node(const T &value = T()):
			value(value),
			left(nullptr),
			right(nullptr)
		{}
		~Node()
		{
			delete left;
			delete right;
		}

		Node *cut()
		{
			left = nullptr;
			right = nullptr;
			return this;
		}
	};

	struct LevelNode
	{
		Node *node;
		int mlevel;

		LevelNode (Node *node = nullptr, int mlevel = 0):
			node(node),
			mlevel(mlevel)
		{}

		T &value()
		{
			return node->value;
		}
		
		int level()
		{
			return mlevel;
		}
	};

	/* TODO IterableQueue instead of DLList */
	class IteratorAdapter: protected DLList<LevelNode>
	{
	public:
		using DLList<LevelNode>::Iterator;
		using DLList<LevelNode>::begin;
		using DLList<LevelNode>::end;

		friend class BTree;
	};

protected:
	Node *root;

	void preorder_r(IteratorAdapter &queue, Node *node, int level = 0)
	{
		if (node)
		{
			queue.push_back({node, level});
			preorder_r(queue, node->left, level+1);
			preorder_r(queue, node->right, level+1);
		}
	}

	void inorder_r(IteratorAdapter &queue, Node *node, int level = 0)
	{
		if (node)
		{
			inorder_r(queue, node->left, level+1);
			queue.push_back({node, level});
			inorder_r(queue, node->right, level+1);
		}
	}

	void postorder_r(IteratorAdapter &queue, Node *node, int level = 0)
	{
		if (node)
		{
			postorder_r(queue, node->left, level+1);
			postorder_r(queue, node->right, level+1);
			queue.push_back({node, level});
		}
	}

public:
	BTree():
		root(nullptr)
	{}
	~BTree()
	{
		delete root;
		root = nullptr;
	}
    bool is_empty() const
	{
		return root == nullptr;
	}

	IteratorAdapter preorder()
	{
		IteratorAdapter adapter;
		preorder_r(adapter, root);
		return adapter;
	}

	IteratorAdapter inorder()
	{
		IteratorAdapter adapter;
		inorder_r(adapter, root);
		return adapter;
	}

	IteratorAdapter postorder()
	{
		IteratorAdapter adapter;
		postorder_r(adapter, root);
		return adapter;
	}

	IteratorAdapter breadthorder()
	{
		IteratorAdapter adapter;
		if (root)
		{
			Queue<Node *> queue;
			queue.push(root);
			while (!queue.empty())
			{
				Node *cur = queue.front();
				/* TODO calculate current level */
				adapter.push_back({cur, -1});
				if (cur->left)
				{
					queue.push(cur->left);
				}
				if (cur->right)
				{
					queue.push(cur->right);
				}
				queue.pop();
			}
		}
		return adapter;
	}
};
