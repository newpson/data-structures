#pragma once
#include "DLList.hpp"
#include <QFrame>
#include <QWidget>

class FrameDLL: public QFrame
{
	Q_OBJECT
	void paintEvent(QPaintEvent *event) override;
public:
	const DLList<QString> *list;
	FrameDLL(QWidget *parent = nullptr, DLList<QString> *list = nullptr);
};
