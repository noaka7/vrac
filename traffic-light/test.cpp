#include "traffic_light.h"
#include <iostream>

void test_traffic_light_set_state() {
  TrafficLight light(FRA);
  COLOUR_STATE c;
  std::cout << "Test set state. Country: " << light.get_country() << std::endl;
  std::cout << "State: " << light.get_state() << std::endl;
  try {
    c = BLUE;
    std::cout << "Try to set invalid state: " << c << std::endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    std::cerr << "Error message: " << e.what() << std::endl;
  }
  std::cout << "State: " << light.get_state() << std::endl;
  try {
    c = GREEN;
    std::cout << "Try to set valid state: " << c << std::endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    std::cerr << "Error message: " << e.what() << std::endl;
  }
  std::cout << "State: " << light.get_state() << std::endl;
}

int main() {
  for (int i = 0; i < NB_OF_COUNTRY; i++) {
    TrafficLight traffic_light = TrafficLight(static_cast<COUNTRY>(i));
    std::cout << "country " << traffic_light.get_country() << std::endl;
    for (int j = 0; j <= traffic_light.count(); j++) {
      std::cout << traffic_light.get_state() << std::endl;
      traffic_light.next();
    }
  }
  test_traffic_light_set_state();
  return 0;
}
