#include "currencyconverter.h"

#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

float currencyConverter(std::string _currency)
{
	std::string date = "latest";
	std::string currency = _currency;
	std::string endpoint = currency + ".json";
	std::string url = "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/" + endpoint;

	cpr::Response r = cpr::Get(cpr::Url{ url });
		
	json tmp = json::parse(r.text);
	std::string total = tmp[currency]["zar"];
		
	
	
			return std::stof(total);
}