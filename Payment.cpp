#include "payment.h"

float monthly(std::vector<OnlineService> services) {

    float total = 0;
    for (int i = 0; i < services.size(); i++)
    {
        if (services[i].getEveryfewMonths() == 1)
        {
            total += services[i].getCost();
        }
    }

    return total;
}