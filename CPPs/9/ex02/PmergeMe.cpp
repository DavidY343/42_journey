/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:11:57 by david             #+#    #+#             */
/*   Updated: 2025/08/25 11:38:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iomanip>


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.size(); j++) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
        long num = std::atol(arg.c_str());
        if (num <= 0 || num > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }
    return true;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    if (right - left + 1 <= 16) { // Umbral para insertion sort
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    fordJohnsonSortVector(arr, left, mid);
    fordJohnsonSortVector(arr, mid + 1, right);
    mergeInsertVector(arr, left, mid, right);
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Implementación para deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr, int left, int right) {
    if (left >= right) return;

    if (right - left + 1 <= 16) { // Umbral para insertion sort
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    fordJohnsonSortDeque(arr, left, mid);
    fordJohnsonSortDeque(arr, mid + 1, right);
    mergeInsertDeque(arr, left, mid, right);
}

void PmergeMe::mergeInsertDeque(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}
void PmergeMe::printContainer(const std::string& prefix, const std::vector<int>& c) const {
    std::cout << prefix;
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c[i];
        if (i + 1 < c.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::process() {
    // Print before
    printContainer("Before: ", _vec);

    // Sort with vector
    clock_t startVec = clock();
    fordJohnsonSortVector(_vec, 0, _vec.size() - 1);
    clock_t endVec = clock();

    // Sort with deque
    clock_t startDeq = clock();
    fordJohnsonSortDeque(_deq, 0, _deq.size() - 1);
    clock_t endDeq = clock();

    // Print after
    printContainer("After: ", _vec);

    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(6) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " 
              << std::fixed << std::setprecision(6) << timeDeq << " us" << std::endl;
}
