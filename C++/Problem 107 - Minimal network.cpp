#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <utility>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>


int main()
{
	std::string line;
	std::ifstream input("txt/Problem107.txt");
	std::vector<std::vector<int>> adjacencyMatrix;
	while(std::getline(input, line))
	{
		std::vector<std::string> values;
		adjacencyMatrix.push_back({});
		boost::split(values, line, boost::is_any_of(","), boost::token_compress_on);
		for(auto&& value : values)
			adjacencyMatrix.back().push_back( value == "-" ? std::numeric_limits<int>::max() : boost::lexical_cast<int>(value));
	}
	long totalSum = 0;
	for(const auto& line : adjacencyMatrix)
		for(const auto& value : line)
			totalSum += value == std::numeric_limits<int>::max() ? 0L : value;
	totalSum /= 2;
	std::vector<std::pair<int,int>> table{{-1, -1}};
	for(std::size_t i = 1; i < adjacencyMatrix.size(); i++)
	{
		table.emplace_back(0, adjacencyMatrix[0][i]);
	}
	long sum = 1;
	while(!std::all_of(table.cbegin(), table.cend(), [](auto&& record){ return record.first == -1;}))
	{
		auto min = std::min_element(table.cbegin(), table.cend(), [](auto&& a, auto&& b){
			return a.second < b.second;
		}) - table.cbegin();
		sum += table[min].second;;
		for(std::size_t i = 0; i < table.size(); i++)
			if(table[i].first != -1)
				if(adjacencyMatrix[i][min] < table[i].second)
					table[i] = std::make_pair(min, adjacencyMatrix[i][min]);
		table[min] = std::make_pair(-1, std::numeric_limits<int>::max());
	}
	std::cout << totalSum - sum << std::endl;
	return 0;	
}
