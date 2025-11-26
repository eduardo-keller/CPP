/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:55:16 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 13:41:42 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat: public Animal{
  public:
  Cat();
  Cat(const Cat& obj);
  Cat& operator=(const Cat& obj);
  ~Cat();

  //virtual is optinal here. if the function in base class is virtual 
  //the function of the derived class will alsobe virtual.
  virtual void makeSound() const;
};

#endif