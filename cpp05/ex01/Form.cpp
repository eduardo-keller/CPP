/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:41:53 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/02 17:14:17 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Default constructor called\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < _highestGrade || _gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (_gradeToSign > _lowestGrade || _gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
	std::cout << "Parameterized constructor called\n";
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
	std::cout << "Copy constructor called\n";
}

Form& Form::operator=(const Form& obj){
	if(this != &obj)
		_signed = obj._signed;	
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "Destructor called" << std::endl;
}

const std::string&	Form::getName() const{
	return _name;
}

bool Form::isSigned() const {return _signed;}

int Form::getGradetoSign() const {return _gradeToSign;}

int Form::getGradetoExecute() const {return _gradeToExecute;}

void	Form::beSigned(Bureaucrat& obj){
	if (obj.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj){
	out << "Name: " << obj.getName() << "; Signed: " << obj.isSigned() << "; Grade to Sign: " //
	<< obj.getGradetoSign() << "; Grade to Execute: " << obj.getGradetoExecute() << "\n";
	return out;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}