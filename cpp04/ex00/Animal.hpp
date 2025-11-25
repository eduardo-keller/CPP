/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:16:56 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/25 12:28:07 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ANIMAL.HPP
# define ANIMAL.HPP

# include <string>

class Animal{
  protected:
  std::string type;
  
  public:
  Animal();
  Animal(const Animal& obj);
  Animal& operator=(const Animal& obj);
  virtual ~Animal();

  void makeSound();
  std::string getType();
};

#endif