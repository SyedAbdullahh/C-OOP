#include<iostream>
#include <string>
using namespace std;
class customer
{
protected:
	int i_hrs;
	float i_cost;
	string c_name;
	float diskspace;
	float add_hrs_rate;
	int add_hrs;
public:
	virtual float computebill();
	virtual void display();
	customer();
	~customer();
	customer(string n, float hrs);
};
void customer::display()
{
	system("cls");
	cout << "\ndear " << c_name << ", customer plan is most suitable for you.";
	cout << "\n--------details of customer plan--------";
	cout << "\ninitial hrs:" << i_hrs;
	cout << "\ninitial cost:" << i_cost;
	cout << "\n additional rate(dollars per hour):" << add_hrs_rate;
	cout << "\n disk space limit(mb):" << diskspace;
	cout << "\n charge per dialup connection: none";
	cout << "\n expected bill:" << this->computebill();
}
customer::customer()
{
	i_hrs = 0;
	i_cost = 0;
	add_hrs_rate = 0;
	diskspace = 0;
	c_name = "";
	add_hrs = 0;

}

customer::~customer()
{
	cout << "\n customer deleted...\n";
}


customer::customer(string n, float hrs)
{

	i_hrs = 4;
	i_cost = 10;
	add_hrs_rate = 4.00;
	diskspace = 1;
	c_name = n;
	int temp = hrs - i_hrs;
	if (temp > 0)
	{
		add_hrs = temp;
	}
	else
	{
		add_hrs = 0;
	}


}

float customer::computebill()
{

	float bill;
	bill = (add_hrs * add_hrs_rate) + i_cost;
	return bill;
}

class hacker :public customer
{
public:
	hacker(string n, float hrs);
	~hacker();
	virtual float computebill() override;
	virtual void display() override;

};
void hacker::display()
{
	system("cls");
	cout << "\ndear " << c_name << ", hacker plan is most suitable for you.";
	cout << "\n--------details of hacker plan--------";
	cout << "\ninitial hrs:" << i_hrs;
	cout << "\ninitial cost:" << i_cost;
	cout << "\n additional rate(dollars per hour):" << add_hrs_rate;
	cout << "\n disk space limit(mb):" << diskspace;
	cout << "\n charge per dialup connection: none";
	cout << "\n expected bill:" << this->computebill();
}

hacker::hacker(string n, float hrs)
{
	i_hrs = 10;
	i_cost = 20;
	add_hrs_rate = 2.50;
	diskspace = 50;
	c_name = n;
	int temp = hrs - i_hrs;
	if (temp > 0)
	{
		add_hrs = temp;
	}
	else
	{
		add_hrs = 0;
	}

}
hacker::~hacker()
{
	cout << "\n hacker deleted";
}

float hacker::computebill()
{
	
	float bill;
	bill = (add_hrs * add_hrs_rate) + i_cost;
	return bill;
}

class chatroom :public customer
{
	int conns;
	float cpc;
public:
	chatroom(string n, int con);
	~chatroom();
	virtual float computebill()override;
	virtual void display();


};
chatroom::chatroom(string n, int con)
{
	c_name = n;

	conns = con;
	cpc = 0.10;
	i_cost = 50;
}
void chatroom::display()
{
	system("cls");
	cout << "\ndear " << c_name << ", chatroom plan is most suitable for you.";
	cout << "\n--------details of chatroom plan--------";
	cout << "\ninitial hrs: unlimited";
	cout << "\ninitial cost:" << i_cost;
	cout << "\n additional rate(dollars per hour):none";
	cout << "\n disk space limit(mb):none";
	cout << "\n charge per dialup connection: none";
	cout << "\n expected bill:" << this->computebill();
}
float chatroom::computebill()
{
	float bill;
	bill = i_cost + (conns * cpc);
	return bill;
}
chatroom::~chatroom() {
	cout << "\nchatroom deleted";

}

int main()
{
	string name;
	float hrs;
	int conns;
	float memory;
	cout << "\n------------------baltimore on-line package suggestion program------------------------";
	cout << "\nenter your good name:";
	getline(cin, name);
	while (cin.fail())
	{
		cout << "\ninvalid input...";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nenter your good name:";
		getline(cin, name);
	}
	system("cls");
	cout << "\n hey " << name << "! welcome.\n how many hours you spend on-line?\n";
	cin >> hrs;
	while (cin.fail() || hrs < 0 || hrs>730)
	{
		cout << "\ninvalid input...";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n how many hours you spend on-line?\n";
		cin >> hrs;
	}

	cout << "\n how many times you dial up?\n";
	cin >> conns;
	while (cin.fail() || conns < 0)
	{
		cout << "\ninvalid input...";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n how many times you dial up?\n";
		cin >> conns;
	}
	customer** cus = new customer * [3];
	int s;
	cout << "\n how many memory you use for webpages or pictures?(in mbs)\n";
	cin >> memory;
	while (cin.fail() || memory < 0)
	{
		cout << "\ninvalid input...";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n how many memory you use for webpages or pictures?(in mbs)\n";
		cin >> memory;
	}
	if (memory <= 1)
	{
		s = 3;
		
		customer c(name, hrs);
		cus[0] = &c;
		hacker h(name, hrs);
		cus[1] = &h;
		chatroom chatt(name, conns);
		cus[2] = &chatt;
		float min = cus[0]->computebill();
		int ind = 0;
		for (int i = 0; i < 3; i++)
		{
			if (cus[i]->computebill() < min)
			{
				min = cus[i]->computebill();
				ind = i;
			}
		}
		cus[ind]->display();
		


	}

	else if (memory >= 1 && memory <= 50)
	{
		s = 2;
		hacker h(name, hrs);
		cus[0] = &h;
		chatroom chatt(name, conns);
		cus[1] = &chatt;
		float min = cus[0]->computebill();
		int ind = 0;
		for (int i = 0; i < 2; i++)
		{
			if (cus[i]->computebill() < min)
			{
				min = cus[i]->computebill();
				ind = i;
			}
		}
		cus[ind]->display();
	



	}

	else if (memory >= 50)
	{
		s = 1;
		chatroom h(name, conns);
		cus[0] = &h;
		float min = cus[0]->computebill();
		cus[0]->display();
	



	}
	delete[]cus;
	return 0;


}



