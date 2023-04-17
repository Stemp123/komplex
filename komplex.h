#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <iostream>

class Komplex
{
public:
    Komplex() {}
    Komplex(float re, float im=0.0);
    static Komplex fromAbsArg(float a, float grader);
    float re() const;
    float im() const;
    float abs() const;
    float argRadians() const;
    float argDegrees() const;

    Komplex konjugat() const;

    operator std::string() const;

    const Komplex& operator+=(const Komplex& h);
    const Komplex& operator-=(const Komplex& h);
    const Komplex& operator*=(const Komplex& h);
    const Komplex& operator/=(const Komplex& h);
private:
    float m_re;
    float m_im;
};

Komplex operator "" _i(long double d);
Komplex operator "" _i(unsigned long long i);

Komplex operator+(const Komplex& v, const Komplex& h);
Komplex operator-(const Komplex& v, const Komplex& h);
Komplex operator-(const Komplex& c);
Komplex operator*(const Komplex& v, const Komplex& h);
Komplex operator/(const Komplex& v, const Komplex& h);

std::ostream& operator<<(std::ostream& out, Komplex c);

#endif // KOMPLEX_H
