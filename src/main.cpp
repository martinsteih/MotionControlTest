#include <iostream>
#include "Measurement.h"

using namespace std;
int main(int argc, char** argv) {
  Sensor sens;
  double test;

  Measurement meas(sens, test);
  while (!meas.isDone())
    ;
  cout << "Done\n";

  return 0;
}
