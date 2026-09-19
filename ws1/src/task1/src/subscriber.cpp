#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "std_msgs/msg/string.hpp"

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<rclcpp::Node>("subscriber_node");
    RCLCPP_INFO(node->get_logger(),"Subscriber node has been started.");
    auto subscription 
            = node->create_subscription<std_msgs::msg::String>(
            "topic",
            10,
            [node](std_msgs::msg::String::ConstSharedPtr msg) {
                RCLCPP_INFO(node->get_logger(),"Received: '%s'",msg->data.c_str());
            }
            );
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
    }