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
#include "UniquePointer.hpp"

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
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}

class Example
{
private:
    int _id;

    public :
        Example(int id) : _id(id) { std::cout << "#" << _id << "construction" << std::endl; }
        ~Example() { std::cout << "#" << _id << "destruction" << std::endl; }
        void method() const { std::cout << "#" << _id << "method" << std::endl; }
};

int main_ex03()
{
    UniquePointer<Example> ptr1(new Example(1));
    UniquePointer<Example> ptr2(new Example(2));
    ptr1.reset();
    ptr2 = new Example(3);
    ptr2.get()->method();
    ptr2->method();
    return 0;
}

void test_ex03()
{
    UniquePointer<int> ptr1(new int(42));
    UniquePointer<int> ptr2; // Hold a nullptr
    //UniquePointer<int> ptr3(ptr1); // DOES NOT COMPILE
    //ptr2 = ptr1; // DOES NOT COMPILE
    ptr2 = new int(84);
    ptr1 = new int(21); // Old int * is deleted
}

int main()
{
    //return main_ex00();
    //return main_ex01();
    //return main_ex02();
    test_ex03();
    return main_ex03();
}
