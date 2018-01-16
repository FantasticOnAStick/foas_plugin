#include <foas/plugin/PluginInstance.h>


namespace foas {
  namespace plugin {
    PluginInstance::PluginInstance(PluginTemplate pluginTemplate) : mTemplate(pluginTemplate) {
    }

    PluginInstance::~PluginInstance() {
    }
  }
}
