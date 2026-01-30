FROM osrf/ros:jazzy-desktop

# Locale (optional but nice)
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Create workspace
RUN mkdir -p /ws/src
WORKDIR /ws

# Install a trivial publisher/subscriber demo (we'll use our own package)
RUN apt-get update && apt-get install -y \
    ros-jazzy-demo-nodes-cpp \
    && rm -rf /var/lib/apt/lists/*

# Entrypoint: source setup and then run the provided command
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
