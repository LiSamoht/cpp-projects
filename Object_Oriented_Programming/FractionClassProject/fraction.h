/*
Thomas Li
CS10B Spring 2024
04/05/2024
Sarkar S
fraction.h

Description:
This header file defines a Fraction class that represents fractions. It provides basic arithmetic operations and comparison operators for fractions.

Private Function Prototypes:

void Fraction::simplify();
pre: None
post: The fraction is simplified...gcd(numerator, denominator) := 1.

Public Function Prototypes:

Fraction(int num, int denom);
pre: denom != 0
post: Constructs a Fraction object with the given numerator and denominator, simplifies the fraction, and ensures the denominator is not zero.

std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
pre: None
post: Outputs the fraction in the format "numerator/denominator" if the fraction is a proper fraction, otherwise in the format "whole_number+numerator/denominator". The fraction is simplified before output.

std::istream& operator>>(std::istream& in, Fraction& readMe);
pre: None
post: Reads a fraction from the input stream in the format "numerator/denominator" or "whole_number+numerator/denominator". The fraction is then simplified.

bool operator<(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is less than the right fraction; otherwise, returns false.

bool operator<=(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is less than or equal to the right fraction; otherwise, returns false.

bool operator>(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is greater than the right fraction; otherwise, returns false.

bool operator>=(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is greater than or equal to the right fraction; otherwise, returns false.

bool operator==(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is equal to the right fraction; otherwise, returns false.

bool operator!=(const Fraction& left, const Fraction& right);
pre: None
post: Returns true if the left fraction is not equal to the right fraction; otherwise, returns false.

Fraction operator+(const Fraction& left, const Fraction& right);
pre: None
post: Returns the sum of the left and right fractions.

Fraction operator-(const Fraction& left, const Fraction& right);
pre: None
post: Returns the difference between the left and right fractions.

Fraction operator*(const Fraction& left, const Fraction& right);
pre: None
post: Returns the product of the left and right fractions.

Fraction operator/(const Fraction& left, const Fraction& right);
pre: None
post: Returns the quotient of the left and right fractions.

Fraction& Fraction::operator+=(const Fraction& right);
pre: None
post: Adds the right fraction to the current fraction and returns the result.

Fraction& Fraction::operator-=(const Fraction& right);
pre: None
post: Subtracts the right fraction from the current fraction and returns the result.

Fraction& Fraction::operator*=(const Fraction& right);
pre: None
post: Multiplies the current fraction by the right fraction and returns the result.

Fraction& Fraction::operator/=(const Fraction& right);
pre: None
post: Divides the current fraction by the right fraction and returns the result.

Fraction& Fraction::operator++();
pre: None
post: Increments the current fraction by 1 and returns the result.

Fraction Fraction::operator++(int);
pre: None
post: Increments the current fraction by 1 and returns the previous value.

Fraction& Fraction::operator--();
pre: None
post: Decrements the current fraction by 1 and returns the result.

Fraction Fraction::operator--(int);
pre: None
post: Decrements the current fraction by 1 and returns the previous value.
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

namespace cs10b_fraction {

    class Fraction {
    private:
        int numerator;
        int denominator;

        void simplify();

    public:
        Fraction(int num = 0, int denom = 1);

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& in, Fraction& readMe);

        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);

        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);

        Fraction& operator+=(const Fraction& right);
        Fraction& operator-=(const Fraction& right);
        Fraction& operator*=(const Fraction& right);
        Fraction& operator/=(const Fraction& right);

        Fraction& operator++();            // Prefix increment
        Fraction operator++(int);          // Postfix increment
        Fraction& operator--();            // Prefix decrement
        Fraction operator--(int);          // Postfix decrement
    };

}

#endif