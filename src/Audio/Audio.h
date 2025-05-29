#ifndef AUDIOBUS_H
#define AUDIOBUS_H
#include <spa/utils/hook.h>



class Audio {
private:
  struct pw_main_loop *loop;
  struct pw_context *context;
  struct pw_core *core;
  struct pw_registry *registry;
  struct spa_hook registry_listener;
public:
  Audio();
  ~Audio();
   void createDevice(bool isInput, bool isVirtual);
};


#endif //AUDIOBUS_H
