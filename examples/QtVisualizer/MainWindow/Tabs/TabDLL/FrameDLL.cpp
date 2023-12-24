#include "DLList.hpp"
#include "FrameDLL.hpp"
#include <QApplication>
#include <QFrame>
#include <QWidget>
#include <QPainter>

FrameDLL::FrameDLL(QWidget *parent, DLList<QString> *list):
	QFrame(parent), list(list)
{}

void FrameDLL::paintEvent(QPaintEvent *event)
{
	QFrame::paintEvent(event);
	QPainter painter(this);

	int x = 20;
	int y = 40;
	for (const QString &str: *list)
	{
		QRect rect = QApplication::fontMetrics().boundingRect(str);
		rect.translate(x, y);
		painter.drawText(x, y, str);
		painter.drawRect(rect.adjusted(-10, -10, 10, 10));
		x += rect.width() + 25;
	}
}
