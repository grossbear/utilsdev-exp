//////////////////////////////////////////////////////////////////////////////
// Application entry point
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "appbase.h"

// external function for creating application object
extern ApplicationBase * CreateApplication(const ArgumentsList & args_list);

//////////////////////////////////////////////////////////////////////////////
// Entry point main function
int main(int argc, char ** argv, char ** envp)
{
    ArgumentsList args_list(argc, argv);
    // Calling external function for creating application
    ApplicationBase * app = CreateApplication(args_list);
    
    app->Init();    // Initializing application
    app->Run();     // Running main loop
    app->Release(); // Release all data in application

    delete (app);   // Deleting application pointer
    app = NULL;
    
    return 0; // Exit program
}
//////////////////////////////////////////////////////////////////////////////
