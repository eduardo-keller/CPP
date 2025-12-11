/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:26:01 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/08 14:54:13 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
AForm("Presidential Pardon", 25, 5), _target(target){}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy), _target(copy._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	if(this != &obj) {
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

const std::string& PresidentialPardonForm::getTarget(void) const{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	checkExecution(executor);
	std::cout << _target << " was pardoned by Zaphod Beeblebrox" << std::endl;
}