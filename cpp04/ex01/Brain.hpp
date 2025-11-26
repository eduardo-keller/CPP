/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:33:59 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 14:46:55 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
  private:
  std::string ideas[100];
  
  public:
  Brain();
  Brain(const Brain& obj);
  Brain& operator=(const Brain& obj);
  virtual ~Brain();

  const std::string& getIdeas(int idex) const;
};


#endif