
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <iostream>

namespace ariel
{
    class Character
    {
    private:
        std::string m_name;
        Point m_location;
        int stricks=0;

    public:
        Character() = default;
        virtual ~Character() = default;
        // Character(const std::string &name, const Point &location)
        //     : m_name(name), m_location(location), stricks(0)
        // {
        // }
        // Automatically generated special member functions
        Character(const Character &) = default;                 // Copy constructor
        Character &operator=(const Character &other) = default; // Copy assignment operator
        Character(Character &&other) = default;                 // Move constructor
        Character &operator=(Character &&) = default;
        virtual std::string print() const = 0;
        virtual void attack(Character *target) = 0;
        virtual bool isAlive() { return false; }
        virtual double distance(Character *other) { return 0.0; }
        virtual void hit(int descore) {}
        virtual std::string getName() { return m_name; }
        virtual Point getLocation() { return m_location; }
    };
}
#endif // CHARACTER_HPP
