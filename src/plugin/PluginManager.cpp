#include <foas/plugin/PluginManager.h>


namespace foas {
  namespace plugin {
    PluginManager::PluginManager() {
    }

    PluginManager::~PluginManager() {
    }

    std::shared_ptr<common::Task> PluginManager::LoadTemplate(std::string path) {
      std::shared_ptr<common::Task> task = std::make_shared<common::Task>([this, path] {
	  std::cout << path << std::endl;
	  std::shared_ptr<PluginTemplate> pluginTemplate = std::make_shared<PluginTemplate>(path);
	  
	  if(pluginTemplate->Load()) {
	    std::string name = pluginTemplate->GetName();

	    if(mLoadedTemplates.find(name) == mLoadedTemplates.end()) {
	      mLoadedTemplates[name] = pluginTemplate;
	    } else {
	      pluginTemplate->Unload();
	    }
	  }
	});
      
      return task;
    }
    
    std::shared_ptr<PluginInstance> PluginManager::InstantiateTemplate(std::string name, std::shared_ptr<message::Bus> bus) {
      std::shared_ptr<PluginInstance> instance = nullptr;
      
      if(mLoadedTemplates.find(name) != mLoadedTemplates.end()) {
	instance = std::make_shared<PluginInstance>(mLoadedTemplates[name], bus);
	
	// TODO: Do more initialization here.
      }
      
      return instance;
    }
  }
}
