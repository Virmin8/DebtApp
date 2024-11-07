#include "onlineservice.h"
#include "functions.h"
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <cstring>

using json = nlohmann::json;

OnlineService::OnlineService(std::string  _name, int _everyfemonths, int _day, int _month, int _year, double _cost, std::string _symbol)
{
    name = _name;
    everyfemonths = _everyfemonths;
    day = _day;
    month = _month;
    year = _year;
    symbol = _symbol;
    cost = _cost;
    if (symbol != "ZAR")
    {
    std::string s = symbol;
    for (auto& x : s) {
        x = tolower(x);
    }

        cost = cost * currencyConverter(s);
    }
    rollOver();
    length = 0;
    
    
}


double OnlineService::currencyConverter(std::string _currency)
{
    std::string date = "latest";
    std::string currency = _currency;
    std::string endpoint = currency + ".json";
    std::string url = "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/" + endpoint;

    cpr::Response r = cpr::Get(cpr::Url{ url });
    json tmp = json::parse(r.text);
    auto total = tmp[currency]["zar"];
    return total;

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

int OnlineService::getLength()
{
    return length;
}

void OnlineService::rollOver()
{
    tm* time = getTime();
    
 
    
 
    if (day <= time->tm_mday && month <= time->tm_mon + 1 && year <= time->tm_year + 1900)
    {

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

void OnlineService::print() 
{
    
    std::cout << name << " Costs: " << cost  << " Next Payment Due: " << day << "/" << month << "/" << year << "\n";
}

void OnlineService::print(int _month, int _year, std::string _paid)
{
    std::cout << name << " Costs: " << cost << " Next Payment Due: " << day << "/" << _month << "/" << year + _year << " Paid: " << _paid << "\n";
}


void OnlineService::setLength(int _length)
{
    length = _length;
}



OnlineService::~OnlineService()
{

}
