/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:12 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/05 18:04:41 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


template <typename T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        //iterator is unique to the container type. container_type resolves to the current
        //type (default is deque). 
        //needs typename to indicate that container_type is a type (vector, deque, etc...)
        //typedef so you are able to use just MutantStack<T>::iterator instead of the whole think in main. 
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        //c gives you acess to the base container. the default is 
        //deque<T>. std::stack is a container adaptor, not a real container.
        iterator begin() { return this->c.begin(); }
        iterator end()   { return this->c.end(); }
        
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const   { return this->c.end(); }


    
};

#endif