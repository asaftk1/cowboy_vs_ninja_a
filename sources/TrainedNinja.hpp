#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"
namespace ariel
{
     class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location){}

        // std::string print() const override{return "Hello";}
        // void attack(Character *target) override{}

        // void move(Character *destination) {}
        // void slash(Character *target){}
    };
} 
#endif  // TRAINEDNINJA_HPP
