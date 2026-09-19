#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "std_msgs/msg/string.hpp"

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);

    auto node = std::make_shared<rclcpp::Node>("publisher_node");

    RCLCPP_INFO(node->get_logger(),"Publisher node has been started.");

    auto publisher = node->create_publisher<std_msgs::msg::String>("topic",10);

    auto timer = node->create_wall_timer(
        std::chrono::seconds(1),
        [publisher]() {
            auto message = std_msgs::msg::String();
            message.data = "Hello, World!";
            publisher->publish(message);
        }
    );

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}