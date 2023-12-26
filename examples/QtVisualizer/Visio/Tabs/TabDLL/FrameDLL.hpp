#pragma once
#include "DLList.hpp"

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QPaintEvent>

class FrameDLL: public QFrame
{
	Q_OBJECT
	void paintEvent(QPaintEvent *event) override;

public:
	const DLList<QString> *list;
	FrameDLL(QWidget *parent = nullptr,
			DLList<QString> *list = nullptr);
};
