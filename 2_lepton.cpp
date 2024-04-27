// C++ assignment 5 lepton cpp file - PHYS30762

#include "2_lepton.h"

lepton::lepton(std::string lepton_flavour)
{
  if (lepton_flavour == "electron" || lepton_flavour == "muon" || lepton_flavour == "tau")
  {
    flavour = lepton_flavour;
    charge = -1;
  }
  else if (lepton_flavour == "antielectron" || lepton_flavour == "antimuon" || lepton_flavour == "antitau")
  {
    flavour = lepton_flavour;
    charge = 1;        
  }
  else if (lepton_flavour == "electron_neutrino" || lepton_flavour == "muon_neutrino" || lepton_flavour == "tau_neutrino" || lepton_flavour == "antielectron_neutrino" || lepton_flavour == "antimuon_neutrino" || lepton_flavour == "antitau_neutrino")
  {
    flavour = lepton_flavour;
    charge = 0;
  }
  else
  {
    std::cout << "The flavour entered is invalid. Setting flavour to electron. " << std::endl;
    flavour = "electron";
    charge = -1;
  }
};

void lepton::lepton_printing_function()
{
  std::cout << "Printing lepton data. " << std::endl;
  std::cout << "Charge: " << get_charge() << "; flavour: " << get_flavour() << "; rest mass: " << get_rest_mass() << " MeV." << std::endl;
}

std::vector<float> operator+(lepton particle_1, lepton particle_2)
{
  four_momentum four_vec_1 = particle_1.get_four_momenta();
  four_momentum four_vec_2 = particle_2.get_four_momenta();

  std::vector<float> summed_four_vec(4);

  summed_four_vec.at(0) = four_vec_1.get_energy() + four_vec_2.get_energy();
  summed_four_vec.at(1) = four_vec_1.get_px() + four_vec_2.get_px();
  summed_four_vec.at(2) = four_vec_1.get_py() + four_vec_2.get_py();
  summed_four_vec.at(3) = four_vec_1.get_pz() + four_vec_2.get_pz();

  return summed_four_vec;
};


float dot_product(lepton particle_1, lepton particle_2)
{
  four_momentum four_vec_1 = particle_1.get_four_momenta();
  four_momentum four_vec_2 = particle_2.get_four_momenta();

  float dot_product_value;

  dot_product_value = (four_vec_1.get_energy()*four_vec_2.get_energy()) - (((four_vec_1.get_px())*(four_vec_2.get_px())) + ((four_vec_1.get_py())*(four_vec_2.get_py())) + ((four_vec_1.get_pz())*(four_vec_2.get_pz())));
  return dot_product_value;
};

// copy constructor
lepton::lepton(lepton &object)
{
  std::cout << "Calling copy constructor... " << std::endl;

  std::shared_ptr<lepton> lepton_copy = std::make_shared<lepton>(object.get_flavour());
  set_four_momenta(object.get_four_momenta());
};

// assignment operator
lepton & lepton::operator=(lepton &object)
{
  std::cout << "Calling copy assignment... " << std::endl;

  if(&object == this) {return *this;}
  else
  {
    std::shared_ptr<lepton> lepton_copy = std::make_shared<lepton>(object.get_flavour());
    set_four_momenta(object.get_four_momenta());
  }
  return *this;
}

// move constructor
lepton::lepton(lepton &&object) noexcept
{
  std::cout << "Calling move constructor... " << std::endl;

  flavour = object.get_flavour();
  charge = object.get_charge();
  rest_mass = object.get_rest_mass();
  four_momentum_vector = object.get_four_momenta();

  four_momentum empty_4_vec(0, 0, 0, 0);
  object.set_four_momenta(empty_4_vec);
};

// move operator
lepton & lepton::operator=(lepton &&object)
{
  std::cout << "Calling move assignment... " << std::endl;

  std::swap(flavour, object.flavour);
  std::swap(charge, object.charge);
  std::swap(rest_mass, object.rest_mass);
  std::swap(four_momentum_vector, object.four_momentum_vector);

  four_momentum empty_4_vec(0, 0, 0, 0);
  object.set_four_momenta(empty_4_vec);

  return *this;
};