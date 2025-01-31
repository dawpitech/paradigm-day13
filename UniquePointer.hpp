/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** UniquePointer.hpp
*/

#ifndef UNIQUEPOINTER_HPP
    #define UNIQUEPOINTER_HPP

template <typename T>
class UniquePointer
{
    public:
        explicit UniquePointer() = default;
        explicit UniquePointer(T* obj)
        {
           this->_content = obj;
        }
        UniquePointer(UniquePointer& _) = delete;
        ~UniquePointer()
        {
            delete this->_content;
        }

        UniquePointer& operator=(T* obj)
        {
            delete this->_content;
            this->_content = obj;
            return *this;
        }
        UniquePointer& operator=(UniquePointer& _) = delete;
        T* operator->() const { return this->_content; }

        void reset()
        {
            delete this->_content;
            this->_content = nullptr;
        }
        T* get() const { return this->_content; }

    private:
        T* _content = nullptr;
};
#endif //UNIQUEPOINTER_HPP
