/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:22:17 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/02 17:09:20 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form{
private:
	const std::string  _name;
	bool 				_signed;
	const int			 _gradeToSign;
	const int 			_gradeToExecute;
	
	static int const	_highestGrade = 1;
	static int const	_lowestGrade = 150;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& copy);
	Form& operator=(const Form& obj);
	~Form();

	const std::string&	getName() const;  
	bool				isSigned() const;
	int					getGradetoSign() const;
	int					getGradetoExecute() const;
	
	void				beSigned(Bureaucrat& obj);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif