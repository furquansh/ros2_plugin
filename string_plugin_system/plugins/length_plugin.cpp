#include "string_plugin_system/string_plugin_base.hpp"
#include <pluginlib/class_list_macros.hpp>

namespace string_plugin_system
{
  class LengthPlugin : public StringPluginBase
  {
  public:
    std::string process(const std::string & input) override
    {
      return "Length: " + std::to_string(input.length());
    }
  };
}

PLUGINLIB_EXPORT_CLASS(string_plugin_system::LengthPlugin, string_plugin_system::StringPluginBase)
