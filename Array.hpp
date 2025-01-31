/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Array.hpp
*/

#ifndef ARRAY_HPP
    #define ARRAY_HPP

    #include <functional>
    #include <stdexcept>

template <typename T, std::size_t Size>
class Array
{
    public:
        T& operator[](std::size_t idx)
        {
            if (idx >= Size)
                throw std::out_of_range("Out of range");
            return this->_array[idx];
        }

        std::size_t size() const { return Size; }

        void forEach(const std::function<void(const T&)>& task) const
        {
            for (std::size_t i = 0; i < Size; i++) { task(this->_array[i]); }
        }

        template<typename U>
        Array<U, Size> convert(const std::function<U(const T&)>& converter) const
        {
            Array<U, Size> array;
            for (std::size_t i = 0; i < Size; i++) { array[i] = converter(this->_array[i]); }
            return array;
        }

    private:
        std::array<T, Size> _array = {};
};

template <typename T, std::size_t Size>
std::ostream& operator<<(std::ostream& os, Array<T, Size>& array)
{
    os << '[';
    for (std::size_t i = 0; i < Size; i++) {
        if (i != 0)
            os << ", ";
        os << array[i];
    }
    os << ']';
    return os;
}
#endif //ARRAY_HPP
