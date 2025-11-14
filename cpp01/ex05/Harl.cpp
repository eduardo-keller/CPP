/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:24:26 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/14 16:10:09 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){
    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;
    level[0] = "DEBUG";
    level[1] = "INFO";
    level[2] = "WARNING";
    level[3] = "ERROR";
}

void Harl::debug( void ){
    std::cout << "Eu amo ter bacon extra para o meu hambúrguer\n"
    "7XL-duplo-queijo-triplopicles-ketchup-especial. Eu realmente amo!"
    << std::endl;
}

void Harl::info( void ){
    std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. Vocês\n"
"não colocaram bacon suficiente no meu hambúrguer! Se vocês tivessem colocado, eu \n"
"não estaria pedindo por mais!"
    << std::endl;
}

void Harl::warning( void ){
    std::cout << "Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos,\n"
"enquanto você começou a trabalhar aqui apenas no mês passado."  << std::endl;
}

void Harl::error( void ){
    std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora." << std::endl;
}

void Harl::complain( std::string level ){
    
    for(int i = 0; i < 4; i++){
        if (this->level[i] == level ){
            (this->*f[i])();
            return ;
        }     
    }
    std::cout << "Invalid command. Choose: DEBUG, INFO, WARNING or ERROR" << std::endl;
}
