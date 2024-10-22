#include <iostream>
#include <fstream>
#include "onlineservice.h"


int main(){

    std::vector<OnlineService> Services;
    std::string strFilename("Services.txt");
    std::ifstream fileIn;

    std::string name;
    int everyfemonths = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    float cost;

    fileIn.open(strFilename.c_str());
    if (!fileIn.is_open())
    {
        std::cout << "File cannot be read!!" << std::endl;
    }
    else
    {
        while (fileIn >> name >> everyfemonths  >> day >> month >> year >> cost )
        {
            OnlineService onlineservices(name,everyfemonths,day,month,year,cost);
            Services.push_back(onlineservices);
        }
    }
    
    if( fileIn.is_open())
    {
        fileIn.close();
    }
    
    for(int i = 0; i < Services.size(); i++)
    {
        std::cout << Services[i].getName() << "Costs: " << Services[i].getCost() << std::endl;
    }


    return 0;
}