//counting how many times each word is mentioned in the text and give N the most frequent

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef map < string, int > statistics;

string prepare (const string &s)
{
	string res;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		char c = tolower (s[i]);
		if ((c >= 'a' && c <= 'z') || c == '\'')
		{
			res.push_back (c);
		}
	}
	return res;
}

// странное название для структуры. в названии нужно существительное
struct one
{
	string word;
	int count;
};

bool compare (const one &a, const one &b)
{
	return (a.count > b.count);
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	freopen ("input.txt", "r", stdin);
	string s;
	statistics a;
	while (!feof (stdin))
	{
		cin >> s;
		//cout << "All right\n";
		string res = prepare (s);
		if (res != "")
		{
			a[res]++;
		}
	}
	
	vector < one > v;
	one buf;
	
	// auto it = ... короче
	for (statistics::iterator it = a.begin(); it != a.end(); ++it)
	{
		buf.word = it -> first;
		buf.count = it -> second;
		v.push_back (buf);
		//cout << it -> first << " " << it -> second << endl;
	}
	
	sort (v.begin(), v.end(), compare);
	
	for (int i = 0; i < n; i++)
	{
		cout << v[i].word << " - " << v[i].count << endl;
	}
	
	return 0;
}

