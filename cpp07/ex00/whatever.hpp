/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:57:56 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/22 12:44:56 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void swap(T &a, T &b){
    T temp;
    temp = b;
    b = a;
    a = temp;
}

template <typename T>
T const &min(T &a, T &b) {
    return (b <= a) ? b : a;
}

template <typename T>
T const &max(T &a, T &b) {
    return (b >= a) ? b : a;
}

#endif