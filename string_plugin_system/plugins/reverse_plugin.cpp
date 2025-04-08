#include "string_plugin_system/string_plugin_base.hpp"
#include <algorithm>
#include <pluginlib/class_list_macros.hpp>

namespace string_plugin_system
{
  class ReversePlugin : public StringPluginBase
  {
  public:
    std::string process(const std::string & input) override
    {
      std::string reversed = input;
      std::reverse(reversed.begin(), reversed.end());
      return reversed;
    }
  };
}

PLUGINLIB_EXPORT_CLASS(string_plugin_system::ReversePlugin, string_plugin_system::StringPluginBase)
