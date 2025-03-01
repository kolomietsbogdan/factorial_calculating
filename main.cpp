#include <iostream>
#include <vector>
#include <chrono>

void multiply(std::vector<int>& result, int multiplier){
	int carry = 0;
	for (size_t i = 0; i < result.size(); ++i){
		int product = result[i] * multiplier + carry;
		result[i] = product % 10;
		carry = product / 10;
	}
	while(carry){
		result.push_back(carry % 10);
		carry /= 10;
	}
}

std::vector<int> factorial(int n){
	std::vector<int> result;
	result.push_back(1);

	for (int i = 2; i <= n; ++i){
		multiply(result, i);
	}

	return result;
}

void printFactorial(const std::vector<int>& result){
	for (auto it = result.rbegin(); it != result.rend(); ++it){
		std::cout << * it;
	}
	std::cout << std::endl;
}

int main()
{
	while(true){
		int n;
		std::cout << "Insert your number(-1 to EXIT): ";
		std::cin >> n;

		if(n == -1){
			std::cout << "Exiting" << std::endl;
			break;
		}

		if(n < 0){
			std::cout << "Factorial isn't defined for negative numbers." << std::endl;
			continue;
		}

		auto start = std::chrono::high_resolution_clock::now();
		std::vector<int> result = factorial(n);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cout << "Factorial of " << n << " is: " << std::endl;
		printFactorial(result);
		std::cout << "Elapsed time is: " << elapsed.count() << " sec" << std::endl;
	}
	std::cout << "Press Enter to Exit." << std::endl;
	return 0;
}
