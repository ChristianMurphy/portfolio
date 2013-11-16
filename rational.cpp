/*!
 * @brief program demonstrates a rational datatype that can execute basic operations and be used with iostream
 * @author Christian Murphy
 */

//libraries for: input/output, strings, time, rand, stringstream
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

//class for rational numbers
class Rational{
    private:
        int numerator, denomenator;

		//reduces the number to the simplest possible form
        void reduce(){
				//sets bound of finding simplifacion based lesser number
				int bound;
				if (numerator < denomenator) {
					bound = abs(numerator);
				}
				else {
					bound = denomenator;
				}
				//checks every number between 2 and the bound to see if rational can be reduced
                for (int i = bound; i > 1; i--){
					//if both numerator and denomenator have mod 0
					//then the numerator and the denomenator can be reduced by i
					if (( (numerator % i) == 0) && ( (denomenator % i) == 0))
					{
                        numerator /= i;
						denomenator /= i;
                    }
                }
        }
        
    public:
		//GETTERS
		//returns denomenator
		int getNumerator() const {
			return numerator;
		}
		//returns numerator
		int getDenomenator() const{
			return denomenator;
		}
		
		//SETTERS
		//sets numerator
		void setNumerator(int numer){
			numerator = numer;
		}
		//sets denomenator
		void setDenomenator(int denomen){
			//if denomenator is greater than 0
			if (denomen > 0){
				denomenator = denomen;
			}
			//if denomenator is 0, error, default to 0
			else if (denomen == 0){
				cout << "ERROR: division by zero" << endl << "defaulting denomenator to one" << endl;
				denomenator = 1;
			}
			//if negative make positive
			else {
				denomenator = -denomen;
				numerator *= -1;
			}
		}
		//sets both numerator and denomenator
		void setRational(int numer, int denomen) {
			setNumerator(numer);
			setDenomenator(denomen);
			reduce();
		}
		
		//FRIENDS
		//allows the input and output operators to be overloaded
        friend ostream& operator << (ostream&, const Rational&);
        friend istream& operator >> (istream&, Rational&);
        
        //CONSTRUCTORS for the class
        //contructor takes both numerator and denomenator
        //and Reduces
		Rational(int numer, int denomen){
			setNumerator(numer);
            setDenomenator(denomen);
            reduce();
        }

		//contructor takes only numerator
		//denomentator defaulted to One
		//I.E. it is a whole number
        Rational(int numer){
            setNumerator(numer);
            setDenomenator(1);
        }
        //default constructor
        //defaults value to 0/1
        Rational(){
            setNumerator(1);
            setDenomenator(1);
        }
        
        //OPERATOR OVERLOADING
        //BOOLEAN OVERLOADS
		//checks if two rationals are equivalent
        bool operator == (Rational other) const {
            return ( (numerator == other.numerator) && (denomenator == other.denomenator));
        }

		//checks if first rational is less than other rational
        bool operator < (Rational other) const {
            return ( (numerator * other.denomenator) < (other.numerator * denomenator) );
        }

		//checks if first rational is less than or equal to other rational
        bool operator <= (Rational other) const {
            return ( (numerator * other.denomenator) <= (other.numerator * denomenator) );
        }

		//checks if first rational is greater than other rational
        bool operator > (Rational other) const {
            return ( (numerator * other.denomenator) > (other.numerator * denomenator) );
        }

		//checks if first rational is greater than or equal to other rational
        bool operator >= (Rational other) const {
            return ( (numerator * other.denomenator) >= (other.numerator * denomenator) );
        }

		//ARITHMATIC OVERLOADING
		//adds first rational to other rational
        Rational operator + (Rational other) const {
            int newNumerator = (numerator * other.denomenator) + (other.numerator * denomenator);
            int newDenomenator = (denomenator * other.denomenator);
            Rational newRational(newNumerator, newDenomenator);
            return newRational;
        }

		//subtracts first rational from other rational
        Rational operator - (Rational other) const {
            int newNumerator = (numerator *  other.denomenator) - (other.numerator * denomenator);
            int newDenomenator = (denomenator * other.denomenator);
            Rational newRational(newNumerator, newDenomenator);
            return newRational;
        }
        
        //multiplies first rational by other rational
        Rational operator * (Rational other) const {
            int newNumerator = (numerator * other.numerator);
            int newDenomenator = (denomenator * other.denomenator);
            Rational newRational(newNumerator, newDenomenator);
            return newRational;

        }
        
        //divides first rational by other rational
        Rational operator / (Rational other) const {
            int newNumerator = (numerator * other.denomenator);
            int newDenomenator = (denomenator * other.numerator);
            Rational newRational(newNumerator, newDenomenator);
            return newRational;
        }
};


//outputs the Rational
ostream& operator << (ostream& output, const Rational &other){
	//strin
    output << other.numerator << "/" << other.denomenator;
    return output;
}

//Input to the rational
istream& operator >> (istream& input, Rational &other){
	//strings to stores input
   	string numeratorStr, denomenatorStr;
   	//ints to stores input
   	int numerator, denomenator;
   	//gets the information from cin
    getline(cin, numeratorStr, '/');
    getline(cin, denomenatorStr);
    //converts from str to stream
	stringstream numeratorStream(numeratorStr);
	stringstream denomenatorStream(denomenatorStr);
	//coverts stream to int
	numeratorStream >> numerator;
	denomenatorStream >> denomenator;
	//sets new numerator and denomenator
	other.setRational(numerator, denomenator);
    return input;
}


int main(){
	//creates test rationals
	Rational ration1(7,14), ration2(6,23), ration3(23,445), add, subtract, multiply, divide, input;
	bool equal, less, lessEqual, greater, greaterEqual;

	//boolean demonstrations
	//equality
	equal = (ration1==ration1);
	cout << ration1 << " == " << ration1 << " is " << equal << endl;
	//less than
	less = (ration1 <  ration2);
	cout << ration1 << " < " << ration2 << " is " << less << endl;
	//less than or equal
	lessEqual = (ration1 <=  ration2);
	cout << ration1 << " <= " << ration3 << " is " << lessEqual << endl;
	//greater than
	greater = (ration2 >  ration1);
	cout << ration2 << " > " << ration1 << " is " << greater << endl;
	//greater than or equal
	greaterEqual = (ration2 >=  ration3);
	cout << ration2 << " >= " << ration3 << " is " << greaterEqual << endl;

	//arithmatic demonstrations
	//adds
	add = (ration1 + ration2);
	cout << ration1 << " + " << ration2 << " = " << add << endl;
	//subtracts
	subtract = (ration2 - ration1);
	cout << ration2 << " - " << ration1 << " = " << subtract << endl;
	//multiplies
	multiply = (ration2 * ration2);
	cout << ration2 << " * " << ration1 << " = " << multiply << endl;
	//divide
	divide = (ration1 * ration2);
	cout << ration1 << " / " << ration2 << " = " << divide << endl;

	//IO demonstration
	//prompts user
	cout << "input a rational number in by entering two numbers seperated by a / :";
	//takes user input
	cin >> input;
	//outputs result
	cout << "the reduced rational number is: " << input << endl;
	return 0;
}
