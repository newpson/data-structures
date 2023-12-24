#pragma once
// .-----------------.
// | BTree::Iterator |
// '-----------------'

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType>::INode::INode(Node *mnode, int mlevel):
	mnode(mnode),
	mlevel(mlevel)
{}

template <typename T>
template <BTree<T>::IteratorType IType>
int BTree<T>::Iterator<IType>::INode::level()
{
	return mlevel;
}

template <typename T>
template <BTree<T>::IteratorType IType>
T &BTree<T>::Iterator<IType>::INode::value()
{
	return mnode->value;
}

// .-------------.
// | BTree::Node |
// '-------------'

template <typename T>
BTree<T>::Node::Node(const T &value):
	value(value),
	left(nullptr),
	right(nullptr)
{}

template <typename T>
BTree<T>::Node::~Node()
{
	delete left;
	delete right;
}

template <typename T>
BTree<T>::Node *BTree<T>::Node::cut()
{
	left = nullptr;
	right = nullptr;
	return this;
}

// .-----------------.
// | BTree::Iterator |
// '-----------------'

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType>::Iterator(BTree<T>::Node *node)
{
	push_r(node, 0);
}

/* template <> */
/* void BTree<T>::Iterator::push_r(BTree<T>::Node *node, int level) */
/* { */
/* 	if (node) */
/* 	{ */
/* 		push_r(node->left, level+1); */
/* 		BTree<T>::Iterator::INode data = {node, level}; */
/* 		queue.push(data); */
/* 		push_r(node->right, level+1); */
/* 	} */
/* } */

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType> &BTree<T>::Iterator<IType>::operator++()
{
	queue.pop();
	return *this;
}

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType>::INode BTree<T>::Iterator<IType>::operator*()
{
	return queue.front();
}

template <typename T>
template <BTree<T>::IteratorType IType>
bool BTree<T>::Iterator<IType>::operator==(const Iterator<IType> &i) const
{
	return queue.size() == i.queue.size();
}

// .-------.
// | BTree |
// '-------'

template <typename T>
BTree<T>::BTree():
	root(nullptr)
{}

template <typename T>
BTree<T>::~BTree()
{
	delete root;
	root = nullptr;
}

template <typename T>
bool BTree<T>::is_empty() const
{
	return root == nullptr;
}

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType> BTree<T>::begin()
{
	return Iterator<IType>(root);
}

template <typename T>
template <BTree<T>::IteratorType IType>
BTree<T>::Iterator<IType> BTree<T>::end()
{
	return Iterator<IType>(nullptr);
}
