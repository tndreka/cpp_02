/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:21:56 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/04 17:15:24 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}

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

Fixed & Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixed_point;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member function called\n";
	fixed_point = raw;
}