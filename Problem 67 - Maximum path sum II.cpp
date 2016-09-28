#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numeric>

auto main()->int{
	std::ifstream input;
	input.open("Problem 67 - Maximum path sum II.txt");
	std::string text, temp;
	std::vector<std::vector<int>> pyramid;
	int size=0;
	while(std::getline(input,temp)){
		std::stringstream ss(temp);
		std::string num;
		std::vector<int> vect;
		vect.reserve(++size);
		while(std::getline(ss,num,' ')){
			vect.push_back(stoi(num));
		}
		pyramid.emplace_back(move(vect));
	}
	input.close();
	std::reverse(begin(pyramid),end(pyramid));
	for(auto &v : pyramid){
		for(auto &num : v){
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	for(int y=1; y<pyramid.size(); y++)
	{
		for(int x=0; x<pyramid[y].size(); x++)
		{
			pyramid[y][x]+=std::max(pyramid[y-1][x],pyramid[y-1][x+1]);
		}
	}
	std::cout << pyramid.back().back() << std::endl;
	return 0;
}
