/*
** EPITECH PROJECT, 2025
** paradigm-day13
** File description:
** Algorithm.hpp
*/

#ifndef ALGORITHM_HPP
    #define ALGORITHM_HPP

    #include <algorithm>

template <typename T>
void swap(T& left, T& right) noexcept
{
    std::swap(left, right);
}

template <typename T>
T min(const T left, const T right)
{
    return std::min(left, right);
}

template <typename T>
T max(const T left, const T right)
{
    return std::max(left, right);
}

template <typename T>
T clamp(const T value, const T min, const T max)
{
    return std::clamp(value, min, max);
}

#endif //ALGORITHM_HPP
