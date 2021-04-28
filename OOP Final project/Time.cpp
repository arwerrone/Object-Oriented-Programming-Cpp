#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

    Time& Time::setToNow() {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int minutes) {
        m_min = minutes;
    }

    std::ostream& Time::write(std::ostream& ostr) const {
        int temp = m_min;
        char col = ':';
        int hh = 0;
        int mm = 0;

        while (temp >= 60)
        {
            temp -= 60;
            hh++;
        }
        mm = temp;
        if (hh < 10) ostr << 0;
        ostr << hh << col;
        if (mm < 10) ostr << 0;
        ostr << mm;

        return ostr;
    }

    std::istream& Time::read(std::istream& istr) {
        int hh = -1, mm = -1;

        istr >> hh;
        if (hh < 0) istr.setstate(ios::failbit);
        if (istr.get() != ':') istr.setstate(ios::failbit);
        istr >> mm;
        if (mm < 0) istr.setstate(ios::failbit);
        if (istr) m_min = (unsigned)mm + hh * 60;

        return istr;
    }

    Time& Time::operator-=(const Time& D) {
        if (m_min > D.m_min) {
            m_min = m_min - D.m_min;
        }
        if (m_min < D.m_min) {
            if (D.m_min > 1440) {
                m_min += 1440;
            }
            m_min += 1440;
            m_min = m_min - D.m_min;
        }
        return *this;
    }

    Time Time::operator-(const Time& D)const {
        int temp = m_min;
        int dtemp = D.m_min;
        do {
            if (temp < dtemp) {
                temp = temp + 1440;
            }
        } while (temp < dtemp);

        temp = temp - dtemp;

        return temp;
    }

    Time& Time::operator+=(const Time& D) {
        m_min += D.m_min;
        return *this;
    }

    Time Time::operator+(const Time& D)const {
        int temp = *this;
        temp += D.m_min;
        return temp;
    }

    Time& Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }

    Time& Time::operator *= (unsigned int val) {
        m_min = m_min* val;
        return *this;
    }

    Time Time::operator *(unsigned int val)const {
        return Time(m_min * val);
    }

    Time& Time::operator /= (unsigned int val) {
        m_min = m_min / val;
        return *this;
    }

    Time Time::operator /(unsigned int val)const {
        return Time(m_min / val);
    }

    Time::operator int()const {
        return int(m_min);
    }

    Time::operator unsigned int()const {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D) {
        D.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Time& D) {
        D.read(istr);
        return istr;
    }

}
