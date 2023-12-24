#pragma once
#include "DLList.hpp"
#include "ui_TabDLL.h"
#include <QWidget>
#include <QGraphicsScene>

class TabDLL: public QWidget, Ui::TabDLL
{
	Q_OBJECT
protected:
	DLList<QString> list;
public:
	TabDLL(QWidget *parent = nullptr);
public slots:
	void push_front();
	void push_back();
	void pop_front();
	void pop_back();
	void clear();
};

