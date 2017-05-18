#include "Map.h"

Map::Map()
{
	for (int i = 0; i < 999999; ++i)
	{
		// array.push_back(new vector< pair<string,int>* >);
		array.push_back(0);
	}
}

int Map::hash(string str)
{
  int sum = 0;

  for(int i=0;i < (int)str.length();i++)
  {
    sum+=str[i];
  }

  return sum;
}

void Map::put(string key, int value)
{
	int index = hash(key);
	if (index >=0 && index < array.size())
	{
		if (array[index]!=0)
		{
			array[index] *= value;
		}else{
			array[index] = value;
		}
	}
	// cout<<"put: "<<key<<endl;
}

int Map::get(string key)
{
  	int index = hash(key);
  	// cout<<"get: "<<key<<endl;
	if (index >=0 && index < array.size())
	{
		return array[index];
	}
	return -1;
}


