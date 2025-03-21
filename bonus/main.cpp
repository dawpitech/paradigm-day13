/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** main.cpp
*/

#include <iostream>

#include "Algorithm.hpp"
#include "Array.hpp"
#include "Command.hpp"
#include "SharedPointer.hpp"
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

int main_ex04()
{
    Command command;
    Stack stack;
    try
    {
        command.registerCommand("push", [&stack]() { stack.push(4.2); });
        command.registerCommand("display", [&stack]()
        {
            std::cout << stack.top() << std::
                endl;
        });
        command.registerCommand("add", [&stack]() { stack.add(); });
        command.registerCommand("sub", [&stack]() { stack.sub(); });
        command.registerCommand("mul", [&stack]() { stack.mul(); });
        command.registerCommand("div", [&stack]() { stack.div(); });
        command.registerCommand("display", []()
        {
        });
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("add");
        command.executeCommand("div");
        command.executeCommand("display");
        command.executeCommand("nau");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

void test_ex05()
{
    int* ptr = new int(42);
    SharedPointer<int> ptr1(ptr); // ptr is now owned by ptr1
    SharedPointer<int> ptr2; // ptr2 hold a nullptr
    SharedPointer<int> ptr3(ptr1); // ptr is now owned by both ptr1 and ptr3

    ptr2 = ptr1; // ptr is now owned by both ptr1 , ptr2 and ptr3
    ptr1 = new int(84); // ptr is now owned by ptr2 and ptr3 , ptr1 hold a new pointer
    ptr2.reset(); // ptr is now owned by ptr3 only
    ptr3.reset(); // last reference of ptr is dropped , ptr is deleted
}

int main_ex05()
{
    SharedPointer<Example> ptr1(new Example(1));
    SharedPointer<Example> ptr2(ptr1);
    SharedPointer<Example> ptr3;
    ptr1.reset();
    ptr3 = ptr2;
    ptr2 = new Example(2);
    ptr2.get()->method();
    ptr3->method();
    return 0;
}

int main()
{
    //return main_ex00();
    //return main_ex01();
    //return main_ex02();
    //test_ex03();
    //return main_ex03();
    //return main_ex04();
    test_ex05();
    return main_ex05();
}
