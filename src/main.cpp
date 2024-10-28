#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <windows.h>

#include "Parsers/JSONParser.hpp"

int main()
{
	// Allow gender signs (UTF-8)
	SetConsoleOutputCP(CP_UTF8);

	const std::unique_ptr<JSONParser> parser{ CreateParser() };
	const std::ifstream fs{ "content/pokedex.json" };
	if (!fs)
	{
		std::cout << "Unable to open file :(\n";
		return 1;
	}

	std::stringstream sstream;
	sstream << fs.rdbuf();

	const JSONDocument::Ptr doc{ parser->Parse(sstream.str()) };

	for (const JSONDocument::Ptr& pokemonElement : doc->At("pokemon")->GetAsVector())
	{
		std::stringstream ss;
		ss << pokemonElement->At("id")->GetAsInteger() << ". ";
		ss << pokemonElement->At("name")->GetAsString() << " ";

		ss << "[";
		for (const JSONDocument::Ptr& typeElement : pokemonElement->At("type")->GetAsVector())
		{
			ss << typeElement->GetAsString() << ", ";
		}
		ss.seekp(-2, std::ios_base::end);
		ss << "]";

		std::cout << ss.str() << '\n';
	}

	std::cin.get();
}
