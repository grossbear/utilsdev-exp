/////////////////////////////////////////////////////////////////////////////
// memutils.cpp
//
// Memory manipulations utils library
/////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include "memutils.h"

/////////////////////////////////////////////////////////////////////////////
// Reset buffers value to zero
void MemReset(void * data, uint size)
{
    ubyte * ptr = reinterpret_cast<ubyte*>(data);
    while(size--) *ptr = 0;
}

/////////////////////////////////////////////////////////////////////////////
// Set same value in each byte of buffer
void MemSet(void * data, ubyte value, uint size)
{
    ubyte * ptr = reinterpret_cast<ubyte*>(data);
    while(size--) *ptr = value;
}

/////////////////////////////////////////////////////////////////////////////
// Copy data from source buffer to destination
void MemCopy(void * dest, const void * src, uint size)
{
    ubyte * dest_ptr = reinterpret_cast<ubyte*>(dest);
    const ubyte * src_ptr  = reinterpret_cast<const ubyte*>(src);
    
    while(size--) *dest_ptr++ = *src_ptr++;
}

/////////////////////////////////////////////////////////////////////////////
// Compare two data buffers
bool MemComp(const void * data1, const void * data2, uint size)
{
    const ubyte * dest_ptr = reinterpret_cast<const ubyte*>(data1);
    const ubyte * src_ptr  = reinterpret_cast<const ubyte*>(data2);
    
    for(uint i = 0; i < size; i++)
        if(*dest_ptr++ != *src_ptr++) return false;
    
    return true;
}
/////////////////////////////////////////////////////////////////////////////

