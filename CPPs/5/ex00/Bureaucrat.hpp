/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:43:46 by david             #+#    #+#             */
/*   Updated: 2025/08/12 01:43:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
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

        Bureaucrat();
        Bureaucrat(const std::string & name, int grade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat & operator=(const Bureaucrat & other);
        ~Bureaucrat();

        const std::string & getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

    private:
        const std::string _name;
        int _grade;

        void _checkGrade(int grade) const;
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & b);

#endif
