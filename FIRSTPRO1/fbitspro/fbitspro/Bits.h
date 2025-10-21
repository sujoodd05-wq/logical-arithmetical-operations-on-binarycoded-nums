#pragma once
#include "BitNode.h"
#include<iostream>
using namespace std;
class Bits
{
private:
	BitNode* head;
	// Don't add new variable members.
	// it is allowed to add any suitable private functions, but you can’t in public.
public:
	// Constructor(s).
	Bits(int num);
	Bits();
	//Copy constructor.
	Bits(const Bits&);
	//Destructor.
	~Bits();
	//Overload the following operators as required in the description:
	   // 1. =
	Bits operator =(const Bits &);
	Bits operator =(int num);
		//2. - , +
	Bits operator+(const Bits&);
	int operator-(const Bits&);

		//3. <<
	Bits operator<<(int shift);
	Bits operator<<(Bits&);
	friend ostream& operator<<(ostream&, const Bits&);
		//4. >>
	Bits operator>>(int shift);
	Bits operator>>(Bits&);
	friend istream& operator>>(istream& is, Bits& );
		//5. &
	Bits operator&(const Bits&);
		//6. |
	Bits operator|(const Bits&);
		//7. ^
	Bits operator^(const Bits&);
		//8. !
	Bits operator!();
		// implement the following friend functions:
		//1. toBitString(Bits&)
	friend char* toString(Bits&);
		//2. toDecimal(Bits&)
	friend int toDecimal(Bits&);
		// Don't add new public functions.

};

