//////////////////////////////////////////////////////////////////////////////
// datastream.h
//
// Abstract class fot input/outputa data stream
//////////////////////////////////////////////////////////////////////////////

#ifndef __DATASTREAM_H__
#define __DATASTREAM_H__

typedef unsigned int uint;

//////////////////////////////////////////////////////////////////////////////
enum StreamSeekMode
{
    SM_SEEK_SET  = 0,
    SM_SEEK_CURR = 1,
    SM_SEEK_END  = 2,
};

//////////////////////////////////////////////////////////////////////////////
class DataStreamInt
{
public:
//    DataStream(){};
//    virtual ~DataStream(){}

    virtual uint Read(void * data, uint size) = 0;
    virtual uint Write(const void * data, uint size) = 0;

    virtual bool IsOpened() = 0;
    virtual bool Seek(uint offset, StreamSeekMode mode) = 0;

    virtual uint GetPos() = 0;
    virtual uint GetSize() = 0;
    virtual bool IsEOS() = 0;
};
//////////////////////////////////////////////////////////////////////////////

#endif //__DATASTREAM_H__
