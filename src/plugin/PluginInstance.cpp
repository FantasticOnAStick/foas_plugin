#include <foas/plugin/PluginInstance.h>


namespace foas {
  namespace plugin {
    PluginInstance::PluginInstance(std::shared_ptr<PluginTemplate> pluginTemplate) : mTemplate(pluginTemplate) {
      mPlugin = pluginTemplate->CreatePlugin();
    }
    
    PluginInstance::~PluginInstance() {
    }
  }
}
