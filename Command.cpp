/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Command.cpp
*/

#include "Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    try {
        this->_map.at(name);
    } catch (std::out_of_range& e) {
        this->_map.insert(std::make_pair(name, function));
        return;
    }
    throw Error("Already registered command");
}

void Command::executeCommand(const std::string& name)
{
    try {
        this->_map.at(name)();
    } catch (std::out_of_range& e)
    {
        throw Error("Unknow command");
    }
}
