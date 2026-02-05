/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:27:57 by ekeller-          #+#    #+#             */
/*   Updated: 2026/02/05 17:40:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(){
    MutantStack<int> mstack;

    std::cout << "---TEST STACK WITH DEFAULT BASE CONTAINER DECK<T>---" << std::endl;
    std::cout << "push 5 and 17 to stack" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "call top() that displays the last element pushed" << std::endl;
    std::cout << mstack.top() << std::endl;
    std::cout << "call pop() to remove the last element" << std::endl;
    mstack.pop();
    std::cout << "call top() to display the new last element" << std::endl;
    std::cout << mstack.top() << std::endl;
    std::cout << "the stack size is now: " << mstack.size() << std::endl;
    std::cout << "push 3, 5, 737, 666, 666 and 0 to stack" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(666);
    mstack.push(666);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "current stack elements: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    
    
    std::cout << "---SAME TEST WITH LIST<T> CONTAINER---" << std::endl;
    std::list<int> l_test;

    std::cout << "push 5 and 17 to the list" << std::endl;
    l_test.push_back(5);
    l_test.push_back(17);

    std::cout << "call back() that displays the last element" << std::endl;
    std::cout << l_test.back() << std::endl;

    std::cout << "call pop_back() to remove the last element" << std::endl;
    l_test.pop_back();
    std::cout << "call back() to display the new last element" << std::endl;
    std::cout << l_test.back() << std::endl;

    std::cout << "the stack size is now: " << l_test.size() << std::endl;

    std::cout << "push 3, 5, 737, 666, 666 and 0 to stack" << std::endl;
    l_test.push_back(3);
    l_test.push_back(5);
    l_test.push_back(737);
    l_test.push_back(666);
    l_test.push_back(666);
    l_test.push_back(0);

    std::list<int>::iterator lt = l_test.begin();
    std::list<int>::iterator lte = l_test.end();

    ++lt;
    --lt;

    std::cout << "current stack elements: " << std::endl;
    while (lt != lte)
    {
        std::cout << *lt << std::endl;
        ++lt;
    }

    return 0;
}