/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/11 16:42:08 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void printHeader(const std::string &title) {
    std::cout << "========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

void testInternBasic(void) {
    printHeader("TEST 10: Intern - Basic Form Creation");

    try {
	Intern someRandomIntern;
	AForm *rrf;

	std::cout << "\nCreating robotomy request form...\n";
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf) {
	    std::cout << *rrf << std::endl;
	    delete rrf;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternAllForms(void) {
    printHeader("TEST 11: Intern - All Form Types");

    Intern intern;
    AForm *forms[3];
    int i;

    try {
	std::cout << "\nCreating shrubbery creation form...\n";
	forms[0] = intern.makeForm("shrubbery creation", "garden");

	std::cout << "\nCreating robotomy request form...\n";
	forms[1] = intern.makeForm("robotomy request", "Marvin");

	std::cout << "\nCreating presidential pardon form...\n";
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
    printHeader("TEST 12: Intern - Invalid Form Name");

    try {
	Intern intern;
	AForm *form;

	std::cout << "\nAttempting to create non-existent form...\n";
	form = intern.makeForm("coffee making", "Kitchen");

	if (form) {
	    std::cout << *form << std::endl;
	    delete form;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternWithBureaucrat(void) {
    printHeader("TEST 13: Intern - Forms with Bureaucrat");

    try {
	Intern intern;
	Bureaucrat boss("Boss", 1);
	AForm *form;

	std::cout << "\nIntern creates form...\n";
	form = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");

	if (form) {
	    std::cout << "\n" << boss << std::endl;
	    std::cout << *form << std::endl;

	    std::cout << "\nBoss signs the form...\n";
	    boss.signForm(*form);

	    std::cout << "\nBoss executes the form...\n";
	    boss.executeForm(*form);

	    delete form;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternMultipleCreations(void) {
    printHeader("TEST 14: Intern - Multiple Form Creations");

    try {
	Intern intern;
	AForm *form1;
	AForm *form2;
	AForm *form3;

	std::cout << "\nCreating first robotomy request...\n";
	form1 = intern.makeForm("robotomy request", "Target1");

	std::cout << "\nCreating second robotomy request...\n";
	form2 = intern.makeForm("robotomy request", "Target2");

	std::cout << "\nCreating third robotomy request...\n";
	form3 = intern.makeForm("robotomy request", "Target3");

	std::cout << "\n--- All forms created ---\n";
	if (form1)
	    std::cout << *form1 << std::endl;
	if (form2)
	    std::cout << *form2 << std::endl;
	if (form3)
	    std::cout << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(void) {
    std::cout << "\n\n";
    printHeader("=== INTERN TESTS ===");
    std::cout << "\n";

    testInternBasic();
    testInternAllForms();
    testInternInvalidForm();
    testInternWithBureaucrat();
    testInternMultipleCreations();

    printHeader("All tests completed!");

    return 0;
}
