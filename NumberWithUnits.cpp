/*NumberWithUnits& operator+=(const NumberWithUnits& other) {
            bunit.unit_num+= other.bunit.unit_num;
            sunit.unit_num+= other.sunit.unit_num;
            return *this; // for call chaining
        }*/
#include<iostream>
#include<string>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

    NumberWithUnits::NumberWithUnits(double num, const char * unit) {
        unit_num=num;
        unit_type=unit;
    }
    
    
    void NumberWithUnits::read_units(ifstream& units_file)
    {
        string text;
        while (getline (units_file, text)) {
            
        }
        //units_file.close();
    }
     NumberWithUnits ariel::operator+(const NumberWithUnits& u1,const NumberWithUnits& u2){
        return u1;
    }
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator++(){
        return *this;
    }

     NumberWithUnits NumberWithUnits::operator+() const{
        const NumberWithUnits a(*this);
        return a ;
    }

     NumberWithUnits NumberWithUnits::operator++(int dummy_flag_for_postfix_increment){
        const NumberWithUnits a(*this);
        return a ;
    }

    

     NumberWithUnits ariel::operator-(const NumberWithUnits& u1,const NumberWithUnits& u2){
            return u2;
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator--(){
        return *this;
    }
     NumberWithUnits NumberWithUnits::operator-() const{
        const NumberWithUnits a(*this);
        return a ;
    }
     NumberWithUnits NumberWithUnits::operator--(int dummy_flag_for_postfix_increment){
        const NumberWithUnits a(*this);
        return a ;
    }

    NumberWithUnits& NumberWithUnits::operator=(const NumberWithUnits& other){
        return *this;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits& other){
        return true;
    }
    bool NumberWithUnits::operator>(const NumberWithUnits& other){
        return true;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits& other){
        return true;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits& other){
        return true;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits& other){
        return true;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits& other){
        return true;
    }
    //bool operator==(const NumberWithUnits& other){}

    NumberWithUnits& NumberWithUnits::operator* (double x){
        return *this;
    } 
    NumberWithUnits ariel::operator*(double x, const NumberWithUnits& n){
        return n;
    }
    std::ostream& ariel::operator<< (std::ostream& os, const NumberWithUnits& n){
        return os;
    }
    std::istream& ariel::operator>> (std::istream& is, NumberWithUnits& n){
        return is;
    }    





