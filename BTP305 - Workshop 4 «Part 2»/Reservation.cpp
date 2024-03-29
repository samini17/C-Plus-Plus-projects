///*
//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: OCT 13, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//*/

#include <sstream>
#include <string>
#include <iomanip>
#include "Reservation.h"

namespace sdds
{
	Reservation::Reservation()
	{
		m_id[30] = { 0 };
		m_name = "";
		m_email = "";
		m_people = 0;
		m_day = 0u;
		m_hour = 0u;
	}

	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}

	Reservation::Reservation(const std::string& res)
	{
		std::stringstream s(res);

		std::string temp, temp2;

		std::getline(s, temp, ':');
		temp2 = trimmer(temp);

		size_t i = 0;
		while (i < temp2.length())
		{
			m_id[i] = temp2[i];
			i++;
		}

		m_id[i] = '\0'; 
		std::getline(s, temp, ',');
		m_name = trimmer(temp);
		std::getline(s, temp, ',');
		m_email = trimmer(temp);
		std::getline(s, temp, ',');
		temp2 = trimmer(temp);
		m_people = (temp2.empty() ? 0 : stoi(temp2));

		std::getline(s, temp, ',');
		temp2 = trimmer(temp);
		m_day = (temp2.empty() ? 0 : stoi(temp2));

		std::getline(s, temp);
		temp2 = trimmer(temp);
		m_hour = (temp2.empty() ? 0 : stoi(temp2));

	}

	std::string Reservation::trimmer(std::string& str) const
	{
		std::string trimmed = "";

		auto start = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');

		if (end >= start)
			trimmed = str.substr(start, (end - start) + 1);

		return trimmed;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& rs)
	{
		os << "Reservation ";
		os << std::setw(10) << std::setfill(' ') << std::right << rs.m_id;
		os << ": ";

		os << std::setw(20) << std::setfill(' ') << std::right << rs.m_name;
		os << std::setw(25) << std::setfill(' ') << std::left << "  <" + rs.m_email + "> ";

		if (rs.m_hour >= 6 && rs.m_hour <= 9)
			os << " Breakfast ";

		else if (rs.m_hour >= 11 && rs.m_hour <= 15)
			os << " Lunch ";

		else if (rs.m_hour >= 17 && rs.m_hour <= 21)
			os << " Dinner ";

		else
			os << " Drinks ";

		os << "on day " << rs.m_day << " @ " << rs.m_hour << ":00 for " << rs.m_people;
		if (rs.m_people > 1)
			os << " people.";
		else
			os << " person.";

		os << std::endl;

		return os;
	}
}