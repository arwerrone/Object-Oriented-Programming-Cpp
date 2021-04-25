#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const{
       return m_number > 0;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }

   bool Account::operator ~() const {
       return m_number == 0;
   }

   Account& Account::operator=(const int i) {
       if (~(*this) && i >= 10000 && i <= 99999) {
           m_number = i;
       }
       else if (i < 10000 || i > 99999) {
           setEmpty();
       }
       else;
       return *this;
   }

   Account& Account::operator=(Account& RO) {
       if (~(*this) && bool(RO)) {
           m_balance = RO.m_balance;
           m_number = RO.m_number;
           RO.m_balance = 0.0;
           RO.m_number = 0;
       }
       else;
       return *this;
   }

   Account& Account::operator+=(double yey) {
       if (*this && yey > 0) {
           m_balance += yey;
       }
       return *this;
   }

   Account& Account::operator-=(double nah) {
       if (*this && nah <= m_balance && nah > 0) {
           m_balance -= nah;
       }
       return *this;
   }

   Account& Account::operator<<(Account& RO) {
       if (this != &RO && this && RO) {
           m_balance += RO.m_balance;
           RO.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& RO) {
       if (this != &RO && this && RO) {
           RO.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+ (const Account& left, const Account& right) {
       double sum = 0;
       if (bool(left) && bool(right)) {
           sum = double(left) + double(right);
       }
       return sum;
   }

   double operator+= (double& left, const Account& right) {
       return left += double(right);
   }

}
