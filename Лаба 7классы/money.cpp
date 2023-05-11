#include "money.h"
Money::Money() : m_rubles(0), m_kopeks(0) {}
Money::Money(long rubles, int kopeks) : m_rubles(rubles), m_kopeks(kopeks) {}
long Money::getRubles() const {
	return m_rubles;
}
int Money::getKopeks() const {
	return m_kopeks;
}
void Money::setRubles(long rubles) {
	m_rubles = rubles;
}
void Money::setKopeks(int kopeks) {
	m_kopeks = kopeks;
}
ostream& operator<<(ostream& os, const Money& money) {
	os << money.m_rubles << "," << money.m_kopeks;
	return os;
}
istream& operator>>(istream& is, Money& money) {
	char comma;
	is >> money.m_rubles >> comma >> money.m_kopeks;
	return is;
}
bool Money::operator==(const Money& other) const {
	return (m_rubles == other.m_rubles) && (m_kopeks == other.m_kopeks);
}
bool Money::operator>(double value) const {
	double total = m_rubles + (m_kopeks / 100.0);
	return total > value;
}