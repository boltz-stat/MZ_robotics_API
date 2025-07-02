// Copyright (c) 2023 MZrobotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <chrono>
#include <iostream>
#include <thread>

#include <mzrobotics/active_control.h>
#include <mzrobotics/active_torque_control.h>
#include <mzrobotics/duration.h>
#include <mzrobotics/exception.h>
#include <mzrobotics/robot.h>

#include "examples_common.h"

/**
 * @example communication_test.cpp
 * An example indicating the network performance.
 *
 * @warning Before executing this example, make sure there is enough space in front of the robot.
 */

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <robot-hostname>" << std::endl;
    return -1;
  }

  uint64_t counter = 0;
  double avg_success_rate = 0.0;
  double min_success_rate = 1.0;
  double max_success_rate = 0.0;
  uint64_t time = 0;
  std::cout.precision(2);
  std::cout << std::fixed;

  try {
    mzrobotics::Robot robot(argv[1]);
    setDefaultBehavior(robot);

    // First move the robot to a suitable joint configuration
    std::array<double, 7> q_goal = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};
    MotionGenerator motion_generator(0.5, q_goal);
    std::cout << "WARNING: This example will move the robot! "
              << "Please make sure to have the user stop button at hand!" << std::endl
              << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
    robot.control(motion_generator);
    std::cout << "Finished moving to initial joint configuration." << std::endl << std::endl;
    std::cout << "Starting communication test." << std::endl;

    robot.set
