#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define IN_FILE "in_file.txt"
#define OUT_FILE "out_file.txt"
int main() {
    // 读取
    ifstream file;
    file.open(IN_FILE);

    if (!file.is_open())  {
        return 0;
    }

    ofstream output;
    output.open(OUT_FILE);

    std::string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        // 处理
        int begin = line.find("SERVICE");
        if (begin != -1) {
            for (int i = begin; i < line.size(); i++) {
                if (line[i] == ' ') {
                    string result = line.substr(begin, i - begin);
                    output<<"MONITOR."<<result<<","<<endl;
                    cout<<"now:"<<result<<endl;
                    break;
                }
            }
        }
    }

    output.close();
    file.close();


    return 0;
}