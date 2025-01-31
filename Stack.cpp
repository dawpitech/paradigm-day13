/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Stack.cpp
*/

#include "Stack.hpp"

double Stack::pop()
{
    if (this->_stack.empty())
        throw Error("Empty stack");
    const auto elem = this->_stack.top();
    this->_stack.pop();
    return elem;
}

double Stack::top() const
{
    if (this->_stack.empty())
        throw Error("Empty stack");
    return this->_stack.top();
}

void Stack::add()
{
    if (this->_stack.size() < 2)
        throw Error("Not enough operands");
    const auto left = this->pop();
    const auto right = this->pop();
    this->push(left + right);
}

void Stack::sub()
{
    if (this->_stack.size() < 2)
        throw Error("Not enough operands");
    const auto left = this->pop();
    const auto right = this->pop();
    this->push(left - right);
}

void Stack::mul()
{
    if (this->_stack.size() < 2)
        throw Error("Not enough operands");
    const auto left = this->pop();
    const auto right = this->pop();
    this->push(left * right);
}

void Stack::div()
{
    if (this->_stack.size() < 2)
        throw Error("Not enough operands");
    const auto left = this->pop();
    const auto right = this->pop();
    if (right == 0.0f)
        throw Error("Cannot divide by zero");
    this->push(left / right);
}
