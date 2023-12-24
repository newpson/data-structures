#include "TicketDialog.hpp"
#include "ui_TicketDialog.h"
#include <QtWidgets>

TicketDialog::TicketDialog(QWidget *parent):
	QDialog(parent)
{
	setupUi(this);
}

Ticket::Data *TicketDialog::getTicketData()
{
	return ticket->data;
}
