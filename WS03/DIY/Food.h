#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char f_name[31];
        int m_calories;
        int m_time;

        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int time);
        void display()const;
        bool isValid()const;
        int calories()const;
    };
}

#endif
