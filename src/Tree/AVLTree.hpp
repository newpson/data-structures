#pragma once
#include "DLList.hpp"
#include "Queue.hpp"

template <typename T>
class AVLTree
{
public:
	struct Node
	{
		T value;
		Node *left;
		Node *right;
		int height;

		Node(const T &value = T()):
			value(value),
			left(nullptr),
			right(nullptr),
			height(1)
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

		LevelNode(Node *node = nullptr, int mlevel = 0):
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

	class IteratorAdapter: protected DLList<LevelNode>
	{
	public:
		using DLList<LevelNode>::Iterator;
		using DLList<LevelNode>::begin;
		using DLList<LevelNode>::end;

		friend class AVLTree;
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

	int height(Node *node)
	{
		if (node)
		{
			return node->height;
		}
		return 0;
	}

	Node *rotate_right(Node *sub)
	{
		Node *temp = sub->left;
		sub->left = temp->right;
		temp->right = sub;
		sub->height = 1+std::max(height(sub->left), height(sub->right));
		temp->height = 1+std::max(height(temp->left), height(temp->right));
		return temp;
	}

	Node *rotate_left(Node *sub)
	{
		Node * temp = sub->right;
		sub->right = temp->left;
		temp->left = sub;
		sub->height = 1+std::max(height(sub->left), height(sub->right));
		temp->height = 1+std::max(height(temp->left), height(temp->right));
		return temp;
	}

	Node *insert_r(Node *sub, const T &value)
	{
		if (!sub)
		{
			Node *temp = new Node(value);
			return temp;
		}

		if (value < sub->value)
		{
			sub->left = insert_r(sub->left, value);
		}
		else if (value > sub->value)
		{
			sub->right = insert_r(sub->right, value);
		}

		sub->height = 1 + std::max(height(sub->left), height(sub->right));

		int diff = height(sub->left) - height(sub->right);
		if (diff > 1)
		{
			if (value < sub->left->value)
			{
				return rotate_right(sub);
			}
			else
			{
				sub->left = rotate_left(sub->left);
				return rotate_right(sub);
			}
		}
		else if (diff < -1)
		{
			if (value > sub->right->value)
			{
				return rotate_left(sub);
			}
			else
			{
				sub->right = rotate_right(sub->right);
				return rotate_left(sub);
			}
		}
		return sub;
	}

	Node *remove_r(Node *sub, const T &value)
	{
		if(!sub)
		{
			return nullptr;
		}

		if (value < sub->value)
		{
			sub->left = remove_r(sub->left, value);
		}
		else if (value > sub->value)
		{
			sub->right = remove_r(sub->right, value);
		}
		else
		{
			Node *right = sub->right;
			if (!sub->right)
			{
				Node *left = sub->left;
				delete sub->cut();
				sub = left;
			}
			else if (!sub->left)
			{
				delete sub->cut();
				sub = right;
			}
			else
			{
				while (right->left)
				{
					right = right->left;
				}
				sub->value = right->value;
				sub->right = remove_r(sub->right, right->value);
			}
		}

		if (!sub)
		{
			return sub;
		}

		sub->height = 1 + std::max(height(sub->left), height(sub->right));
		int diff = height(sub->left) - height(sub->right);
		if (diff > 1)
		{
			if (height(sub->left) >= height(sub->right))
			{
				return rotate_right(sub);
			}
			else
			{
				sub->left = rotate_left(sub->left);
				return rotate_right(sub);
			}
		}
		else if (diff < -1)
		{
			if (height(sub->right) >= height(sub->left))
			{
				return rotate_left(sub);
			}
			else
			{
				sub->right = rotate_right(sub->right);
				return rotate_left(sub);
			}
		}
		return sub;
	}

	Node *find_r(Node *sub, const T &value) const
	{
		if (sub)
		{
			if (sub->value == value)
			{
				return sub;
			}
			if (value < sub->value)
			{
				return find_r(sub->left, value);
			}
			return find_r(sub->right, value);
		}
		return nullptr;
	}

public:
	AVLTree():
		root(nullptr)
	{}
	~AVLTree()
	{
		delete root;
		root = nullptr;
	}
	Node *find(const T &value) const
	{
		return find_r(root, value);
	}

	AVLTree<T> &insert(const T &value)
	{
		root = insert_r(root, value);
		return *this;
	}

	AVLTree<T> &remove(const T &value)
	{
		root = remove_r(root, value);
		return *this;
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
