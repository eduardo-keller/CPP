/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:00 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/18 17:03:38 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>


class Fixed {
	private:
	int _intFixedPoint;
	//the last bite of the int (left bite or the 8 LSBs) is the fractional part.
	static int const _intFractional = 8;

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
	
};


#endif