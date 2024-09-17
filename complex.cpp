//kkorenn1@gmail.com
#include "complex.hpp"

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getter methods
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

// Comparison operators
bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator<(const Complex& other) const {
    return this->magnitude() < other.magnitude();
}

bool Complex::operator<=(const Complex& other) const {
    return this->magnitude() <= other.magnitude();
}

bool Complex::operator>(const Complex& other) const {
    return this->magnitude() > other.magnitude();
}

bool Complex::operator>=(const Complex& other) const {
    return this->magnitude() >= other.magnitude();
}

// Magnitude of the complex number
double Complex::magnitude() const {
    return std::sqrt(real * real + imag * imag);
}

// Overload << operator for printing
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << " + " << c.imag << "i";
    else os << " - " << -c.imag << "i";
    return os;
}
