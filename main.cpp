#include "timeArray.h"
#include <vector>
#include <fstream>
#include <string>

namespace ParkSeohee2114012
{
    void printTimeArrayVector(std::vector<timeArray>v)
    {
        for (const auto& vi : v)
            vi.printAll();
        
        std::cout << " size / capacity: " << v.size() << " / " << v.capacity() << std::endl; 

    }
//     void readWriteTimeFile(std::ifstream& fin, std::ofstream& fout)
//     {
//         timeOfDay
//     }
//     void parsingAlarm(std::iostream& io)   
//     public 
//     {
//         getHour
//         getMinute
//         setHour
//         setMinute
//     }
//    }



int main()
{
    using namespace ParkSeohee2114012;
    
    timeArray ta1{3};
    ta1[0] = timeOfDay{1,1};
    ta1[1] = timeOfDay{2,2};
    ta1[2] = timeOfDay{3,3};
    ta1.printAll();

    timeArray ta2{ta1}; ta2.printAll();
    timeArray ta3{ta2}; ta3 = std::move(ta2); ta2.printAll();

    std::vector<timeArray> v;
    v.push_back(ta1);printTimeArrayVector(v);
    v.push_back(std::move(ta1));printTimeArrayVector(v);
    ta1.printAll();

    std::ifstream fin{"timeData.txt"};
    if (fin.fall())//if(!fin)
    {
        std::cout << "input file open failed\n";
        std::exit(1);
    }
    std::ofstream fout;
    std::string filename;
    std::cout << "Enter out file name: ";
    std::cin >> filename;
    fout.open(filename + ".txt");

    return 0;
}