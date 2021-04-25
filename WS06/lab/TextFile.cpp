/**
 * Name:			Angelo Dikon Wong
 * Student ID:		14802199
 * Seneca email:	adikon-wong@myseneca.ca
 * Section:			OOP244 - NGG
 **/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
      m_value = nullptr;
   }

   void TextFile::setEmpty() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;         //nao tenho certeza se e, se n for tira o []... provavelmente n
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       delete[] m_filename;
       m_filename = nullptr;

       if (isCopy) {
           m_filename = new char[strLen(fname) + 3];
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       
       if (!isCopy) {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
       }
   }

   void TextFile::setNoOfLines() {
       ifstream file(m_filename);
       while (file) {
           m_noOfLines += (file.get() == '\n');
       }
       if (m_noOfLines == 0) {
           delete[] m_filename;
           m_filename = nullptr;
       }
       else {
           m_noOfLines++;
       }
   }

   void TextFile::loadText() {
       int i = 0;
       if (m_filename != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
           m_textLines = new Line[m_noOfLines];
           ifstream file(m_filename);
           string line;

           while (getline(file, line)) {
               m_textLines[i++] = line.c_str();
           }
           m_noOfLines = i;
       }
   }

   void TextFile::saveAs(const char* fileName)const {
       ofstream file(fileName);
       int x = m_noOfLines;
       for (int i = 0; i < x; i++) {
           file << m_textLines[i] << endl;
       }
   }

   TextFile::TextFile(unsigned pageSize):m_pageSize{pageSize} {
       
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       //:m_pageSize{pageSize}, m_textLines{nullptr}, m_noOfLines{0}{
       m_pageSize = pageSize;
       if (filename != nullptr) {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile::TextFile(const TextFile& text){
       //:m_pageSize{text.m_pageSize}, m_textLines{nullptr}, m_noOfLines{0} {
       m_pageSize = text.m_pageSize;
       if (text.m_filename != nullptr) {
           setFilename(text.m_filename, true);
           text.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& text) {
       if (this != &text) {
           delete[] m_textLines;
           m_textLines = nullptr;
           if (text.m_filename != nullptr) {
               text.saveAs(m_filename);
               setNoOfLines();
               loadText();
           }
       }
       return *this;
   }
   
   TextFile::~TextFile() {
       setEmpty();
   }

   unsigned TextFile::lines()const {
       return m_noOfLines;
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
       if (m_filename != nullptr) {
           cout << m_filename << endl;
           int len = strLen(m_filename);
           cout.width(len);
           cout.fill('=');
           cout << "" << endl;
           int x = m_noOfLines;
           for (int i = 0; i < x; i++) {
               cout << m_textLines[i] << endl;
               if ((i + 1) % m_pageSize == 0) {
                   ostr << "Hit ENTER to continue...";
                   cin.ignore(1000, '\n');
               }
           }
       }
       return ostr;
   }
   
   std::istream& TextFile::getFile(std::istream& istr) {
       string temp;
       getline(istr, temp);
       setFilename(temp.c_str());
       setNoOfLines();
       loadText();

       return istr;
   }

   const char* TextFile::operator[](unsigned index)const {
       const char* line = nullptr;
       if (*this) {
           line = m_textLines[index % m_noOfLines];
       }

       return line;
   }

   TextFile::operator bool()const {
       return m_textLines != nullptr;
   }

   const char* TextFile::name()const {
       return m_filename;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }

   std::istream& operator>>(std::istream& istr, TextFile& text) {
       return text.getFile(istr);
   }

}