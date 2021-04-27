/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
#include <iostream>
#include <fstream>

namespace sdds {
   class HtmlText :  public Text {
      char* m_title = nullptr;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& right);
      HtmlText& operator=(const HtmlText& right);
      ~HtmlText();
      void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os,const HtmlText& right);
}
#endif // !SDDS_HTMLTEXT_H__
