#include "AVLTree.hpp"
#include "FrameAVLT.hpp"
#include "TreeData.hpp"

#include <QApplication>
#include <QFrame>
#include <QWidget>
#include <QPainter>

FrameAVLT::FrameAVLT(QWidget *parent, AVLTree<TreeData> *tree):
	QFrame(parent), tree(tree)
{}

void FrameAVLT::paintEvent(QPaintEvent *event)
{
	QFrame::paintEvent(event);
	QPainter painter(this);
	painter.setBackgroundMode(Qt::OpaqueMode);

	int x = 20, dx = 30;
	int y = 20, dy = 30;

	for (auto i: tree->inorder())
	{
		int level = i.level();
		TreeData &data = i.value();
		data.y = y + dy*level;
		data.x = x;
		x += dx;
	}

	for (auto i: tree->breadthorder())
	{
		auto node = i.node;
		TreeData &parent = i.value();

		if (node->left)
		{
			TreeData child = node->left->value;
			painter.drawLine(parent.x, parent.y, child.x, child.y);
		}
		if (node->right)
		{
			TreeData child = node->right->value;
			painter.drawLine(parent.x, parent.y, child.x, child.y);
		}

		painter.setPen(parent.color);
		painter.drawText(parent.x, parent.y, QString::number(parent.value));
		parent.color = Qt::black;
	}
	// for (const QString &str: *tree)
	// {
	// 	rect.translate(x, y);
	// 	painter.drawText(x, y, str);
	// 	painter.drawRect(rect.adjusted(-10, -10, 10, 10));
	// 	x += rect.width() + 25;
	// }
}
