/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:20:54 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/08 17:38:55 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
	Should output something similar to:
	$> ./a.out
	Default constructor called
	Copy constructor called
	Copy assignment operator called // <-- This line may be missing depending on your implementation
	getRawBits member function called
	Default constructor called
	Copy assignment operator called
	getRawBits member function called
	getRawBits member function called
	0
	getRawBits member function called
	0
	getRawBits member function called
	0
	Destructor called
	Destructor called
	Destructor called
*/