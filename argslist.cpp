//////////////////////////////////////////////////////////////////////////////
// appargs.cpp
//
// Program arguments container structure definition
//////////////////////////////////////////////////////////////////////////////

#include "utils/memutils.h"
#include "utils/strutils.h"
#include "argslist.h"

//////////////////////////////////////////////////////////////////////////////
void ArgumentsList::Reset()
{
    arguments_count = 0;
    MemReset(agruments_list, MAX_ARGS_SIZE);
    MemReset(arguments_ptr, MAX_ARGS_NUM);
}

//////////////////////////////////////////////////////////////////////////////
// Constructor
ArgumentsList::ArgumentsList(int argc, char ** argv)
{
    Reset();
    
    uint offset = 0;
    for(int i = 0; i < argc; i++)
    {
        uint bytes = StrAppend(agruments_list, argv[i], MAX_ARGS_SIZE);
        arguments_ptr[i] = agruments_list + offset;
        offset += bytes;
        offset++;
    }
}

//////////////////////////////////////////////////////////////////////////////
// Copy constructor
ArgumentsList::ArgumentsList(const ArgumentsList & args_list)
{
    Reset();
        
    // Copy arguments count
    arguments_count = args_list.arguments_count;
    if (!arguments_count) return ;
    
    // Copy args string data
    MemCopy(agruments_list, args_list.agruments_list, MAX_ARGS_SIZE);
    
    // Set pointers to arguments
    for(uint i = 0; i < arguments_count; i++)
    {
        const char * ptr1 = args_list.arguments_ptr[0];
        const char * ptr2 = args_list.arguments_ptr[i];
        uint arg_pos = ptr2 - ptr1;
        arguments_ptr[i] = agruments_list + arg_pos;
    }
}

//////////////////////////////////////////////////////////////////////////////
ArgumentsList::~ArgumentsList() {}

