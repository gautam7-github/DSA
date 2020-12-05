#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Array
{
private:
    vector<T> arr;

public:
    bool isFull()
    {
        if (arr.size() == arr.capacity())
            return true;
    }
};

int main()
{
    Array<string> Sudo;
    cout << "" << endl;
    return 0;
}