#include "komplex.h"
#include <cmath>
#include <sstream>
#include <cassert>

Komplex::Komplex(float re, float im): m_re(re), m_im(im) {}

Komplex Komplex::fromAbsArg(float a, float grader) {
    float radians = grader * M_PI / 180.0;
    return Komplex(a * cos(radians), a * sin(radians));
}

float Komplex::re() const {
    return m_re;
}

float Komplex::im() const {
    return m_im;
}

float Komplex::abs() const {
    return sqrt(m_re * m_re + m_im * m_im);
}

float Komplex::argRadians() const {
    return atan2f(m_im, m_re);
}

float Komplex::argDegrees() const {
    return argRadians() * M_PI / 180.0;
}

Komplex Komplex::konjugat() const {
    return Komplex(m_re, -m_im);
}

Komplex::operator std::string() const {
    std::stringstream ss;
    ss << "(" << m_re << (m_im >= 0 ? "+" : "-") << fabsf(m_im) << "i)";
    return ss.str();
}
/*
Komplex::operator std::string() const {
    std::string str_re = std::to_string(m_re);
    std::string str_im = std::to_string(m_im);
    std::string tecken = m_im >= 0 ? "+" : "-";

    std::string str = "(" + str_re + tecken + str_im + "i)";
    return str;
}
*/
const Komplex & Komplex::operator += (const Komplex & h) {
    *this = *this + h;
    return * this;
}
const Komplex & Komplex::operator -= (const Komplex & h) {
    *this = *this - h;
    return * this;
}

const Komplex & Komplex::operator *= (const Komplex & h) {
    *this = *this * h;
    return * this;
}

const Komplex & Komplex::operator /= (const Komplex & h) {
    *this = *this / h;
    return * this;
}

Komplex operator "" _i(long double d) {
    return Komplex(0, d);
}

Komplex operator "" _i(unsigned long long i) {
    return Komplex(0.0, i);
}

Komplex operator*(const Komplex& v, const Komplex& h){
    return Komplex( v.re()*h.re()-v.im()*h.im(), v.re()*h.im()+v.im()*h.re());
}

Komplex operator/(const Komplex& v, const Komplex& h){
    Komplex taljare = v * h.konjugat();
    Komplex namnare = h * h.konjugat();
    assert(abs(namnare.im()) < 0.0001);
    return Komplex( taljare.re()/namnare.re(), taljare.im()/namnare.re());
}

Komplex operator+(const Komplex& v, const Komplex& h) {
    return Komplex(v.re() + h.re(), v.im() + h.im());
}

Komplex operator-(const Komplex& v, const Komplex& h) {
    return Komplex(v.re() - h.re(), v.im() - h.im());
}

Komplex operator-(const Komplex& c) {
    return Komplex(-c.re(), -c.im());
}

std::ostream& operator<<(std::ostream& out, Komplex c){
    out << std::string(c);
    return out;
}
