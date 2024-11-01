/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:15:12 by david             #+#    #+#             */
/*   Updated: 2024/11/01 01:15:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate area of triangle using cross product
static Fixed area(Point const& a, Point const& b, Point const& c) {
    Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
                  (c.getX() - a.getX()) * (b.getY() - a.getY()));
    return area / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate area of the main triangle
    Fixed abcArea = area(a, b, c);
    if (abcArea < Fixed(0)) {
        abcArea = abcArea * Fixed(-1);
    }
    
    // Calculate areas of three triangles formed by the point and two vertices
    Fixed pabArea = area(point, a, b);
    if (pabArea < Fixed(0)) {
        pabArea = pabArea * Fixed(-1);
    }
    
    Fixed pbcArea = area(point, b, c);
    if (pbcArea < Fixed(0)) {
        pbcArea = pbcArea * Fixed(-1);
    }
    
    Fixed pcaArea = area(point, c, a);
    if (pcaArea < Fixed(0)) {
        pcaArea = pcaArea * Fixed(-1);
    }
    
    // Check if point is on any edge or vertex
    if (pabArea == Fixed(0) || pbcArea == Fixed(0) || pcaArea == Fixed(0)) {
        return false;
    }
    
    // Point is inside if sum of three areas equals the main triangle area
    Fixed sumArea = pabArea + pbcArea + pcaArea;
    return sumArea == abcArea;
}