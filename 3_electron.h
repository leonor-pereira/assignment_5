// C++ assignment 5 electron header file - PHYS30762

#ifndef ELECTRON_H
#define ELECTRON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"
#include "2_lepton.h"

class electron: public lepton
{
  private:
    std::shared_ptr<std::vector<float>> energy_deposited = std::make_shared<std::vector<float>>(4);

  public:
    electron() = default;
    electron(four_momentum four_vec, float em_1_deposited, float em_2_deposited, float had_1_deposited, float had_2_deposited, int charge_value);
    ~electron() {std::cout << "Calling electron destructor... " << std::endl;};
    // setters and getters
    void set_energy_deposited(four_momentum four_vec, float em_1_deposited, float em_2_deposited, float had_1_deposited, float had_2_deposited);

    void set_electron_charge(int charge_value);
    void lepton_printing_function() override;
};

#endif