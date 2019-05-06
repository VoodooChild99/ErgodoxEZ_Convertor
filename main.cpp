#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void swap(string*ptr, int i, int j)
{
	string a = ptr[i];
	ptr[i] = ptr[j];
	ptr[j] = a;
}

int main(int argc,char* argv[])
{
	if (argc>=2)
	{
		string keys[3][76];
		ifstream inf;
		inf.open(argv[1], ios::in);
		if (inf)
		{
			string s;
			int num = 0;
			while (getline(inf, s))
			{
				int pos = s.find("LAYOUT_ergodox");
				if (pos != s.npos)
				{
					pos += 15;
					int np = pos;
					for (int i = 0; i < 76; ++i)
					{
						np = s.find(",", pos);
						if (np != s.npos)
						{
							if (i != 75)
							{
								keys[num][i] = s.substr(pos, np - pos);
							}
							else
							{
								keys[num][i] = s.substr(pos, np - pos - 1);
							}
							pos = np + 1;
						}
						else
						{
							cerr << "Wrong!" << endl;
							inf.close();
							return -1;
						}
					}
					++num;
					if (num == 3)
						break;
				}
			}
		}
		else
		{
			cerr << "Can't open file!\n";
			return - 1;
		}

		for (int i = 0; i < 3; ++i)
		{

			swap(keys[i], 0, 44);
			swap(keys[i], 1, 43);
			swap(keys[i], 2, 42);
			swap(keys[i], 3, 41);
			swap(keys[i], 4, 40);
			swap(keys[i], 5, 39);
			swap(keys[i], 6, 38);

			swap(keys[i], 7, 51);
			swap(keys[i], 8, 50);
			swap(keys[i], 9, 49);
			swap(keys[i], 10, 48);
			swap(keys[i], 11, 47);
			swap(keys[i], 12, 46);
			swap(keys[i], 13, 45);

			swap(keys[i], 14, 57);
			swap(keys[i], 15, 56);
			swap(keys[i], 16, 55);
			swap(keys[i], 17, 54);
			swap(keys[i], 18, 53);
			swap(keys[i], 19, 52);

			swap(keys[i], 20, 64);
			swap(keys[i], 21, 63);
			swap(keys[i], 22, 62);
			swap(keys[i], 23, 61);
			swap(keys[i], 24, 60);
			swap(keys[i], 25, 59);
			swap(keys[i], 26, 58);

			swap(keys[i], 27, 69);
			swap(keys[i], 28, 68);
			swap(keys[i], 29, 67);
			swap(keys[i], 30, 66);
			swap(keys[i], 31, 65);

			swap(keys[i], 32, 71);
			swap(keys[i], 33, 70);
			swap(keys[i], 34, 72);
			swap(keys[i], 35, 75);
			swap(keys[i], 36, 74);
			swap(keys[i], 37, 73);
		}

		ofstream of;
		of.open("keymap.c");
		if (of)
		{
			string s;
			int num = 0;
			inf.seekg(0, inf.beg);
			while (getline(inf, s))
			{
				int pos = s.find("LAYOUT_ergodox");
				if (pos == s.npos)
				{
					of << s << endl;
				}
				else
				{
					pos += 15;
					s = s.substr(0, pos);
					for (int i = 0; i < 76; ++i)
					{
						s.append(keys[num][i]);
						if (i != 75)
							s.append(",");
						else
							s.append("),");
					}
					of << s << endl;
					++num;
				}
			}
		}
		else
		{
			cerr << "Can't write to file!\n";
			return -1;
		}

		cout << "done!" << endl;
		inf.close();
		of.close();
	}
	else if(argc<=1)
	{
	cerr << "invalid input!" << endl;
	}
}