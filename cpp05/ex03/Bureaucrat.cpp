/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:58:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/08 15:21:35 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade){
	if (_grade < _highestGrade)
		throw GradeTooHighException();
	if (_grade > _lowestGrade)
		throw GradeTooLowException();
	//std::cout << "Parameterized constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){
	//std::cout << "Copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	if(this != &obj)
		_grade = obj._grade;	
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	//std::cout << "Destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < _highestGrade)
		throw GradeTooHighException();
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade(){
	if (_grade - 1 < _highestGrade)
		throw GradeTooHighException();
	_grade -= 1;
}
void	Bureaucrat::decrementGrade(){
	if(_grade + 1 > _lowestGrade)
		throw GradeTooLowException();
	_grade += 1;
}

void	Bureaucrat::signForm(AForm& form){
	try{
		if (form.isSigned() == 1)
		{
			std::cout << form.getName() << " is already signed" <<std::endl;
			return ;
		}
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() <<std::endl;
	}
	catch(std::exception &e){
		std::cout << _name << " couldn't sign " << form.getName() << " because "
		  << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out << obj.getName() << ", burocrat with classification " << obj.getGrade() << "\n";
	return out;
}

//throw() specifies which exceptions it can throw. if its empty like in this case,
//it shows the method/function does not throws execeptions.
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

void			 Bureaucrat::executeForm(AForm const & form) const{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << " succesfully" << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}