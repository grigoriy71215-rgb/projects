#include <iostream>
#include <memory>

template <typename Derived> class ElectricalAppliance {
private:
  int power = 0;

public:
  ElectricalAppliance() { static_cast<Derived *>(this)->whoAmI(); }
  ElectricalAppliance(int power) : power(power) {
    static_cast<Derived *>(this)->whoAmI();
  }

  ~ElectricalAppliance() = default;

  int getPower() const { return power; }
  void whoAmI() { std::cout << "I am electrical appliance\n"; }
};

class SmartPhone : public ElectricalAppliance<SmartPhone> {
public:
  SmartPhone() {}
  SmartPhone(int power) : ElectricalAppliance<SmartPhone>(power) {}

  void whoAmI() { std::cout << "I am smartphone\n"; }
};

class Flatiron : public ElectricalAppliance<Flatiron> {
public:
  Flatiron() {}
  Flatiron(int power) : ElectricalAppliance<Flatiron>(power) {}

  void whoAmI() { std::cout << "I am flatiron\n"; }
};

int main(int argc, char *argv[]) {
  int smartPhonePower = 10;
  SmartPhone *smartphone = new SmartPhone(smartPhonePower);
  int flatironPower = 1000;
  Flatiron *flatiron = new Flatiron(flatironPower);
  delete smartphone;
  delete flatiron;
  return 0;
}
