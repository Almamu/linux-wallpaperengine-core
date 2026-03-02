#include "SubprocessApp.h"
#include "WPSchemeHandlerFactory.h"
#include "WallpaperEngine/Data/Model/Project.h"

using namespace WallpaperEngine::WebBrowser::CEF;

SubprocessApp::SubprocessApp (Context& context) :
    m_context (context) {
    for (const auto& info : this->getContext ().projects) {
        this->m_handlerFactories[info->workshopId] = new WPSchemeHandlerFactory (*info);
    }
}

void SubprocessApp::OnRegisterCustomSchemes (CefRawPtr<CefSchemeRegistrar> registrar) {
    // register all the needed schemes, "wp" + the background id is going to be our scheme
    for (const auto& workshopId : this->m_handlerFactories | std::views::keys) {
	registrar->AddCustomScheme (
	    WPSchemeHandlerFactory::generateSchemeName (workshopId),
	    CEF_SCHEME_OPTION_STANDARD | CEF_SCHEME_OPTION_SECURE | CEF_SCHEME_OPTION_FETCH_ENABLED
	);
    }
}

const WallpaperEngine::Context& SubprocessApp::getContext () const {
    return this->m_context;
}

const std::map<std::string, WPSchemeHandlerFactory*>& SubprocessApp::getHandlerFactories () const {
    return this->m_handlerFactories;
}