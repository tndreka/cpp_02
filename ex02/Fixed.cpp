/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:23:44 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/08 17:55:06 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Default constructor
	-Initializes the fixed_point to 0;
*/
Fixed::Fixed()
{
	// std::cout << "Default constructor called\n";
	fixed_point = 0;
}

/*
	Destructor
	-Clean up
	-Prints destruction message
*/
Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";	
}

/*
	Copy constructor
	-Copy new object as copy of one existing one
*/
Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called\n";
	fixed_point = other.fixed_point;
}

/*
	Copy Assignment Operator
	-Does self-assignment check
	-copies from source object
	-returns a reference
*/	
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->fixed_point = other.fixed_point;
	return *this;
}

/*
	INT CONSTRUCTOR:
		-conversts int to fixed point by left shifting 8bits
		-or by multiplication of num *256 (2^8)
*/
Fixed::Fixed(const int dec)
{
	// std::cout << "Int constructor called\n";
	fixed_point = dec << fractional_bits;
}

/*
	FLOAT CONSTRUCTOR:
		-converts float to fixed-points with proper rounding
		-uses roundf() to round the num for more accuracy
*/
Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called\n";
	fixed_point = roundf(num *(1 << fractional_bits));
	// fixed_point = (int)(num *(1 << fractional_bits));
}

/*
	getRawBits()
		-access raw fixed point value
		-print msg
		-returns stored int value
*/
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member functiom called\n";
	return fixed_point;
}

/*
	setRawBits()
		-seter for raw fixed point value
		-print msg
		- sets the int
*/
void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member functiom called\n";
	fixed_point = raw;
}

/*
	toInt();
		-Converts bacck to float by right shifting 8bits
		-the same as devifing it by 2^8 or 256
		-loses fractional part	
*/
int Fixed::toInt(void) const
{
	return fixed_point >> fractional_bits;
}

/*
	toFloat();
		-Converts back to float by deviding by 256
		-saves fractional part	
*/
float Fixed::toFloat(void) const
{
	float to_f;
	to_f = (float)fixed_point / 256;
	return to_f;
}

bool Fixed:: operator>(const Fixed& other)const
{
	return this->fixed_point > other.fixed_point;
}

bool Fixed:: operator<(const Fixed& other)const
{
	return this->fixed_point < other.fixed_point;
}

bool Fixed:: operator>=(const Fixed& other)const
{
	return this->fixed_point >= other.fixed_point;
}

bool Fixed:: operator<=(const Fixed& other)const
{
	return this->fixed_point <= other.fixed_point;
}

bool Fixed:: operator==(const Fixed& other)const
{
	return this->fixed_point == other.fixed_point;
}

bool Fixed:: operator!=(const Fixed& other)const
{
	return this->fixed_point != other.fixed_point;
}

Fixed Fixed:: operator+(const Fixed& other)const
{
	Fixed res;
	res.fixed_point = this->fixed_point + other.fixed_point;
	return res;
}

Fixed Fixed:: operator-(const Fixed& other)const
{
	Fixed res;
	res.fixed_point = this->fixed_point - other.fixed_point;
	return res;
}

Fixed Fixed:: operator*(const Fixed& other)const
{
	Fixed res;
	res.fixed_point = (this->fixed_point * other.fixed_point) >> fractional_bits;
	return res;
}

Fixed Fixed:: operator/(const Fixed& other) const
{
	Fixed res;
	res.fixed_point = this->fixed_point / other.fixed_point;
	return res;
}

/*
	PRE INCREMENT ++Fixed
	Fixed& operator++(void)
	{
		this function modifies Fixed value and adds 1 ro it,
		and then it returns the same object after modification.
	}
*/

Fixed& Fixed::operator++(void)
{
	fixed_point++;
	return *this;
}

/*
	POST DECREMENT Fixed++
	Fixed Fixed::operator++(int)
	{
		This function first saves the old value and the increments and returns the old obj.
		-> the int parameter is for the the compilet to know that this is the post increment not
		the pre increment
		
	}

*/
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	fixed_point++;
	return tmp;
}


Fixed& Fixed::operator--(void)
{
	fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	fixed_point--;
	return tmp;
}

Fixed& Fixed:: min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	else
		return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed& Fixed:: max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}