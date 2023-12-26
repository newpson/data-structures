#include "TabAVLT.hpp"

#include <QWidget>
#include <QIntValidator>
#include <QString>

TabAVLT::TabAVLT(QWidget *parent):
	QWidget(parent), random(1, 1000)
{
	setupUi(this);
	value->setValidator(new QIntValidator(0, 1000, this));
	frame->tree = &tree;
}

void TabAVLT::insert()
{
	if (cb_random->isChecked())
	{
		int rvalue = random(generator);
		value->setText(QString::number(rvalue));
		tree.insert(TreeData(rvalue));
	}
	else
	{
		QString text = value->text();
		if (!text.isEmpty())
		{
			tree.insert(TreeData(text.toInt()));
		}
	}
}

void TabAVLT::remove()
{
	QString text = value->text();
	if (!text.isEmpty())
	{
		tree.remove(TreeData(text.toInt()));
	}
}

void TabAVLT::find()
{
	QString text = value->text();
	auto node = tree.find(TreeData(text.toInt()));
	if (node)
	{
		node->value.color = Qt::magenta;
	}
}
