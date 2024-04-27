// C++ assignment 5 main cpp file - PHYS30762

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"
#include "2_lepton.h"
#include "3_electron.h"
#include "4_muon.h"
#include "5_neutrino.h"
#include "6_tau.h"

int main()
{
  // creation of a four momentum object
  four_momentum four_vec_1;
  four_vec_1.set_e_px_py_pz(10, 9, 3, 2);

  // creation of objects going into the test vector
  std::shared_ptr<lepton> electron1 = std::make_shared<electron>(four_vec_1, 2.5, 2.5, 3, 2, -1);
  std::shared_ptr<lepton> electron2 = std::make_shared<electron>(four_vec_1, 2.5, 2.5, 3, 2, -1);
  std::shared_ptr<lepton> antielectron1 = std::make_shared<electron>(four_vec_1, 2.5, 2.5, 3, 2, +1);
  std::shared_ptr<lepton> muon1 = std::make_shared<muon>("muon", 1);
  std::shared_ptr<lepton> muon2 = std::make_shared<muon>("muon", 1);
  std::shared_ptr<lepton> muon3 = std::make_shared<muon>("muon", 1);
  std::shared_ptr<lepton> muon4 = std::make_shared<muon>("muon", 1);
  std::shared_ptr<lepton> antimuon1 = std::make_shared<muon>("antimuon", 1);
  std::shared_ptr<lepton> muon_neutrino1 = std::make_shared<neutrino>("muon_neutrino", 1);
  std::shared_ptr<lepton> electron_neutrino1 = std::make_shared<neutrino>("electron_neutrino", 0);
  std::shared_ptr<tau> tau1 = std::make_shared<tau>("leptonic", -1);
  std::shared_ptr<tau> antitau1 = std::make_shared<tau>("leptonic", +1);

  // decaying the taus - objects are accessible via the printing function
  tau1->get_decay_products("muon", four_vec_1);
  antitau1->get_decay_products("antielectron", four_vec_1);

  std::vector<std::shared_ptr<lepton>> particle_vector;
  particle_vector.push_back(electron1);
  particle_vector.push_back(electron2);
  particle_vector.push_back(muon1);
  particle_vector.push_back(muon2);
  particle_vector.push_back(muon3);
  particle_vector.push_back(muon4);
  particle_vector.push_back(antielectron1);
  particle_vector.push_back(antimuon1);
  particle_vector.push_back(muon_neutrino1);
  particle_vector.push_back(electron_neutrino1);
  particle_vector.push_back(tau1);
  particle_vector.push_back(antitau1);

  // printing of all information regardless of derived class
  for (int i = 0; i < particle_vector.size(); i++) {(particle_vector.at(i))->lepton_printing_function();}

  // sum of two electron's four vectors
  std::vector<float> four_vector_sum;
  four_vector_sum = *electron1 + *electron2;

  std::cout << "Printing four vector sum components. Energy: " << four_vector_sum.at(0) << "; px: " << four_vector_sum.at(1) << "; py: " << four_vector_sum.at(2) << "; pz: " << four_vector_sum.at(3) << ". \n" << std::endl;
  
  // adding four-momenta to the antielectron and antimuon
  antielectron1->set_four_momenta(four_vec_1);
  antimuon1->set_four_momenta(four_vec_1);

  // calculation of the dot product of the four-momenta of the antielectron and antimuon
  float dot_product_val;
  dot_product_val = dot_product(*antielectron1, *antimuon1);
  std::cout << "The dot product value is " << dot_product_val << ". " << std::endl;

  // copying unique pointer information from one electron to another
  std::unique_ptr<lepton> electron_copy = std::make_unique<electron>(four_vec_1, 3, 2, 1.5, 3.5, -1);
  std::unique_ptr<lepton> moved_electron = std::make_unique<electron>();
  moved_electron=std::move(electron_copy);

  // tau ownership by multiple variables
  std::shared_ptr<tau> shared_tau_source = std::make_shared<tau>("hadronic", -1);
  std::shared_ptr<tau> ownership_tau_1 = std::make_shared<tau>();
  std::shared_ptr<tau> ownership_tau_2 = std::make_shared<tau>();
  ownership_tau_1 = shared_tau_source;
  ownership_tau_2 = shared_tau_source;
}