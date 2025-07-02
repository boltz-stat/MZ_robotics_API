// Copyright (c) 2023 MZrobotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <iostream>

#include <mzrobotics/exception.h>
#include <mzrobotics/robot.h>

/**
 * @example echo_robot_state.cpp
 * An example showing how to continuously read the robot state.
 */

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <robot-hostname>" << std::endl;
    return -1;
  }

  try {
    mzrobotics::Robot robot(argv[1]);

    size_t count = 0;
    robot.read([&count](const mzrobotics::RobotState& robot_state) {
      // Printing to std::cout adds a delay. This is acceptable for a read loop such as this, but
      // should not be done in a control loop.
      std::cout << robot_state << std::endl;
      return count++ < 100;
    });

    std::cout << "Done." << std::endl;
  } catch (mzrobotics::Exception const& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  return 0;
}
