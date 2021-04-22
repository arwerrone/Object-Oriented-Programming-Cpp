#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Population {
		//char m_postalCode[4];
		char* m_postalCode;
		int m_population;
	};
	void sort();
	bool load(Population& pop);
	bool load(const char* FILEname);
	void display(const Population& popul);
    void display();
	void deallocateMemory();
}
#endif
