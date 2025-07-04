/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:20:29 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/04 17:18:30 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed_point;
		static const int fractional_bits = 8;
	public:
		Fixed();//Default constructor
		Fixed(const Fixed& other);//COPY Constructor
		Fixed(const int dec);//A constructor that takes a const INT as a parameter
		Fixed(const float num);//A constructor that takes a const FLOAT as a parameter
		Fixed& operator=(const Fixed& other);//Copy assign operator
		~Fixed();//Destructor
		int     getRawBits(void)const;
        void    setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif