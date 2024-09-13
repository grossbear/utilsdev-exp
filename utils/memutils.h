/////////////////////////////////////////////////////////////////////////////
// memutils.h
//
// Memory manipulations utils library
/////////////////////////////////////////////////////////////////////////////

#ifndef __MEMUTILS_H__
#define __MEMUTILS_H__

typedef unsigned int uint;
typedef unsigned char ubyte;

/////////////////////////////////////////////////////////////////////////////
// Reset buffers value to zero
void MemReset(void * data, uint size);
/////////////////////////////////////////////////////////////////////////////
// Set same value in each byte of buffer
void MemSet(void * data, ubyte value, uint size);
/////////////////////////////////////////////////////////////////////////////
// Copy data from source buffer to destination
void MemCopy(void * dest, const void * src, uint size);
/////////////////////////////////////////////////////////////////////////////
// Compare two data buffers
bool MemComp(const void * data1, const void * data2, uint size);
/////////////////////////////////////////////////////////////////////////////

#endif //__MEMUTILS_H__
