/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:05:01 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 11:35:23 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << _name << " constructor called" << std::endl; 
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
    std::cout << "FragTrap "<< _name << " copy constructor called" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->_name= obj._name;
        this->_hitPoints= obj._hitPoints;
        this->_energyPoints= obj._energyPoints;
        this->_attackDamage= obj._attackDamage;
    }
	return *this;
}

FragTrap::~FragTrap(){
     std::cout << "FragTrap " << _name << " destructor called" << std::endl;
};


void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _name << " asks for a positive high five." << std::endl;
}
