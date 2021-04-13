#include <exception>
#include <iostream>
#include <list>
using namespace std;

enum class colour { red, green, yellow, red_yellow, blue };
enum class country { fra, gbr, ncr };

struct InvalidStateException : public std::exception {
  const char *what() const throw() { return "Invalid state"; }
};

class TrafficLight {
public:
  TrafficLight() {}
  TrafficLight(colour state) {
    try {
      this->set_state(state);
    } catch (const InvalidStateException &e) {
      cerr << "Error message: " << e.what() << endl;
    }
  }
  TrafficLight(country country) { this->set_country(country); };
  TrafficLight(country country, colour state) {
    this->set_country(country);
    try {
      this->set_state(state);
    } catch (const InvalidStateException &e) {
      cerr << "Error message: " << e.what() << endl;
    }
  };
  country get_country() const { return this->country; };
  colour get_state() const { return *(this->state); };
  unsigned int size() const { return this->sequence.size(); }
  void set_state(const colour &state) {
    if (this->contains(state)) {
      while (state != this->get_state()) {
        this->next();
      }
    } else {
      throw InvalidStateException();
    }
  }
  void next() {
    this->state++;
    if (sequence.cend() == this->state) {
      this->state = sequence.begin();
    }
  };

private:
  country country;
  list<colour>::iterator state;
  list<colour> sequence;
  void set_country(enum country country) {
    this->country = country;
    switch (country) {
    case country::fra:
      sequence = {colour::red, colour::green, colour::yellow};
      state = sequence.begin();
      break;
    case country::gbr:
      sequence = {colour::red, colour::red_yellow, colour::green,
                  colour::yellow};
      state = sequence.begin();
      break;
    default:
      break;
    }
  }
  bool contains(const colour &c) const {
    for (auto it = this->sequence.begin(); this->sequence.cend() != it; it++) {
      if (c == *it) {
        return true;
      }
    }
    return false;
  }
};

ostream &operator<<(ostream &out, const colour &colour) {
  string s;
  switch (colour) {
  case colour::red:
    s = "RED";
    break;
  case colour::green:
    s = "GREEN";
    break;
  case colour::yellow:
    s = "YELLOW";
    break;
  case colour::red_yellow:
    s = "RED AND YELLOW";
    break;
  case colour::blue:
    s = "BLUE";
    break;
  default:
    s = "";
    break;
  }
  return out << s;
}

ostream &operator<<(ostream &out, const country &country) {
  string s;
  switch (country) {
  case country::fra:
    s = "FRA";
    break;
  case country::gbr:
    s = "GBR";
    break;
  case country::ncr:
    s = "NCR";
    break;
  default:
    s = "";
    break;
  }
  return out << s;
}

int main() {
  for (int i = 0; i < static_cast<int>(country::ncr); i++) {
    TrafficLight light(static_cast<country>(i));
    cout << "country " << light.get_country() << endl;
    for (int i = 0; i <= light.size(); i++) {
      cout << light.get_state() << endl;
      light.next();
    }
  }
  /* Test set_state */
  TrafficLight light(country::fra);
  colour c;
  cout << "Test set state. Country: " << light.get_country() << endl;
  cout << "Current state: " << light.get_state() << endl;
  try {
    c = colour::blue;
    cout << "Try to set invalid state: " << c << endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    cerr << "Error message: " << e.what() << endl;
  }
  cout << "Current state: " << light.get_state() << endl;
  try {
    c = colour::green;
    cout << "Try to set valid state: " << c << endl;
    light.set_state(c);
  } catch (const InvalidStateException &e) {
    cerr << "Error message: " << e.what() << endl;
  }
  cout << "Current state: " << light.get_state() << endl;
  /* end test */
  return 0;
}
