#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
int main() {
	std::map<std::string, int> words{{"one", 1},   {"two", 2},	 {"three", 3},
									 {"four", 4},  {"five", 5},	 {"six", 6},
									 {"seven", 7}, {"eight", 8}, {"nine", 9}};
	std::string filename = "main2.txt";
	std::ifstream file(filename);
	std::string content;
	int total{};

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file " << filename << std::endl;
	}
	int callibration{};
	std::string line;

	while (std::getline(file, line)) {
		int firstWord{};
		int lastWord{};
		auto fposWord{std::string::npos};
		auto rposWord{0};

		std::cout << "[Checking]:" << line << std::endl;
		for (auto &checkVariable : words) {

			auto currentPos = line.find(checkVariable.first);
			if (currentPos != std::string::npos && currentPos <= fposWord) {
				firstWord = checkVariable.second;
				std::cout << "First Word:" << firstWord << std::endl;
				fposWord = currentPos;
			}
		}

		for (auto &checkNo : words) {

			auto currentPos = line.find(std::to_string(checkNo.second));
			std::cout << currentPos << std::endl;
			if (currentPos != std::string::npos && currentPos <= fposWord) {
				firstWord = checkNo.second;
				std::cout << "First Word:" << firstWord << std::endl;
				fposWord = currentPos;
			}
		}
		std::cout << "[Found]: First word " << firstWord << std::endl;
		for (auto &checkVariable : words) {

			auto currentPos = line.rfind(checkVariable.first);
			if (currentPos != std::string::npos && currentPos >= rposWord) {
				lastWord = checkVariable.second;
				std::cout << "Last Word:" << lastWord << std::endl;
				rposWord = currentPos;
			}
		}
		for (auto &checkNo : words) {

			auto currentPos = line.rfind(std::to_string(checkNo.second));
			if (currentPos != std::string::npos && currentPos >= rposWord) {
				lastWord = checkNo.second;
				std::cout << "Last Word:" << lastWord << std::endl;
				rposWord = currentPos;
			}
		}
		std::cout << "[Found]: Last word " << lastWord << std::endl;
		total += firstWord * 10 + lastWord;
		std::cout << "[Result]: " << total << std::endl;
	}
	return 0;
}
