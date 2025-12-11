/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:23:03 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/11 16:39:36 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
    std::cout << "Intern default constructor called" << std::endl;
}

//cast to void to silence flags. there is nothign to do
//since there are no attributes
Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(void) { std::cout << "Intern destructor called" << std::endl; }

AForm* Intern::createPardon(std::string const &target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(std::string const &target){
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const &target){
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makeForm(std::string const &formName, std::string const &target){
    const std::string forms[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

    AForm* (Intern::*formCreator[3])(const std::string& target) = {
        &Intern::createPardon,
        &Intern::createShrubbery,
        &Intern::createRobotomy};
    for(int i = 0; i < 3; i++)
    {
        if(forms[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreator[i])(target);
        }  
    }
    std::cout << "Error: Form name \"" << formName << "\" does not exist" << std::endl;
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what(void) const throw() {
    return "Form not found";
}