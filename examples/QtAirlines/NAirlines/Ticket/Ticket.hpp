#pragma once
#include "ui_Ticket.h"

#include <QWidget>
#include <QListWidgetItem>
#include <QString>
#include <QDate>

class Ticket: public QWidget, Ui::Ticket
{
	Q_OBJECT

public:
	struct Data: QListWidgetItem
	{
	private:
		static int last_id;
	public:
		const int id;
		QString name;
		QString surname;
		QString patronymic;
		QString city;
		QDate date;
		QString fnumber;
		QString airplane;

		Data();
		virtual QVariant data(int role) const override;
	};
	Data *data;

	Ticket(QWidget *parent = nullptr);
	void setReadOnly(bool);
	void updateFields();

public slots:
	void setData(QListWidgetItem *item);
	void setFirstName();
	void setLastName();
	void setPatronymic();
	void setCity();
	void setDate();
};
