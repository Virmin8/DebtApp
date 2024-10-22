#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "onlineservice.h"
#include <fstream>

void ReadFromFile(std::string, std::vector<OnlineService>&);
void WriteToFile(std::vector<OnlineService>&);

float TotalMonthly(int, std::vector<OnlineService>&);
float TotalYearly(std::vector<OnlineService>&);

#endif
