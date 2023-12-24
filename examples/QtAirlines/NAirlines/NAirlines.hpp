#pragma once
#include "ui_NAirlines.h"
#include "Ticket.hpp"

#include "DLList.hpp"
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <random>

class NAirlines: public QMainWindow, Ui::NAirlines
{
	Q_OBJECT
	DLList<Ticket::Data *> tickets;
public:
	static const QString airplanes[];
	static const int airplanes_count;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> random;

	NAirlines(QWidget *parent = nullptr);

public slots:
	void addTicket();
	void cleanTickets();
};

