/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** main.cpp
*/

#include <iostream>

#include "Algorithm.hpp"
#include "Array.hpp"
#include "Stack.hpp"

int main_ex00()
{
    int a = 42;
    int b = 21;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp(0, a, b) = " << ::clamp(0, a, b) << std::endl;
    std::string c = "ghi";
    std::string d = "abc";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << "clamp(\"def\", c, d) = " << ::clamp(std::string("def"), c, d) << std::
        endl;
    return 0;
}

int main_ex01()
{
    Array<int, 3> array;
    try
    {
        array[0] = 21;
        array[1] = 42;
        array[2] = 84;
        array[3] = 84;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << array << std::endl;
    array
        .convert<float>([](const int& v) { return static_cast<float>(v) / 10.f; })
        .forEach([](const float& v) { std::cout << v << std::endl; });
    return 0;
}

int main_ex02()
{
    Stack stack;
    stack.push(42.21);
    stack.push(84.42);
    stack.push(21.12);
    stack.add();
    stack.div();
    try
    {
        stack.mul();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}

int main()
{
    //return main_ex00();
    //return main_ex01();
    return main_ex02();
}
