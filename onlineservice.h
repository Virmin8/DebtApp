#ifndef ONLINESERVICE_H
#define ONLINESERVICE_H

#include <vector>
#include <string>

class OnlineService
{
private:
    std::string name;
    int everyfemonths;
    int day;
    int month;
    int year;
    float cost;

    
public:
    OnlineService(std::string, int, int, int, float);
    ~OnlineService();
    int getDay();
    int getEveryfewMonths();
    int getMonth();
    int getYear();
    float getCost();
    std::string getName();
};

#endif