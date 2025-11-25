/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:15:05 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 10:25:31 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << "ClapTrap default constructor called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name),
_hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage) {
    std::cout << "ClapTrack copy constructor called" << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << "ClapTrack copy assignment operator called" << std::endl;
    if (this != &obj)
		this->_name= obj._name;
        this->_hitPoints= obj._hitPoints;
        this->_energyPoints= obj._energyPoints;
        this->_attackDamage= obj._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
     std::cout << "ClapTrack " << _name << " destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target){
    if(_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " is dead" << std::endl; 
        return ;
    }
    if(_energyPoints == 0){
        std::cout << "ClapTrap " << _name << " has no energy left" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " has died" << std::endl; 
        return ;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " of damage." << std::endl;
    _hitPoints = _hitPoints - amount;
    if (_hitPoints < 1)
        std::cout << "ClapTrap " << _name << " has died." << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount){
    if(_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " has died" << std::endl; 
        return ;
    }
    if(_energyPoints == 0){
        std::cout << "ClapTrap " << _name << " has no energy left" << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " recovered " << amount << " hit points" << std::endl;
}

void ClapTrap::getStatus(){
    std::cout << "ClapTrap " << _name << " status:" << std::endl;
    std::cout << "Hit Points: " << _hitPoints << std::endl;
    std::cout << "Energy Points: " << _energyPoints << std::endl;
    std::cout << "Attack Damage: " << _attackDamage << std::endl;
    std::cout << std::endl;
}