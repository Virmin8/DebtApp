#include "onlineservice.h""
OnlineService::OnlineService(std::string  _name, int _everyfemonths, int _day, int _month, float _cost)
{
    name = _name;
    everyfemonths = _everyfemonths;
    day = _day;
    month = _month;
    cost = _cost;
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
float OnlineService::getCost(){
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
void OnlineService::print() const
{
    std::cout << name << " Costs: " << cost << ". Next Payment Due: " << day << "/" << month << std::endl;
}
OnlineService::~OnlineService()
{

}
 