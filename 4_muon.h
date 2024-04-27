// C++ assignment 5 muon header file - PHYS30762

#ifndef MUON_H
#define MUON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"
#include "2_lepton.h"

class muon: public lepton
{
  private:
    bool isolation;

  public:
    muon() = default;
    muon(std::string muon_flavour, bool isolation_status);
    ~muon() {std::cout << "Calling muon destructor... " << std::endl;};
    void set_isolation(bool isolation_value);
    void set_muon_charge(int charge_value);
    void set_muon_flavour(std::string muon_flavour);
    bool get_isolation() const {return isolation;};
    void lepton_printing_function();
};

#endif