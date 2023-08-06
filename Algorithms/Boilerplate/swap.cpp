#include "swap.hpp"

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Explicit instantiations for common types to prevent linker errors.
template void swap<int>(int&, int&);
template void swap<double>(double&, double&);

// Explicit instantiations for common pointer types.
template void swap<int*>(int*&, int*&);
template void swap<double*>(double*&, double*&);