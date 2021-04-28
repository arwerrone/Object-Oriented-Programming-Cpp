/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
#include <fstream>
using namespace std;
namespace sdds {
   class Text {
      char* m_filename = nullptr;
      char* m_content = nullptr;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);

      Text(const Text& right);
      Text& operator=(const Text& right);
      ~Text();
      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, Text& right);
}
#endif // !SDDS_PERSON_H__

