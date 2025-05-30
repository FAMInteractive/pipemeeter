#ifndef AUDIOBUS_H
#define AUDIOBUS_H


class Audio {
public:

  struct data {
    struct pw_main_loop *loop;
    struct pw_context *context;
    struct pw_core *core;

  };
  // struct pw_main_loop *loop;
  // struct pw_context *context;
  // struct pw_core *core;
  // struct pw_registry *registry;
  // struct spa_hook registry_listener;
public:
  Audio();
  ~Audio();
};


#endif //AUDIOBUS_H
