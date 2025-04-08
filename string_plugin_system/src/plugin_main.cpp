#include <rclcpp/rclcpp.hpp>
#include <pluginlib/class_loader.hpp>
#include "string_plugin_system/string_plugin_base.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  pluginlib::ClassLoader<string_plugin_system::StringPluginBase> loader(
    "string_plugin_system", "string_plugin_system::StringPluginBase");

  std::string plugin_name;
  std::cout << "Enter plugin name (ReversePlugin or LengthPlugin): ";
  std::cin >> plugin_name;
  if (plugin_name == "ReversePlugin") {
  plugin_name = "string_plugin_system::ReversePlugin";
} else if (plugin_name == "LengthPlugin") {
  plugin_name = "string_plugin_system::LengthPlugin";
} else {
  std::cerr << "Invalid plugin name entered!" << std::endl;
  return 1;
}

  try {
    auto plugin = loader.createSharedInstance(plugin_name);
    std::string input;
    std::cout << "Enter a string: ";
    std::cin.ignore();
    std::getline(std::cin, input);

    std::string output = plugin->process(input);
    std::cout << "Plugin output: " << output << std::endl;
  } catch (const pluginlib::LibraryLoadException & ex) {
    std::cerr << "Failed to load plugin: " << ex.what() << std::endl;
  }

  rclcpp::shutdown();
  return 0;
}
