#ifndef CONFIG_PARSER_PARSER_HPP
#define CONFIG_PARSER_PARSER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "ParsingModule.hpp"

namespace ConfigParser {

class Parser {
 public:
  Parser() = default;

  void registerModule(std::shared_ptr<ParsingModule> module);
  std::shared_ptr<ParsingModule> module(const std::string& name);

  bool parse(const std::string& filePath);

 private:
  std::unordered_map<std::string, std::shared_ptr<ParsingModule>> _modules;
};

} /* namespace ConfigParser */

#endif
