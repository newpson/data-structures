#pragma once
#include "AVLTree.hpp"
#include "TreeData.hpp"

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>

class FrameAVLT: public QFrame
{
	Q_OBJECT
	void paintEvent(QPaintEvent *event) override;

public:
	AVLTree<TreeData> *tree;
	FrameAVLT(QWidget *parent = nullptr, AVLTree<TreeData> *tree = nullptr);
};
