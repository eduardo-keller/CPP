/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:25 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/08 16:52:28 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
AForm("Shrubbery Creation", 145, 137), _target(target){}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy), _target(copy._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	if(this != &obj) {
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const std::string& ShrubberyCreationForm::getTarget(void) const{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	checkExecution(executor);
	
    std::ofstream outfile((_target + "_shrubbery").c_str());

    outfile << "        _-_" << std::endl;
    outfile << "     /~~   ~~\\" << std::endl;
    outfile << "  /~~         ~~\\" << std::endl;
    outfile << " {               }" << std::endl;
    outfile << "  \\  _-     -_  /" << std::endl;
    outfile << "    ~  \\\\ //  ~" << std::endl;
    outfile << " _- -   | | _- _" << std::endl;
    outfile << "   _ -  | |   -_" << std::endl;
    outfile << "       // \\\\" << std::endl;

    outfile.close();
}
