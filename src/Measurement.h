#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <math.h>
#include <complex>
#include <thread>
#include <vector>
#include "Sensor.h"

using namespace std;

class Measurement {
 public:
  Measurement(const Sensor& sensor, const double& axis_position)
      : _sensor{sensor}, _axis{axis_position}, _values{} {
    _values.reserve(sensor.getNumberOfMeasurements());
    runner = thread{[&]() {
      for (volatile long int i{0}; i < 5000000000; ++i)
	;
      for (int i{0}; i < _values.capacity(); ++i) {
	_values.push_back(complex<double>(sin(i), i));
      }
    }};
  }

  ~Measurement() {
    if (runner.joinable())
      runner.join();
  }

  bool isDone() const {
    return _values.size() == _sensor.getNumberOfMeasurements() ? true : false;
  }

 private:
  const Sensor& _sensor;
  const double& _axis;
  vector<complex<double>> _values;
  thread runner;
};

#endif
