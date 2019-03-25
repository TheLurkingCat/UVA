/*
    遞迴、二元樹
*/
#include <algorithm>
#include <iostream>

using namespace std;

class Fraction {
    int numerator;
    int denominator;

   public:
    Fraction(int numerator, int denominator) {
        this->denominator = denominator;
        this->numerator = numerator;
    }

    Fraction() {}

    Fraction& operator+=(const Fraction& other) {
        this->denominator += other.denominator;
        this->numerator += other.numerator;
        int&& factor = __gcd(denominator, numerator);
        this->denominator /= factor;
        this->numerator /= factor;
        return *this;
    }

    bool operator!=(const Fraction& other) const {
        return this->denominator != other.denominator || this->numerator != other.numerator;
    }

    bool operator<(const Fraction& other) const {
        return value() < other.value();
    }

    bool operator>(const Fraction& other) const {
        return other.value() > value();
    }

    explicit operator bool() const {
        return denominator != 1 || numerator != 1;
    }

    friend istream& operator>>(istream& in, Fraction& fraction) {
        in >> fraction.numerator >> fraction.denominator;
        return in;
    }

    double value() const {
        return (double)numerator / denominator;
    }
};

int main() {
    Fraction to_find;
    while (cin >> to_find && to_find) {
        Fraction left = {0, 1}, middle = {1, 1}, right = {1, 0};
        while (to_find != middle) {
            if (to_find < middle) {
                cout << "L";
                right = middle;
                middle += left;
            } else {
                cout << "R";
                left = middle;
                middle += right;
            }
        }
        cout << "\n";
    }
    return 0;
}