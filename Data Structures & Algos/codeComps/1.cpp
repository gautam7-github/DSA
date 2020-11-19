#include <bits/stdc++.h>
using namespace std;
void create()
{
	int num;
	string name;
	cout << "HELLO : " << endl;

	ofstream file;
	file.open("data.csv", ios::out | ios::app);

	cin >> num >> name;

	file << num << "," << name << endl;
	file.close();
}
void read()
{
	ifstream file;
	file.open("data.csv", ios::in);

	int num;
	char delim = ',';
	vector<string> row;
	string line, word, temp;

	while (getline(file, line))
	{
		row.clear();
		stringstream ss(line);

		while (getline(ss, word, delim))
		{
			row.push_back(word);
		}
		num = stoi(row[0]);

		cout << "DATA : \n";
		cout << "num : " << row[0] << "\t\tname : " << row[1] << endl;

		row.clear();
	}
	if (file.eof())
	{
		perror("GOODBYE pedit");
	}
	file.close();
}
int main()
{
	create();
	read();
	return 0;
}