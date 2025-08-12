#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat bob("Bob", 1);

    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        bob.signForm(*form);
        try {
            form->execute(bob);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Fry");
    if (form) {
        bob.signForm(*form);
        try {
            form->execute(bob);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form) {
        bob.signForm(*form);
        try {
            form->execute(bob);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete form;
    }

    form = someRandomIntern.makeForm("nonexistent form", "Nobody");
    if (form)
        delete form;

    return 0;
}
