// C++ assignment 5 four momentum cpp file - PHYS30762

#include "1_four_momentum.h"

four_momentum::four_momentum(float energy, float px, float py, float pz)
{
  if(energy > 0)
  {
    (*four_momentum_vector).at(0) = energy;
    (*four_momentum_vector).at(1) = px;
    (*four_momentum_vector).at(2) = py;
    (*four_momentum_vector).at(3) = pz;
  }
  else
  {
    std::cout << "The energy value entered is smaller or equal to zero. Setting the energy to 50 GeV. " << std::endl;

    (*four_momentum_vector).at(0) = 50;
    (*four_momentum_vector).at(1) = px;
    (*four_momentum_vector).at(2) = py;
    (*four_momentum_vector).at(3) = pz;
  }
};

void four_momentum::set_e_px_py_pz(float energy, float px, float py, float pz)
{
  if(energy > 0)
  {
    (*four_momentum_vector).at(0) = energy;
    (*four_momentum_vector).at(1) = px;
    (*four_momentum_vector).at(2) = py;
    (*four_momentum_vector).at(3) = pz;
  }
  else
  {
    std::cout << "The energy value entered is smaller or equal to zero. Setting the energy to 50 GeV. " << std::endl;
    (*four_momentum_vector).at(0) = 50;
    (*four_momentum_vector).at(1) = px;
    (*four_momentum_vector).at(2) = py;
    (*four_momentum_vector).at(3) = pz;
  }
};

void four_momentum::set_e(float energy)
{
  if(energy > 0)
  {
    (*four_momentum_vector).at(0) = energy;
  }
  else
  {
    std::cout << "The energy value entered is smaller or equal to zero. Setting the energy to 50 GeV. " << std::endl;
    (*four_momentum_vector).at(0) = 50;
  }
};

// copy constructor
four_momentum::four_momentum(four_momentum &object)
{
  std::cout << "Calling copy constructor... " << std::endl;

  std::shared_ptr<std::vector<float>> four_momentum_copy = std::make_shared<std::vector<float>>(4);
  set_e_px_py_pz(object.get_energy(), object.get_px(), object.get_py(), object.get_pz());
};

// assignment operator
four_momentum & four_momentum::operator=(const four_momentum &object)
{
  std::cout << "Calling copy assignment... " << std::endl;

  if(&object == this) {return *this;}
  else
  {
    std::shared_ptr<std::vector<float>> four_momentum_copy = std::make_shared<std::vector<float>>(4);

    set_e_px_py_pz(object.get_energy(), object.get_px(), object.get_py(), object.get_pz());
  }

  return *this;
};

// move constructor
four_momentum::four_momentum(four_momentum &&object) noexcept
{
  std::cout << "Calling move constructor... " << std::endl;

  (*four_momentum_vector).at(0) = object.get_energy();
  (*four_momentum_vector).at(1) = object.get_px();
  (*four_momentum_vector).at(2) = object.get_py();
  (*four_momentum_vector).at(3) = object.get_pz();

  object.four_momentum_vector = nullptr;
};

// move operator
four_momentum & four_momentum::operator=(four_momentum &&object)
{
  std::cout << "Calling move assignment... " << std::endl;

  std::swap(four_momentum_vector, object.four_momentum_vector);
  object.four_momentum_vector = nullptr;

  return *this;
};