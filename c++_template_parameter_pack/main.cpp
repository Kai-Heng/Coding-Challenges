#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()

// Recursive case: compute the value of the reversed binary digits
template <bool First, bool...Rest>
int reversed_binary_value() {
    return First + 2 * reversed_binary_value<Rest...>();
}

// Base case: empty list of digits returns 0
template <>
int reversed_binary_value<0>() {
    return 0;
}

// Single digit case: return the digit itself
template <>
int reversed_binary_value<1>() {
    return 1;
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
