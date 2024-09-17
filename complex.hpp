//kkorenn1@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0);

    double getReal() const;
    double getImag() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    double magnitude() const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif 
