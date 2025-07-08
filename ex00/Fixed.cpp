/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:43:40 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/08 17:43:38 by tndreka          ###   ########.fr       */
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
    *this = other;
}

/*
	Copy Assignment Operator
	-Does self-assignment check
	-copies from source object
	-returns a reference
*/
Fixed& Fixed::operator=(const Fixed& other)
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
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

/*
	getRawBits()
		-access raw fixed point value
		-print msg
		-returns stored int value
*/
int Fixed::getRawBits(void) const
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
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    fixed_point = raw;
}