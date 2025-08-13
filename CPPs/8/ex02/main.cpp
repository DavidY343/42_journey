/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:06:23 by david             #+#    #+#             */
/*   Updated: 2025/08/13 13:14:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"



template <typename It>
void print_range(It begin, It end) {
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Test 1: Básico ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Forward iteration: ";
    print_range(mstack.begin(), mstack.end());

    std::cout << "Reverse iteration: ";
    print_range(mstack.rbegin(), mstack.rend());

    std::cout << "\n=== Test 2: Iteradores constantes ===" << std::endl;
    const MutantStack<int> constStack = mstack;
    std::cout << "Const forward iteration: ";
    print_range(constStack.begin(), constStack.end());
    std::cout << "Const reverse iteration: ";
    print_range(constStack.rbegin(), constStack.rend());

    std::cout << "\n=== Test 3: MutantStack con strings ===" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("uno");
    strStack.push("dos");
    strStack.push("tres");
    print_range(strStack.begin(), strStack.end());

    std::cout << "\n=== Test 4: Comparativa con std::list<int> ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::cout << "List forward iteration: ";
    print_range(lst.begin(), lst.end());

    std::cout << "\n=== Test 5: Copia y asignación ===" << std::endl;
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy forward iteration: ";
    print_range(copyStack.begin(), copyStack.end());

    MutantStack<int> assignStack;
    assignStack = mstack;
    std::cout << "Assigned forward iteration: ";
    print_range(assignStack.begin(), assignStack.end());

    return 0;
}


// int main() {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;

//     mstack.pop();
//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::cout << "\nReverse iteration:\n";
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
//         std::cout << *rit << std::endl;
//     }

//     std::stack<int> s(mstack);

//     return 0;
// }
