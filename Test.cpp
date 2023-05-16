#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>

using namespace ariel;

TEST_SUITE("Point class tests")
{

    Point p1(0.5, 0.5);
    Point p2(-1, 0.5);
    Point p3(1.5, 0.5);
    Point p4(1, 2);
    Point p5(4, 6);
    Point p6(-1.5, 0.5);

    TEST_CASE("distance function: ")
    {
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_NE(p1.distance(p3), p1.distance(p6));
        CHECK_GT(p1.distance(p2), 0);
        CHECK_EQ(p1.distance(p2), 1.5);
        CHECK_EQ(p1.distance(p3), 1);
    }

    TEST_CASE("moveTowards function")
    {
        double distance = p4.distance(p5);
        double targetDistance = distance / 2.0;
        double targetDistance2 = distance * 2.0;

        Point newPoint = Point::moveTowards(p4, p5, targetDistance);
        Point newPoint2 = Point::moveTowards(p4, p5, targetDistance);

        CHECK(p1.distance(newPoint) < distance);
        CHECK(p1.distance(newPoint2) > distance);
        CHECK_THROWS(Point::moveTowards(p4, p5, -1));
    }
}
TEST_SUITE("init")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *Oninja = new OldNinja("Ni", a);
    YoungNinja *Yninja = new YoungNinja("Hu", a);
    TrainedNinja *Tninja = new TrainedNinja("Ba", b);
    TEST_CASE("Ninja init")
    {

        CHECK_EQ(Oninja->getName(), "Ni");
        CHECK_EQ(Yninja->getName(), "Hu");
        CHECK_EQ(Tninja->getName(), "Ba");
        CHECK_EQ(Oninja->getLocation(), Yninja->getLocation());
        CHECK_NE(Oninja->getLocation(), Tninja->getLocation());
    }

    TEST_CASE("Cowboy init")
    {
        CHECK_EQ(tom->getName(),"Tom");
        CHECK(tom->hasboolets());
        CHECK_EQ(tom->getLocation().distance(Point(3,2)),0);

    }
    TEST_CASE("Team init")
    {
        Point a(32.3, 44), b(1.3, 3.5);

        Team team(tom);
        Team team2(Oninja);
        CHECK_EQ(team.stillAlive(), 1);
        CHECK_EQ(team2.stillAlive(), 1);
    }

}
TEST_SUITE("Team Functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *Oninja = new OldNinja("Ni", a);
    YoungNinja *Yninja = new YoungNinja("Hu", a);
    TrainedNinja *Tninja = new TrainedNinja("Ba", b);
    Team team(tom);
    Team team2(Oninja);
    TEST_CASE("add function")
    {
        TrainedNinja *susi = new TrainedNinja("Susi",a);
        Cowboy *asaf = new Cowboy("Asaf", a);

        int aliveNinjas = team2.stillAlive();
        team2.add(susi);
        CHECK_NE(team2.stillAlive(), aliveNinjas);
        int aliveCowboys = team2.stillAlive();
        team.add(asaf);
        CHECK_NE(team.stillAlive(),aliveCowboys);


    }
};