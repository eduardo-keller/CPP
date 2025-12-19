/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/17 12:12:30 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

//this exercise shows the factory pattern in OOP. If a new form is
//introduced, I only need to modify the creation logic in one place. 

void printHeader(const std::string &title) {
    std::cout << "========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

void testInternAllForms(void) {
    printHeader("TEST 0: Intern - All Form Types");

    Intern intern;
    AForm *forms[3];
    int i;

    try {
	forms[0] = intern.makeForm("shrubbery creation", "garden");

	forms[1] = intern.makeForm("robotomy request", "Marvin");

	forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << "\n--- Forms Created ---\n";
	for (i = 0; i < 3; i++) {
	    if (forms[i]) {
		std::cout << *forms[i] << std::endl;
	    }
	}

	std::cout << "\n--- Cleaning up ---\n";
	for (i = 0; i < 3; i++) {
	    delete forms[i];
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternInvalidForm(void) {
    printHeader("TEST 1: Intern - Invalid Form Name");

    
	Intern intern;
	AForm *form;

	std::cout << "\nAttempting to create non-existent form...\n";
	form = intern.makeForm("coffee making", "Kitchen");

	if (form) {
	    std::cout << *form << std::endl;
	    delete form;
	}
}

void testInternWithBureaucrat(void) {
    printHeader("TEST 2: Intern - Forms with Bureaucrat");

    try {
	Intern intern;
	Bureaucrat boss("Boss", 1);
	AForm *form;

	form = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");

	if (form) {
	    std::cout << "\n" << boss << std::endl;
	    std::cout << *form;

	    boss.signForm(*form);
		std::cout << *form << std::endl;
		
	    boss.executeForm(*form);

	    delete form;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(void) {
    testInternAllForms();
    testInternInvalidForm();
    testInternWithBureaucrat();

    return 0;
}
