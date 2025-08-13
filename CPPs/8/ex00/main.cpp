/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:52:10 by david             #+#    #+#             */
/*   Updated: 2025/08/13 12:52:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void test_with_vector() {
    std::cout << "[vector] tests\n";
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 2); // 0,2,4,...,18

    try {
        std::vector<int>::iterator it = easyfind(v, 8);
        std::cout << "Found value 8 at index " << (it - v.begin()) << "\n";
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    try {
        (void)easyfind(v, 7);
    } catch (const std::exception &e) {
        std::cout << "Not found as expected (7): " << e.what() << "\n";
    }
}

static void test_with_list() {
    std::cout << "[list] tests\n";
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) lst.push_back(i); // 1..5

    try {
        std::list<int>::const_iterator it = easyfind(static_cast<const std::list<int>&>(lst), 3);
        size_t idx = 0;
        for (std::list<int>::const_iterator i = lst.begin(); i != it; ++i) ++idx;
        std::cout << "Found value 3 at position " << idx << "\n";
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}

static void test_with_deque() {
    std::cout << "[deque] tests\n";
    std::deque<int> dq;
    for (int i = 0; i < 6; ++i) dq.push_back(i * -3); // 0,-3,-6,-9,-12,-15

    try {
        std::deque<int>::iterator it = easyfind(dq, -9);
        std::cout << "Found value -9 at index " << (it - dq.begin()) << "\n";
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}

int main() {
    test_with_vector();
    test_with_list();
    test_with_deque();
    return 0;
}
