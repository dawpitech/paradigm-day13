/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** SharedPointer.hpp
*/

#ifndef SHAREDPOINTER_HPP
    #define SHAREDPOINTER_HPP

template <typename T>
class SharedPointer
{
    public:
        explicit SharedPointer()
        {
            *this->_count += 1;
        }
        explicit SharedPointer(T* obj)
        {
            this->_content = obj;
            *this->_count = 1;
        }
        SharedPointer(const SharedPointer& other)
        {
            this->_content = other._content;
            this->_count = other._count;
            *this->_count += 1;
        }
        ~SharedPointer()
        {
            *this->_count -= 1;
            if (*this->_count == 0)
                delete this->_content;
        }

        SharedPointer& operator=(T* obj)
        {
            *this->_count -= 1;
            if (*this->_count == 0)
                delete this->_content;
            this->_content = obj;
            this->_count = new std::size_t;
            *this->_count += 1;
            return *this;
        }
        SharedPointer& operator=(const SharedPointer& other)
        {
            *this->_count -= 1;
            if (*this->_count == 0)
                delete this->_content;
            this->_content = other._content;
            this->_count = other._count;
            *this->_count += 1;
            return *this;
        }
        T* operator->() const { return this->_content; }

        void reset()
        {
            *this->_count -= 1;
            if (*this->_count == 0)
                delete this->_content;
            this->_content = nullptr;
            this->_count = new std::size_t;
            *this->_count += 1;
        }
        T* get() const { return this->_content; }

    private:
        T* _content = nullptr;
        std::size_t* _count = new std::size_t;
};
#endif //SHAREDPOINTER_HPP
