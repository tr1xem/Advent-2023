#include <random>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>


int main()
{
	// char name[] = "test";
    std::map<std::string , char> words {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };
    std::ifstream inf{"main2.txt"};
    std::ofstream edit{"new.txt"};
	// for (int i = 0; i < 6; i++)
	// {
	// 	std::cout << name[i] << std::endl;
	// }
    std::string name{};
    std:: vector<std::pair<std::string, char>> orderedWords(words.begin(), words.end());
    int final = 0;
    while(inf>> name){
        size_t firstPosition = std::string::npos;
        std::string firstword;

        std::cout << name << std::endl;
        for (const auto& num : orderedWords){
            size_t pos = name.find(num.first);
            if (pos != std::string::npos){
                if(firstPosition = std::string::npos ||pos< firstPosition){
                    firstPosition = pos;
                    firstword = num.first;
                    std::cout << num.second<< std::endl;
                    // break;
                }

            }
        }
        std::cout << firstword<< std::endl;
    }
    // std::string name{};
    // while (inf >> name)
    // {
    //  char tempnum[]= "00";
    //     for(int i= 0;i <= name.length();i++){
    //         const char c = name[i];
    //         if(isdigit(c))
    //         {
    //             tempnum[0]=c;
    //             // std::cout << final << std::endl;
    //             break;
    //         }
    //     }
    //     for(int i= name.length();i >= 0;i--){
    //         const char c = name[i];
    //         if(isdigit(c))
    //         {
    //             tempnum[1]=c;
    //             // std::cout << final << std::endl;
    //             break;
    //         }
    //     }
    //     final +=atoi(tempnum);
    //     // std::cout << name << "\n";
    // }
    // std::cout << final << std::endl;
    // // std::cout << final << std::endl;
    std::cin.get();
	return 0;

}
