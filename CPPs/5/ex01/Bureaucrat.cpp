/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:00:53 by david             #+#    #+#             */
/*   Updated: 2025/08/12 02:00:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHighException: grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLowException: grade is too low";
}

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name), _grade(grade)
{
    _checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {}

const std::string & Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::_checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
    _checkGrade(_grade - 1);
    --_grade;
}

void Bureaucrat::decrementGrade() {
    _checkGrade(_grade + 1);
    ++_grade;
}

void Bureaucrat::signForm(Form & form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
