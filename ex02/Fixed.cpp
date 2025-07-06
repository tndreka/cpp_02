/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:23:44 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/06 03:43:44 by tndreka          ###   ########.fr       */
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
	fixed_point = (int)(num *(1 << fractional_bits));
}