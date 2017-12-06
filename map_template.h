#ifndef __ASSOCTAB_H__
#define __ASSOCTAB_H__

class assocTab
{
	private:
		struct node
		{
			node *next;
			char *key;
			int val;
			node (const char *k):next (NULL)
			{
				key = new char[strlen (k) + 1];
				strcpy (key, k);
			};
			~node ()
			{
				delete[]key;
			}
			node (const node & s):next (NULL)
			{
				if (s.key == NULL)
					key = NULL;
				else
				{
					key = new char[strlen (s.key) + 1];
					strcpy (key, s.key);
				}
				val=s.val;
			};
			private:			//assignment not allowed
				node & operator= (const node &);
		};
	node *head;
	void insert (const char *key, int value);
	void clear ();
	node *find (const char *key) const;
	void swap (assocTab & l);
	public:
	assocTab ();
	assocTab (const assocTab & l);
	assocTab & operator= (const assocTab & l);
	~assocTab ();
	int &operator[] (const char *);
};

assocTab::assocTab ()
{
	head = NULL;
}

void assocTab::clear ()
{
	while (head)
	{
		node *t = head->next;
		delete head;
		head = t;
	};
}

assocTab::~assocTab ()
{
	clear ();
}

void assocTab::insert (const char *key, int value)
{
	node *nowy = new node (key);
	nowy->next = head;
	head = nowy;
	head->val = value;
}

void assocTab::swap (assocTab & l)
{
	node *t = head;
	head = l.head;
	l.head = t;
}


assocTab::assocTab (const assocTab & l)
{
	node *src, **dst;
	head = NULL;
	src = l.head;
	dst = &head;
	try
	{
		while (src)
		{
			*dst = new node (*src);
			src = src->next;
			dst = &((*dst)->next);
		}
	}
	catch (...)
	{
		clear ();
		throw;
	};
}

assocTab & assocTab::operator= (const assocTab & l)
{
	if (&l == this)
	return *this;
	assocTab t (l);
	swap (t);
	return *this;
}

assocTab::node * assocTab::find (const char *key) const
{
	node * c = head;
	while (c)
	{
		if (!strcmp (c->key, key)) return c;
		c = c->next;
	};
	return NULL;
}

int &assocTab::operator[] (const char *key)
{
	node *c = find (key);
	if (!c)
	{
		insert (key, 0);
		c = head;
	};
	return c->val;
}

#endif /* __ASSOCTAB_H__ */
