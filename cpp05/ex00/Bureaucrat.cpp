/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:58:33 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/28 18:03:31 by ekeller-@st      ###   ########.fr       */
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


void	Bureaucrat::setGrade(int grade) {
	if (grade < _highestGrade)
		throw GradeTooHighException();
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade should be between 1 and 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade should be between 1 and 150");
}

const std::string& Bureaucrat::getName() const{
	return _name;
}

const int Bureaucrat::getGrade() const{
	return _grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out << obj.getName() << ", burocrata com classificação " << obj.getGrade() << "\n";
	return out;
}