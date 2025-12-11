/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:22:17 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/12/11 16:47:06 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm{
private:
	const std::string  _name;
	bool 				_signed;
	const int			 _gradeToSign;
	const int 			_gradeToExecute;
	
	static int const	_highestGrade = 1;
	static int const	_lowestGrade = 150;

protected:
	void		checkExecution(Bureaucrat const & executor) const;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& obj);
	virtual ~AForm();

	const std::string&	getName() const;  
	bool				isSigned() const;
	int					getGradetoSign() const;
	int					getGradetoExecute() const;
	
	void				beSigned(Bureaucrat& obj);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif