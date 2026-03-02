#pragma once

#include "WallpaperEngine/Context.h"
#include "include/cef_app.h"
#include "include/cef_browser_process_handler.h"
#include "include/wrapper/cef_helpers.h"

#define WPENGINE_SCHEME "wp"

namespace WallpaperEngine::WebBrowser::CEF {
class BrowserApp;
}

namespace WallpaperEngine::WebBrowser {
class WebBrowserContext {
public:
    explicit WebBrowserContext (Context& context);
    ~WebBrowserContext ();

    Context& getContext () const;

private:
    Context& m_context;
    CefRefPtr<CefApp> m_browserApplication = nullptr;
    CefRefPtr<CefCommandLine> m_commandLine = nullptr;
};
} // namespace WallpaperEngine::WebBrowser
