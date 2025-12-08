/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:06:18 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/08 16:07:42 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
private:
    std::string _target;

public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();
    
	const std::string& getTarget(void) const;
    void execute(Bureaucrat const &executor) const;
};


#endif