// C++ assignment 5 four momentum header file - PHYS30762

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

const double electron_charge = -1.6e-19; // coulombs
const double speed_of_light = 2.99792458e8; // m/s
const double electron_mass = 1; // to the nearest mev
const double muon_mass = 106; // to the nearest mev

class four_momentum
{
  private:
    std::shared_ptr<std::vector<float>> four_momentum_vector = std::make_shared<std::vector<float>>(4);

  public:
    // constructors and member functions
    four_momentum() = default;
    four_momentum(float energy, float px, float py, float pz);
    ~four_momentum() {std::cout << "Calling destructor..." << std::endl;};
    void set_e_px_py_pz(float energy, float px, float py, float pz);
    void set_e(float energy);
    void set_px(float px){(*four_momentum_vector).at(1) = px;};
    void set_py(float py){(*four_momentum_vector).at(2) = py;};
    void set_pz(float pz){(*four_momentum_vector).at(3) = pz;};
    float get_energy() const {return (*four_momentum_vector).at(0);};
    float get_px() const {return (*four_momentum_vector).at(1);};
    float get_py() const {return (*four_momentum_vector).at(2);};
    float get_pz() const {return (*four_momentum_vector).at(3);};

    // copy constructor
    four_momentum(four_momentum &object);

    // assignment operator
    four_momentum & operator=(const four_momentum &object);

    // move constructor
    four_momentum(four_momentum &&object) noexcept;

    // move operator
    four_momentum & operator=(four_momentum &&object);
};

#endif