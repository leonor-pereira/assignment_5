// C++ assignment 5 neutrino cpp file - PHYS30762

#include "5_neutrino.h"

neutrino::neutrino(std::string neutrino_flavour, bool interaction_status)
{
  rest_mass = 0;
  charge = 0;
  if (neutrino_flavour == "electron_neutrino" || neutrino_flavour == "muon_neutrino" || neutrino_flavour == "tau_neutrino" || neutrino_flavour == "antielectron_neutrino" || neutrino_flavour == "antimuon_neutrino" || neutrino_flavour == "antitau_neutrino")
  {
    flavour = neutrino_flavour;
  }
  else
  {
    std::cout << "The flavour entered is invalid. Setting neutrino flavour to electron neutrino. " << std::endl;
    flavour = "electron_neutrino";
  }

  if (interaction_status == 0 || interaction_status == 1)
  {
    hasInteracted = interaction_status;
  }
  else
  {
    std::cout << "An invalid interaction status was entered. Setting interaction status to true. " << std::endl;
    hasInteracted = 1;
  }
};

void neutrino::set_neutrino_flavour(std::string neutrino_flavour)
{
  rest_mass = 0;
  charge = 0;
  if (neutrino_flavour == "electron_neutrino" || neutrino_flavour == "muon_neutrino" || neutrino_flavour == "tau_neutrino" || neutrino_flavour == "antielectron_neutrino" || neutrino_flavour == "antimuon_neutrino" || neutrino_flavour == "antitau_neutrino")
  {
    flavour = neutrino_flavour;
  }
  else
  {
    std::cout << "The flavour entered is invalid. Setting neutrino flavour to electron neutrino. " << std::endl;
    flavour = "electron_neutrino";
  }
};

void neutrino::set_neutrino_charge(int charge_value)
{
  rest_mass = 0;
  if (charge_value == 0)
  {
    charge = charge_value;
  }
  else
  {
    std::cout << "The charge value entered is invalid. Setting charge to 0. " << std::endl;
    charge = 0;
  }
};

void neutrino::set_interaction(bool interaction_value)
{
  rest_mass = 0;
  if (interaction_value == 1)
  {
    hasInteracted = interaction_value;
    std::cout << "The neutrino has interacted. " << std::endl;
  }
  else if (interaction_value == 0)
  {
    hasInteracted = interaction_value;
    std::cout << "The neutrino has not interacted. " << std::endl;
  }
  else
  {
    std::cout << "An invalid value was inputted. Setting interaction to true. " << std::endl;
    hasInteracted = 1;
  }
};

void neutrino::lepton_printing_function()
{
  lepton::lepton_printing_function();
  std::cout << "Interaction status: " << get_interaction() << ". \n" << std::endl;
};
