/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:00:01 by david             #+#    #+#             */
/*   Updated: 2025/08/12 11:00:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm();

    PresidentialPardonForm(const std::string &target);

    PresidentialPardonForm(const PresidentialPardonForm &other);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};

#endif
