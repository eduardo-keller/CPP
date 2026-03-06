/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:06:33 by ekeller-          #+#    #+#             */
/*   Updated: 2026/03/04 13:55:00 by ekeller-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

#include <iostream>
#include <iomanip>
#include <set>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cerrno>

#include <sys/time.h>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char** argv) {
    if (argc < 2) {
        throw std::runtime_error("Error");
    }

    const std::vector<int> input = parseInputToVector(argc, argv);

    printVector("Before: ", input);

    // Vector timing: include data copy + all algorithm work
    long long start = nowMicroseconds();
    std::vector<int> v = input;
    fordJohnsonSortVector(v);
    long long end = nowMicroseconds();
    const double vecTimeUs = static_cast<double>(end - start);

    // Deque timing: include container construction + all algorithm work
    start = nowMicroseconds();
    std::deque<int> d(input.begin(), input.end());
    fordJohnsonSortDeque(d);
    end = nowMicroseconds();
    const double deqTimeUs = static_cast<double>(end - start);

    // Output
    printVector("After:  ", v);

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(2) << vecTimeUs << " us" << std::endl;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(2) << deqTimeUs << " us" << std::endl;

    // Sanity (optional): ensure vector result is sorted
    if (!isSortedVector(v)) {
        throw std::runtime_error("Error");
    }
}

std::vector<int> PmergeMe::parseInputToVector(int argc, char** argv) {
    std::vector<int> values;
    values.reserve(static_cast<size_t>(argc - 1));

    // Duplicates handling is left to discretion in the subject.
    // Here we choose to reject duplicates (simplifies unique-key steps in Ford–Johnson pairing).
    // std::set stores values in a sorted order and rejects duplicates. 
    std::set<int> seen;

    for (int i = 1; i < argc; ++i) {
        const int value = parsePositiveIntToken(std::string(argv[i]));
        //insert returns a pair, with the second element indicating  insertion success.
        if (!seen.insert(value).second) {
            throw std::runtime_error("Error");
        }
        values.push_back(value);
    }
    if (values.empty()) {
        throw std::runtime_error("Error");
    }
    return values;
}

int PmergeMe::parsePositiveIntToken(const std::string& token) {
    if (token.empty()) {
        throw std::runtime_error("Error");
    }

    for (size_t i = 0; i < token.size(); i++) {
        const char c = token[i];
        if (c < '0' || c > '9') {
            throw std::runtime_error("Error");
        }
    }
    
    //errno is a special macro error variable. if std::strtol fails
    //errno to ERANGE in acse of overflow.
    errno = 0;
    const long v = std::strtol(token.c_str(), 0, 10);
    if (errno != 0 || v <= 0 || v > INT_MAX) {
        throw std::runtime_error("Error");
    }
    return static_cast<int>(v);
}

void PmergeMe::printVector(const std::string& label, const std::vector<int>& v) {
    std::cout << label;
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) {
            std::cout << " ";
            
        }
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::string& label, const std::deque<int>& d) {
    std::cout << label;
    for (size_t i = 0; i < d.size(); ++i) {
        std::cout << d[i];
        if (i + 1 < d.size()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

long long PmergeMe::nowMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return static_cast<long long>(tv.tv_sec) * 1000000LL + static_cast<long long>(tv.tv_usec);
}

bool PmergeMe::isSortedVector(const std::vector<int>& v) {
    if (v.size() < 2) {
        return true;
    }
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i - 1] > v[i]) {
            return false;
        }
    }
    return true;
}

// -------------------------
// Jacobsthal insertion order
// -------------------------
// Returns the insertion order for pair indices [1..pairCount-1] (0 is inserted first separately).
// Using 1-based Jacobsthal J: 0,1,1,3,5,11,...
// After inserting a1, insert: a3,a2,a5,a4,a11,... (within bounds).
std::vector<size_t> PmergeMe::buildJacobsthalInsertionOrder(size_t pairCount) {
    std::vector<size_t> order;
    if (pairCount <= 1) {
        return order;
    }

    size_t prev = 1; // J2
    size_t curr = 3; // J3

    while (curr <= pairCount) {
        for (size_t i = curr; i > prev; --i) {
            // i is 1-based pair index, convert to 0-based
            order.push_back(i - 1);
        }
        const size_t next = curr + 2 * prev; // J(k+1) = J(k) + 2*J(k-1)
        prev = curr;
        curr = next;
    }

    // Insert remaining indices down from pairCount to prev+1
    for (size_t i = pairCount; i > prev; --i) {
        order.push_back(i - 1);
    }

    return order;
}

// -------------------------
// Lower bound helpers
// -------------------------
size_t PmergeMe::lowerBoundVector(const std::vector<int>& data, int value, size_t endExclusive) {
    size_t first = 0;
    size_t count = endExclusive;

    while (count > 0) {
        const size_t step = count / 2;
        const size_t it = first + step;

        if (data[it] < value) {
            first = it + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

size_t PmergeMe::lowerBoundDeque(const std::deque<int>& data, int value, size_t endExclusive) {
    size_t first = 0;
    size_t count = endExclusive;

    while (count > 0) {
        const size_t step = count / 2;
        const size_t it = first + step;

        if (data[it] < value) {
            first = it + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

// -------------------------
// Pair reordering helpers
// (bigs are unique here because we reject duplicates in parsing)
// -------------------------
void PmergeMe::reorderPairsBySortedBigsVector(std::vector<IntPair>& pairs,
                                             const std::vector<int>& sortedBigs) {
    std::vector<IntPair> ordered;
    ordered.reserve(pairs.size());

    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < sortedBigs.size(); ++i) {
        const int big = sortedBigs[i];

        bool found = false;
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].big == big) {
                used[j] = true;
                ordered.push_back(pairs[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Error");
        }
    }

    pairs.swap(ordered);
}

void PmergeMe::reorderPairsBySortedBigsDeque(std::deque<IntPair>& pairs,
                                            const std::deque<int>& sortedBigs) {
    std::deque<IntPair> ordered;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < sortedBigs.size(); ++i) {
        const int big = sortedBigs[i];

        bool found = false;
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].big == big) {
                used[j] = true;
                ordered.push_back(pairs[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Error");
        }
    }

    pairs.swap(ordered);
}

// -------------------------
// Ford–Johnson for std::vector<int>
// -------------------------
// -------------------------
// Ford–Johnson for std::vector<int> (IMPROVED: no scanning for big position)
// -------------------------
void PmergeMe::fordJohnsonSortVector(std::vector<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    std::vector<IntPair> pairs;
    pairs.reserve(data.size() / 2);

    const bool hasStraggler = (data.size() % 2u) != 0u;
    int straggler = 0;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        const int a = data[i];
        const int b = data[i + 1];

        IntPair p;
        if (a < b) { p.small = a; p.big = b; }
        else       { p.small = b; p.big = a; }
        pairs.push_back(p);
    }

    if (hasStraggler) {
        straggler = data.back();
    }

    // Recursively sort the bigs
    std::vector<int> bigs;
    bigs.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) {
        bigs.push_back(pairs[i].big);
    }
    fordJohnsonSortVector(bigs);

    // Reorder pairs to match sorted bigs
    reorderPairsBySortedBigsVector(pairs, bigs);

    // Main chain starts with sorted bigs
    std::vector<int> chain;
    chain.reserve(data.size());
    for (size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].big);
    }

    // Track current positions of each pair's big inside "chain"
    // Initially: big of pair i is at position i
    std::vector<size_t> bigPos(pairs.size(), 0);
    for (size_t i = 0; i < bigPos.size(); ++i) {
        bigPos[i] = i;
    }

    // Helper: after inserting at insertPos, all big positions >= insertPos shift right by 1
    // (C++98: do it inline each time)

    // Insert the first small (a1) with bound up to b1
    if (!pairs.empty()) {
        const size_t upperBound = 1; // search only within first big
        const size_t insertPos = lowerBoundVector(chain, pairs[0].small, upperBound);
        chain.insert(chain.begin() + static_cast<std::vector<int>::difference_type>(insertPos),
                     pairs[0].small);

        for (size_t k = 0; k < bigPos.size(); ++k) {
            if (bigPos[k] >= insertPos) {
                ++bigPos[k];
            }
        }
    }

    // Insert remaining smalls in Jacobsthal order, bounded by their paired big position
    const std::vector<size_t> order = buildJacobsthalInsertionOrder(pairs.size());
    for (size_t t = 0; t < order.size(); ++t) {
        const size_t pairIndex = order[t];
        const int smallVal = pairs[pairIndex].small;

        const size_t upperBound = bigPos[pairIndex] + 1; // include the paired big
        const size_t insertPos = lowerBoundVector(chain, smallVal, upperBound);

        chain.insert(chain.begin() + static_cast<std::vector<int>::difference_type>(insertPos),
                     smallVal);

        for (size_t k = 0; k < bigPos.size(); ++k) {
            if (bigPos[k] >= insertPos) {
                ++bigPos[k];
            }
        }
    }

    // Insert straggler (if any) into full chain
    if (hasStraggler) {
        const size_t insertPos = lowerBoundVector(chain, straggler, chain.size());
        chain.insert(chain.begin() + static_cast<std::vector<int>::difference_type>(insertPos),
                     straggler);
    }

    data.swap(chain);
}


// -------------------------
// Ford–Johnson for std::deque<int> (IMPROVED: no scanning for big position)
// -------------------------
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    std::deque<IntPair> pairs;

    const bool hasStraggler = (data.size() % 2u) != 0u;
    int straggler = 0;

    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        const int a = data[i];
        const int b = data[i + 1];

        IntPair p;
        if (a < b) { p.small = a; p.big = b; }
        else       { p.small = b; p.big = a; }
        pairs.push_back(p);
    }

    if (hasStraggler) {
        straggler = data.back();
    }

    // Recursively sort the bigs
    std::deque<int> bigs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        bigs.push_back(pairs[i].big);
    }
    fordJohnsonSortDeque(bigs);

    // Reorder pairs to match sorted bigs
    reorderPairsBySortedBigsDeque(pairs, bigs);

    // Main chain starts with sorted bigs
    std::deque<int> chain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].big);
    }

    // Track current positions of each pair's big inside "chain"
    std::vector<size_t> bigPos(pairs.size(), 0);
    for (size_t i = 0; i < bigPos.size(); ++i) {
        bigPos[i] = i;
    }

    // Insert the first small (a1)
    if (!pairs.empty()) {
        const size_t upperBound = 1;
        const size_t insertPos = lowerBoundDeque(chain, pairs[0].small, upperBound);

        chain.insert(chain.begin() + static_cast<std::deque<int>::difference_type>(insertPos),
                     pairs[0].small);

        for (size_t k = 0; k < bigPos.size(); ++k) {
            if (bigPos[k] >= insertPos) {
                ++bigPos[k];
            }
        }
    }

    // Insert remaining smalls in Jacobsthal order (bounded)
    const std::vector<size_t> order = buildJacobsthalInsertionOrder(pairs.size());
    for (size_t t = 0; t < order.size(); ++t) {
        const size_t pairIndex = order[t];
        const int smallVal = pairs[pairIndex].small;

        const size_t upperBound = bigPos[pairIndex] + 1;
        const size_t insertPos = lowerBoundDeque(chain, smallVal, upperBound);

        chain.insert(chain.begin() + static_cast<std::deque<int>::difference_type>(insertPos),
                     smallVal);

        for (size_t k = 0; k < bigPos.size(); ++k) {
            if (bigPos[k] >= insertPos) {
                ++bigPos[k];
            }
        }
    }

    // Insert straggler (if any)
    if (hasStraggler) {
        const size_t insertPos = lowerBoundDeque(chain, straggler, chain.size());
        chain.insert(chain.begin() + static_cast<std::deque<int>::difference_type>(insertPos),
                     straggler);
    }

    data.swap(chain);
}