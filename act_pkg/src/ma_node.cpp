#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MaNode : public rclcpp::Node
{
public:
    MaNode() : Node("ma_node")
    {
        chao_subscription_ = this->create_subscription<std_msgs::msg::String>(
            "behappy", 10,
            std::bind(&MaNode::chao_callback, this, std::placeholders::_1));
        
        yao_subscription_ = this->create_subscription<std_msgs::msg::String>(
            "besad", 10,
            std::bind(&MaNode::yao_callback, this, std::placeholders::_1));
    }

private:
    void chao_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }
    
    void yao_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_ERROR(this->get_logger(), "%s", msg->data.c_str());
    }
    
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr chao_subscription_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr yao_subscription_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MaNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
