#ifndef __FOAS_PLUGIN_PLUGINMANAGER_H__
#define __FOAS_PLUGIN_PLUGINMANAGER_H__


#include <map>
#include <memory>

#include <foas/common/Task.h>

#include <foas/plugin/PluginTemplate.h>
#include <foas/plugin/PluginInstance.h>


namespace foas {
  namespace plugin {
    class PluginManager {
    private:
      std::map<std::string, PluginTemplate> mLoadedTemplates;
      
    public:
      PluginManager();
      ~PluginManager();

      std::shared_ptr<common::Task> LoadTemplate(std::string path);
      PluginInstance InstantiateTemplate(std::string name);
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGINMANAGER_H__ */
