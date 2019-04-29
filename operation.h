#ifndef OPERATION_H
#define OPERATION_H

#include<iostream>
#include<string>
#include<vector>
#include "people.h"

using namespace std;

//Fun to show main menu
int mainChoice()
{
    cout<<"***************Welcome to People data management system**********************"<<endl;
    cout<<"Select from following options"<<endl;
    cout<<"(1) Insert new a entry"<<endl;
    cout<<"(2) Delete a entry"<<endl;
    cout<<"(3) Modify a entry"<<endl;
    cout<<"(4) Show all the entry"<<endl;
    cout<<"(5) Search "<<endl;
    cout<<"(6) Exit "<<endl;
    int choice;
    cin>>choice;
    return choice;
}

//fun to give search option
int searchChoice()
{
    cout<<"****************Choose a search option*************************************"<<endl;
    cout<<"(1) Search by name"<<endl;
    cout<<"(2) Search by occupation"<<endl;
    cout<<"(3) Search by Mobile No."<<endl;
    int ch;
    cin>>ch;
    return ch;
}

//select occupation
int selectOcc()
{
    cout<<"******select occupation**********"<<endl;
    cout<<"(1) Student"<<endl;
    cout<<"(2) Govt. job"<<endl;
    cout<<"(3) Private job"<<endl;
    cout<<"(4) No job"<<endl;
    cout<<"(5) other"<<endl;
    int ch;
    cin>>ch;
    if(ch>5 || ch<1)
    {
        cout<<"enter a valid choice"<<endl;
        ch=selectOcc();
    }
    return ch;
}

//return occupation as string by occupation id
string occu(int i)
{
    if(i==1)
        return "Student";
    else if(i==2)
        return "Govt. Job";
    else if(i==3)
        return "Private Job";
    else if(i==4)
        return "No job";
    else
        return "other";
}

// func to insertion sort
//every element is inserted according to its order
void SortAndInsert(vector<person> &vect,person A)
{
    vect.push_back(A);
    string key = A.give_name();
    int j = vect.size()-2;

    while (j >= 0 && vect[j].give_name() > key)
    {
        vect[j+1] = vect[j];
        j = j-1;
    }
    vect[j+1] = A;
    cout<<"Id is generated ID="<<j+2<<endl;
}

//insert function
void Insert(vector<person> &vect)
{
	person A;
    cout<<"**************************Insert*******************************************"<<endl;
    string First;
    string middile;
    string last;
    string city;
    string ocu;
    char dob[10];
    cout<<"First   Name : ";
    cin>> First;
    cout<<"Middile Name : ";
    cin>>middile;
    cout<<"Last    Name : ";
    cin>>last;
    cout<<"City    Name : ";
    cin>>city;
    int o=selectOcc();
    ocu=occu(o);
    cout<<"DOB(dd-mm-yyyy): ";
    cin>>dob;
    string m;
    cout<<"Mobile No     : ";
    cin>>m;

    A.enter(First,middile,last,dob,city,ocu,m);
    //insertion sort
    SortAndInsert(vect,A);
    cout<<"*************************Operation completed*******************************************"<<endl;
}

// delete fun
void deletee(vector<person> &vect)
{
    cout<<"*************************Delete*******************************************"<<endl;
    cout<<"Enter Id to delete"<<endl;
    int t;
    cin>>t;
    cout<<"***************************************************************************"<<endl;
    vect[t-1].display();
    cout<<"***************************************************************************"<<endl;
    cout<<"Are you sure ,You want to delete this(y/n)";
    char yes;
    cin>>yes;

    if(yes=='Y'||yes=='y')
    {
        vect.erase(vect.begin()+t-1);
        cout<<"*************************Operation completed*******************************************"<<endl;
    }
    else
    {
        cout<<"*************************No entry is deleted*******************************************"<<endl;
    }

}


//show all Entry
void Show_all(vector<person> &vect)
{
    for(int i=0;i<vect.size();i++)
    {
            cout<<"ID : "<<i+1<<endl;
            vect[i].display();
    }
}

