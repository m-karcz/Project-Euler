#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

auto main()->int{
  std::ifstream input;
  input.open("Problem 81 - Path sum: two ways.txt");
  std::string line, temp_str;
  std::vector<std::vector<int>> matrix;
  while(std::getline(input,line)){
    std::stringstream ss(line);
    std::vector<int> temp_vect;
    while(std::getline(ss, temp_str, ',')){
      temp_vect.push_back(std::stoi(temp_str));
    }
    matrix.push_back(temp_vect);
  }
  input.close();
  for(int y=1; y<80; y++){
    matrix[y][0]+=matrix[y-1][0];
  }
  for(int x=1; x<80; x++){
    matrix[0][x]+=matrix[0][x-1];
    for(int y=1; y<80; y++){
      matrix[y][x]+=std::min(matrix[y-1][x],matrix[y][x-1]);
    }
  }
  std::cout << matrix.back().back() << std::endl;
  return 0;
}
