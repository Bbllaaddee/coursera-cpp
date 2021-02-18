#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

class Date
{
	friend bool operator<(const Date&, const Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	Date() = default;
	Date(int year, int month, int day) : _year(year)
	{
		if(month<1 || month>12) { throw std::domain_error("Month value is invalid: " + std::to_string(month)); }
		if(day<1 || day>31) { throw std::domain_error("Day value is invalid: " + std::to_string(day)); }
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if(lhs._year!=rhs._year)   { return lhs._year  < rhs._year; }
	if(lhs._month!=rhs._month) { return lhs._month < rhs._month; }
	if(lhs._day!=rhs._day)     { return lhs._day   < rhs._day; }
	return false;
}

std::istream& operator>>(std::istream& inp, Date& date)
{
	auto fuck = [](const std::string& str){ throw std::invalid_argument("Wrong date format: " + str); };
	std::string input;
	inp >> input;
	std::istringstream ss(input);
	int year;
	int month;
	int day;
	if(!(ss>>year)) { fuck(input); }
	if(ss.peek() != '-') { fuck(input); }
	ss.ignore(1);
	if(!(ss>>month)) { fuck(input); }
	if(ss.peek() != '-') { fuck(input); }
	ss.ignore(1);
	if(!(ss>>day)) { fuck(input); }
	std::string extra_shit;
	if(ss>>extra_shit) { fuck(input); }
	Date tmp(year, month, day);
	date = tmp;
	return inp;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	return out << std::setw(4) << std::setfill('0') << date._year << '-'
		       << std::setw(2) << std::setfill('0') << date._month << '-'
		       << std::setw(2) << std::setfill('0') << date._day;
}

class Database
{
public:
	void add_event(const Date& date, const std::string& event) { db[date].insert(event); }
	bool delete_event(const Date& date, const std::string& event) { return db[date].erase(event); }
	int  delete_date(const Date& date)
	{
		int n = db[date].size();
		std::cout << "Deleted " << n << " events" << std::endl;
		db.erase(date);
		return n;
	}
	const std::set<std::string>& find(const Date& date) const { return db.at(date); }
	void print() const
	{
		for(const auto& [date,events] : db)
		{
			for(const auto& event: events) { std::cout << date << ' ' << event << std::endl; }
		}
	}

private:
	std::map<Date,std::set<std::string>> db;
};

int main()
{
	Database db;
	std::string command;
	while(std::getline(std::cin, command))
	{
		std::istringstream inp(command);
		std::string query;
		inp >> query;
		if(query=="Add")
		{
			Date date;
			try { inp >> date; }
			catch(std::invalid_argument& e) { std::cout << e.what() << std::endl; return 1; }
			catch(std::domain_error& e) { std::cout << e.what() << std::endl; return 1; }
			std::string event;
			inp >> event;
			db.add_event(date,event);
		}
		else if(query=="Del")
		{
			Date date;
			try { inp >> date; }
			catch(std::invalid_argument& e) { std::cout << e.what() << std::endl; return 1; }
			catch(std::domain_error& e) { std::cout << e.what() << std::endl; return 1; }
			std::string event;
			if(inp>>event)
			{
				if(db.delete_event(date,event)) { std::cout << "Deleted successfully" << std::endl; }
				else { std::cout << "Event not found" << std::endl; }
			}
			else { db.delete_date(date); }
		}
		else if(query=="Find")
		{
			Date date;
			try { inp >> date; }
			catch(std::invalid_argument& e) { std::cout << e.what() << std::endl; return 1; }
			catch(std::domain_error& e) { std::cout << e.what() << std::endl; return 1; }
			try
			{
				for(const auto& event : db.find(date))
				{
					std::cout << event << std::endl;
				}
			}
			catch(std::out_of_range& e) { continue; }
		}
		else if(query=="Print") { db.print(); }
		else if(query=="") {}
		else { std::cout << "Unknown command: " << command << std::endl; }
	}
}
