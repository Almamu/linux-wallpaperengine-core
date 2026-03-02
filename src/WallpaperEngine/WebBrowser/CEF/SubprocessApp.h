#pragma once

#include "WPSchemeHandlerFactory.h"
#include "WallpaperEngine/WebBrowser/WebBrowserContext.h"
#include "include/cef_app.h"

namespace WallpaperEngine::Application {
class WallpaperApplication;
}

namespace WallpaperEngine::WebBrowser::CEF {
class SubprocessApp : public CefApp {
public:
    explicit SubprocessApp (Context& context);

    void OnRegisterCustomSchemes (CefRawPtr<CefSchemeRegistrar> registrar) override;

protected:
    const Context& getContext () const;
    const std::map<std::string, WPSchemeHandlerFactory*>& getHandlerFactories () const;

private:
    std::map<std::string, WPSchemeHandlerFactory*> m_handlerFactories = {};
    Context& m_context;
    IMPLEMENT_REFCOUNTING (SubprocessApp);
    DISALLOW_COPY_AND_ASSIGN (SubprocessApp);
};
}