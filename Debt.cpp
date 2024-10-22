#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include "onlineservice.h"
#include <chrono>

int main() {

    std::time_t timestamp = std::time(0);
    std::tm* now = std::localtime(&timestamp);

    int day = now->tm_mday;
    int month = now->tm_mon + 1;
    int year = now->tm_year + 1900;
    std::string answer;

    std::vector<OnlineService> Services;

    std::string strFilename("Services.txt");
   
    std::cout << "Would you like to load the default Service List? (y or n): ";
    std::cin >> answer;

        if (answer == "n")
        {
            std::cout << "Please enter the correct filename: ";
            std::cin >> strFilename;

        }
    

    float total = 0.00;
    bool quit = false;
    
    std::cout << "The Current Date is :" << day << "/" << month << "/" << year << std::endl << std::endl;

    ReadFromFile(strFilename, Services);

    for (int i = 0; i < Services.size(); i++)
    {
        Services[i].print();

    }
    

    while (!quit)
    {
        total = TotalMonthly(month,Services);
        std::cout << std::endl << "Total Cost for the month: " << total << std::endl;
        total = TotalYearly (Services);
        std::cout << std::endl << "Total Cost for the year: " << total << std::endl;

        total = 0.00;

        std::cout << "Please enter which month you would like to see the costs for (1-12) or Quit (q or Q): ";
        std::cin >> answer;

        if(answer == "q" || answer == "Q")
        {
            quit = true;
        }
        else
        {
            month = stoi(answer);
        }
        
    }

    WriteToFile(Services);
    return 0;
}