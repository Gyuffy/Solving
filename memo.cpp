#include <iostream>

using namespace std;

struct memo
{
    /* data */
    int a;
};

enum Juno
{
    UP,
    LEFT
};


auto main(int argc, char* argv[]) -> int
{
    cout << argc << endl;

    for (size_t i = 0; i < argc; i++)
    {
        cout << '[' << argv[i] << ']';
    }
    cout << endl;
    
    


    return 0;
}
