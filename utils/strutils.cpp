/////////////////////////////////////////////////////////////////////////////
// strutils.cpp
//
// String manipulations utils library
/////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include "strutils.h"

/////////////////////////////////////////////////////////////////////////////
uint GetDestSize(uint dest_size)
{
    dest_size = (!dest_size) ? (0xffffffff) : (dest_size);
    dest_size--;
    
    return dest_size;
}

/////////////////////////////////////////////////////////////////////////////
// Get string lenght
uint StrLen(const char * str)
{
    const char * ptr = str;
    uint len = 0;
    while(*ptr++) len++;
    
    return len;
}

/////////////////////////////////////////////////////////////////////////////
// Copy one string into another
uint StrCopy(char * dest, const char * src, uint dest_size)
{
    if(!dest || !src || dest_size < 2) return 0;
    dest_size = GetDestSize(dest_size);

    uint len = 0;
    while(*dest++ = *src++)
    {
        len++;
        if(len == dest_size) break;
    }
    *dest = 0;
    
    return len;
}

/////////////////////////////////////////////////////////////////////////////
// Compare two string if even parts are equal
bool StrComp(const char * str1, const char * str2)
{
    uint len1 = StrLen(str1);
    uint len2 = StrLen(str2);
    uint len_min = (len1 > len2) ? (len2) : (len1);
    
    for (uint i = 0; i < len_min; i++)
        if (*str1++ != *str2++) return false;
    
    return true;
}

/////////////////////////////////////////////////////////////////////////////
// Append string into another string
uint StrAppend(char * dest, const char * src, uint dest_size)
{
    if(!dest || !src || dest_size < 2) return 0;
    dest_size = GetDestSize(dest_size);
    uint dest_len = StrLen(dest);
    
    if(dest_size <= dest_len) return 0;
    uint frac_size = dest_size - dest_len;
    if(frac_size < 2) return 0;
    
    char * next = dest + dest_len;
    uint len = 0;
    while(*next++ = *src++)
    {
        len++;
        if(len == frac_size) break;
    }
    *next = 0;
    
    return len;
}

/////////////////////////////////////////////////////////////////////////////
// Append symbol into another string
uint StrAppend(char * dest, char symbol, uint dest_size)
{
    if(!dest || dest_size < 2) return 0;
    dest_size = GetDestSize(dest_size);
    uint dest_len = StrLen(dest);
    
    if(dest_size <= dest_len) return 0;
    uint frac_size = dest_size - dest_len;
    if(frac_size < 2) return 0;
    
    char * next = dest + dest_len;
    *next++ = symbol;
    *next = 0;
    
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
// Find character in string (not implemeneted)
const char * StrFind(const char * str, char symbol)
{
    while(*str) 
    {
        if (*str == symbol) return str;
        str++;
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Find first occured character from pattern list
const char * StrFind(const char * str, const char * pattern)
{
    while (*str)
    {
        const char * pat_ptr = pattern;
        while (*pat_ptr)
        {
            if (*pat_ptr == *str) return str;
            pat_ptr++;
        }
        str++;
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Find first occured character that is not on pattern characters list
const char * StrFindNot(const char * str, const char * pattern)
{
    while (*str)
    {
        const char * pat_ptr = pattern;
        while (*pat_ptr)
        {
            if (*pat_ptr != *str) return str;
            pat_ptr++;
        }
        str++;
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Find string inside another string (not implemented)
const char * StrFindSub(const char * str, const char * pattern)
{
    uint str_len = StrLen(str);
    uint pat_len = StrLen(pattern);
    if (pat_len > str_len) return NULL;
    
    uint frac_len = str_len - pat_len;
    const char * str_ptr = str;
    const char * pat_ptr = pattern;
    
    for(uint i = 0; i < frac_len; i++)
    {
        str_ptr = str + i;
        uint idx;
        for (idx = 0; idx < pat_len; idx++)
        {
            if(pat_ptr[idx] != str_ptr[idx]) break;
        }
        if(idx == pat_len) return str_ptr;
    }
    
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Find first occured alpha numerical symbol (includeing 0x2D and 0x5F)
const char * StrFindAlphaNum(const char * str)
{
    if(str == NULL) return NULL;
    
    const char * ptr = str;
    while(*ptr)
    {
        unsigned char symbol = *ptr;
        if(symbol >= 0x30 && symbol <= 0x39) return ptr;
        if(symbol >= 0x41 && symbol <= 0x5A) return ptr;
        if(symbol >= 0x61 && symbol <= 0x7B) return ptr;
        if(symbol == 0x2D || symbol == 0x5F) return ptr;
        ptr++;
    }
    
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// Find first occured alpha numerical symbol in reverse order
// (includeing 0x2D and 0x5F)
const char * StrFindAlphaNumRev(const char * str)
{
    if(str == NULL) return NULL;
    if(*str == 0) return NULL;
    
    uint size = StrLen(str);
    const char * ptr = str + size - 1;
    
    while(size)
    {
        unsigned char symbol = *ptr;
        if(symbol >= 0x30 && symbol <= 0x39) return ptr;
        if(symbol >= 0x41 && symbol <= 0x5A) return ptr;
        if(symbol >= 0x61 && symbol <= 0x7B) return ptr;
        if(symbol == 0x2D || symbol == 0x5F) return ptr;
        ptr++;
        size--;
    }
    
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
