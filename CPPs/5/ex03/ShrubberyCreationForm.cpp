/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:37:12 by david             #+#    #+#             */
/*   Updated: 2025/08/12 12:43:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecute(executor);

    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "   ccee88oo\n"
                " C8O8O8Q8PoOb o8oo\n"
                "dOB69QO8PdUOpugoO9bD\n"
                "CgggbU8OU qOp qOdoUOdcb\n"
                "    6OuU  /p u gcoUodpP\n"
                "      \\\\\\//  /douUP\n"
                "        \\\\////\n"
                "         |||/\\\n"
                "         |||\\/\n"
                "         |||||\n"
                "   .....//||||\\....\n";
        file.close();
    }
}
