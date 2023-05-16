#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
namespace ariel
{
    class Ninja :public Character
    {

        public:

        std::string print() const override { return "Hello"; }

        void move(Character *destination) {}

        void attack(Character *target) override {}

        void slash(Character *target) {}
    };

}
#endif