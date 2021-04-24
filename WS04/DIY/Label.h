#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds {
	class Label {
		char m_frame[9];
		char* m_conent;

	public:
		void setToDefault();
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;

	};
}
#endif
