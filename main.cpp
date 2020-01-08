#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
const int N=1000;
class Cache{
private:
    char* p;
    int n;
public:

    Cache (){
        p = nullptr;
        n = 0;

    }
    Cache(int mb)
    {
        n = mb * 1024 * 1024/4;
        p = new char[n];

    }
    void init () {
        for(unsigned int i = 0; i < n; i++) {
            p[i] = rand() % 1000;
        }
    }
    void heat () {
        for(unsigned int i = 0; i < n; i++) {
            p[i] ++;
        }
    }


    void experement(int reg, int num) {
        unsigned char m;

        auto start = chrono::system_clock::now();
        init();
        heat();

        for (unsigned int i = 0; i < N; i++) {
            switch (reg) {
                case 1:


                    for (unsigned int j = 0; j < n; j++) {

                        m = p[j];
                    }

                    break;

                case 2:

                    for (unsigned int j = n - 1; j >= 0; j--) {
                        m = p[j];
                    }

                    break;

                case 3:
                {

                    for (unsigned int j = 0; j < n; j++) {
                        unsigned int i = rand() % n;


                            m=p[i];


                    }

                }
                    break;
            }

        }
        auto end = chrono::system_clock::now();

        chrono::nanoseconds time = end - start;


        cout << endl << "travel variant: ";

        switch (reg) {
            case 1:

                cout << "direction";
                break;
            case 2:
                cout << "nodirection";
                break;
            case 3:
                cout << "random";
                break;
        }
        cout << endl << "Number: " << num;
        cout << endl << "buffer size: " << n * 4 / (1024 * 1024) << "mb";
        cout << endl << "duration: " << time.count() << " nanosec";


    }
};


int main()
{
    Cache Ob1(1), Ob2(2), Ob3(4), Ob4(8), Ob5(12);


    int i=1;

        Ob1.experement(1,i);
        i++;
        Ob1.experement(2,i);
        i++;
        Ob1.experement(3,i);
        i=1;
    Ob2.experement(1,i);
    i++;
    Ob2.experement(2,i);
    i++;
    Ob2.experement(3,i);
    i=1;
    Ob3.experement(1,i);
    i++;
    Ob3.experement(2,i);
    i++;
    Ob3.experement(3,i);
    i=1;
     Ob4.experement(1,i);
    i++;
    Ob4.experement(2,i);
    i++;
    Ob5.experement(3,i);
    i=1;
     Ob5.experement(1,i);
    i++;
    Ob5.experement(2,i);
    i++;
    Ob5.experement(3,i);
    








    return 0;
}
