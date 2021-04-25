/**
 * Name:                Angelo Dikon Wong
 * Student ID:          148021199
 * Seneca email:        adikon-wong@myseneca.ca
 * Section:             OOP244 - NGG
 **/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(const int i);
      Account& operator=(Account& RO);
      Account& operator+=(double yey);
      Account& operator-=(double nah);
      Account& operator<<(Account& RO);
      Account& operator>>(Account& RO);
   };
   double operator+ (const Account& left, const Account& right);
   double operator+= (double& left, const Account& right);
}
#endif // SDDS_ACCOUNT_H_