//////////////////////////////////////////////////////////////////////////////
// configdata.cpp
//
// Conifg data container
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "../utils/memutils.h"
#include "../utils/strutils.h"
#include "configdata.h"

#define MAX_FILE_BUFFER     262144

//////////////////////////////////////////////////////////////////////////////
// Read file to buffer
long ReadFileData(char * buffer, long buffer_size, const char * file_name)
{
    FILE * pfile = fopen(file_name, "rb");
    if (!pfile) return 0;
    
    fseek (pfile, 0, SEEK_END);
    long size = ftell (pfile);
    fseek (pfile, 0, SEEK_SET);
    
    if (size >= buffer_size) 
    {
        fclose(pfile);
        return 0;
    }
    
    size_t result = fread(buffer,1,size,pfile);
    fclose(pfile);
    
    return (long) result;
}

//////////////////////////////////////////////////////////////////////////////
// Set parameters table
bool SetParamsFromString(ParamData * params, long count, const char * buffer)
{
    
}

//////////////////////////////////////////////////////////////////////////////
// Main struct constructor
ConfigData::ConfigData(const char * file_name)
{
    char file_buffer[MAX_FILE_BUFFER];
    MemReset(params, sizeof(ParamData) * PARAM_DATA_SIZE);
    MemReset(file_buffer, sizeof(char) * MAX_FILE_BUFFER);
    
    long size = ReadFileData(file_buffer, MAX_FILE_BUFFER, file_name);
    bool result = SetParamsFromString(params, PARAM_DATA_SIZE, file_buffer);
}
