#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::ifstream inf{"main2.txt"};

    int final = 0;

    // std::string name{};
    std::string name{};
    while (inf >> name)
    {
     char tempnum[]= "00";
        for(int i= 0;i <= name.length();i++){
            const char c = name[i];
            if(isdigit(c))
            {
                tempnum[0]=c;
                // std::cout << final << std::endl;
                break;
            }
        }
        for(int i= name.length();i >= 0;i--){
            const char c = name[i];
            if(isdigit(c))
            {
                tempnum[1]=c;
                // std::cout << final << std::endl;
                break;
            }
        }
        final +=atoi(tempnum);
        // std::cout << name << "\n";
    }
    std::cout << final << std::endl;
    // std::cout << final << std::endl;
    std::cin.get();
	return 0;

}
