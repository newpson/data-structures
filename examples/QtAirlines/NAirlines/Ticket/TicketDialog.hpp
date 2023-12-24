#pragma once
#include "ui_TicketDialog.h"
#include "Ticket.hpp"

#include <QWidget>
#include <QDialog>

class TicketDialog: public QDialog, Ui::TicketDialog
{
	Q_OBJECT
public:
	TicketDialog(QWidget *parent = nullptr);
	Ticket::Data *getTicketData();
};


