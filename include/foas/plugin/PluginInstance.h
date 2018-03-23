#ifndef __FOAS_PLUGIN_PLUGININSTANCE_H__
#define __FOAS_PLUGIN_PLUGININSTANCE_H__


#include <foas/plugin/PluginTemplate.h>
#include <foas/message/Bus.h>


namespace foas {
  namespace plugin {
    class PluginInstance {
    private:
      std::shared_ptr<PluginTemplate> mTemplate;
      std::shared_ptr<Plugin> mPlugin;
      
    public:
      PluginInstance(std::shared_ptr<PluginTemplate> pluginTemplate, std::shared_ptr<message::Bus> bus);
      ~PluginInstance();

      void Initialize();
      void Deinitialize();
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGININSTANCE_H__ */
