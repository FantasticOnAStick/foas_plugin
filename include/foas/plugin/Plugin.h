#ifndef __FOAS_PLUGIN_PLUGIN_H__
#define __FOAS_PLUGIN_PLUGIN_H__


#include <foas/message/Bus.h>


namespace foas {
  namespace plugin {
    class Plugin {
    private:
      std::shared_ptr<message::Bus> mBus;
      
    public:
      Plugin(std::shared_ptr<message::Bus> bus);
      ~Plugin();
    };
  }
}


#endif /* __FOAS_PLUGIN_PLUGIN_H__ */
