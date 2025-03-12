#include <iostream>
#include <string>

using namespace std;

int	main(int argc, char** argv)
{
	int i = 0;

	if (argc == 1)
		return (cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl), 1;
	while (argv[++i])
	{
		for (int j = 0; argv[i][j]; j++)
		{
			cout << (char)toupper(argv[i][j]);
		}
	}
	cout << endl;
}
