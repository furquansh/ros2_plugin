cmake_minimum_required(VERSION 3.8)
project(string_plugin_system)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pluginlib REQUIRED)

include_directories(include)
add_library(reverse_plugin SHARED plugins/reverse_plugin.cpp)
ament_target_dependencies(reverse_plugin rclcpp pluginlib)

add_library(length_plugin SHARED plugins/length_plugin.cpp)
ament_target_dependencies(length_plugin rclcpp pluginlib)

add_executable(plugin_main src/plugin_main.cpp)
ament_target_dependencies(plugin_main rclcpp pluginlib)
target_link_libraries(plugin_main reverse_plugin length_plugin)

pluginlib_export_plugin_description_file(string_plugin_system plugins/plugin_description.xml)

install(
  TARGETS reverse_plugin length_plugin plugin_main
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/ DESTINATION include)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
