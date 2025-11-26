/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:08:50 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 13:41:59 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef Dog_HPP
# define Dog_HPP

# include <string>
# include "Animal.hpp"

class Dog: public Animal{
  public:
  Dog();
  Dog(const Dog& obj);
  Dog& operator=(const Dog& obj);
  ~Dog();

  //virtual is optinal here. if the function in base class is virtual 
  //the function of the derived class will alsobe virtual.
  virtual void makeSound() const;
};

#endif