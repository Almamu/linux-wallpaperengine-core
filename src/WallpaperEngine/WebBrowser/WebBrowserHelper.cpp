#include "include/cef_app.h"
#include "WallpaperEngine/WebBrowser/CEF/SubprocessApp.h"
#include "WallpaperEngine/Context.h"
#include <iostream>

int main(int argc, char* argv[]) {
    CefMainArgs main_args(argc, argv);

    // We don't have a real context here, as this is a subprocess
    // but SubprocessApp needs one to get the project list for scheme handlers
    // In a real scenario, we might want to pass this information differently
    // for now, let's see if we can just pass a dummy context or if it's really needed
    // The current SubprocessApp uses context.projects to register scheme handlers.
    
    // Since we don't have the context here, we might need a different App class for the helper
    // or a way to initialize it without a full context.
    
    // For now, let's just use a null context and see if it crashes, 
    // but ideally we should pass the project info to the subprocess.
    // CEF subprocesses usually don't need the full app state.
    
    return CefExecuteProcess(main_args, nullptr, nullptr);
}