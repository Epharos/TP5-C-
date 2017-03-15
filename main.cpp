#include <iostream>
#include <string>
#include "IntCollection.h"
#include "StringCollection.h"

using namespace std;

int main()
{
	// IntCollection i(20);
	// IntCollection j(10);

	// i.add(24);
	// i.add(2);
	// i.add(30);
	// i.add(27);
	// j.add(2);
	// j.add(35);

	// int min, max;
	// double average;

	// i.properties(min, max, average);

	// cout << min << " - " << max << " - " << average << endl;

	// i.print();

	// i.deleteOccurences(2);

	// i.print();

	// i.print();
	// j.print();

	// IntCollection* c = i.intersectP(j);
	// IntCollection& d = i.intersectR(j);

	// (*c).print();
	// d.print();

	// d.sort();

	// d.print();

	// delete c;
	// delete &d;

	// ----------------------------

	StringCollection s(10);
	StringCollection t;

	s.add("yolo");
	s.add("test héhé");
	s.add("salut les gens !");

	t.add("la maison près de la fontaine");

	s.sort();
	s.print();

	StringCollection* c = s.intersectP(t);
	StringCollection& d = s.intersectR(t);

	(*c).print();
	d.print();

	delete c;
	delete &d;
}