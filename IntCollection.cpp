#include "IntCollection.h"
#include <iostream>
#include <math.h>

using namespace std;

IntCollection::IntCollection() : values(new int[1]), size(1), cursor(0)
{
	cout << "Constructeur vide appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
}

IntCollection::IntCollection(int len) : values(new int[len]), size(len), cursor(0)
{
	cout << "Constructeur taille appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
}

IntCollection::IntCollection(const IntCollection& basic) : values(new int[basic.size]), size(basic.size), cursor(basic.cursor)
{
	for(int i = 0 ; i < size ; i++)
	{
		values[i] = basic.values[i];
	}

	cout << "Constructeur par copie appelé (" << this << ")" << endl;
	cout << this << " > Collection de taille " << size << endl << endl;
} 

bool IntCollection::add(int value)
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

void IntCollection::print()
{
	for(int i = 0 ; i < cursor - 1 ; i++)
	{
		cout << values[i] << " - ";
	}

	cout << values[cursor - 1] << endl;
}

bool IntCollection::contains(int value)
{
	for(int i = 0 ; i < cursor ; i++)
	{
		if(values[i] == value)
		{
			return true;
		}
	}

	return false;
}

void IntCollection::shift(int start)
{
	for(int i = start ; i < cursor ; i++)
	{
		values[i] = values[i + 1];
	}
}

void IntCollection::deleteOccurences(int value)
{
	for(int i = 0 ; i < cursor ; i++)
	{
		if(values[i] == value)
		{
			shift(i);
			i--;
			cursor--;
		}
	}
}

void IntCollection::properties(int& min, int& max, double& average)
{
	min = values[0];
	max = values[0];
	double sum = 0;

	for(int i = 0 ; i < cursor ; i++)
	{
		if(values[i] < min)
		{
			min = values[i];
		}

		if(values[i] > max)
		{
			max = values[i];
		}

		sum += values[i];
	}

	average = sum / float(cursor);
}

IntCollection * IntCollection::intersectP(IntCollection& col)
{
	int newSize = size + col.size;
	IntCollection* result = new IntCollection(newSize);

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

IntCollection & IntCollection::intersectR(IntCollection& col)
{
	int newSize = size + col.size;
	IntCollection* result = new IntCollection(newSize);

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

int IntCollection::maxIndexInRange(int stop)
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

void IntCollection::sort()
{
	for(int i = cursor - 1 ; i >= 0 ; i--)
	{
		int maxIndex = maxIndexInRange(i + 1);
		int temp = values[i];
		values[i] = values[maxIndex];
		values[maxIndex] = temp;
	}
}

IntCollection::~IntCollection()
{
	delete [] values;
	cout << endl << "Destructeur appelé (" << this << ")" << endl;
}