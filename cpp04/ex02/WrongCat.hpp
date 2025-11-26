/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:46:26 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/26 12:48:07 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
  public:
  WrongCat();
  WrongCat(const WrongCat& obj);
  WrongCat& operator=(const WrongCat& obj);
  ~WrongCat();

  void makeSound() const;
};

#endif