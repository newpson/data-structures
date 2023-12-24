#include "Ticket.hpp"
#include "ui_Ticket.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QString>
#include <QVariant>
#include <QDebug>

Ticket::Ticket(QWidget *parent):
	QWidget(parent), data(new Ticket::Data())
{
	setupUi(this);
}

void Ticket::setReadOnly(bool readOnly)
{
	bool frame = !readOnly;
	name_last->setReadOnly(readOnly); name_last->setFrame(frame);
	name_first->setReadOnly(readOnly); name_first->setFrame(frame);
	name_patronymic->setReadOnly(readOnly); name_patronymic->setFrame(frame);
	city->setReadOnly(readOnly); city->setFrame(frame);
	date->setReadOnly(readOnly); date->setFrame(frame);
	if (readOnly)
	{
		delete data;
	}
}

void Ticket::updateFields()
{
	id->setText(QString::number(data->id));
	name_last->setText(data->surname);
	name_first->setText(data->name);
	name_patronymic->setText(data->patronymic);
	city->setText(data->city);
	date->setDate(data->date);
	flight_number->setText(data->fnumber);
	airplane->setText(data->airplane);
}

int Ticket::Data::last_id = 0;
Ticket::Data::Data(): QListWidgetItem(),
	id(++last_id)
{}

QVariant Ticket::Data::data(int role) const
{
	if (role == Qt::DisplayRole)
	{
		return QString("Ticket #")+QString::number(id);
	}
	return QListWidgetItem::data(role);
}

void Ticket::setData(QListWidgetItem *item)
{
	data = dynamic_cast<Ticket::Data *>(item);
	updateFields();
}

void Ticket::setFirstName()
{
	data->name = name_first->text();
}

void Ticket::setLastName()
{
	data->surname = name_last->text();
}

void Ticket::setPatronymic()
{
	data->patronymic = name_patronymic->text();
}

void Ticket::setCity()
{
	data->city = city->text();
}

void Ticket::setDate()
{
	data->date = date->date();
}
