#pragma once

#include "frontends/context.h"

#include "Configuration.h"
#include "Audio/AudioContext.h"
#include "Render/RenderContext.h"

namespace WallpaperEngine {
struct LoadedProject {
    std::vector<Data::Model::ProjectUniquePtr>::const_iterator ref;
    std::unique_ptr<RenderContext> render;
};

struct Context {
    std::unique_ptr<TextureCache> texture_cache;
    std::unique_ptr<Audio::AudioContext> audio;
    const Configuration* config;
    wp_gl_proc_address* gl_proc_address;
    std::vector<Data::Model::ProjectUniquePtr> projects;
    bool isRunning;
    double renderTime;
};
}