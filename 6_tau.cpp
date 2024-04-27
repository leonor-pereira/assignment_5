// C++ assignment 5 tau cpp file - PHYS30762

#include "6_tau.h"

tau::tau(std::string decay_type, int charge_value)
{
  rest_mass = 1777;
  if (decay_type == "hadronic")
  {
    decay_flag = decay_type;
    std::cout << "The tau is decaying hadronically. " << std::endl;
  }
  else if (decay_type == "leptonic")
  {
    decay_flag = decay_type;
    std::cout << "The tau is decaying leptonically. " << std::endl;
  }
  else
  {
    std::cout << "An invalid input was entered. Setting decay type to leptonic. " << std::endl;
    decay_flag = "leptonic";
  }

  if (charge_value==-1)
  {
    charge = charge_value;
    flavour = "tau";
  }
  else if (charge_value==+1)
  {
    charge = charge_value;
    flavour = "antitau";
  }
  else
  {
    std::cout << "Charge value inputted is invalid. Setting charge to -1. " << std::endl;
    charge = -1;
    flavour = "tau";        
  }   
};

void tau::set_decay_type(std::string type)
{
  rest_mass = 1777;
  if (type == "hadronic")
  {
    decay_flag = type;
    std::cout << "The tau is decaying hadronically. " << std::endl;
  }
  else if (type == "leptonic")
  {
    decay_flag = type;
    std::cout << "The tau is decaying leptonically. " << std::endl;
  }
  else
  {
    std::cout << "An invalid input was entered. Setting decay type to leptonic. " << std::endl;
    decay_flag = "leptonic";
  }
};

void tau::get_decay_products(std::string decay_flavour, four_momentum decay_product_4vec)
{
  rest_mass = 1777;
  std::vector<std::shared_ptr<lepton>> decay_products(3);

  if (decay_flag == "leptonic")
  {
    if (decay_flavour == "electron" && flavour == "tau")
    {
      std::cout << "The tau decayed into an electron, an antielectron neutrino and a tau neutrino. " << std::endl;
      std::shared_ptr<lepton> decayed_electron = std::make_shared<electron>(decay_product_4vec, 25, 50, 15, 10, -1);
      std::shared_ptr<lepton> decayed_antielectron_neutrino = std::make_shared<neutrino>("antielectron_neutrino", 0);
      std::shared_ptr<lepton> decayed_tauneutrino = std::make_shared<neutrino>("tau_neutrino", 0);

      decay_products.at(0) = decayed_electron;
      decay_products.at(1) = decayed_antielectron_neutrino;
      decay_products.at(2) = decayed_tauneutrino;

      decay_products_vector = decay_products;
    }
    else if (decay_flavour == "muon" && flavour == "tau")
    {
      std::cout << "The tau decayed into a muon, an antimuon neutrino and a tau neutrino. " << std::endl;
      std::shared_ptr<lepton> decayed_muon = std::make_shared<muon>("muon", 0);
      std::shared_ptr<lepton> decayed_antimuon_neutrino = std::make_shared<neutrino>("antimuon_neutrino", 0);
      std::shared_ptr<lepton> decayed_tau_neutrino = std::make_shared<neutrino>("tau_neutrino", 0);     

      decay_products.at(0) = decayed_muon;
      decay_products.at(1) = decayed_antimuon_neutrino;
      decay_products.at(2) = decayed_tau_neutrino;

      decay_products_vector = decay_products;
    }
  }
  else if (decay_flavour == "antielectron" && flavour == "antitau")
  {
      std::cout << "The antitau decayed into an antielectron, an electron neutrino and an antitau neutrino. " << std::endl;
      std::shared_ptr<lepton> decayed_antielectron = std::make_shared<electron>(decay_product_4vec, 25, 50, 15, 10, +1);
      std::shared_ptr<lepton> decayed_electron_neutrino = std::make_shared<neutrino>("electron_neutrino", 0);
      std::shared_ptr<lepton> decayed_antitau_neutrino = std::make_shared<neutrino>("antitau_neutrino", 0);

      decay_products.at(0) = decayed_antielectron;
      decay_products.at(1) = decayed_electron_neutrino;
      decay_products.at(2) = decayed_antitau_neutrino;

      decay_products_vector = decay_products;
  }
  else if (decay_flavour == "antimuon" && flavour == "antitau")
  {
      std::cout << "The antitau decayed into a antimuon, a muon neutrino and an antitau neutrino. " << std::endl;
      std::shared_ptr<lepton> decayed_antimuon = std::make_shared<muon>("antimuon", 0);
      std::shared_ptr<lepton> decayed_muon_neutrino = std::make_shared<neutrino>("muon_neutrino", 0);
      std::shared_ptr<lepton> decayed_antitau_neutrino = std::make_shared<neutrino>("antitau_neutrino", 0);     

      decay_products.at(0) = decayed_antimuon;
      decay_products.at(1) = decayed_muon_neutrino;
      decay_products.at(2) = decayed_antitau_neutrino;

      decay_products_vector = decay_products;
  }
  else
  {
    std::cout << "The decay flag is not leptonic, so no decay products can be obtained. " << std::endl;
  }
};

void tau::lepton_printing_function()
{
  lepton::lepton_printing_function();
  std::cout << "Decay flag: " << decay_flag << "." << std::endl;
  std::cout << "Printing decay product information. \n" << std::endl;
      
  for (int i = 0; i < decay_products_vector.size(); i++)
  {
    (decay_products_vector.at(i))->lepton_printing_function();
  }
};