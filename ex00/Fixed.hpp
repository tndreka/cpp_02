/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:43:53 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/08 17:37:35 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Orthodox Canonical Form involves defining these 4 member functions
		for a class:
			-1. Default Constructor
			-2. Copy 	Constructor
			-3. Copy	Assignment Operator
			-4. Destructor

			1) Default Constructor :
				is a member function in a class that initializes an object with
				default values.
			2) Copy Constructor:
				is a member function that initializes a new object as  a copy
				of an existing object. 
			3) Copy assignment operator:
				is a member function that assigns the value of one object to 
				another already existing object.
			4) Destructor:
				Used to clean up resources
*/
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int     getRawBits(void)const;
        void    setRawBits(int const raw);

};

#endif