#include "TabDLL.hpp"
#include <QWidget>

TabDLL::TabDLL(QWidget *parent):
	QWidget(parent)
{
	setupUi(this);
	frame->list = &list;
}

void TabDLL::push_front()
{
	QString text = value->text();
	if (!text.isEmpty())
	{
		list.push_front(value->text());
	}
}

void TabDLL::push_back()
{
	QString text = value->text();
	if (!text.isEmpty())
	{
		list.push_back(value->text());
	}
}

void TabDLL::pop_front()
{
	if (!list.empty())
	{
		list.pop_front();
	}
}

void TabDLL::pop_back()
{
	if (!list.empty())
	{
		list.pop_back();
	}
}

void TabDLL::clear()
{
	while (!list.empty())
	{
		list.pop_back();
	}
}
