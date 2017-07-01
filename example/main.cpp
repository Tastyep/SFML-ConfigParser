#include <utility>

#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Actions.hpp"
#include "BindModule.hpp"
#include "Parser.hpp"

class Window {
 public:
  Window()
    : _window(sf::VideoMode(800, 600), "InputConverter") {}

  void run() {
    sf::Event event;

    this->init();
    if (_parser.parse("../testConfig.cfg") == false) {
      this->close();
    }
    auto parsingModule = _parser.module("bind");
    auto bindModule = std::static_pointer_cast<ConfigParser::BindModule<sf::Keyboard::Key, Action>>(parsingModule);
    auto bindMapping = bindModule->mapping();

    for (const auto& mapping : bindMapping) {
      std::cout << "Key: " << mapping.first << " bound on the action: " << mapping.second << std::endl;
    }

    while (_window.isOpen()) {
      while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          this->close();
        }
      }
    }
  }

  void init() {
    using Key = sf::Keyboard::Key;

    auto bindModule = std::make_shared<ConfigParser::BindModule<Key, Action>>();

    bindModule->configureKeys({
      { "Left", Key::Left }, //
      { "Escape", Key::Escape },
    });
    bindModule->configureActions({
      { "Left", Action::LEFT }, //
      { "Escape", Action::ESCAPE },
    });

    _parser.registerModule(std::move(bindModule));
  }

  void close() {
    _window.close();
  }

 private:
  sf::Window _window;
  ConfigParser::Parser _parser;
};

int main() {
  Window window;

  window.run();
  return 0;
}
