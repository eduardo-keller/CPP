/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:06:36 by ekeller-          #+#    #+#             */
/*   Updated: 2026/03/03 12:07:06 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void run(int argc, char** argv);

private:
    struct IntPair {
        int small;
        int big;
    };

    // Parsing / validation
    static std::vector<int> parseInputToVector(int argc, char** argv);
    static int parsePositiveIntToken(const std::string& token);

    // Display
    static void printVector(const std::string& label, const std::vector<int>& v);
    static void printDeque(const std::string& label, const std::deque<int>& d);

    // Timing
    static long long nowMicroseconds();

    // Ford–Johnson (merge-insert) implementations (separate per container)
    static void fordJohnsonSortVector(std::vector<int>& data);
    static void fordJohnsonSortDeque(std::deque<int>& data);

    // Helpers (separate per container where it matters)
    static size_t lowerBoundVector(const std::vector<int>& data, int value, size_t endExclusive);
    static size_t lowerBoundDeque(const std::deque<int>& data, int value, size_t endExclusive);

    static std::vector<size_t> buildJacobsthalInsertionOrder(size_t pairCount);

    static void reorderPairsBySortedBigsVector(std::vector<IntPair>& pairs,
                                              const std::vector<int>& sortedBigs);
    static void reorderPairsBySortedBigsDeque(std::deque<IntPair>& pairs,
                                             const std::deque<int>& sortedBigs);

    static bool isSortedVector(const std::vector<int>& v);
};

#endif