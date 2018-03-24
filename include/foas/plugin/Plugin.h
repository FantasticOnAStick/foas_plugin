#ifndef __FOAS_PLUGIN_PLUGIN_H__
#define __FOAS_PLUGIN_PLUGIN_H__


#include <foas/message/Bus.h>


namespace foas {
  namespace plugin {
    class Plugin {
    protected:
      std::shared_ptr<message::Bus> mBus;
      
    public:
      Plugin(std::shared_ptr<message::Bus> bus);
      ~Plugin();

      virtual bool Initialize() = 0;
      virtual void Deinitialize() = 0;
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGIN_H__ */
