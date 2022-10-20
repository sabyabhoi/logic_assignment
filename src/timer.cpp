#include "timer.hpp"

Timer::Timer() {
  startTimepoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
  stop();
}

void Timer::stop() {
  auto endTimepoint = std::chrono::high_resolution_clock::now();

  auto start =
	  std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint)
		  .time_since_epoch()
		  .count();
  auto end =
	  std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
		  .time_since_epoch()
		  .count();

  auto duration = end - start;
  double ms = duration * 0.001;
  std::cout << duration << "us\n";
}
