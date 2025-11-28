/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:38:16 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/11/28 18:04:09 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main () {
Bureaucrat valid("valid", 1);
Bureaucrat test("valid", 0);	
try
  {
	Bureaucrat error("error", 0);
	
	
  }
  catch (std::exception& e)
  {
    std::cerr << "exception caught: " << e.what() << '\n';
  }
  
  std::cout << valid;
  return 0;
}