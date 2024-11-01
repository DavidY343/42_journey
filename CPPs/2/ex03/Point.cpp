/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pointer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:14:53 by david             #+#    #+#             */
/*   Updated: 2024/11/01 01:15:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        // Since x and y are const, we can't modify them
        // This is just to maintain Orthodox Canonical Form
    }
    return *this;
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}