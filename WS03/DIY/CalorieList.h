#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        char m_title[37];
        Food* m_items;
        int m_noOfFoods;
        int m_itemsAdded;
        int totalCalories()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfItems);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif
