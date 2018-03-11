#include <foas/plugin/PluginTemplate.h>


namespace foas {
  namespace plugin {
    PluginTemplate::PluginTemplate(std::string path) : mPath(path), mLibHandle(nullptr), mName("") {
    }
    
    PluginTemplate::~PluginTemplate() {
    }
    
    bool PluginTemplate::Load() {
      if(mPath != "") {
	if(common::FileSystem::GetPathType(mPath) == common::FileSystem::FileSystemEntryType::File) {
	  void* libHandle = dlopen(mPath.c_str(), RTLD_NOW);
	  
	  if(libHandle) {
	    std::string (*getName)() = (std::string(*)())dlsym(libHandle, "GetName");

	    if(getName) {
	      mName = getName();

	      if(mName != "") {
		std::shared_ptr<Plugin> (*createInstance)(std::shared_ptr<message::Bus>) = (std::shared_ptr<Plugin>(*)(std::shared_ptr<message::Bus>))dlsym(libHandle, "CreateInstance");
		
		if(createInstance) {
		  mCreateInstanceFunction = [createInstance](std::shared_ptr<message::Bus> bus) {
		    return createInstance(bus);
		  };
		  
		  mLibHandle = libHandle;
		  
		  return true;
		}
	      }
	    }
	    
	    mName = "";
	    dlclose(libHandle);
	  }
	}
      }
      
      return false;
    }

    void PluginTemplate::Unload() {
      if(mLibHandle) {
	dlclose(mLibHandle);
	mLibHandle = nullptr;
      }
    }

    std::string PluginTemplate::GetName() {
      return mName;
    }
    
    std::shared_ptr<Plugin> PluginTemplate::CreatePlugin(std::shared_ptr<message::Bus> bus) {
      return mCreateInstanceFunction(bus);
    }
  }
}
