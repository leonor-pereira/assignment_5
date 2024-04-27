// C++ assignment 5 electron cpp file - PHYS30762

#include "3_electron.h"

electron::electron(four_momentum four_vec, float em_1_deposited, float em_2_deposited, float had_1_deposited, float had_2_deposited, int charge_value)
{
  rest_mass = 1; // to closest mev
  float energy_sum;
  energy_sum = em_1_deposited + em_2_deposited + had_1_deposited + had_2_deposited;

  if (energy_sum == four_vec.get_energy())
  {
    four_momentum_vector = four_vec;
    (*energy_deposited).at(0) = em_1_deposited;
    (*energy_deposited).at(1) = em_2_deposited;
    (*energy_deposited).at(2) = had_1_deposited;
    (*energy_deposited).at(3) = had_2_deposited;
  }
  else
  {
    float correcting_factor = (four_vec.get_energy())/energy_sum;
    (*energy_deposited).at(0) = em_1_deposited*correcting_factor;
    (*energy_deposited).at(1) = em_2_deposited*correcting_factor;
    (*energy_deposited).at(2) = had_1_deposited*correcting_factor;
    (*energy_deposited).at(3) = had_2_deposited*correcting_factor;
  }

  if (charge_value==-1)
  {
    charge = charge_value;
    flavour = "electron";
  }
  else if (charge_value==+1)
  {
    charge = charge_value;
    flavour = "antielectron";
  }
  else
  {
    std::cout << "Charge value inputted is invalid. Setting charge to -1. " << std::endl;
    charge = -1;
    flavour = "electron";        
  }
};

// setters and getters
void electron::set_energy_deposited(four_momentum four_vec, float em_1_deposited, float em_2_deposited, float had_1_deposited, float had_2_deposited)
{
  rest_mass = 1; // to closest mev
  float energy_sum;
  energy_sum = em_1_deposited + em_2_deposited + had_1_deposited + had_2_deposited;

  if (energy_sum == four_vec.get_energy())
  {
    (*energy_deposited).at(0) = em_1_deposited;
    (*energy_deposited).at(1) = em_2_deposited;
    (*energy_deposited).at(2) = had_1_deposited;
    (*energy_deposited).at(3) = had_2_deposited;
  }
  else
  {
    std::cout << "The four vector entered and the deposited energies do not match. Correcting values. " << std::endl;
    float correcting_factor = (four_vec.get_energy())/energy_sum;
    (*energy_deposited).at(0) = em_1_deposited*correcting_factor;
    (*energy_deposited).at(1) = em_2_deposited*correcting_factor;
    (*energy_deposited).at(2) = had_1_deposited*correcting_factor;
    (*energy_deposited).at(3) = had_2_deposited*correcting_factor;
  }
};

void electron::set_electron_charge(int charge_value)
{
  rest_mass = 1; // to closest mev65
  if (charge_value==-1)
  {
    charge = charge_value;
    flavour = "electron";
  }
  else if (charge_value==+1)
  {
    charge = charge_value;
    flavour = "antielectron";
  }
  else
  {
    std::cout << "Charge value inputted is invalid. Setting charge to -1. " << std::endl;
    charge = -1;
    flavour = "electron";        
  }
};

void electron::lepton_printing_function()
{
  lepton::lepton_printing_function();
  std::cout << "Printing electron four-momenta. Energy: " << four_momentum_vector.get_energy() << "; px: " << four_momentum_vector.get_px() << "; py: " << four_momentum_vector.get_py() << "; pz: "  << four_momentum_vector.get_pz() << ". " << std::endl;
  std::cout << "Printing energy deposited in calorimeter. Electromagnetic 1st layer component: " << (*energy_deposited).at(0) << "; electromagnetic 2nd layer component: " << (*energy_deposited).at(1) << "; hadronic 1st layer component: " << (*energy_deposited).at(2) << "; hadronic 2nd layer component: " << (*energy_deposited).at(3) << ". \n" << std::endl;
};
