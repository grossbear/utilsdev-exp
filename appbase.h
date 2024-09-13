/////////////////////////////////////////////////////////////////////////////
// appbase.h
//
// Application base class declaration
/////////////////////////////////////////////////////////////////////////////

#ifndef __APPLICATION_BASE_H__
#define __APPLICATION_BASE_H__

#include <string>
#include "argslist.h"

class ApplicationBase
{
public:
    static ApplicationBase * GetSingleton();
    virtual ~ApplicationBase();
    
    virtual void Init();
    virtual void Run();
    virtual void Release();
    
    virtual void Render();
    
    
protected:
    // Constructor
    ApplicationBase(const ArgumentsList & args_list);
    
    // Arguments functions
    unsigned int GetInputArgumentsCount() const;
    const char * GetInputArgument(unsigned int idx) const;
    
    // Application instance
    static ApplicationBase * m_application;
  
private:
    bool m_running;
    ArgumentsList m_args_list;
};


#endif //__APPLICATION_BASE_H__
