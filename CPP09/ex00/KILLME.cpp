#include <iostream>
#include <map>
#include <algorithm>

/* TESTING MAP CONTAINER*/

int main(void)
{
	std::map < int, std::string > map;

	map[0] = "number 1";
	map[1] = "number 2";
	map[2] = "number 3";

	//Add um novo elemento no container
	map.insert(std::pair<int, std::string >(10, "New number"));

	//Add um novo elemento no container
	map.emplace(15, "number 9");

	//atualizar o valor de um elemento, dessa forma se nao existir ele vai dar erro, se a atribuicao for feita diretamente, sem o 'at' ele vai criar uma nova se nao existir
	map.at(0) = "number 60";

	std::cout << "size: " << map.size() << std::endl;
	std::cout << "max_size: " << map.max_size() << std::endl;

	//apaga um elemento do container
	map.erase(1);

	if (map.find(3) != map.end())
		std::cout << "Encontrou" << std::endl;
	

	std::map <int, std::string>::const_iterator it;

	for (it = map.begin(); it != map.end(); it++)
	{
		std::cout << "first: " << it->first  << " | second: " << it->second << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
