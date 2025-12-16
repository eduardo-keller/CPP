/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:19:58 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/16 16:13:00 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
private:
   AForm* createPardon(std::string const &target);
   AForm* createShrubbery(std::string const &target);
   AForm* createRobotomy(std::string const &target);
    

public:
    Intern(void);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern(void);
    
    AForm*  makeForm(std::string const &formName, std::string const &target);

};

#endif