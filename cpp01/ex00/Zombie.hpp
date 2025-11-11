/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:46:47 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/11 16:10:19 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie{
    private:
    std::string name;
    
    public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
    
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif