/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:19:58 by ekeller-          #+#    #+#             */
/*   Updated: 2025/12/11 16:46:58 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

    class FormNotFoundException : std::exception {
        public:
            virtual const char *what() const throw();
    };

};

#endif