//modify
void modify(vector<person> &vect)
{
    cout<<"*************************Modify*******************************************"<<endl;
    int t;
    cout<<"Enter Id to Modify Entry"<<endl;
    cin>>t;
    cout<<"***************************************************************************"<<endl;
    vect[t-1].display();
    cout<<"***************************************************************************"<<endl;

    while(1)
    {
        cout<<"select a correct option"<<endl;
        cout<<"(1) Change Name"<<endl;
        cout<<"(2) Change Mobile Number"<<endl;
        cout<<"(3) Change Date of birth"<<endl;
        cout<<"(4) Change City"<<endl;
        cout<<"(5) Change Occupation"<<endl;
        cout<<"(6) Exit"<<endl;
        int x;
        cin>>x;
        int exit_code=0;
        switch(x)
        {
            case 1:
            {
                string First;
                string middile;
                string last;
                cout<<"First   Name : ";
                cin>> First;
                cout<<"Middile Name : ";
                cin>>middile;
                cout<<"Last    Name : ";
                cin>>last;


                person A;

                string dob;
                cout<<"Enter new DOB(dd-mm-yyyy): ";
                cin>>dob;


                string city=vect[t-1].give_city();

		string o=vect[t-1].give_occ();

                string mobil=vect[t-1].give_mobile();

                vect.erase(vect.begin()+t-1);

                A.enter(First,middile,last,dob,city,o,mobil);
                SortAndInsert(vect,A);
                exit_code=1;
                cout<<"**********Modified Successfully******************"<<endl;
                break;
            }
            case 2:
            {
                string mo;
                cout<<"Enter new Mobile number"<<endl;
                cin>>mo;
                vect[t-1].set_mob(mo);


		cout<<"**********Modified Successfully******************"<<endl;
		cout<<"Do you want to change anything else(y/n)"<<endl;
		char yes;


		cin>>yes;

		if(yes=='Y'||yes=='y')
		{
			exit_code=0;
		}
		else exit_code=1;
                break;
            }
            case 3:
            {
                char dob[10];
                cout<<"Enter new DOB(dd-mm-yyyy): ";
                cin>>dob;
                vect[t-1].set_dob(dob);

		cout<<"**********Modified Successfully******************"<<endl;
		cout<<"Do you want to change anything else(y/n)"<<endl;
		char yes;


		cin>>yes;

		if(yes=='Y'||yes=='y')
		{
			exit_code=0;
		}
		else exit_code=1;

                break;
            }
            case 4:
            {
                string ci;
                cout<<"Enter new city"<<endl;
                cin>>ci;
                vect[t-1].set_city(ci);

		cout<<"**********Modified Successfully******************"<<endl;
		cout<<"Do you want to change anything else(y/n)"<<endl;
		char yes;


		cin>>yes;

		if(yes=='Y'||yes=='y')
		{
			exit_code=0;
		}
		else exit_code=1;

                break;
            }
            case 5:
            {
 		string oc;
                int o=selectOcc();
		oc=occu(o);
                vect[t-1].set_occ(oc);


		cout<<"**********Modified Successfully******************"<<endl;
		cout<<"Do you want to change anything else(y/n)"<<endl;
		char yes;


		cin>>yes;

		if(yes=='Y'||yes=='y')
		{
			exit_code=0;
		}
		else exit_code=1;
                break;
            }
            case 6:
            {
                exit_code=1;
                break;
            }
            default:
            {
                cout<<"Please select correct option"<<endl;
                break;
            }
        }
        if(exit_code==1)
        {
            break;

        }
    }

}

void search(vector<person> &vect)
{
    int t=searchChoice();
    int found=0;
    switch(t)
    {
        case 1:
        {
            string x;

            cout<<"enter First Name"<<endl;
            cin>>x;
            cout<<"*************Here is your Search Result************"<<endl;
            for(int i=0;i<vect.size();i++)
            {
                if(vect[i].give_first()==x)
                {
                    cout<<"ID : "<<i;
                    vect[i].display();
                    found=1;
                }
            }
            break;
        }
        case 2:
        {
            //by occupation
	    string oc;
            int o=selectOcc();
	    oc=occu(o);

            cout<<"*************Here is your Search Result************"<<endl;
            for(int i=0;i<vect.size();i++)
            {
                if(vect[i].give_occ()==oc)
                {
                    cout<<"ID : "<<i;
                    vect[i].display();
                    found=1;
                }
            }

            break;

        }
        case 3:
        {
            // by mobile
            string mm;
            cout<<"enter Mobile no"<<endl;
            cin>>mm;
            cout<<"*************Here is your Search Result************"<<endl;
            for(int i=0;i<vect.size();i++)
            {
                if(vect[i].give_mobile()==mm)
                {
                    cout<<"ID : "<<i;
                    vect[i].display();
                    found=1;
                }
            }
            break;
        }
        default:
        {
            cout<<"Please enter correct option"<<endl;
            search(vect);
        }
    }
    if(found==0)
    {
        cout<<"************No result found**************** "<<endl;
    }

}





#endif
