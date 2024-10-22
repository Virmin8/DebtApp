#include "functions.h"
#include <iostream>

void ReadFromFile(std::string name,std::vector<OnlineService> &service)
{
    std::string servicename;
    int months;
    int day;
    int month;
    int year;
    double cost;
    std::string  symbol;

    std::ifstream fileIn;
    fileIn.open(name.c_str());
    if (!fileIn.is_open())
    {
        std::cout << "File cannot be read!!" << std::endl;
    }
    else
    {
        while (fileIn >> servicename >> months >> day >> month >> year >> cost >> symbol)
        {
            OnlineService onlineservices(servicename, months, day, month, year, cost, symbol);
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

double TotalMonthly(int month, std::vector<OnlineService>& Services)
{
    tm* time = getTime();

    double total = 0.00;
    for (int i = 0; i < Services.size(); i++)
    {
        if (Services[i].getMonth() == month || Services[i].getEveryfewMonths() == 1)
        {
            total = total + Services[i].getCost();
            
        }
    }
    return total;
}

double TotalYearly(std::vector<OnlineService> &services)
{
    double total = 0.00;
    for (int i = 1; i < 13; i++)
    {
        total += TotalMonthly(i, services);
    }
    return total;
}

tm* getTime()
{
    std::time_t timestamp = std::time(0);
    std::tm* now = std::localtime(&timestamp);

    return now;
}
double RestMonthly(int month, std::vector<OnlineService>& Services)
{
    tm* time = getTime();

    double total = 0.00;
    for (int i = 0; i < Services.size(); i++)
    {
        if (Services[i].getMonth() == month && Services[i].getYear() == time->tm_year + 1900)
        {
            total = total + Services[i].getCost();
        }
    }
    return total;
}

double RestYearly(std::vector<OnlineService>& Services)
{
    tm* time = getTime();
    double total = RestMonthly(time->tm_mon + 1, Services);

    for (int i = time->tm_mon + 2; i < 13; i++)
    {
        total += TotalMonthly(i, Services);
    }
    return total;
}

void print(int month, std::vector<OnlineService>& Services)
{
    for (int i = 0; i < Services.size(); i++)
    {
        if (Services[i].getMonth() == month || Services[i].getEveryfewMonths() == 1)
        {

            std::cout << Services[i].getName() << " Costs: " << Services[i].getCost() << " Next Payment Due: " << Services[i].getDay() << "/" << Services[i].getMonth() << "/" << Services[i].getYear() << "\n";
        }
    }
}
    