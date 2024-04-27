// C++ assignment 5 tau header file - PHYS30762

#ifndef TAU_H
#define TAU_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"
#include "2_lepton.h"
#include "3_electron.h"
#include "4_muon.h"
#include "5_neutrino.h"

class tau: public lepton
{
  private:
    std::string decay_flag;
    std::vector<std::shared_ptr<lepton>> decay_products_vector;

  public:
    tau() = default;
    tau(std::string decay_type, int charge_value);
    ~tau() {std::cout << "Calling tau destructor... " << std::endl;};
    void set_decay_type(std::string type);
    void get_decay_products(std::string decay_flavour, four_momentum decay_product_4vec);
    void lepton_printing_function() override;
};

#endif