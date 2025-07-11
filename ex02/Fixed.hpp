/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:23:46 by tndreka           #+#    #+#             */
/*   Updated: 2025/07/07 19:37:02 by tndreka          ###   ########.fr       */
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
	static	Fixed& min(Fixed& a, Fixed& b);
	static	const Fixed& min(const Fixed& a, const Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);
	static	const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator <<(std::ostream& out, const Fixed& fixed);

#endif