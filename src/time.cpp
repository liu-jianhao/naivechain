#include <time.h>
#include <iostream>

using namespace std;


int main()
{
    time_t timep;
    time(&timep);
    cout << "time():" << timep << endl;
    return 0;
}
