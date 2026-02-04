/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:00:49 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/20 15:23:39 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"
#include "Data.hpp"


int main() {
    Data initial_data;
    Data *deserialized_data;
    //uintptr_t has the exact size of a pointer according to your OS.
    uintptr_t serialized_data;
    
    initial_data.id = 1;
    initial_data.name = "Bob";
    initial_data.val = 1.111;

    std::cout << "INITIAL DATA:" << std::endl;
    std::cout << "id: " << initial_data.id << ", name: " << initial_data.name
    << ", value: " << initial_data.val << std::endl;
    
    serialized_data = Serializer::serialize(&initial_data);
    
    deserialized_data = Serializer::deserialize(serialized_data);

    std::cout << "DESERIALIZED DATA:" << std::endl;
    std::cout << "id: " << deserialized_data->id << ", name: " << deserialized_data->name
    << ", value: " << deserialized_data->val << std::endl;
    
    if (deserialized_data == &initial_data) {
        std::cout << "SUCCESS: Pointers Match!" << std::endl;
        std::cout << "initial_data address: " << &initial_data << std::endl;
        std::cout << "deserialized_data address: " << deserialized_data << std::endl;
    }
        
    
}