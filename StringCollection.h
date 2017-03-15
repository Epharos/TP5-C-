#ifndef StringCollection_h
#define StringCollection_h

#include <string>

class StringCollection
{
	std::string* values;
	int size;
	int cursor;

	public :
		StringCollection();
		StringCollection(int);
		StringCollection(const StringCollection&);

		bool add(std::string);
		void print();
		bool contains(std::string);
		void deleteOccurences(std::string);
		StringCollection * intersectP(StringCollection&);
		StringCollection & intersectR(StringCollection&);
		void sort();

		~StringCollection();

	private :
		void shift(int);
		int maxIndexInRange(int);
};

#endif