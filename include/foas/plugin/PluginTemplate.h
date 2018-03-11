#ifndef __FOAS_PLUGIN_PLUGINTEMPLATE_H__
#define __FOAS_PLUGIN_PLUGINTEMPLATE_H__


#include <functional>
#include <memory>

#include <dlfcn.h>

#include <foas/plugin/Plugin.h>
#include <foas/common/FileSystem.h>


namespace foas {
  namespace plugin {
    class PluginTemplate {
    private:
      std::string mPath;

      void* mLibHandle;
      std::function<std::shared_ptr<Plugin>()> mCreateInstanceFunction;

      std::string mName;
      
    public:
      PluginTemplate(std::string path);
      ~PluginTemplate();

      bool Load();
      void Unload();

      std::string GetName();

      std::shared_ptr<Plugin> CreatePlugin();
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGINTEMPLATE_H__ */
