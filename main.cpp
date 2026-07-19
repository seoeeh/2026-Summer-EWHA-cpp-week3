#include "timeArray.h"
#include <vector>
#include <fstream>
#include <string>
#include "alarm.h"
#include <sstream>

namespace ParkSeohee2114012
{
    void printTimeArrayVector(std::vector<timeArray>v)
    {
        for (const auto& vi : v)
            vi.printAll();
        
        std::cout << " size / capacity: " << v.size() << " / " << v.capacity() << std::endl; 

    }
    void readWriteTimeFile(std::ifstream& fin, std::ofstream& fout)
     {
        std::vector<timeOfDay> v;
         timeOfDay t;

        std::streambuf* origbuf{std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);         
         while (fin >> t) //timeOfDay의 입력연산자
            v.push_back(t);
        std::cout.rdbuf(origbuf);  
        for (const auto& vi : v)
            fout << vi << '\n';
    }
    //std::iostream -> std::stringstream
    //              -> std::fstream
    void parsingAlarm(std::iostream& io)   
    {
        alarm a;

        std::streambuf* origbuf{std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);
        io >> a; //alarm의 입력연산자
        std::cout.rdbuf(origbuf);

        io.clear();
        io.seekp(0, std::ios::end);

        io << a; //alarm의 출력연산자
    }
}


int main()
{
    using namespace ParkSeohee2114012;
    
    // timeArray ta1{3};
    // ta1[0] = timeOfDay{1,1};
    // ta1[1] = timeOfDay{2,2};
    // ta1[2] = timeOfDay{3,3};
    // ta1.printAll();

    // timeArray ta2{ta1}; ta2.printAll();
    // timeArray ta3{ta2}; ta3 = std::move(ta2); ta2.printAll();

    // std::vector<timeArray> v;
    // v.push_back(ta1);printTimeArrayVector(v);
    // v.push_back(std::move(ta1));printTimeArrayVector(v);
    // ta1.printAll();

    // std::ifstream fin{"timeData.txt"};
    // if (fin.fail())//if(!fin)
    // {
    //     std::cout << "input file open failed\n";
    //     std::exit(1);
    // }

    // std::ofstream fout;
    // std::string filename;

    // std::cout << "Enter out file name: ";
    // std::cin >> filename;

    // fout.open(filename + ".txt");


    // if (fout.fail())//if(!fin)
    // {
    //     std::cout << "output file open failed\n";
    //     std::exit(1);
    // }

    // timeOfDay t;
    // fin >> t;
    // fout << t <<  std::endl;


    // readWriteTimeFile(fin, fout);

    // fin.close();
    // fout.close();

    std::stringstream ss;
    std::string ad{"morning\n7 0\n1\n"};
    ss << ad; //std::cout << ad;
    parsingAlarm(ss); //io = ss;
    std::cout << ss.str() << '\n';

    std::fstream fs{"alarmData.txt"};
    if (fs.fail())//if(!fin)
    {
        std::cout << "file open failed\n";
        std::exit(1);
    }
    parsingAlarm(fs);
    
    return 0;
}