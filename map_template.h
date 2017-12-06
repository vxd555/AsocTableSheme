#ifndef __ASSOCTAB_H__
#define __ASSOCTAB_H__

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

template <class Key, class ClassType> class map_template
{
	public: 
		class Item
		{
			public:
				ClassType value;
				Key key;

				Item(const Key& k, const ClassType& val) : value(val), key(k) {}
		    
		};
		vector<Item> data;
		
    	void Clear()
    	{
    		data.clear();
    		return;
    	}
    	
    	int Size() const
    	{
    		return data.size();
    	}
    	
    	ClassType *Find(Key key)
    	{
    		for(int i = 0; i < Size(); ++i)
    		{
    			if(data[i].key == key)
    			{
    				return &data[i].value;
    			}
    		}
    		return nullptr;
    	}
    
		void Add(const Key& key, const ClassType& val)
		{
			if(Find(key))
			{
				cout << "klucz juz znajduje sie w bazie\n";
				return;
			}
			Item tempItem(key, val);
			data.push_back(tempItem);
			return;
		}
		
		map_template()
		{
		
		}
		map_template(const map_template& mt)
		{
			data = mt.data;
		}
		~map_template()
    	{
    		Clear();
    	}
    	
    	friend ostream& operator<< (ostream& out, const map_template<Key, ClassType>& mt)
    	{
    		for(int i = 0; i < mt.Size(); ++i)
			{
				cout << mt.data[i].value << "\n";
			}
			return out;
    	}
};


#endif /* __ASSOCTAB_H__ */
