#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

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
  std::array<std::array<int, 80>,80> bound_matrix;
  for(int y=0; y<80; y++){
    bound_matrix[y][0]=matrix[y][0];
  }
  for(int x=1; x<80; x++){
    for(int y=0; y<80; y++){
      int bound=bound_matrix[y][x-1];
      for(int y_up=y-1, sum=0; y_up>=0; y_up--){
        sum+=matrix[y_up][x];
        bound=std::min(bound,sum+bound_matrix[y_up][x-1]);
      }
      for(int y_down=y+1, sum=0; y_down<80; y_down++){
        sum+=matrix[y_down][x];
        bound=std::min(bound,sum+bound_matrix[y_down][x-1]);
      }
      bound_matrix[y][x]=matrix[y][x]+bound;
    }
  }
  int path=bound_matrix.front().back();
  for(const auto& line : bound_matrix){
    path=std::min(path,line.back());
  }
  std::cout << path << std::endl;
  return 0;
}
