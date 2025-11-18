/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:00 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/18 14:33:12 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>


class Fixed {
	private:
	int _intFixedPoint;
	static int const _intFractional = 8;

	public:
	Fixed();
	//initialize a new obj from an existing one 
	Fixed(const Fixed& copy);
	//replace the state of an existing object with another existing obj.
	Fixed& operator=(const Fixed& obj);
	~Fixed();
	
	int getRawBits() const;
	void setRawBits(int const raw);
	
};


#endif