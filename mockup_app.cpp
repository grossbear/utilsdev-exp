//////////////////////////////////////////////////////////////////////////////
// mockup_app.cpp
//
// Mockup application class for testing base class
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "mockup_app.h"

//////////////////////////////////////////////////////////////////////////////
ApplicationBase * CreateApplication(const ArgumentsList & args_list)
{
    MockupApplication::CreateSingleton(args_list);
    
    return MockupApplication::GetSingleton();
}

//////////////////////////////////////////////////////////////////////////////
void MockupApplication::CreateSingleton(const ArgumentsList & args_list)
{
    if (m_application == NULL)
    {
        m_application = new MockupApplication(args_list);
    }
}

//////////////////////////////////////////////////////////////////////////////
MockupApplication::MockupApplication(const ArgumentsList & args_list):
ApplicationBase(args_list)
{
    printf("Mockup Application class constructor\n");
}

//////////////////////////////////////////////////////////////////////////////
MockupApplication::~MockupApplication()
{
    printf("Mockup Application class destructor\n");
}
