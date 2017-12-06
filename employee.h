#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

class Employee;
class Manager;
ostream& operator<< (ostream &o, const Employee& em);
ostream& operator<< (ostream &o, const Manager& ma);

class Employee
{
	public:
		string name;
		string Position;
		int Age;
	
		Employee()
		{
			name = "";
			Position = "";
			Age = 0;
		}
		Employee (const string n, const string d, int age): name (n), Position (d), Age(age)
		{

		}
		Employee(const Employee& em)
		{
			name = (const string)em.name;
			Position = (const string)em.Position;
			Age = em.Age;
		}
		virtual void print() const
		{
			cout << name << '\t' << Position << '\t' <<Age << endl;
		}
		friend ostream& operator<< (ostream &o, const Employee& em);
};

ostream& operator<< (ostream &o, const Employee& em)
{
	em.print();
	return o;
}

class Manager:public Employee
{
	int level;
	public:
		Manager (const string n, const string d, int age, int l):Employee(n, d, age), level (l)	
		{
		};
		void print () const override
		{
			Employee::print ();
			cout << "\tlevel" << level << endl;
		}
		friend ostream& operator<< (ostream &o, const Manager& ma);
};

ostream& operator<< (ostream &o, const Manager& ma)
{
	ma.print();
	return o;
}


void print_list(set < Employee * >&s)
{
	for (set < Employee * >::const_iterator p = s.begin (); p != s.end (); ++p)
		(*p)->print ();
}

void print_list_2(set < Employee * >&s)
{
	for_each (s.begin (), s.end (), mem_fun (&Employee::print));
}
