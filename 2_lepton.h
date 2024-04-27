// C++ assignment 5 lepton header file - PHYS30762

#ifndef LEPTON_H
#define LEPTON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "1_four_momentum.h"

class lepton
{
  friend class electron;
  friend class muon;
  friend class tau;
  friend class neutrino;
  protected:
    int charge;
    float rest_mass;
    std::string flavour;
    four_momentum four_momentum_vector;
  public:
    lepton() = default;
    lepton(std::string lepton_flavour);
    ~lepton() {std::cout << "Calling lepton destructor... " << std::endl;};
    void set_four_momenta(four_momentum four_momentum_input){four_momentum_vector = four_momentum_input;};
    int get_charge() const {return charge;};
    float get_rest_mass() const {return rest_mass;};
    std::string get_flavour() const {return flavour;};
    four_momentum get_four_momenta() {return four_momentum_vector;};
    virtual void lepton_printing_function();
    friend std::vector<float> operator+(lepton particle_1, lepton particle_2);
    friend float dot_product(lepton particle_1, lepton particle_2);

    // copy constructor
    lepton(lepton &object);

    // assignment operator
    lepton & operator=(lepton &object);

    // move constructor
    lepton(lepton &&object) noexcept;

    // move operator
    lepton & operator=(lepton &&object);
};

#endif