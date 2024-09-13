//////////////////////////////////////////////////////////////////////////////
//  stdfilestream.h
//
//  File input/output stream class using standard C functions
//////////////////////////////////////////////////////////////////////////////

#ifndef __STD_FILE_STREAM_H__
#define __STD_FILE_STREAM_H__

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
enum OpenMode 
{
    open_read,
    open_read_write,
    open_create,
    open_overwrite,
    open_append,
};

//////////////////////////////////////////////////////////////////////////////
class Std32FileStream : public DataStream
{
public:
    Std32FileStream();
    virtual ~Std32FileStream();

    bool    Open(const char * file_name, OpenMode mode);
    bool    Close();

    uint    Read(void * data, uint size);
    uint    Write(const void * data, uint size);

    bool    IsOpened();
    bool    Seek(uint offset, SeekMode pos);

    uint    GetPos();
    uint    GetSize();

    bool    IsEOS();

protected:
    FILE    *m_file;
    int     m_error;
    uint    m_size;
};

//////////////////////////////////////////////////////////////////////////////



#endif //__STD_FILE_STREAM_H__
