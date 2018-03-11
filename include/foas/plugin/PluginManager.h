#ifndef __FOAS_PLUGIN_PLUGINMANAGER_H__
#define __FOAS_PLUGIN_PLUGINMANAGER_H__


#include <iostream>
#include <map>
#include <memory>

#include <foas/common/Task.h>

#include <foas/plugin/PluginTemplate.h>
#include <foas/plugin/PluginInstance.h>
#include <foas/message/Bus.h>


namespace foas {
  namespace plugin {
    class PluginManager {
    private:
      std::map<std::string, std::shared_ptr<PluginTemplate>> mLoadedTemplates;
      
    public:
      PluginManager();
      ~PluginManager();

      std::shared_ptr<common::Task> LoadTemplate(std::string path);
      std::shared_ptr<PluginInstance> InstantiateTemplate(std::string name, std::shared_ptr<message::Bus> bus);
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGINMANAGER_H__ */
