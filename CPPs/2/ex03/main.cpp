/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:05:58 by david             #+#    #+#             */
/*   Updated: 2024/11/01 01:16:29 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
    // Test cases for BSP
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    
    // Test point inside triangle
    Point p1(2.0f, 2.0f);
    std::cout << "Point (2,2) inside triangle: " << (bsp(a, b, c, p1) ? "yes" : "no") << std::endl;
    
    // Test point outside triangle
    Point p2(4.0f, 4.0f);
    std::cout << "Point (4,4) inside triangle: " << (bsp(a, b, c, p2) ? "yes" : "no") << std::endl;
    
    // Test point on edge
    Point p3(2.0f, 0.0f);
    std::cout << "Point (2,0) inside triangle: " << (bsp(a, b, c, p3) ? "yes" : "no") << std::endl;
    
    // Test point on vertex
    Point p4(0.0f, 0.0f);
    std::cout << "Point (0,0) inside triangle: " << (bsp(a, b, c, p4) ? "yes" : "no") << std::endl;
    
    return 0;
}