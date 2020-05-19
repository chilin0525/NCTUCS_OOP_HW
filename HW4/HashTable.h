#ifndef HASHTABLE
#define HASHTABLE
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <sstream>
using namespace std;

struct _dictionary{
    string key;
    string gender;
    int height, weight;
//func-----------------
    string getGender();
    int getHeight();
    int getWeight();
    _dictionary(){};
    _dictionary(string k, string g, int h, int w) : key(k), gender(g), height(h), weight(w){};
};

class HashTable{
    public:
        void addItem(string k, string g, int h, int w);
        _dictionary& operator[](const string&);
        vector<list<_dictionary>> table;
        HashTable() { table.resize(999); }

    private:
        int Hashfunction(string key_str);
};

string _dictionary::getGender(){
    return this->gender;
}

int _dictionary::getHeight(){
    return this->height;
}

int _dictionary::getWeight(){
    return this->weight;
}


_dictionary& HashTable::operator[](const string& temp){
    int index = Hashfunction(temp);
    list<_dictionary>::iterator itr=table[index].begin();
    while(itr != table[index].end())
	{
		if((*itr).key==temp)
		{
		    return (*itr);
	    }
	    itr++;
	}
}

void HashTable::addItem(string k, string g, int h, int w){
    _dictionary temp(k, g, h, w);
    int index = Hashfunction(k);
    table[index].push_front(temp);
}

int HashTable::Hashfunction(string temp)
{
	stringstream ss;
	ss.clear();
	long long int number;
	ss<<temp;
	ss>>number;
	number=pow(number,0.5);
	return number%999;
}

#endif
