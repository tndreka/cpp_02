/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:21:56 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/08 17:49:11 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Default constructor
	-Initializes the fixed_point to 0;
*/
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}


/*
	Copy constructor
	-Copy new object as copy of one existing one
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	fixed_point = other.fixed_point;
}

/*
	Constructor(const int parameter)
	{
		In the constructor we will take a parameter an int.
		This int we need to store it as a fixed-point number.
		[Int_Part][8_fractional_bits]
		if we have the int = 5;
		to convert 5 in to fixed-point num we need to shift it by left 8 bits(the number of the fractional bits).
		You need to multiply by 2^8 = 256
		[101][here shift left by 8 bits 00000000] = 101 00000000
		or in numbers we get 5.0 in fixed-point format 
		5 * 256 = 1280
	} 
*/
Fixed::Fixed(const int dec)
{
	std::cout << "Int constructor called\n";
	fixed_point = dec << fractional_bits;
}

/*
	Constructor(const float param)
	{
	********
	Using the same logic as we did at the previous constructor.
	we will recive a float valueand need to store it as a fixed-point number.
	with 8 fractional bits will convert the float to an int that will be the same value in fixed-point number.
	we multiply the float with 2^8 and then conver it to int in which this part we this will handle also the fractional part
	float = 5.25
	fixed_point = (int)(dec * 256)
	-> 5.25 * 256 (2^8 = 256) = 1344.0
	as an int value it will be  1344 and this will be the represantor of the 5.25 in fixed-point num.
	}
*/
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	fixed_point = (int)(num * (1 << fractional_bits));
}

/*
	Copy Assignment Operator
	-Does self-assignment check
	-copies from source object
	-returns a reference
*/	
Fixed & Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

/*
	Destructor
	-Clean up
	-Prints destruction message
*/
Fixed:: ~Fixed()
{
	std::cout << "Destructor called\n";
}

/*
	getRawBits()
		-access raw fixed point value
		-print msg
		-returns stored int value
*/
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixed_point;
}

/*
	setRawBits()
		-seter for raw fixed point value
		-print msg
		- sets the int
*/
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fixed_point = raw;
}

/*
	toInt();
		-Converts bacck to float by right shifting 8bits
		-the same as devifing it by 2^8 or 256
		-loses fractional part	
*/
int		Fixed::toInt(void) const
{
	return fixed_point >> fractional_bits;
}

/*
	toFloat();
		-Converts back to float by deviding by 256
		-saves fractional part	
*/
float Fixed::toFloat(void)const
{
	float to_f;

	to_f = (float)fixed_point / 256;
	return to_f;
}

/*
		STREAM OPERATOR
	- Outputs the floating-point representation
	- Uses toFloat() for conversion
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}