/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:23:20 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/20 15:44:29 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdint.h>
#include "Serializer.hpp"
#include "Data.hpp"

//reinterpret cast just changes the label/type, its reinterpretation. it
//does not change the bits...

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& obj) {(void)obj;}

Serializer& Serializer::operator=(const Serializer& obj) {
    (void)obj;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}