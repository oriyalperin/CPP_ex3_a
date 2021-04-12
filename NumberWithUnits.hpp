#pragma once
#include<iostream>
#include<string>
#include<map>
namespace ariel{

    typedef class NumberWithUnits{

        private:
            std::map<std::string,NumberWithUnits> units;
            /*typedef struct unit{
                std::string unit_type;
                int unit_num;
            };

            unit bunit;
            unit sunit;*/
            std::string unit_type;
            double unit_num;
            
        public:
            /*int unit_num() const {  // getter
                return unit_num;
            }

            int& unit_num()  {       // setter and getter
                return unit_num;
            }*/
            NumberWithUnits(double num, const char * unit);
            static void read_units(std::ifstream& units_file);
            friend NumberWithUnits operator+(const NumberWithUnits& u1,const NumberWithUnits& u2);
            NumberWithUnits& operator+=(const NumberWithUnits& other);
            NumberWithUnits& operator++();
             NumberWithUnits operator+() const;
             NumberWithUnits operator++(int dummy_flag_for_postfix_increment);
            

            friend  NumberWithUnits operator-(const NumberWithUnits& u1,const NumberWithUnits& u2);
            NumberWithUnits& operator-=(const NumberWithUnits& other);
            NumberWithUnits& operator--();
             NumberWithUnits operator-() const;
             NumberWithUnits operator--(int dummy_flag_for_postfix_increment);

            NumberWithUnits& operator=(const NumberWithUnits& other);
            bool operator!=(const NumberWithUnits& other);
            bool operator>(const NumberWithUnits& other);
            bool operator>=(const NumberWithUnits& other);
            bool operator<(const NumberWithUnits& other);
            bool operator<=(const NumberWithUnits& other);
            bool operator==(const NumberWithUnits& other);

            NumberWithUnits&  operator* (double x); 

            friend NumberWithUnits operator*(double x, const NumberWithUnits& n);
            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& n);
            friend std::istream& operator>> (std::istream& is, NumberWithUnits& n);



    } nwu ;

}