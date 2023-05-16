#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"

namespace ariel
{
  class Cowboy : public Character
    {
    public:
        Cowboy(const std::string &name, const Point &location){}

        std::string print() const override{return "Hello";}

        void attack(Character *target) override{}

        void shoot(Character *target){}
        
        static bool hasboolets(){return true;}

        void reload(){};
    };
  
} 
#endif  // COWBOY_HPP
