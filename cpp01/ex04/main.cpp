/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:22:51 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/13 16:39:27 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <fstream>

int main(){
    std::ifstream ifs("numbers.txt");
    int n1 = 1;
    int n2 = 2;
    ifs >> n1 >> n2;
    
    std::cout << n1 << " " << n2 << std::endl;
    
}