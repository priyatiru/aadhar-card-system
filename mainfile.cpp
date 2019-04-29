#include<iostream>
#include<string>
#include "people.h"
#include "operation.h"
#include<vector>
#include "IO.h"
using namespace std;

// vector to store all data
vector<person> population;

//using constructor to LoadData and destructor to write in file
class io
{
public:

      io(){
        LoadData(population);
        cout<<"Now you are ready to go"<<endl;
      }

      ~io()
      {
         WriteTOFile(population);
      }
};
int main()
{
    io x; //calls destructor to load data;

    int ch,p;
    bool exit_code=0; // flag to break loop
    while(1)
    {
        ch=mainChoice();
        switch(ch)
        {
            case 1:
                Insert(population);    //calling Insert fun from operation.h
                break;
            case 2:
                deletee(population); //calling deletee fun from operation.h
                break;
            case 3:
                modify(population);  //calling modify fun from operation.h
                break;
            case 4:
                cout<<"**************************************************************************************"<<endl;
                cout<<"Name        "<<"\t"<<" DateOfBirth "<<"\t"<<" city  \t"<<" occupation \t"<<"Mobile No. \t"<<endl;
                Show_all(population);  //calling Show_all fun from operation.h
                cout<<"**************************************************************************************"<<endl;
                break;
            case 5:
                search(population);   //calling search fun from operation.h
                break;
            case 6:
                exit_code=1;   //flag 1 to break the loop
                break;
            default:
                cout<<endl<<"Please Slect a correct option"<<endl;
        }
        if(exit_code)
        {
            cout<<"********************Thanking You For using this Application *****************************"<<endl;
            break;

        }
    }


}
