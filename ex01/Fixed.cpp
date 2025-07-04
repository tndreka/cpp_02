/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:21:56 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/04 16:00:14 by tndreka          ###   ########.fr       */
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
	}
*/
Fixed::Fixed(const float dec)
{
	std::cout << "Float constructor called\n";
}	
