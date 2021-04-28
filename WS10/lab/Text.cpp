#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "Text.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index)const {
       return  m_content[index];
   }

   Text::Text(const char* filename) {
       if (filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
       else {
           m_filename = nullptr;
       }
   }

   Text::Text(const Text& right){
       operator=(right);
   }

   Text& Text::operator=(const Text& right) {
       if (this != &right) {
           if (right.m_content != nullptr) {
               delete[] m_content;
               m_content = nullptr;
               m_content = new char[strLen(right.m_content) + 1];
               strCpy(m_content, right.m_content);
           }
       }
       return *this;
   }

   Text::~Text() {
       delete[] m_content;
       m_content = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
   }

   void Text::read() {
       int leng = getFileLength();
       if (leng > 0) {
           delete[] m_content;
           m_content = nullptr;
           m_content = new char[leng + 1];
           ifstream fin(m_filename);
           string toread;
           getline(fin, toread, '\0');
           strCpy(m_content, toread.c_str());
       }
   }

   void Text::write(std::ostream& os)const {
       if (m_content != nullptr)
           os << m_content;
   }

   std::ostream& operator<<(std::ostream& os, Text& right) {
       right.write(os);
       return os;
   }

}
