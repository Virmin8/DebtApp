#ifndef ONLINESERVICE_H
#define ONLINESERVICE_H

#include <vector>
#include <string>
#include <iostream>

class OnlineService
{
private:
    std::string name;
    int everyfemonths;
    int day;
    int month;
    float cost;

    
public:
    OnlineService(std::string, int, int, int, float);
    ~OnlineService();
    int getDay();
    int getEveryfewMonths();
    int getMonth();
    float getCost();
    std::string getName();
    void setMonth(int);
    void print() const;
};

#endif