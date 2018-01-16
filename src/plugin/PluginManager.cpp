#include <foas/plugin/PluginManager.h>


namespace foas {
  namespace plugin {
    PluginManager::PluginManager() {
    }

    PluginManager::~PluginManager() {
    }

    std::shared_ptr<common::Task> PluginManager::LoadTemplate(std::string path) {
      std::shared_ptr<common::Task> task = std::make_shared<common::Task>([this, path] {
	  // ...
	});
      
      return task;
    }
    
    PluginInstance PluginManager::InstantiateTemplate(std::string name) {
      PluginTemplate temp;
      PluginInstance instance(temp);
      
      // ...
      
      return instance;
    }
  }
}
