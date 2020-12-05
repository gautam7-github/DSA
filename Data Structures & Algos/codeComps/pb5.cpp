// perform separate chaining

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> keys{78, 28, 34, 64, 24, 90, 22, 45, 63};

    vector<forward_list<int>> HashTable(11);
    for (int i = 0; i < keys.size(); i++)
    {
        int hashVal = keys[i] % 11;
        cout << hashVal << " -> " << keys[i] << " % ";
        cout << "11" << endl;
        HashTable[hashVal].emplace_front(keys[i]);
    }
    for (int i = 0; i < 12; i++)
    {
        cout << i << " :: ";
        for (int &j : HashTable[i])
            cout << j << " -> ";
        cout << "X";
        cout << endl;
    }
}