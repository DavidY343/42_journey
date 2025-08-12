/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:01:00 by david             #+#    #+#             */
/*   Updated: 2025/08/12 02:01:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
public:
    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException() {}
        virtual ~GradeTooHighException() throw() {}
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException() {}
        virtual ~GradeTooLowException() throw() {}
        virtual const char* what() const throw();
    };

    Form();
    Form(const std::string & name, int gradeToSign, int gradeToExecute);
    Form(const Form & other);
    Form & operator=(const Form & other);
    ~Form();

    const std::string & getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat & b);

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    void _checkGrade(int grade) const;
};

std::ostream & operator<<(std::ostream & os, const Form & f);

#endif
