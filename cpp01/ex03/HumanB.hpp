/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:54:36 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 15:08:01 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB{
    private:
    std::string _name;
    Weapon *_weapon;

    public:
    HumanB(std::string setName);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon &weapon);
};

#endif