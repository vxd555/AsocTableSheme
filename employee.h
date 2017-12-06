#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

class Employee
{
	protected:
	string name;
	string department;
	int id;
	public:
		Employee()
		{
			name = "";
			department = "";
			id = 0;
		}
		Employee (const string n, const string d, int ident): name (n), department (d), id(ident)
		{

		}
		Employee(const Employee& em)
		{
			name = (const string)em.name;
			department = (const string)em.department;
			id = em.id;
		}
		virtual void print() const
		{
			cout << name << '\t' << department << '\t' << id << endl;
		}
		//friend ostream& operator<< (ostream &o, const Employee& em);
};

/*ostream& operator<< (ostream &o, const Employee& em)
{
	em.print();
	return o;
}*/

class Manager:public Employee
{
	int level;
	public:
		Manager (const string n, const string d, int ident, int l):Employee(n, d, ident), level (l)	
		{
		};
		void print () const override
		{
			Employee::print ();
			cout << "\tlevel" << level << endl;
		}
		//friend ostream& operator<< (ostream &o, const Manager& ma);
};

/*ostream& operator<< (ostream &o, const Manager& ma)
{
	ma.print();
	return o;
}*/


void print_list(set < Employee * >&s)
{
	for (set < Employee * >::const_iterator p = s.begin (); p != s.end (); ++p)
		(*p)->print ();
}

void print_list_2(set < Employee * >&s)
{
	for_each (s.begin (), s.end (), mem_fun (&Employee::print));
}
