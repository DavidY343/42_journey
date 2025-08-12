/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:00:57 by david             #+#    #+#             */
/*   Updated: 2025/08/12 02:01:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

const char* Form::GradeTooHighException::what() const throw() {
    return "Form::GradeTooHighException: grade is too high";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "Form::GradeTooLowException: grade is too low";
}

Form::Form()
: _name("UnnamedForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string & name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _checkGrade(_gradeToSign);
    _checkGrade(_gradeToExecute);
}

Form::Form(const Form & other)
: _name(other._name),
  _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign),
  _gradeToExecute(other._gradeToExecute)
{
}

Form & Form::operator=(const Form & other)
{
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

void Form::_checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string & Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat & b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream & operator<<(std::ostream & os, const Form & f)
{
    os << "Form '" << f.getName() << "', signed: "
       << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
