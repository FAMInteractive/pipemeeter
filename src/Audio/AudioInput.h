#ifndef AUDIOBUS_H
#define AUDIOBUS_H
#include "rohrkabel/context.hpp"
#include "rohrkabel/loop.hpp"
#include "rohrkabel/core/core.hpp"
#include "rohrkabel/registry/events.hpp"
#include "rohrkabel/registry/registry.hpp"


#include <memory>
#include <type_traits>

static std::string extract_name(const std::string &value);

class AudioInput {
private:
  std::shared_ptr<pipewire::main_loop> loop;
  std::shared_ptr<pipewire::context> context;
  std::shared_ptr<pipewire::core> core;
  std::optional<pipewire::registry> reg;

  std::string name;
public:
  AudioInput(std::string name);
  ~AudioInput();

  void run();
};


#endif //AUDIOBUS_H
