#ifndef __UTIL_H__
#define __UTIL_H__

template <typename T>
void swap1(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
#endif