/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:23:46 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/07 19:10:22 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixed_point;
	static const int fractional_bits =  8;
public:
	Fixed();//Default C
	Fixed(const Fixed& other); //Copy C
	Fixed(const int dec);//Int C
	Fixed(const float num);//Floar C
	Fixed& operator=(const Fixed& other);// Copy assignment operator
	~Fixed();//Destrucor
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other)const;
	Fixed	operator/(const Fixed& other)const;
	Fixed&	operator++(void);//pre increment;
	Fixed	operator++(int);//post increment
	Fixed&	operator--(void);//pre increment;
	Fixed	operator--(int);//post increment
};


#endif