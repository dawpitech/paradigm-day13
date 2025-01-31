/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Stack.hpp
*/

#ifndef STACK_HPP
    #define STACK_HPP

    #include <stack>
    #include <string>

class Stack
{
    public:
        class Error final : public std::exception
        {
            public:
                Error(std::string what) { this->_what = what; }
                const char* what() const noexcept override { return this->_what.c_str(); }

            protected:
                std::string _what;
        };
        void push(const double value) { this->_stack.push(value); }
        double pop();
        double top() const;

        void add();
        void sub();
        void mul();
        void div();

    private:
        std::stack<double> _stack = {};
};
#endif //STACK_HPP
