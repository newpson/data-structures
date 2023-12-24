#pragma once
#include "BTree.hpp"

template <typename T>
class BSTree: protected BTree<T>
{
protected:
	using Node = typename BTree<T>::Node;

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
				return find_r(sub->left);
			}
			return find_r(sub->right);
		}
		return nullptr;
	}

	void insert_r(Node *&sub, const T &value)
	{
		if (sub)
		{
			if (value < sub->value)
			{
				insert_r(sub->left, value);
			}
			else
			{
				insert_r(sub->right, value);
			}
		}
		else
		{
			sub = new Node(value);
		}
	}

	void remove_r(Node *&sub, const T &value)
	{
		if (sub)
		{
			if (value < sub->value)
			{
				remove_r(sub->left, value);
			}
			else if (value > sub->value)
			{
				remove_r(sub->right, value);
			}
			else
			{
				if (sub->left && sub->right)
				{
					/* doubious solution (double pass) */
					T value;
					for (Node *temp = sub->right; temp; temp = temp->left)
					{
						value = temp->value;
					}
					sub->value = value;
					remove_r(sub->right, value);
				}

				else if (sub->left || sub->right)
				{
					Node *temp = sub->left ? sub->left : sub->right;
					delete sub->cut();
					sub = temp;
				}
				else
				{
					delete sub;
					sub = nullptr;
				}
			}
		}
	}

public:
	Node *find(const T &value) const
	{
		return find_r(this->root, value);
	}

	BSTree<T> &insert(const T &value)
	{
		insert_r(this->root, value);
		return *this;
	}

	BSTree<T> &remove(const T &value)
	{
		remove_r(this->root, value);
		return *this;
	}

	using BTree<T>::is_empty;
	using BTree<T>::Iterator;
	using BTree<T>::begin;
	using BTree<T>::end;
};
