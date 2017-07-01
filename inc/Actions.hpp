#ifndef CONFIG_PARSER_ACTIONS_HPP
#define CONFIG_PARSER_ACTIONS_HPP

#include <iostream>
#include <type_traits>

namespace ConfigParser {

// clang-format off
enum class Action {
  ESCAPE,
  ACTION,
  JUMP,
  LEFT,
  RIGHT,
  UP,
  DOWN
};
// clang-format om

inline std::ostream& operator<<(std::ostream& os, Action action) {
  os << static_cast<std::underlying_type<Action>::type>(action);
  return os;
}

} /* namespace ConfigParser */

#endif
