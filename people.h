#ifndef PEOPLE_H
#define PEOPLE_H

#include<iostream>
#include <string.h>




class DOB{    //Date of DateOfBirth class
    int day;
    int month;
    int year;
    std::string fullDob;
    public:
      //Dob constructor
        DOB(int d=1,int m=1,int y=2000){
            day=d;
            month=m;
            year=y;
        }
        //set date manualy member func
        void set_dob(int d=1,int m=1,int y=2000){
            day=d;
            month=m;
            year=y;
        }

        // set by string
        void set_dob(std::string str)
        {
		        fullDob=str;
        }
        // return dob as string
        std::string give_dob()
        {
            return fullDob;
        }
};

class Name{     //name class
    std::string first;
    std::string middle;
    std::string last;
    public:
       //Name constructor
        Name(std::string a=" ",std::string b=" ",std::string c=" ")
        {
            first=a;
            middle=b;
            last=c;
        }
        void set_name(std::string a=" ",std::string b=" ",std::string c=" ")
        {
            first=a;
            middle=b;
            last=c;
        }

        std::string give_name()
        {
            return first +" "+ middle +" "+ last+" ";
        }
        std::string give_first()
        {
            return first;
        }
        std::string give_mid()
        {
            return middle;
        }
        std::string give_last()
        {
            return last;
        }
};

class person:public DOB,public Name
{
    std::string mobile;
    std::string city;
    std::string  occ;
    public:
        void enter(std::string a,std::string b,std::string c,std::string str,std::string ci,std::string oc,std::string mob)
        {
              set_dob(str);
              set_name(a,b,c);
              city=ci;
              occ=oc;
              mobile=mob;
        }
        void set_city(std::string ci)
        {
            city=ci;
        }
        void set_mob(std::string mob)
        {
            mobile=mob;
        }
        void set_occ(std::string x)
        {
            occ=x;
        }
        std::string give_city()
        {
            return city;
        }
        std::string give_mobile()
        {
            return mobile;
        }

        std::string give_occ()
        {
            return occ;

        }

        void display()
        {
            std::cout<<give_name()<<"\t"<<give_dob()<<"\t"<<city<<"\t" <<occ<<"\t"<<give_mobile()<<std::endl;
        }

};






#endif     //person.h
