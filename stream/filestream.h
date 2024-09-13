//////////////////////////////////////////////////////////////////////////////
//  filestream.h
//
//  Input/Output file stream class
//////////////////////////////////////////////////////////////////////////////

#ifndef __FILESTREAM_H__
#define __FILESTREAM_H__

//////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#include "sys/win32filestream.h"
typedef Win32FileStream DataFileStream;
#else
#include "sys/stdfilestream.h"
//--typedef CStd32FileStream DataFileStream;
#endif 


#endif //__FILESTREAM_H__

//////////////////////////////////////////////////////////////////////////////
