#ifndef __FOAS_PLUGIN_PLUGININSTANCE_H__
#define __FOAS_PLUGIN_PLUGININSTANCE_H__


#include <foas/plugin/PluginTemplate.h>


namespace foas {
  namespace plugin {
    class PluginInstance {
    private:
      PluginTemplate mTemplate;
      
    public:
      PluginInstance(PluginTemplate pluginTemplate);
      ~PluginInstance();
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGININSTANCE_H__ */
