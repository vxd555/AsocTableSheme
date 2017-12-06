#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Employee
{
	protected:
	string name;
	string department;
	int id;
	public:
	Employee (const string n, const string d, int ident): name (n), department (d), id(ident)
	{

	};
	void print () const
	{
		cout << name << '\t' << department << '\t' << id << endl;
	}
};

class Manager:public Employee
{
	int level;
	public:
		Manager (const string n, const string d, int ident, int l):Employee(n, d, ident), level (l)	
		{
		};
		void print () const
		{
			Employee::print ();
			cout << "\tlevel" << level << endl;
		}
};


void print_list(set < Employee * >&s)
{
	for (set < Employee * >::const_iterator p = s.begin (); p != s.end (); ++p)
		(*p)->print ();
}

void print_list_2(set < Employee * >&s)
{
	for_each (s.begin (), s.end (), mem_fun (&Employee::print));
}
