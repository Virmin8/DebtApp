#include "onlineservice.h"
#include "functions.h"

OnlineService::OnlineService(std::string  _name, int _everyfemonths, int _day, int _month, int _year, double _cost, std::string _symbol)
{
    name = _name;
    everyfemonths = _everyfemonths;
    day = _day;
    month = _month;
    cost = _cost;
    year = _year;
    symbol = _symbol;
    paid = false;
    costConverted = 0.00;
    rollOver();
}

int OnlineService::getDay() {
    return day;
}

int OnlineService::getEveryfewMonths(){
    return everyfemonths;
}

int OnlineService::getMonth(){
    return month;
}

double OnlineService::getCost(){
    return cost;
}

std::string OnlineService::getName()
{
    return name;
}

void OnlineService::setMonth(int _month)
{
    month = _month;
}

int OnlineService::getYear()
{
    return year;
}

std::string OnlineService::getSymbol()
{
    return symbol;
}

double OnlineService::getCostConverted()
{
    return costConverted;
}

bool OnlineService::getPaid()
{
    return paid;
}

void OnlineService::setPaid(bool _paid)
{
    paid = _paid;
}

void OnlineService::rollOver()
{
    tm* time = getTime();
    
 
    
 
    if (day <= time->tm_mday && month <= time->tm_mon + 1 && year <= time->tm_year + 1900)
    {
        paid = true;

        if (everyfemonths == 1)
        {
            month = time->tm_mon + 2;
            if (month % 12 == 0)
            {
                month = 12;
            }
            if (month % 12 == 1)
            {   
                month = 1;
                year = year + 1;
            }
        }
        if (everyfemonths == 12)
        {
        year = time->tm_year + 1901;
        }
    }
    
}

void OnlineService::setDay(int _day) {
    day = _day;
}

void OnlineService::setEveryfewMonths(int _every)
{
    everyfemonths = _every;
}

void OnlineService::setCost(double _cost)
{
    cost = _cost;
}

void OnlineService::setYear(int _year)
{
    year = _year;
}

void OnlineService::setName(std::string _name)
{
    name = _name;
}

void OnlineService::print() const
{
    std::cout << name << " Costs: " << cost << " Next Payment Due: " << day << "/" << month << "/" << year << "\n";
}

void OnlineService::setCostConverted(double _costConverted)
{
    costConverted = _costConverted;
}

OnlineService::~OnlineService()
{

}
 