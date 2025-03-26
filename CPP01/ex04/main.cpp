#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
	std::string	filename, filename_replace, s1, s2;

	if (argc != 4)
		return (std::cout << "--- Invalid input ---\n", 1);
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	filename_replace = filename + ".replace";
	std::ifstream file(filename.c_str());
	if (!file){
		return (std::cout << "Impossible open the file!\n", 1);}
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();//convert buffer to string
	while (1)
	{
		size_t i = content.find(argv[2]);
		if (i == std::string::npos)
			break;
		content.erase(i, s1.length());
		content.insert(i, s2);
	}
	std::ofstream outfile(filename_replace.c_str());
	if (!outfile){
		return (std::cout << "Error creating replace file!\n", 1);}	
	outfile << content;
	outfile.close();
	file.close();
	return 0;
}

