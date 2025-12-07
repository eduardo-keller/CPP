/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:26:01 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/06 13:53:24 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < _highestGrade || _gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (_gradeToSign > _lowestGrade || _gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
	//std::cout << "Parameterized constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
	//std::cout << "Copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	if(this != &obj)
		_signed = obj._signed;	
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	//std::cout << "Destructor called" << std::endl;
}