
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

using namespace std::chrono_literals;

class PosePublisher : public rclcpp::Node
{
public:
  PosePublisher() : Node("pose_publisher")
  {
    pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
      "/detected_object_pose", 10);

    timer_ = this->create_wall_timer(500ms, [this]() {
      geometry_msgs::msg::PoseStamped msg;
      msg.header.stamp = this->get_clock()->now();
      msg.header.frame_id = "world";
      msg.pose.position.x = 1.0;
      msg.pose.position.y = 2.0;
      msg.pose.position.z = 0.5;
      msg.pose.orientation.w = 1.0;

      pub_->publish(msg);
    });
  }

private:
  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PosePublisher>());
  rclcpp::shutdown();
  return 0;
}
