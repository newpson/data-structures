#include "NAirlines.hpp"
#include "ui_NAirlines.h"
#include "Ticket.hpp"
#include "TicketDialog.hpp"

#include <QWidget>
#include <QMainWindow>
#include <QDialog>
#include <QListWidgetItem>
#include <QString>

const QString NAirlines::airplanes[] =
{
	"Airbus A300", "Airbus A310", "Airbus A318", "Airbus A319", "Airbus A320",
	"Airbus A321", "Antonov An 140", "Antonov An 148", "Antonov An 158",
	"Antonov An 225", "Beechcraft 1300", "Beriev Be 200", "Boeing 717",
	"Boeing 757", "Boeing 767", "Boeing 777", "Boeing 787", "Bombardier CRJ 100",
	"Bombardier CRJ 200", "Bombardier CRJ 700", "Bombardier CRJ 900",
	"Embraer 170", "Embraer 175", "Embraer 190", "Embraer 195", "Fokker 50",
	"Fokker 70", "Fokker 100", "Indonesian Aero"
};

const int NAirlines::airplanes_count = sizeof(NAirlines::airplanes)/sizeof(QString);

NAirlines::NAirlines(QWidget *parent):
	QMainWindow(parent), random(0, airplanes_count)
{
	setupUi(this);
	ticket->setReadOnly(true);
}

void NAirlines::addTicket()
{
	TicketDialog *dialog = new TicketDialog();
	if (dialog->exec() == QDialog::Accepted)
	{
		Ticket::Data *data = dialog->getTicketData();
		data->airplane = airplanes[random(generator)];
		for (int i = 0; i < 2; ++i)
		{
			data->fnumber += QString('A'+random(generator)%26);
		}
		for (int i = 0; i < 4; ++i)
		{
			data->fnumber += QString::number(random(generator)%10);
		}

		auto ti = tickets.begin();
		int i = 0;
		for (; ti != tickets.end(); ++ti, ++i)
		{
			if (data->date > dynamic_cast<Ticket::Data *>(tickets_list->item(i))->date)
			{
				break;
			}
		}
		tickets_list->insertItem(i, data);
		tickets.insert(ti, data);
	}
}

void NAirlines::cleanTickets()
{
	QDate date = date_old->date();
	int i = tickets_list->count()-1;
	while (!tickets.empty() && tickets.back()->date <= date)
	{
		tickets_list->takeItem(i);
		tickets.pop_back();
		--i;
	}
}
