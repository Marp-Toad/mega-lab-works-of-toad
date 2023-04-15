#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <initializer_list>
#include <utility>
#include <vector>
#include <map>

using namespace std;

class pc {

    string processor;
    int ram, hHD;

public:

    pc() {
        processor = "";
        ram = 0;
        hHD = 0;
    }

    pc(string anchous, int nautilus, int kelp) {
        processor = anchous;
        ram = nautilus;
        hHD = kelp;
    }

    pc(const pc& link) {
        processor = link.processor;
        ram = link.ram;
        hHD = link.hHD;
    }

    ~pc() {

    }

    string get_processor() {
        return processor;
    }

    int get_ram() {
        return ram;
    }

    int get_hHD() {
        return hHD;
    }

    void set_processor(string proc) {
        processor = proc;
    }

    void set_ram(int operativka) {
        ram = operativka;
    }

    void set_hHD(int joskiy) {
        hHD = joskiy;
    }

    void showAtt() {

        cout << processor << "\n";
        cout << ram << "\n";
        cout << hHD << "\n";

    }


};

int main() {

    pc pcExample1;
    pc pcExample2("celeron", 8, 8);
    pc pcExample3(pcExample1);

    pcExample2.showAtt();

    cout << pcExample2.get_hHD();

}
