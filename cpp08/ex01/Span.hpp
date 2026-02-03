/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:01:12 by ekeller-          #+#    #+#             */
/*   Updated: 2026/01/30 17:38:29 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& assign);
        ~Span();
    
        void addNumber(int nb);
        template <typename iterator>
        void addRange(iterator begin, iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        void printNumbers(void) const;
    
};

#endif