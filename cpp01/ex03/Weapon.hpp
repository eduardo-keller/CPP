/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:41:32 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 12:50:51 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{
	private:
	std::string _type;

	public:
	Weapon(std::string type);
	~Weapon();
	//CONST
	//first const indicates that  getType returns a read-only reference
	//to type, preventing things like weapon.getType() = "hack".
	//second const marks getType as a const member function, indicating 
	//that it doesnt modify the object and allows you to call const weapon objects.
	//REFERENCE
	//it is not strictly necessary to return a reference to type.
	//I could return by value, which means a copy of type would be made.
	//using a reference makes the the code more efficient.
	// OPTIONS and DISCUSSION
	// - if there is const at the end the return must be const if its a reference. if the it returns by
	// value the const is not necessary
	// 1)Read‑only reference (no copy):
	// const std::string& getType() const;
	// 2)Return by value (makes a copy, modifiable by caller, object stays const):
	// std::string getType() const;
	// 3)Provide a modifiable reference (no copy), but then the function itself cannot be const:
	// std::string& getType();
	const std::string& getType() const;
	void setType(std::string newType);
    
};

#endif