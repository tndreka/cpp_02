/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:23:44 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/07 19:08:55 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";	
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	fixed_point = other.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->fixed_point = other.fixed_point;
	return *this;
}

Fixed::Fixed(const int dec)
{
	std::cout << "Int constructor called\n";
	fixed_point = dec << fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	fixed_point = roundf(num *(1 << fractional_bits));
	// fixed_point = (int)(num *(1 << fractional_bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member functiom called\n";
	return fixed_point;
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member functiom called\n";
	fixed_point = raw;
}

int Fixed::toInt(void) const
{
	return fixed_point >> fractional_bits;
}
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
	res.fixed_point = this->fixed_point * other.fixed_point;
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
