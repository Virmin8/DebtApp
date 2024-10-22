#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "onlineservice.h"
#include <fstream>
#include <chrono>


tm* getTime();

void ReadFromFile(std::string, std::vector<OnlineService>&);
void WriteToFile(std::vector<OnlineService>&);

double TotalMonthly(int, std::vector<OnlineService>&);
double TotalYearly(std::vector<OnlineService>&);
double RestMonthly(int month, std::vector<OnlineService>& Services);
double RestYearly(std::vector<OnlineService>&);
void print(int,std::vector<OnlineService>&);

#endif
