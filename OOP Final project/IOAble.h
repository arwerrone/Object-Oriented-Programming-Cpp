#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>

namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream&) const = 0;
		virtual std::istream& csvRead(std::istream&) = 0;
		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual ~IOAble(){};
	};
	std::ostream& operator<<(std::ostream& os, IOAble& right);
	std::istream& operator>>(std::istream& in, IOAble& right);
}
#endif
