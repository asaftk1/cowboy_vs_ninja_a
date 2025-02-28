#pragma once

#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> m_members;

    public:
      
        Team(Character *initialMember) {}

        // Copy constructor
        Team(const Team &other) = delete;

        // Copy assignment operator
        Team &operator=(const Team &other) = delete;

        // Move constructor
        Team(Team &&other) noexcept
            : m_members(std::move(other.m_members))
        {
            other.m_members.clear();
        }

        // Move assignment operator
        Team &operator=(Team &&other) noexcept
        {
            if (this != &other)
            {
                m_members = std::move(other.m_members);
                other.m_members.clear();
            }
            return *this;
        }

        ~Team()
        {
            for (Character *member : m_members)
            {
                member = m_members.back();
                m_members.pop_back();
                delete member;
            }
        }

        void add(Character *member) {
            m_members.push_back(member);
        }

        static int stillAlive() { return 0; }

        void attack(Team *enemyTeam) {}

        void print() const {}

        void slash(Character *target) {}
    };
}