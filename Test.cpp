/**
 * An example of how to write expected tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Oriya Alperin>
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("operators") {
    
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{5, "m"};
    NumberWithUnits expected{2.5,"km"};

    CHECK(( (nwu)(a+b)==expected)==true);// 2km+ 5m
    CHECK(((nwu)(a+=NumberWithUnits{8, "km"}) ==expected)==true); //10km

    expected={9,"km"};
    CHECK(((nwu)(a-=NumberWithUnits{1000,"m"})==expected)==true);

    b--;
    expected={4,"m"};
    CHECK((b==expected )==true);

    NumberWithUnits c{16, "ton"};
    expected={17, "ton"};
    c++;
    CHECK((c==expected)==true);
    

    NumberWithUnits d{1000,"kg"};
    expected= {16,"ton"};
    CHECK(((nwu)(c-d)==expected)==true);

    NumberWithUnits e{24, "hour"};
    expected = {-24,"hour" };
    CHECK(((nwu)-e == expected)==true);
    CHECK(((nwu)-(-e) == -expected)==true);
    expected = {-48,"hour"};
    CHECK (((nwu)(-e - (+e))== expected)==true);
    NumberWithUnits f{45, "min"};
    expected = {25.30,"hour"};
    CHECK(((nwu)(e+f+f) == expected)==true);
    expected= {80,"min"};
    CHECK (((nwu)f*2 == expected)==true);
    expected= {0,"min"};
    CHECK (((nwu)(0*f) == expected)==true);
    NumberWithUnits g= {90,"sec"};
    CHECK((g>expected)==true);
    expected= {1.30, "min"};
    CHECK((g==expected) == true);
    
    NumberWithUnits h = {53.28, "ILS"};
    expected = { 15, "USD"};
    CHECK((expected<h) == true);
    CHECK((expected<=h) == true);
    CHECK((expected> h) == false);
    expected = {16, "USD"};
    CHECK((expected<=h) == true);
    CHECK ((expected != h )== true);

}

TEST_CASE("illegal commands")
{
    NumberWithUnits kg{5,"kg"};
    NumberWithUnits hour{20, "hour"};
    NumberWithUnits min{16, "min"};
    NumberWithUnits ils{20,"ILS"};
    NumberWithUnits m{54,"m"};
    CHECK_THROWS(ils-min);
    CHECK_THROWS (kg+=ils);
    CHECK_THROWS(m-=hour);
    CHECK_THROWS(kg+hour);

    CHECK_THROWS(NumberWithUnits(120,"KM"));
    CHECK_THROWS(NumberWithUnits(59,"MIN"));

    CHECK_THROWS(NumberWithUnits(1, "GB"));
    CHECK_THROWS(NumberWithUnits(1, "day"));
    //CHECK_THROWS(NumberWithUnits(22, "GB")>= NumberWithUnits(200, "MB"));
    //CHECK_THROWS(NumberWithUnits(33, "cm")!= NumberWithUnits(2, "week"));
    


}


/* Add more test cases here */
