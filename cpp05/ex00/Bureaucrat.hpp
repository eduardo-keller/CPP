/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:04:40 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/28 18:02:35 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
private:
	std::string const _name;
	int					_grade;
	static int const	_highestGrade = 1;
	static int const	_lowestGrade = 150;
	
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	// Bureaucrat(const Bureaucrat& copy);
	// Bureaucrat& operator=(const Bureaucrat& copy);
	// ~Bureaucrat();

	const std::string& getName() const;
	// //for primitive types such as int is better to return
	// //a copy(by value). not a reference. is more efficient.
	const int		getGrade() const;
	// void	incrementGrade();
	// void	decrementGrade();
	void	setGrade(int grade);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
		
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif