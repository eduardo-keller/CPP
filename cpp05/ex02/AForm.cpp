/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:41:53 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/06 13:23:30 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	//std::cout << "Default constructor called\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < _highestGrade || _gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (_gradeToSign > _lowestGrade || _gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
	//std::cout << "Parameterized constructor called\n";
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
	//std::cout << "Copy constructor called\n";
}

AForm& AForm::operator=(const AForm& obj){
	if(this != &obj)
		_signed = obj._signed;	
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm(){
	//std::cout << "Destructor called" << std::endl;
}

const std::string&	AForm::getName() const{
	return _name;
}

bool AForm::isSigned() const {return _signed;}

int AForm::getGradetoSign() const {return _gradeToSign;}

int AForm::getGradetoExecute() const {return _gradeToExecute;}

void	AForm::beSigned(Bureaucrat& obj){
	if (obj.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::checkExecution(Bureaucrat const & executor) const{
	if(isSigned() == false)
		throw FormNotSignedException();
	if(executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj){
	out << "AForm: " << obj.getName() << "; Signed: " << obj.isSigned() << "; Grade to Sign: " //
	<< obj.getGradetoSign() << "; Grade to Execute: " << obj.getGradetoExecute() << "\n";
	return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("The form is not signed! Cannot execute the order!");
}