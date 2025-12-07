/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/04 12:04:58 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void printTest(std::string str){
	std::cout << "=============================" << std::endl;
	std::cout << str << std::endl;
	std::cout << "=============================" << std::endl;
}


void testInvalidForm(){
	printTest("0: TEST INVALID FORM");
	try{
		Form nuclear("Launch Bomb", 0, 10);
		std::cout << std::endl;
		std::cout << nuclear;
	}
	catch(std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try{
		Form nuclear("Launch Bomb", 150, 151);
		std::cout << std::endl;
		std::cout << nuclear;
	}
	catch(std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testValidSigning(){
	printTest("1: TEST VALID SIGNING");
	try{
		Bureaucrat president("president", 1);
		Bureaucrat intern("intern", 140);
		Form nuclear("Launch Bomb", 1, 10);
		Form internForm("Intern Form", 140, 140);
		std::cout << president;
		std::cout << intern;
		std::cout << nuclear;
		std::cout << internForm;
		std::cout << "\nTry to sign forms: \n";
		president.signForm(nuclear);
		intern.signForm(internForm);
		std::cout << nuclear;
		std::cout << internForm;
	}
	catch(std::exception &e){
		std::cout << "exception caught " << e.what() << std::endl;
	}
}

void testInvalidSigning(){
	printTest("2: TEST INVALID SIGNING");
	try{
		Bureaucrat intern("intern", 140);
		Form nuclear("Launch Bomb", 1, 10);

		std::cout << intern;
		std::cout << nuclear;
		std::cout << "\nTry to sign forms: \n";
		intern.signForm(nuclear);
		std::cout << nuclear;
	}
	catch(std::exception &e){
		std::cout << "exception caught " << e.what() << std::endl;
	}
}

void testCopyandAssignment(){
	printTest("3: TEST COPY AND ASSIGNMENT");
	try{
		Bureaucrat originalBureaucrat("Original Bureaucrat", 1);
		Form originalForm("Launch Bomb", 1, 10);

		std::cout << originalBureaucrat;
		std::cout << originalForm;
		
		Form copiedForm(originalForm);
		std::cout << "Display state of copied form: \n";
		std::cout << copiedForm;
		std::cout << "\nSign copied form: \n";
		originalBureaucrat.signForm(copiedForm);
		
		std::cout << "\nDisplay copied form, original form and assigned form respectively: \n";
		std::cout << copiedForm;
		std::cout << originalForm;
		Form assignedForm;
		assignedForm = copiedForm;
		std::cout << assignedForm;
	}
	catch(std::exception &e){
		std::cout << "exception caught " << e.what() << std::endl;
	}
}

int main(void) {
	testInvalidForm();
	testValidSigning();
	testInvalidSigning();
	testCopyandAssignment();
    return 0;
}