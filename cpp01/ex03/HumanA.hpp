/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:13:52 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 12:52:11 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA{
	private:
	std::string _name;
	Weapon& _weapon;
	
	public:
	HumanA(std::string setname, Weapon& weapon);
	~HumanA();
	//const not necessary but best practice. 
	void attack() const;
};

#endif