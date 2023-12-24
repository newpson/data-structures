#pragma once
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

		Node(const T &value = T());
		~Node();

		Node *cut();
	};

	enum IteratorType
	{
		PREFIX,
		INFIX,
		POSTFIX,
		BREADTH
	};

	template <IteratorType IType = IteratorType::INFIX>
	class Iterator
	{
	public:
		struct INode
		{
		private:
			int mlevel;
			Node *mnode;

		public:
			INode(Node *mnode = nullptr, int mlevel = 0);
			int level();
			T &value();
		};
	private:
		Queue<INode> queue;
		void push_r(Node *node, int level);
	public:
		Iterator(Node *node = nullptr);
		Iterator<IType> &operator++();
		INode operator*();
		bool operator==(const Iterator<IType> &i) const;
	};

protected:
	Node *root;

public:
	BTree();
	~BTree();
	bool is_empty() const;

	template <IteratorType IType = IteratorType::INFIX>
	Iterator<IType> begin();

	template <IteratorType IType = IteratorType::INFIX>
	Iterator<IType> end();
};

#include "BTree.tcc"
