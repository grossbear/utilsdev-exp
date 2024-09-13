//////////////////////////////////////////////////////////////////////////////
//  win32filestream.h
//
//  Win32 file input/output stream class
//////////////////////////////////////////////////////////////////////////////

#ifndef __WIN32_FILE_STREAM_H__
#define __WIN32_FILE_STREAM_H__

#include <TCHAR.H>
#include <windows.h>
#include "../../common/platformtypes.h"
#include "../datastream.h"


//////////////////////////////////////////////////////////////////////////////
enum StreamOpenMode 
{
    SM_OPEN_READ,
    SM_OPEN_READ_WRITE,
    SM_OPEN_CREATE,
    SM_OPEN_OVERWRITE,
    SM_OPEN_APPEND,
};

//////////////////////////////////////////////////////////////////////////////
class Win32FileStream : public DataStreamInt
{
public:
    Win32FileStream(const char * file_name, StreamOpenMode mode);
    virtual ~Win32FileStream();
    
    //
    bool    Close();

    uint    Read(void * data, uint size);
    uint    Write(const void * data, uint size);

    bool    IsOpened();
    bool    Seek(long offset, StreamSeekMode pos);

    uint    GetPos();
    uint    GetSize();
    bool    IsEOS();
    
private:
    bool    Open(const char * file_name, StreamOpenMode mode);
    void    SetFileSize();
    
    DWORD   GetAccessFlag(StreamOpenMode mode);
    DWORD   GetSharedFlag(StreamOpenMode mode);
    
    HANDLE  m_handle;
    int     m_error;
    uint    m_size;
};
//////////////////////////////////////////////////////////////////////////////

#endif //__WIN32_FILE_STREAM_H__
