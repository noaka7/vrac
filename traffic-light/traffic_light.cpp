#include "traffic_light.h"
#include <iostream>
using namespace std;

// public
TrafficLight::TrafficLight() {}
TrafficLight::TrafficLight(COLOUR_STATE state) {
  try {
    this->set_state(state);
  } catch (const InvalidStateException &e) {
    cout << "Error message: " << e.what() << endl;
  }
}
TrafficLight::TrafficLight(COUNTRY country) { this->set_country(country); }
TrafficLight::TrafficLight(COUNTRY country, COLOUR_STATE state) {
  this->set_country(country);
  try {
    this->set_state(state);
  } catch (const InvalidStateException &e) {
    cerr << "Error message: " << e.what() << endl;
  }
}
inline COUNTRY TrafficLight::get_country() const { return this->country; }
inline COLOUR_STATE TrafficLight::get_state() const { return this->state; }
inline int TrafficLight::count() const { return this->states.size(); }
void TrafficLight::set_state(COLOUR_STATE state) {
  if (this->states.cend() == this->states.find(state)) {
    throw InvalidStateException();
  } else {
    this->state = state;
  }
}
void TrafficLight::next() {
  switch (this->country) {
  case FRA:
    this->next_fra();
    break;
  case GBR:
    this->next_gbr();
    break;
  default:
    break;
  }
};

// private
void TrafficLight::set_country(COUNTRY country) {
  this->country = country;
  switch (country) {
  case FRA:
    this->states = {RED, GREEN, YELLOW};
    this->state = RED;
    break;
  case GBR:
    this->states = {RED, RED_YELLOW, GREEN, YELLOW};
    this->state = RED;
    break;
  default:
    break;
  }
}
void TrafficLight::next_fra() {
  switch (this->state) {
  case RED:
    this->state = GREEN;
    break;
  case GREEN:
    this->state = YELLOW;
    break;
  case YELLOW:
    this->state = RED;
    break;
  default:
    break;
  }
}
void TrafficLight::next_gbr() {
  switch (this->state) {
  case RED:
    this->state = RED_YELLOW;
    break;
  case RED_YELLOW:
    this->state = GREEN;
    break;
  case GREEN:
    this->state = YELLOW;
    break;
  case YELLOW:
    this->state = RED;
    break;
  default:
    break;
  }
}

ostream &operator<<(ostream &out, const COLOUR_STATE &colour) {
  string s;
  switch (colour) {
  case RED:
    s = "RED";
    break;
  case GREEN:
    s = "GREEN";
    break;
  case YELLOW:
    s = "YELLOW";
    break;
  case RED_YELLOW:
    s = "RED AND YELLOW";
    break;
  case BLUE:
    s = "BLUE";
    break;
  default:
    s = "";
    break;
  }
  return out << s;
}

void test_traffic_light_set_state() {
  TrafficLight light(FRA);
  COLOUR_STATE c;
  cout << "Test set state. Country: " << light.get_country() << endl;
  cout << "State: " << light.get_state() << endl;
  try {
    c = BLUE;
    cout << "Try to set invalid state: " << c << endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    cerr << "Error message: " << e.what() << endl;
  }
  cout << "State: " << light.get_state() << endl;
  try {
    c = GREEN;
    cout << "Try to set valid state: " << c << endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    cerr << "Error message: " << e.what() << endl;
  }
  cout << "State: " << light.get_state() << endl;
}

int main() {
  for (int i = 0; i < NB_OF_COUNTRY; i++) {
    TrafficLight traffic_light = TrafficLight(static_cast<COUNTRY>(i));
    cout << "country " << traffic_light.get_country() << endl;
    for (int j = 0; j <= traffic_light.count(); j++) {
      cout << traffic_light.get_state() << endl;
      traffic_light.next();
    }
  }
  test_traffic_light_set_state();
  return 0;
}
