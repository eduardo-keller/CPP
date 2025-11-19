/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:00 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/19 15:52:54 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>


class Fixed {
	private:
	int _intFixedPoint;
	//the last bite of the int (left bite or the 8 LSBs) is the fractional part.
	static int const _fractional = 8;

	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator=(const Fixed& obj);
	~Fixed();
	
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits() const;
	void setRawBits(int const raw);
	
	//new from ex02
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;	
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;	
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);	
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
	
	
};


std::ostream& operator<<(std::ostream& out, const Fixed& obj);


#endif