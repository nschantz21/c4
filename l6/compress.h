#ifndef COMPRESS_H
#define COMPRESS_H

template <typename ForwardIterator, typename OutputIterator>
void compress(
    ForwardIterator first,
    ForwardIterator last,
    OutputIterator result)
{
    // special case empty container
    if (first==last) return;
    // always insert the first element
    ForwardIterator next = first;
    while (first != last)
    {
        if (*first != *(++next))
        {
            *(++result) = *first;
        }
        ++first;
    }
}

#endif
