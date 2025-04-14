/*
Class Invariant:
- The denominator of a Fraction object is never zero.
-The numerator and denominator are always to be simplified (relatively prime)

Private Data Members:
- numerator: Stores the numerator of the fraction.
- denominator: Stores the denominator of the fraction.
*/
#include "fraction.h"

namespace cs10b_fraction {
	/* 
	Simplifies the fraction so that the numerator and denominator are relatively prime. If denominator is 1, the fraction is simplified. The fraction is first treated
	as a positive value always...its final sign is determined at the end. The simplification process works through constantly dividing the remainder and denominator
	by prime numbers less than the original denominator value.
	*/
	void Fraction::simplify() {
		//if integer, already simplified fully
		if (denominator == 1) {
			return;
		}

		int num = abs(numerator);
		int denom = abs(denominator);

		int intPart = num / denom;
		int residue = num % denom;

		bool simplified = false;
		const int PRIME_THRESHOLD = denom;

		while (!simplified) {
			for (int i = 2; i <= PRIME_THRESHOLD; i++) {
				if ((denom % i == 0) && (residue % i == 0)) {
					residue = residue / i;
					denom = denom / i;
					break;
				}
				if (i == PRIME_THRESHOLD) {
					simplified = true;
				}
			}
		}
		if (numerator < 0 || denominator < 0) {
			numerator = -1 * (intPart * denom + residue);
		}
		else {
			numerator = intPart * denom + residue;
		}
		denominator = denom;
	}



	/*
	Constructs a Fraction object with the given numerator and denominator.
	*/
	Fraction::Fraction(int num, int denom) {
		assert(denom != 0);
		numerator = num;
		denominator = denom;
		simplify();
	}



	/*
	 Outputs the fraction to the output stream.
	*/
	std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
		Fraction copy = fraction;
		copy.simplify();

		if (copy.denominator == 1) {
			out << copy.numerator;
		}
		else if (abs(copy.numerator) < abs(copy.denominator)) {
			out << copy.numerator << "/" << copy.denominator;
		}
		else {
			//if original fraction was negative, reverse sign of remainder for formatting
			if (fraction.numerator < 0) {
				out << copy.numerator / copy.denominator << "+"
					<< -1 * copy.numerator % copy.denominator << "/" << copy.denominator;
			}
			else {
				out << copy.numerator / copy.denominator << "+"
					<< copy.numerator % copy.denominator << "/" << copy.denominator;
			}
		}
		return out;
	}



	/*
	Reads a fraction from the input stream.
	*/
	std::istream& operator>>(std::istream& in, Fraction& readMe) {
		int num, denom, intPart;
		char slash, sign;

		in >> sign;
		bool negative = (sign == '-');

		if (!negative) {
			in.putback(sign); // Put back the character as it's not a negative sign
		}

		in >> num; //read in the numerator

		char nextChar = in.peek(); //look at next character

		if (nextChar == '+') {
			in.ignore();//ignore the + sign

			intPart = num; //was a mixed number, so intPart gets the original numerator we read in first
			in >> num; //now read in true numerator

			in >> slash; 

			in >> denom;
		}
		else if (nextChar == '/') {
			intPart = 0; //not a mixed number, so intPart = 0
			in.ignore();
			in >> denom;
		}
		else {
			intPart = 0; //not a mixed numbber so intPart = 0
			denom = 1;
		}

		num = intPart * denom + num;

		if (negative) {
			num = -num;
		}

		readMe = Fraction(num, denom);
		readMe.simplify();

		return in;
	}


	
	/*
	 Compares two fractions to determine if the left fraction is less than the right fraction.
	*/
	bool operator<(const Fraction& left, const Fraction& right) {
		return (left.numerator * right.denominator) < (right.numerator * left.denominator);
	}
	/*
	Compares two fractions to determine if the left fraction is less than or equal to the right fraction.
	*/
	bool operator<=(const Fraction& left, const Fraction& right) {
		return (left.numerator * right.denominator) <= (right.numerator * left.denominator);
	}
	/*
	Compares two fractions to determine if the left fraction is greater than the right fraction.
	*/
	bool operator>(const Fraction& left, const Fraction& right) {
		return (left.numerator * right.denominator) > (right.numerator * left.denominator);
	}
	/*
	Compares two fractions to determine if the left fraction is greater than or equal to the right fraction.
	*/
	bool operator>=(const Fraction& left, const Fraction& right) {
		return (left.numerator * right.denominator) >= (right.numerator * left.denominator);
	}
	/*
	Compares two fractions to determine if they are equal.
	*/
	bool operator==(const Fraction& left, const Fraction& right) {
		return (left.numerator * right.denominator) == (right.numerator * left.denominator);
	}
	/*
	Compares two fractions to determine if they are not equal.
	*/
	bool operator!=(const Fraction& left, const Fraction& right) {
		return !(left == right);
	}



	/*
	Adds two fractions.
	*/
	Fraction operator+(const Fraction& left, const Fraction& right) {
		int numerator = left.numerator * right.denominator + right.numerator * left.denominator;
		int denominator = left.denominator * right.denominator;
		return Fraction(numerator, denominator);
	}
	/*
	Subtracts two fractions.
	*/
	Fraction operator-(const Fraction& left, const Fraction& right) {
		int numerator = left.numerator * right.denominator - right.numerator * left.denominator;
		int denominator = left.denominator * right.denominator;
		return Fraction(numerator, denominator);
	}
	/*
	 Multiplies two fractions.
	*/
	Fraction operator*(const Fraction& left, const Fraction& right) {
		int numerator = left.numerator * right.numerator;
		int denominator = left.denominator * right.denominator;
		return Fraction(numerator, denominator);
	}
	/*
	Divides two fractions.
	*/
	Fraction operator/(const Fraction& left, const Fraction& right) {
		int numerator = left.numerator * right.denominator;
		int denominator = left.denominator * right.numerator;
		return Fraction(numerator, denominator);
	}



	/*
	 Adds the right fraction to the current fraction.
	*/
	Fraction& Fraction::operator+=(const Fraction& right) {
		*this = *this + right;
		return *this;
	}
	/*
	Subtracts the right fraction from the current fraction.
	*/
	Fraction& Fraction::operator-=(const Fraction& right) {
		*this = *this - right;
		return *this;
	}
	/*
	Multiplies the current fraction by the right fraction.
	*/
	Fraction& Fraction::operator*=(const Fraction& right) {
		*this = *this * right;
		return *this;
	}
	/*
	Divides the current fraction by the right fraction.
	*/
	Fraction& Fraction::operator/=(const Fraction& right) {
		*this = *this / right;
		return *this;
	}



	/*
	Prefix increment operator.
	*/
	Fraction& Fraction::operator++() {
		*this += 1;
		return *this;
	}
	/*
	Postfix increment operator.
	*/
	Fraction Fraction::operator++(int) {
		Fraction temp(*this);
		*this += 1;
		return temp;
	}
	/*
	Prefix decrement operator.
	*/
	Fraction& Fraction::operator--() {
		*this -= 1;
		return *this;
	}
	/*
	Postfix decrement operator.
	*/
	Fraction Fraction::operator--(int) {
		Fraction temp(*this);
		*this -= 1;
		return temp;
	}
}
