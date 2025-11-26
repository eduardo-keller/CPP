/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:39:21 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 13:52:16 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal{
  protected:
  std::string type;
  
  public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& obj);
  WrongAnimal& operator=(const WrongAnimal& obj);
  virtual ~WrongAnimal();

  void makeSound() const;
  const std::string& getType() const;
};

#endif