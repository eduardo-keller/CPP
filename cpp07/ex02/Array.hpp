/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:58:59 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/27 16:29:27 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <stdexcept>

template <typename T>
class Array{
    private:
    T               *_array;
    unsigned int	_size;

    public:
    Array(): _array(NULL), _size(0) {}
    Array(unsigned int n): _array(new T[n]()), _size(n) {}
    Array(const Array &copy): _array(new T[copy._size]), _size(copy._size){
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = copy._array[i];
    }
    ~Array() {delete [] _array;}
    Array   &operator=(const Array &copy) {
        if (this != &copy)
        {
            delete[] _array;
            _size = copy._size;
            _array = new T[_size];
            for (unsigned int i = 0;i < _size; ++i)
                _array[i] = copy._array[i];
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if(index >= _size)
            throw std::out_of_range("Index outside valid range");
            
        return _array[index];
    }

    const T& operator[](unsigned int index) const{
        if(index >= _size)
            throw std::out_of_range("Index outside valid range");
            
        return _array[index];
    }
    
    unsigned int size(void) const {return _size;}
    

};



#endif