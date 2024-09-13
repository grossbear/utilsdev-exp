//////////////////////////////////////////////////////////////////////////////
// appargs.h
//
// Program arguments container structure declaration
//////////////////////////////////////////////////////////////////////////////

#ifndef __ARGS_LIST_H__
#define __ARGS_LIST_H__

#define MAX_ARGS_SIZE   32367
#define MAX_ARGS_NUM    4096

typedef unsigned int uint;

struct ArgumentsList
{
    ArgumentsList(int argc, char ** argv);
    ArgumentsList(const ArgumentsList & args_list);
    ~ArgumentsList();
    
    void Reset();

    char agruments_list[MAX_ARGS_SIZE];
    const char * arguments_ptr[MAX_ARGS_NUM];
    uint arguments_count;
};



#endif //__ARGS_LIST_H__
