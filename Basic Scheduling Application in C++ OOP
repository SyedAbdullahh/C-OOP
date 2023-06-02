#include<iostream>
using namespace std;
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int, int, int);
	void addDay(int);
	void addMonth(int);
	void addYear(int);

	int GetDay();
	int GetMonth();
	int GetYear();
	void print();
};
Date::Date(int yearr, int monthh, int dayy)
{
	year = yearr;
	month = monthh;
	day = dayy;
}
Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}
class Event
{
protected:
	string title;
	Date date;
public:
	Event();
	Event(string s, const Date& d);
	virtual void print();
};
Event::Event(string s, const Date& d)
{
	title = s;
	date = d;
}
void Event::print()
{
	cout << "\n" << title << ": " << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay()<<endl;
}
class RecurringEvent : public Event
{
public:
	RecurringEvent();
	RecurringEvent(string s, const Date& d) :Event(s, d){}
	virtual Event** occurrences(int i) = 0;
};
class DailyEvent :public RecurringEvent
{
public:

	DailyEvent(string s, Date d) :RecurringEvent(s, d)
	{

	}
	virtual Event** occurrences(int i);
	void operator++(int r);
};


Event** DailyEvent::occurrences(int i)
{
	Event** arr = new Event * [i];
	for (int x = 0; x < i; x++)
	{
		if (this->date.GetDay() + (x) <= 31)
		{
			arr[x] = new DailyEvent(this->title, Date(this->date.GetYear(), this->date.GetMonth(), this->date.GetDay() + (x)));
		}

		if (this->date.GetDay() + (x) > 31 && this->date.GetMonth() == 12)
		{
			arr[x] = new DailyEvent(this->title, Date(this->date.GetYear() + 1, 1, (this->date.GetDay() + (x)) % 31));
		}
		if (this->date.GetDay() + (x) > 31 && this->date.GetMonth() < 12)
		{
			arr[x] = new DailyEvent(this->title, Date(this->date.GetYear(), this->date.GetMonth() + 1, (this->date.GetDay() + (x)) % 31));
		}


	}
	return arr;
}
//Weekly Event

class WeeklyEvent :public RecurringEvent
{
public:

	WeeklyEvent(string s, Date d):RecurringEvent(s,d){}
	virtual Event** occurrences(int i);
};
Event** WeeklyEvent::occurrences(int i)
{
	Event** arr = new Event * [i];
	for (int x = 0; x < i; x++)
	{
		if (this->date.GetDay() + (x * 7) <= 31)
		{
			arr[x] = new WeeklyEvent(this->title, Date(this->date.GetYear(), this->date.GetMonth(), this->date.GetDay() + (x * 7)));
		}
		else if (this->date.GetDay() + (x * 7)> 31&&this->date.GetMonth()==12)
		{
			arr[x] = new WeeklyEvent(this->title, Date((this->date.GetYear()+ (((this->date.GetDay() + (x * 7)) / 31) / 12)), (((this->date.GetDay() + (x * 7)) / 31)%12),((this->date.GetDay() + (x * 7))%31)));
		}
		else if (this->date.GetDay() + (x * 7)> 31&&this->date.GetMonth()<12)
		{
			arr[x] = new WeeklyEvent(this->title, Date((this->date.GetYear() + (((this->date.GetDay() + (x * 7)) / 31) / 12)), (this->date.GetMonth()+ (((this->date.GetDay() + (x * 7)) / 31)%12)), (this->date.GetDay() + (x * 7))%31));
		}


	}
	return arr;
}
class MonthlyEvent :public RecurringEvent
{
public:

	MonthlyEvent(string s, Date d) :RecurringEvent(s, d){}
	virtual Event** occurrences(int i);
};

Event** MonthlyEvent::occurrences(int i)
{
	Event** arr = new Event * [i];
	for (int x = 0; x < i; x++)
	{
		if ((this->date.GetMonth() + x) <= 12)
		{
			arr[x] = new WeeklyEvent(this->title, Date(this->date.GetYear(), this->date.GetMonth()+x, this->date.GetDay()));

		}

		else if ((this->date.GetMonth() + x)>12)
		{
			arr[x] = new WeeklyEvent(this->title, Date((this->date.GetYear()+ ((this->date.GetMonth() + x)/12)), ((this->date.GetMonth() + x) % 12), this->date.GetDay()));

		}
	}
	return arr;
	
}
int main() {
	RecurringEvent** rec = new RecurringEvent * [3];
	rec[0] = new DailyEvent("client meeting", Date(2022, 12, 31));
	rec[1] = new WeeklyEvent("lecture", Date(2022, 2, 8));
	rec[2] = new MonthlyEvent("project monitoring", Date(2022, 6, 8));
	for (int i = 0; i < 3; i++) {
		Event** occurr = rec[i]->occurrences(3);
		for (int j = 0; j < 3; j++) {
			occurr[j]->print();
			cout << endl;
		}
	}
	// …
	return 0;
}
