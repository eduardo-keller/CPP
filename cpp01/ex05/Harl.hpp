/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:19:34 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/14 16:13:26 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl{
    private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    void (Harl::*f[4])();
    std::string level[4];
    

    public:
    Harl();
    void complain( std::string level );

};

#endif