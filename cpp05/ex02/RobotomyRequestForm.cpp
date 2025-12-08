/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:13:11 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/08 19:47:25 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
AForm("Robotomy Request", 72, 45), _target(target){}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy), _target(copy._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	if(this != &obj) {
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

const std::string& RobotomyRequestForm::getTarget(void) const{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkExecution(executor);
	std::cout << "* DRILLING NOISES *" << std::endl;  

	//static so that the seed is initialized only
	//once and srand() is called only once.
	static bool seeded = false;
    if (!seeded) {
		//returns the elapsed since unix epoch
		//which keeps changing after every program call
	std::srand(std::time(NULL));
	seeded = true;
    }
	
	if (std::rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
	}
}