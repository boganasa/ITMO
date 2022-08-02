#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "Archive.h"
#include <json.hpp>
#include <curl.h>
#pragma comment(lib,"libcurl.lib")

#define JSON_TRY_USER if(true)                               //Проверка на ошибки от json. Выводит код ошибки и пояснение
#define JSON_CATCH_USER(exception) if(false)
#define JSON_THROW_USER(exception)                           \
    {std::clog << "Error in " << __FILE__ << ":" << __LINE__ \
               << " (function " << __FUNCTION__ << ") - "    \
               << (exception).what() << std::endl;           \
     std::abort();}

std::string ErrBuff[CURL_ERROR_SIZE];


using json = nlohmann::json;


static size_t Writer(char* buffer, size_t size, size_t nmemb, std::string* html) {
	int result = 0;

	if (buffer != NULL) {
		html->append(buffer, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

int main()
{
	std::string* CountryVocabular = new std::string[34];
	for (int i = 0; i < 34; i++)
	{
		CountryVocabular[i] = "XXX";
	}
	

	Archive catalog;
	catalog.setNumberOfRequests(0);
	catalog.resizeDirectory(34);


	CURL* curl;
	std::string QueryRezult1;
	std::string Error;


	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, Error);
	curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
	if (!curl)
	{
		std::wcout << "ERROR with reading link" << std::endl;
		std::cout << Error;
		return -1;
	}
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &QueryRezult1);
	curl_easy_perform(curl);

	json ParseJson;
	json Valute;
	json Country;

	double Value;
	double Middle = 0, Median = 0;

	int IndexVocabular = 0;
	bool FirstKey = false;
	for (int i = 20; i < QueryRezult1.length() - 10; i++)
	{
		if ((!FirstKey) && (QueryRezult1[i] == '{'))
		{
			FirstKey = true;
			i += 17;
			CountryVocabular[IndexVocabular][0] = QueryRezult1[i - 6];
			CountryVocabular[IndexVocabular][1] = QueryRezult1[i - 5];
			CountryVocabular[IndexVocabular][2] = QueryRezult1[i - 4];
			//std::cout << CountryVocabular[IndexVocabular] << std::endl;
			IndexVocabular++;
		}
		else if (FirstKey && (QueryRezult1[i] == '}'))
		{
			i += 12;
			CountryVocabular[IndexVocabular][0] = QueryRezult1[i];
			CountryVocabular[IndexVocabular][1] = QueryRezult1[i + 1];
			CountryVocabular[IndexVocabular][2] = QueryRezult1[i + 2];
			//std::cout << CountryVocabular[IndexVocabular] << std::endl;
			IndexVocabular++;
		}
	}
	QueryRezult1.clear();


	curl_easy_cleanup(curl);

	while (!_kbhit())
	{
		std::string QueryRezult;
		curl = curl_easy_init();
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, Error);
		if (!curl)
		{
			std::wcout << "ERROR with reading link" << std::endl;
			std::cout << Error;
			return -1;
		}
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &QueryRezult);
		curl_easy_perform(curl);
		
		//std::cout << QueryRezult << std::endl;

		ParseJson = json::parse(QueryRezult);
		Valute = ParseJson["Valute"];
		++catalog;

		for (int i = 0; i < Valute.size(); i++)
		{
			Country = Valute[CountryVocabular[i]];
			Value = Country["Value"];
			catalog.setDirectory(i, Value);
			std::cout << CountryVocabular[i] << ": " << Value << "\n";
		}
		
		curl_easy_cleanup(curl);
		QueryRezult.clear();
		Sleep(10000);
		system("cls");
	}

	std::cout << "=========MIDDLE========" << std::endl;
	for (int i = 0; i < catalog.getSize(); i++)
	{
		Middle = catalog.SearchMiddle(i);

		std::cout << CountryVocabular[i] << ": " << Middle << std::endl;
	}

	std::cout << "=========MEDIAN========" << std::endl;
	for (int i = 0; i < catalog.getSize(); i++)
	{
		Median = catalog.SearchMedian(i);

		std::cout << CountryVocabular[i] << ": " << Median << std::endl;
	}
	
	return 0;
}