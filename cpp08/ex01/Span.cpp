/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:54:32 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/02 16:44:37 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <stdexcept>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <limits>

Span::Span(): _maxSize(0){}

Span::Span(unsigned int N): _maxSize(N){}

Span::Span(const Span& copy): _maxSize(copy._maxSize), _numbers(copy._numbers){}

Span& Span::operator=(const Span& copy){
    if(this != &copy){
        _maxSize = copy._maxSize;
        _numbers = copy._numbers;
    }
    return *this;
}

Span::~Span(){}

unsigned int Span::longestSpan() const{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");

    int min = *std::min_element( _numbers.begin(), _numbers.end());
    int max = *std::max_element( _numbers.begin(), _numbers.end());
    return max- min;
}


unsigned int Span::shortestSpan() const{
    return 1;
}

void Span::addNumber(int nb){
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Vector is full");
    _numbers.push_back(nb);
}

template <typename iterator>
void Span::addRange(iterator begin, iterator end){
    int rangeLenght = std::distance(begin, end);
    if (rangeLenght + _numbers.size() >_maxSize)
        throw std::out_of_range("Range does not fit the vector");
    _numbers.insert(_numbers.end(), begin, end);
}

template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);

void Span::printNumbers(void) const{
    for (long unsigned int i = 0; i < _numbers.size(); i++)
        std::cout << _numbers[i] << " ";
    std::cout << std::endl;
}