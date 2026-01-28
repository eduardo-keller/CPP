/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:11:12 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/26 12:56:24 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>


template <typename T>
void iter(T *array, std::size_t len, void (*f)(T&)){
    if(!array || !f)
        return;
    
    //f(array[i]) is equivalent to (*f)(array[i]). dereferencing is implicit
    for(std::size_t i = 0; i < len; i++)
        f(array[i]);
}

template <typename T>
void iter(T const *array, std::size_t len, void (*f)(T const&)){
    if(!array || !f)
        return;
    
    for(std::size_t i = 0; i < len; i++)
        f(array[i]);
}


#endif