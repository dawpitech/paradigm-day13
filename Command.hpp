/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Command.hpp
*/

#ifndef COMMAND_HPP
    #define COMMAND_HPP

    #include <functional>
    #include <iostream>
    #include <map>
    #include <string>

class Command
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

        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);

    protected:
        std::map<std::string, std::function<void()>> _map = {};
};
#endif //COMMAND_HPP
