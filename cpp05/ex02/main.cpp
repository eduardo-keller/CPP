/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/08 17:39:08 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void printTest(std::string str){
	std::cout << "=============================" << std::endl;
	std::cout << str << std::endl;
	std::cout << "=============================" << std::endl;
}


void testExecuteUnsignedForm(){
	printTest("TEST 0: EXECUTE UNSIGNED FORM");
	std::cout << std::endl << "Test Presidential Pardon: " << std::endl;
	try{
		Bureaucrat p("President", 1);
		PresidentialPardonForm pp("Edward Snowden");
		std::cout << p;
		std::cout << pp;
		p.executeForm(pp);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "Test Shrubbery Creation: " << std::endl;
	try{
		Bureaucrat p("Gardener", 1);
		ShrubberyCreationForm sc("House");
		std::cout << p;
		std::cout << sc;
		p.executeForm(sc);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void testExecuteValidSignedForm(){
	printTest("TEST 1: VALID EXECUTION OF FORM ");
	std::cout << std::endl << "Test Presidential Pardon: " << std::endl;
	try{
		Bureaucrat p("President", 1);
		PresidentialPardonForm pp("Edward Snowden");
		ShrubberyCreationForm sc;
		std::cout << p;
		std::cout << pp;
		p.signForm(pp);
		p.executeForm(pp);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Test Shrubbery Creation: " << std::endl;
	try{
		Bureaucrat p("Gardener", 1);
		ShrubberyCreationForm sc("House");
		std::cout << p;
		std::cout << sc;
		p.signForm(sc);
		p.executeForm(sc);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Test Robotomization: " << std::endl;
	try{
		Bureaucrat p("Robot King", 1);
		RobotomyRequestForm rr("Dog");
		std::cout << p;
		std::cout << rr;
		p.signForm(rr);
		p.executeForm(rr);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void testExecuteSignedFormInvalidGrade(){
	printTest("TEST 2: INVALID EXECUTION OF FORM BECAUSE OF LOW GRADE");
	std::cout << std::endl << "Test Presidential Pardon: " << std::endl;
	try{
		Bureaucrat p("President", 6);
		PresidentialPardonForm test("Edward Snowden");
		std::cout << p;
		std::cout << test;
		p.signForm(test);
		p.executeForm(test);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "Test Shrubbery Creation: " << std::endl;
	try{
		Bureaucrat p("Gardener", 138);
		ShrubberyCreationForm sc("House");
		std::cout << p;
		std::cout << sc;
		p.signForm(sc);
		p.executeForm(sc);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

int main(void) {
	testExecuteUnsignedForm();
	testExecuteValidSignedForm();
	testExecuteSignedFormInvalidGrade();

    return 0;
}