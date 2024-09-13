//////////////////////////////////////////////////////////////////////////////
//  win32filestream.cpp
//
//  Win32 file input/output stream class
//////////////////////////////////////////////////////////////////////////////

#include "win32filestream.h"

/*
LONGLONG W32Min(LONGLONG x1, LONGLONG x2)
{
    return x1 < x2 ? x1 : x2;
}
*/

//////////////////////////////////////////////////////////////////////////////
Win32FileStream::Win32FileStream(const char * file_name, StreamOpenMode mode):
m_handle(NULL), m_error(0), m_size(0)
{
    Open(file_name, mode);
    SetFileSize();
}

//////////////////////////////////////////////////////////////////////////////
Win32FileStream::~Win32FileStream()
{
    Close();
}

//////////////////////////////////////////////////////////////////////////////
bool Win32FileStream::Close()
{
    if (!m_handle)
        return false;

    BOOL result = CloseHandle(m_handle);
    m_error = 0;
    m_size = 0;
    m_handle = NULL;

    return (bool) result;
}

//////////////////////////////////////////////////////////////////////////////
bool Win32FileStream::IsOpened()
{
    return (bool)((m_handle != NULL) && (m_handle != INVALID_HANDLE_VALUE));
}


//////////////////////////////////////////////////////////////////////////////
bool Win32FileStream::IsEOS()
{
    return (bool)(GetPos() == m_size);
}

//////////////////////////////////////////////////////////////////////////////
uint Win32FileStream::GetPos()
{
#ifdef SIZE_INT_64
    LARGE_INTEGER dist_move;
    dist_move.QuadPart = 0;
    dist_move.LowPart = SetFilePointer (m_handle, 0, 
                                        & dist_move.HighPart, FILE_CURRENT);
    DWORD dwError = GetLastError();
    if(dist_move.LowPart != INVALID_SET_FILE_POINTER && dwError == NO_ERROR)
        return (uint) dist_move.QuadPart; //isize_t
#else
    DWORD dwPtrLow = SetFilePointer(m_handle, 0, 0, FILE_CURRENT);
    DWORD dwError = GetLastError();
    if(dwPtrLow != INVALID_SET_FILE_POINTER && dwError == NO_ERROR)
        return (uint) dwPtrLow;
#endif //SIZE_INT_64

    return 0;
}
//////////////////////////////////////////////////////////////////////////////
uint Win32FileStream::GetSize()
{
    return m_size;
}
//////////////////////////////////////////////////////////////////////////////
bool Win32FileStream::Seek(long offset, StreamSeekMode mode)
{
    if(m_handle == NULL)
        return false;

    const DWORD mode_tab[] = {FILE_BEGIN, FILE_CURRENT, FILE_END};

#ifdef SIZE_INT_64
    LARGE_INTEGER dist_move;
    dist_move.QuadPart = (LONGLONG)offset;
    dist_move.LowPart = SetFilePointer( m_handle, dist_move.LowPart,
                                        & dist_move.HighPart, mode_tab[mode]);
    DWORD dwError = GetLastError();
    if(dist_move.LowPart == INVALID_SET_FILE_POINTER || dwError != NO_ERROR)
        return false;
#else
    DWORD dwPtrLow = SetFilePointer(m_handle, offset, 0, mode_tab[mode]);
    DWORD dwError = GetLastError();
    if(dwPtrLow == INVALID_SET_FILE_POINTER && dwError != NO_ERROR)
        return false;
#endif //SIZE_INT_64

    return true;
}

//////////////////////////////////////////////////////////////////////////////
uint Win32FileStream::Read(void * data, uint size)
{
    if (m_handle == NULL)
        return 0;

    DWORD dwReaded = 0;
    if (!ReadFile(m_handle, data, (DWORD)size, & dwReaded, NULL))
        return 0;

    return (uint) dwReaded;
}

//////////////////////////////////////////////////////////////////////////////
uint Win32FileStream::Write(const void * data, uint size)
{
    if(m_handle == NULL)
        return 0;

    DWORD dwWritten = 0;
    if(!WriteFile(m_handle, data, (DWORD) size, & dwWritten, NULL))
        return 0;

    return (uint)dwWritten;
}

//////////////////////////////////////////////////////////////////////////////
// private methods
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
bool Win32FileStream::Open(const char * file_name, StreamOpenMode mode)
{
    if(file_name == NULL)
        return (bool) false;

    if(m_handle != NULL)
        return (bool) false;

    DWORD access_flags = GetAccessFlag(mode);
    DWORD share_flags = GetSharedFlag(mode);
    
    const DWORD create_tab[] = {OPEN_EXISTING, 
                                OPEN_ALWAYS, 
                                CREATE_NEW, 
                                CREATE_ALWAYS, 
                                OPEN_EXISTING};
    DWORD flags = 0;
    m_handle = CreateFileA( file_name, access_flags, share_flags, NULL, 
                            create_tab[mode], flags, NULL);

    return (bool)(m_handle != INVALID_HANDLE_VALUE);
}

//////////////////////////////////////////////////////////////////////////////
void Win32FileStream::SetFileSize()
{
#ifdef SIZE_INT_64
    LARGE_INTEGER largeint;
    largeint.QuadPart = 0;
    largeint.LowPart = SetFilePointer ( m_handle, 0, & largeint.HighPart, 
                                        FILE_CURRENT);
    DWORD dwError = GetLastError();
    if (largeint.LowPart != INVALID_SET_FILE_POINTER && 
        dwError == NO_ERROR)
    {
        m_size = (uint) min (largeint.QuadPart, (LONGLONG)0xFFFFFFFF);
    }      
#else
    DWORD dwPtrLow = SetFilePointer(m_handle, 0, 0, FILE_CURRENT);
    DWORD dwError = GetLastError();
    if(dwPtrLow != INVALID_SET_FILE_POINTER && dwError == NO_ERROR)
    {
        m_size = (uint) min (dwPtrLow, (LONGLONG)0xFFFFFFFF);
    }
#endif //SIZE_INT_64
}

//////////////////////////////////////////////////////////////////////////////
DWORD Win32FileStream::GetAccessFlag(StreamOpenMode mode)
{
    if (mode == SM_OPEN_READ) return GENERIC_READ;
    
    return GENERIC_READ | GENERIC_WRITE;
}

//////////////////////////////////////////////////////////////////////////////
DWORD Win32FileStream::GetSharedFlag(StreamOpenMode mode)
{
    //(mode == open_read) ? (FILE_SHARE_READ | FILE_SHARE_WRITE) : (FILE_SHARE_READ);
    return FILE_SHARE_READ;
}
//////////////////////////////////////////////////////////////////////////////




