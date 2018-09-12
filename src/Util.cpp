#include "Util.h"

vector<pair<string, pair< int, int> > > fill_moves(string m)
{
	int i=0, j=0;
	string ch = "";
	string temp_str = "";
	vector<pair<string, pair< int, int> > > answer;
	int a,b;
	while(i < m.length())
	{
		int count = 0;
		j = i;
		while(count < 3)
		{
			if(m[j] != ' ')
			{
				while(m[j] != ' ')
					j++;
				count++;
			}
			while(m[j] == ' ')
				j++;
		}
		temp_str = m.substr(i, j - i);
		i = j;
		if(fill_move(temp_str, ch, a, b) == 1)
		{
			answer.push_back(make_pair(ch, make_pair(a, b)));
		}
		else
		{
			break;
		}
	}
	return answer;
}

int fill_move(string m, string &ch, int &a, int &b)
{
	if(m.length() == 0)
		return 0;
	
	int i=0;
	while(m[i]==' ')
		i++;

	int j=i;
	while(m[j]!=' ')
		j++;
	ch = m.substr(i, j-i);

	i = j;
	while(m[i]==' ')
		i++;

	j=i;
	while(m[j]!=' ')
		j++;

	a = stoi(m.substr(i, j-i));

	i = j+1;
	j++;
	while(j<m.length() && m[j]!=' ')
		j++;

	if(j == m.length() - 1)
	{
		b = stoi(m.substr(i, j-i+1));
	}
	else
	{
		b = stoi(m.substr(i, j-i));
	}
	return 1;
}