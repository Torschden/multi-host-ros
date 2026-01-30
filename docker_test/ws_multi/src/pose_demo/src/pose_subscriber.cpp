#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

class PoseSubscriber : public rclcpp::Node
{
public:
  PoseSubscriber() : Node("pose_subscriber")
  {
    sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
      "/detected_object_pose", 10,
      [this](geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        RCLCPP_INFO(
          this->get_logger(),
          "Pose: [%.2f, %.2f, %.2f]",
          msg->pose.position.x,
          msg->pose.position.y,
          msg->pose.position.z);
      });
  }

private:
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr sub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PoseSubscriber>());
  rclcpp::shutdown();
  return 0;
}
