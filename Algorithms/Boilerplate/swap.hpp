#ifndef SWAP_UTILITY_HPP
#define SWAP_UTILITY_HPP

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif // SWAP_UTILITY_HPP
