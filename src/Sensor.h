#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
 public:
  int getNumberOfMeasurements() const { return _number_of_measurements; }

 private:
  int _number_of_measurements{3600};
  double _current_value{156.3};
};

#endif
