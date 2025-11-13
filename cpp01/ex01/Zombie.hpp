/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:46:47 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 17:29:01 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie{
    private:
    std::string name;
    
    
    public:
    Zombie();
    ~Zombie();
    void setName(std::string set_name);
    void announce(void);
    
};

Zombie* zombieHorde( int N, std::string name );
#endif