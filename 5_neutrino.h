// C++ assignment 5 neutrino header file - PHYS30762

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"
#include "2_lepton.h"

class neutrino: public lepton
{
  private:
    bool hasInteracted;
  public:
    neutrino() = default;
    neutrino(std::string neutrino_flavour, bool interaction_status);
    ~neutrino() {std::cout << "Calling neutrino destructor... " << std::endl;};
    void set_neutrino_flavour(std::string neutrino_flavour);
    void set_neutrino_charge(int charge_value);
    void set_interaction(bool interaction_value);
    bool get_interaction() const {return hasInteracted;};
    void lepton_printing_function() override;
};

#endif