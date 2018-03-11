#include <foas/plugin/Plugin.h>


namespace foas {
  namespace plugin {
    Plugin::Plugin(std::shared_ptr<message::Bus> bus) : mBus(bus) {
    }

    Plugin::~Plugin() {
    }
  }
}
