#ifndef STRING_PLUGIN_BASE_HPP
#define STRING_PLUGIN_BASE_HPP

#include <string>

namespace string_plugin_system
{
  class StringPluginBase
  {
  public:
    virtual ~StringPluginBase() = default;
    virtual std::string process(const std::string & input) = 0;
  };
}

#endif
