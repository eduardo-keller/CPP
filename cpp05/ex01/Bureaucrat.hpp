/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:04:40 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/01 18:17:07 by ekeller-@st      ###   ########.fr       */
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
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& obj);
	~Bureaucrat();

	const std::string& getName() const;
	const int		getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			setGrade(int grade);

	void 			signForm(Form &form);

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