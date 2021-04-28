#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include <iostream>
#include "cstring.h"
#include <fstream>
#include <cstring>

using namespace std;
namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title):Text(filename){
		if (title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
	}

	HtmlText::HtmlText(const HtmlText& right):Text(right) {
		delete[] m_title;
		m_title = nullptr;
		m_title = new char[strLen(right.m_title) + 1];
		strCpy(m_title, right.m_title);
	}

	HtmlText& HtmlText::operator=(const HtmlText& right) {
		if (this != &right) {
			if (right.m_title != nullptr) {
				Text::operator=(right);
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strLen(right.m_title) + 1];
				strCpy(m_title, right.m_title);
			}
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::write(std::ostream& os)const {
		bool MS = false;
		os << "<html><head><title>";
		if (m_title != nullptr)
			os << m_title;
		else
			os << "No Title";
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		const HtmlText& T = *this;
		for (int i = 0; T[i]; i++) {
			switch (T[i])
			{
			case ' ':
				if (MS)
					os << "&nbsp;";
				else {
					MS = true;
					os << " ";
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				MS = false;
				os << T[i];
				break;
			}
		}
		os << "</body>\n</html>";
	}

	std::ostream& operator<<(std::ostream& os, const HtmlText& right) {
		right.write(os);
		return os;
	}

}
