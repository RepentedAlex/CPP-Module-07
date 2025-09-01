#include "iter.hpp"

#include <iostream>

void	printItem(int &value) {
	std::cout << value << std::endl;
}

int	main() {
	int tmp[] = {0, 1, 21, 27, 42};
	int	length = 5;

	::iter(tmp, length, printItem);

	return (0);
}
