#include "StringCollection.h"
#include <iostream>
#include <string>

using namespace std;

StringCollection::StringCollection() : values(new string[1]), size(1), cursor(0)
{
	cout << "Constructeur vide appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
}

StringCollection::StringCollection(int len) : values(new string[len]), size(len), cursor(0)
{
	cout << "Constructeur taille appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
}

StringCollection::StringCollection(const StringCollection& basic) : values(new string[basic.size]), size(basic.size), cursor(basic.cursor)
{
	for(int i = 0 ; i < size ; i++)
	{
		values[i] = basic.values[i];
	}

	cout << "Constructeur par copie appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
} 

bool StringCollection::add(string value)
{
	if(cursor < size)
	{
		values[cursor] = value;
		cursor++;
	}
	else
	{
		cout << "Ajout impossible, taille maximale atteinte" << endl;
		return false;
	}

	return true;
}

void StringCollection::print()
{
	for(int i = 0 ; i < cursor - 1 ; i++)
	{
		cout << values[i] << " - ";
	}

	cout << values[cursor - 1] << endl;
}

bool StringCollection::contains(string value)
{
	for(int i = 0 ; i < cursor ; i++)
	{
		if(!values[i].compare(value))
		{
			return true;
		}
	}

	return false;
}

void StringCollection::shift(int start)
{
	for(int i = start ; i < cursor ; i++)
	{
		values[i] = values[i + 1];
	}
}

void StringCollection::deleteOccurences(string value)
{
	for(int i = 0 ; i < cursor ; i++)
	{
		if(!values[i].compare(value))
		{
			shift(i);
			i--;
			cursor--;
		}
	}
}

StringCollection * StringCollection::intersectP(StringCollection& col)
{
	int newSize = size + col.size;
	StringCollection* result = new StringCollection(newSize);

	for(int i = 0 ; i < cursor ; i++)
	{
		(*result).add(values[i]);
	}

	for(int i = 0 ; i < col.cursor ; i++)
	{
		(*result).add(col.values[i]);
	}

	return result;
}

StringCollection & StringCollection::intersectR(StringCollection& col)
{
	int newSize = size + col.size;
	StringCollection* result = new StringCollection(newSize);

	for(int i = 0 ; i < cursor ; i++)
	{
		(*result).add(values[i]);
	}

	for(int i = 0 ; i < col.cursor ; i++)
	{
		(*result).add(col.values[i]);
	}

	return (*result);
}

int StringCollection::maxIndexInRange(int stop)
{
	int maxIndex = 0;

	for(int i = 0 ; i < stop ; i++)
	{
		if(values[i] > values[maxIndex])
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}

void StringCollection::sort()
{
	for(int i = cursor - 1 ; i >= 0 ; i--)
	{
		int maxIndex = maxIndexInRange(i + 1);
		string temp = values[i];
		values[i] = values[maxIndex];
		values[maxIndex] = temp;
	}
}

StringCollection::~StringCollection()
{
	delete [] values;
	cout << endl << "Destructeur appelé (" << this << ")" << endl;
}