#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>
#include <thread>

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("yao_node");
    
    auto publisher = node->create_publisher<std_msgs::msg::String>("besad", 10);
    auto message = std_msgs::msg::String();
    message.data = "hope nobody be sad";
    
    rclcpp::WallRate loop_rate(10);
    
    while (rclcpp::ok()) {
        publisher->publish(message);
        loop_rate.sleep();
    }
    
    rclcpp::shutdown();
    return 0;
}
