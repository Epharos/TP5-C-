#ifndef IntCollection_h
#define IntCollection_h

class IntCollection
{
	int *values;
	int size;
	int cursor;

	public :
		IntCollection();
		IntCollection(int);
		IntCollection(const IntCollection&);

		bool add(int);
		void print();
		bool contains(int);
		void deleteOccurences(int);
		void properties(int&, int&, double&);
		IntCollection * intersectP(IntCollection&);
		IntCollection & intersectR(IntCollection&);
		void sort();

		~IntCollection();

	private :
		void shift(int);
		int maxIndexInRange(int);
};

#endif