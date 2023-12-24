#include "DLList.hpp"
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <format>

class NAirlines
{
public:
	static constexpr std::size_t AIRPLANES = 29;
	static const std::string Airplanes[AIRPLANES];

	struct Ticket
	{
	private:
		static int mid;
	public:
		std::size_t id;
		std::string destination;
		std::string person;
		int airplane;
		std::chrono::year_month_day date;
		Ticket(const std::string &person = "", const std::string &destination = "",
			   const std::chrono::year_month_day &date = std::chrono::year_month_day()):
			id(mid),
			destination(destination),
			person(person),
			airplane(random()%AIRPLANES),
			date(date)
		{
			++mid;
		}

		friend std::ostream &operator<<(std::ostream &out, const Ticket &ticket);
	};
protected:
	DLList<Ticket> tickets;

public:
	void addTicket(const std::string &person,
		const std::string &destination,
		const std::string &date);

	friend std::ostream &operator<<(std::ostream &out, const NAirlines &airlines);
};

int NAirlines::Ticket::mid = 0;
const std::string NAirlines::Airplanes[] =
{
	"Airbus_A300", "Airbus_A310", "Airbus_A318", "Airbus_A319", "Airbus_A320", "Airbus_A321",
	"Antonov_An_140", "Antonov_An_148", "Antonov_An_158", "Antonov_An_225",
	"Beechcraft_1300",
	"Beriev_Be_200",
	"Boeing_717", "Boeing_757", "Boeing_767", "Boeing_777", "Boeing_787",
	"Bombardier_CRJ_100", "Bombardier_CRJ_200", "Bombardier_CRJ_700", "Bombardier_CRJ_900",
	"Embraer_170", "Embraer_175", "Embraer_190", "Embraer_195",
	"Fokker_50", "Fokker_70", "Fokker_100",
	"Indonesian_Aero"
};

void NAirlines::addTicket(const std::string &person,
	const std::string &destination,
	const std::string &date)
{
	DLList<Ticket>::Iterator i = tickets.begin();
	std::chrono::year_month_day _date;
	std::stringstream stream;
	stream << date;
	for (; (*i).date < _date; ++i);
	tickets.insert(i, Ticket(person, destination, date));
}

std::ostream &operator<<(std::ostream &out, const NAirlines::Ticket &ticket)
{
	out << std::format("Ticket No {} (to {})", ticket.id, ticket.destination) << std::endl;
	out << std::format("Name: {}", ticket.person) << std::endl;
	out << std::format("Airplane: {}", NAirlines::Airplanes[ticket.airplane]) << std::endl;
	out << std::format("Date: {}", ticket.date) << std::endl;
	return out;
}

std::ostream &operator<<(std::ostream &out, const NAirlines &airlines)
{
	for (const NAirlines::Ticket &ticket: airlines.tickets)
	{
		out << ticket << std::endl;
	}
	return out;
}

int main()
{
	NAirlines company;
	company.addTicket("Dimitrenko Kirill Alekseevich", "Switzerland, Zurich", "");
	company.addTicket("Dimitrenko Kirill Alekseevich", "Switzerland, Zurich", "");
	company.addTicket("Dimitrenko Kirill Alekseevich", "Switzerland, Zurich", "");
	company.addTicket("Dimitrenko Kirill Alekseevich", "Switzerland, Zurich", "");

	std::cout << company;
	return 0;
}
