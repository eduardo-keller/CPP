/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/01 18:02:11 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void testValidConstruction() {
	std::cout << "\nTEST VALID CONSTRUCTION\n";
	try{
		Bureaucrat valid1("valid1", 1);
		Bureaucrat valid150("valid150", 150);
		std::cout << valid1;
		std::cout << valid150;
	}
	catch(std::exception& e){
		std::cerr << "exception caught: " << e.what() << '\n';
	}
}

void testInvalidConstruction() {
	std::cout << "\nTEST INVALID CONSTRUCTION:\n";
	try{
		Bureaucrat valid0("valid0", 0);
		Bureaucrat valid151("valid150", 151);
		std::cout << valid0;
		std::cout << valid151;
	}
	catch(std::exception& e){
		std::cerr << "exception caught: " << e.what() << '\n';
	}
}

void testValidIncrementandDecrement() {
	std::cout << "\nTEST VALID INCREMENT AND DECREMENT:\n";
	try{
		Bureaucrat valid2("valid2", 2);
		Bureaucrat valid149("valid149", 149);
		std::cout << valid2;
		std::cout << valid149;
		valid2.incrementGrade();
		valid149.decrementGrade();
		std::cout << valid2;
		std::cout << valid149;
	}
	catch(std::exception& e){
		std::cerr << "exception caught: " << e.what() << '\n';
	}
}

void testInvalidIncrementandDecrement() {
	std::cout << "\nTEST INVALID INCREMENT AND DECREMENT:\n";
	try{
		Bureaucrat valid1("valid1", 1);
		Bureaucrat valid150("valid1150", 150);
		std::cout << valid1;
		std::cout << valid150;
		valid1.incrementGrade();
		valid150.decrementGrade();

	}
	catch(std::exception& e){
		std::cerr << "exception caught: " << e.what() << '\n';
	}
}

void testCopyAndAssignment(void) {
	std::cout << "\nTEST COPY AND ASSIGNMENT:\n";

    try {
	Bureaucrat original("Original", 42);
	std::cout << "Original: " << original;

	Bureaucrat copy(original);
	std::cout << "Copy: " << copy;

	Bureaucrat assigned("Assigned", 100);
	std::cout << "Before assignment: " << assigned;

	assigned = original;
	std::cout << "After assignment: " << assigned;

    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}


int main () {
	testValidConstruction();
	testInvalidConstruction();
	testValidIncrementandDecrement();
	testInvalidIncrementandDecrement();
	testCopyAndAssignment();
}