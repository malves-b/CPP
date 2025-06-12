#include "iter.hpp"

int main(void)
{
	int		arr[5] = {1, 9, 30, 20, 7};
	char	arr2[7] = {'M', 'A', 'T', 'H', 'E', 'U', 'S'};

	iter(arr, 5, print<int>);
	iter(arr2, 7, print<char>);
	return 0;
}
