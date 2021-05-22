#include "traffic_light.h"
#include <iostream>

// public
TrafficLight::TrafficLight() {}
TrafficLight::TrafficLight(COLOUR_STATE state) {
  try {
    this->set_state(state);
  } catch (const InvalidStateException &e) {
    std::cout << "Error message: " << e.what() << std::endl;
  }
}
TrafficLight::TrafficLight(COUNTRY country) { this->set_country(country); }
TrafficLight::TrafficLight(COUNTRY country, COLOUR_STATE state) {
  this->set_country(country);
  try {
    this->set_state(state);
  } catch (const InvalidStateException &e) {
    std::cerr << "Error message: " << e.what() << std::endl;
  }
}
COUNTRY TrafficLight::get_country() const { return this->country; }
COLOUR_STATE TrafficLight::get_state() const { return this->state; }
int TrafficLight::count() const { return this->states.size(); }
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

std::ostream &operator<<(std::ostream &out, const COLOUR_STATE &colour) {
  std::string s;
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
