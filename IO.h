#ifndef IO_H
#define IO_H

#include<iostream>
#include<fstream>
#include<vector>
#include "people.h"
#include "operation.h"
using namespace std;



void WriteTOFile(vector<person> &vect)
{
    ofstream first,mid,last,mob,city,oc,dob;
    first.open("first.txt",ios::out | ios::trunc );
    mid.open("mid.txt", ios::out | ios::trunc );
    last.open("last.txt", ios::out | ios::trunc );
    mob.open("mobile.txt", ios::out | ios::trunc );
    city.open("city.txt", ios::out | ios::trunc );
    oc.open("occu.txt", ios::out | ios::trunc );
    dob.open("dob.txt",ios::out | ios::trunc );
    for(int i=0;i<vect.size();i++)
    {
        first<<vect[i].give_first() <<endl;
        mid<<vect[i].give_mid() <<endl;
        last<< vect[i].give_last() <<endl;
      	oc<< vect[i].give_occ()<<endl;
      	dob<< vect[i].give_dob()<<endl;
      	mob<< vect[i].give_mobile() <<endl;
        city<< vect[i].give_city()<<endl;
    }
    first.close();
    mid.close();
    last.close();
    mob.close();
    city.close();
    oc.close();
    dob.close();
}


void LoadData(vector<person> &vect)
{
    fstream first,mid,last,mob,city,oc,dob;
    first.open("first.txt",ios::in );
    mid.open("mid.txt", ios::in );
    last.open("last.txt", ios::in );
    mob.open("mobile.txt", ios::in );
    city.open("city.txt", ios::in );
    oc.open("occu.txt", ios::in );
    dob.open("dob.txt",ios::in );

    while(first and last and mob and city and oc and dob)
    {

        person A;
        string dd;
        std::string a,b,c;
        b=" ";
        getline(first, a);
        getline(mid, b);
        getline(last, c);
        A.set_name(a,b,c);
        getline(mob, a);
        A.set_mob(a);
        getline(city,b);
        A.set_city(b);

        getline(dob,dd);
        A.set_dob(dd);

	getline(oc,a);

        A.set_occ(a);
        SortAndInsert(vect,A);
    }


    vect.erase(vect.begin());
    first.close();
    mid.close();
    last.close();
    mob.close();
    city.close();
    oc.close();
    dob.close();
}



#endif
