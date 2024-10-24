//add and remove services
//add indicator that service was paid for, for the month
//currency converter via online api
//work on app version, backend seems pretty much done

#include "functions.h"
#include "onlineservice.h"
#include <chrono>

int main() {

    
    tm* now = getTime();
    int day = now->tm_mday;
    int month = now->tm_mon + 1;
    int year = now->tm_year + 1900;
    std::string answer;

    std::vector<OnlineService> Services;

    double total = 0.00;
    bool quit = false;
    
    std::cout << "The Current Date is :" << day << "/" << month << "/" << year << "\n\n";

    ReadFromFile(Services);
    std::cout << "Would you like to view a list of your current Services? (y or n): "; //Needs user checks!!
    std::cin >> answer;

    if (answer == "y" || answer == "Y") 
    {
        std::cout << "\nYour current Services: \n";
        for (int i = 0; i < Services.size(); i++)
        {
            Services[i].print();

        }
    }
   
    total = RestMonthly(month, Services);
    std::cout << "\nTotal Cost for the rest of the month: " << total << "\n";
    total = RestYearly(Services);
    std::cout << "Total Cost for the rest of the year: " << total << "\n\n";
    

    while (!quit)
    {
        std::cout << "List of Services for the Month: \n";
        print(month, Services);

        total = TotalMonthly(month,Services);
        std::cout << std::endl << "Total Cost for the month: " << total << "\n";
        total = TotalYearly(Services);
        std::cout << "Total Cost for the year: " << total <<  "\n\n";
        
        total = 0.00;

        std::cout << "\nPlease enter which month you would like to see the costs for (1-12) or Quit (q or Q): "; //Needs user checks!!
        std::cin >> answer;
        std::cout << "\n";

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