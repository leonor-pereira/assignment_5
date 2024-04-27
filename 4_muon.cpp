// C++ assignment 5 muon cpp file - PHYS30762

#include "4_muon.h"

muon::muon(std::string muon_flavour, bool isolation_status)
{
  rest_mass = 106; // to closest mev

  if (muon_flavour == "muon")
  {
    flavour = muon_flavour;
    charge = -1;
  }
  else if (muon_flavour == "antimuon")
  {
    flavour = muon_flavour;
    charge = +1;
  }
  else
  {
    std::cout << "Flavour inputted is invalid. Setting flavour to muon. " << std::endl;
    charge = -1;
    flavour = "muon";           
  }

  if (isolation_status == 1)
  {
    isolation = isolation_status;
    std::cout << "The muon is isolated. " << std::endl;
  }
  else if (isolation_status == 0)
  {
    isolation = isolation_status;
    std::cout << "The muon is not isolated. " << std::endl;
  }
  else
  {
    std::cout << "An invalid value was inputted. Setting isolation to true. " << std::endl;
    isolation = 1;
  }
};

void muon::set_isolation(bool isolation_value)
{
  rest_mass = 106; // to closest mev
  if (isolation_value == 1)
  {
    isolation = isolation_value;
    std::cout << "The muon is isolated. " << std::endl;
  }
  else if (isolation_value == 0)
  {
    isolation = isolation_value;
    std::cout << "The muon is not isolated. " << std::endl;
  }
  else
  {
    std::cout << "An invalid value was inputted. Setting isolation to true. " << std::endl;
    isolation = 1;
  }
};

void muon::set_muon_charge(int charge_value)
{
  rest_mass = 106; // to closest mev
  if (charge_value==-1)
  {
    charge = charge_value;
    flavour = "muon";
  }
  else if (charge_value==+1)
  {
    charge = charge_value;
    flavour = "antimuon";
  }
  else
  {
    std::cout << "Charge value inputted is invalid. Setting charge to -1. " << std::endl;
    charge = -1;
    flavour = "muon";        
  }
};

void muon::set_muon_flavour(std::string muon_flavour)
{
  rest_mass = 106; // to closest mev
  if (muon_flavour == "muon")
  {
    flavour = muon_flavour;
    charge = -1;
  }
  else if (muon_flavour == "antimuon")
  {
    flavour = muon_flavour;
    charge = +1;
  }
  else
  {
    std::cout << "Flavour inputted is invalid. Setting flavour to muon. " << std::endl;
    charge = -1;
    flavour = "muon";           
  }
};

void muon::lepton_printing_function()
{
  lepton::lepton_printing_function();
  std::cout << "Isolation status: " << isolation << ". \n" << std::endl;
};
