/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:06:30 by ekeller-          #+#    #+#             */
/*   Updated: 2026/03/03 12:07:17 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    try {
        PmergeMe sorter;
        sorter.run(argc, argv);
        return 0;
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}