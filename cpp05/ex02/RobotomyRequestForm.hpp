/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:11:50 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/08 17:12:57 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();
    
	const std::string& getTarget(void) const;
    void execute(Bureaucrat const &executor) const;
};


#endif