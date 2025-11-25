/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:05:01 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 11:08:45 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl; 
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
    std::cout << "ScavTrap "<< _name << " copy constructor called" << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->_name= obj._name;
        this->_hitPoints= obj._hitPoints;
        this->_energyPoints= obj._energyPoints;
        this->_attackDamage= obj._attackDamage;
    }
	return *this;
}

ScavTrap::~ScavTrap(){
     std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
};


void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if(_hitPoints == 0){
        std::cout << "ScavTrap " << _name << " is dead" << std::endl; 
        return ;
    }
    if(_energyPoints == 0){
        std::cout << "ScavTrap " << _name << " has no energy left" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << ", the beast, attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
