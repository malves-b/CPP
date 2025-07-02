#include <iostream>
#include <map>
#include <algorithm>

/* TESTING MAP CONTAINER*/

int main(void)
{
	std::map < int, std::string > map;
	std::map < int, std::string >::iterator it;

	map.insert(std::pair<int, std::string>(0, "microfone"));
	map.insert(std::pair<int, std::string>(1, "microfone"));
	map.insert(std::pair<int, std::string>(2, "microfone"));
	map.insert(std::pair<int, std::string>(3, "microfone"));
	map.insert(std::pair<int, std::string>(4, "Mouse"));
	map.insert(std::pair<int, std::string>(5, "Teclado"));
	map.insert(std::pair<int, std::string>(6, "Monitor"));

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
	//apaga um conjunto de elementos do container
	map.erase(map.find(0), map.find(3));

	//apaga todos os elementos do container
	// map.clear();

	//metodo find procura um elemento dentro do container
	if ((it = map.find(2)) != map.end()){
		std::cout << "Produto encontrado" << std::endl;
		std::cout << it->first << '-' << it->second << std::endl;
	}else {std::cout << "Produto nao encontrado\n";}
	


	for (it = map.begin(); it != map.end(); it++)
	{
		std::cout << "first: " << it->first  << " | second: " << it->second << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
