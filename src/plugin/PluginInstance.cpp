#include <foas/plugin/PluginInstance.h>


namespace foas {
  namespace plugin {
    PluginInstance::PluginInstance(std::shared_ptr<PluginTemplate> pluginTemplate, std::shared_ptr<message::Bus> bus) : mTemplate(pluginTemplate) {
      mPlugin = pluginTemplate->CreatePlugin(bus);
    }
    
    PluginInstance::~PluginInstance() {
    }
  }
}
