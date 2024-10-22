#include "functions.h"
#include <iostream>

void ReadFromFile(std::string name,std::vector<OnlineService> &service)
{
    std::string servicename;
    int months;
    int day;
    int month;
    float cost;

    std::ifstream fileIn;
    fileIn.open(name.c_str());
    if (!fileIn.is_open())
    {
        std::cout << "File cannot be read!!" << std::endl;
    }
    else
    {
        while (fileIn >> servicename >> months >> day >> month >> cost)
        {
            OnlineService onlineservices(servicename, months, day, month, cost);
            service.push_back(onlineservices);
        }
    }

    if (fileIn.is_open())
    {
        fileIn.close();
    }

}

void WriteToFile(std::vector<OnlineService>& Services)
{
    std::string answer;
    std::ofstream fileout;

    std::cout << "Would you like to save changes to the Services? (y or n): ";
    std::cin >> answer;
 

    if (answer == "y" || answer == "Y")
    {
        std::cout << "Please enter filename: ";
        std::cin >> answer;
        fileout.open(answer);
        if (!fileout.is_open())
        {
            std::cout << "File cannot be read!!" << std::endl;
        }
        else
        {
            for (int i = 0; i < Services.size(); i++)
            {
                fileout << Services[i].getName() << " " << Services[i].getEveryfewMonths() << " " << Services[i].getDay() << " " << Services[i].getMonth() << " " << Services[i].getCost() << std::endl;

            }
            if (fileout.is_open())
            {
                fileout.close();
            }
        }
    }
}

float TotalMonthly(int month, std::vector<OnlineService>& Services)
{
    float total = 0.00;
    for (int i = 0; i < Services.size(); i++)
    {
        if (Services[i].getMonth() == month || Services[i].getEveryfewMonths() == 1)
        {
            total = total + Services[i].getCost();
        }
    }
    return total;
}

float TotalYearly(std::vector<OnlineService>& services)
{
    float total = 0.00;
    for (int i = 1; i < 13; i++)
    {
        total += TotalMonthly(i, services);
    }
    return total;
}