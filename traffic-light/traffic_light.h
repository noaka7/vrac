#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <exception>
#include <ostream>
#include <unordered_set>

typedef enum {
  RED,
  GREEN,
  YELLOW,
  RED_YELLOW,
  BLUE,
  NB_OF_COLOUR_STATE
} COLOUR_STATE;

typedef enum { FRA, GBR, NB_OF_COUNTRY } COUNTRY;

struct InvalidStateException : public std::exception {
  const char *what() const throw() { return "Invalid state"; }
};

class TrafficLight {
public:
  TrafficLight();
  TrafficLight(COUNTRY);
  TrafficLight(COLOUR_STATE);
  TrafficLight(COUNTRY, COLOUR_STATE);
  COUNTRY get_country() const;
  COLOUR_STATE get_state() const;
  int count() const;
  void set_state(COLOUR_STATE);
  void next();

private:
  // COUNTRY country = static_cast<COUNTRY>(0);
  // COLOUR_STATE state = static_cast<COLOUR_STATE>(0);
  // std::unordered_set<COLOUR_STATE> states = {RED, GREEN, YELLOW};
  COUNTRY country;
  COLOUR_STATE state;
  std::unordered_set<COLOUR_STATE> states;
  void set_country(COUNTRY);
  void next_fra();
  void next_gbr();
};

std::ostream &operator<<(std::ostream &, const COLOUR_STATE &);

#endif /* TRAFFIC_LIGHT_H */
