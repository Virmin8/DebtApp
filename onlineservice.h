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
    int year;
    double cost;
    std::string symbol;
    double costConverted;
    void setPaid();

    
public:
    OnlineService(std::string, int, int, int, int, double , std::string);
    ~OnlineService();

    int getDay();
    int getEveryfewMonths();
    int getMonth();
    double getCost();
    int getYear();
    std::string getName();
    std::string  getSymbol();
    double getCostConverted();
    
    void setDay(int);
    void setEveryfewMonths(int);
    void setMonth(int);
    void setCost(double);
    void setYear(int);
    void setName(std::string);
    void setCostConverted(double);

    void print() const;
};

#endif