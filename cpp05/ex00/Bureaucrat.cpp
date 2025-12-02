/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:58:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/02 17:03:59 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	std::cout << "Parameterized constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){
	std::cout << "Copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	if(this != &obj)
		_grade = obj._grade;	
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out << obj.getName() << ", burocrata com classificação " << obj.getGrade() << "\n";
	return out;
}

//throw() specifies which exceptions it can throw. if its empty like in this case,
//it shows the method/function does not throws execeptions.
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too High! Grade should be between 1 and 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low! Grade should be between 1 and 150");
}