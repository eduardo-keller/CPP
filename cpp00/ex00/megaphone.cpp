/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:50:02 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/10/22 18:14:39 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv) {
	if (argc > 1){
		for(int i = 1; i < argc; i++){
			std::string word = argv[i];
			for (size_t j = 0; j < word.length(); j++){
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(word[j])));

			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}