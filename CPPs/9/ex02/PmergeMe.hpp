/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:11:28 by david             #+#    #+#             */
/*   Updated: 2025/08/25 11:35:48 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iterator>
#include <climits>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char** argv);
    void process();

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // Ford-Johnson para vector
    void fordJohnsonSortVector(std::vector<int>& arr, int left, int right);
    void mergeInsertVector(std::vector<int>& arr, int left, int mid, int right);
    void binaryInsertVector(std::vector<int>& arr, int left, int right, int value);

    // Ford-Johnson para deque
    void fordJohnsonSortDeque(std::deque<int>& arr, int left, int right);
    void mergeInsertDeque(std::deque<int>& arr, int left, int mid, int right);
    void binaryInsertDeque(std::deque<int>& arr, int left, int right, int value);

    void printContainer(const std::string& prefix, const std::vector<int>& c) const;
};

#endif
