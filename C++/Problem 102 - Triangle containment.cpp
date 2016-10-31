#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

struct Point{
  int x;
  int y;
};

bool check_side_contains_origin(const Point& a, const Point& b){
  return (b.x-a.x)*a.y==(b.y-a.y)*a.x;
}

double calculate_area(const Point& a, const Point& b, const Point& c){
  return double(abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)))/2;
}

bool check_if_interior_contains_origin(const Point& a, const Point& b, const Point& c){
  Point z{0,0};
  double area1=calculate_area(a,b,c);
  double area2=calculate_area(z,b,c)+calculate_area(a,z,c)+calculate_area(a,b,z);
  return abs(area1-area2)<0.000001;
}

int main(){
  std::fstream input;
  input.open("txt/Problem102.txt");
  std::string line, number;
  int count=0;
  while(std::getline(input,line)){
    Point a,b,c;
    std::stringstream ss(line);
    std::getline(ss,number,',');
    a.x=std::stoi(number);
    std::getline(ss,number,',');
    a.y=std::stoi(number);
    std::getline(ss,number,',');
    b.x=std::stoi(number);
    std::getline(ss,number,',');
    b.y=std::stoi(number);
    std::getline(ss,number,',');
    c.x=std::stoi(number);
    std::getline(ss,number,',');
    c.y=std::stoi(number);
    if(!check_side_contains_origin(a,b) && !check_side_contains_origin(b,c) && !check_side_contains_origin(a,c) && check_if_interior_contains_origin(a,b,c)){
      count++;
    }
  }
  input.close();
  std::cout << "Number of triangles contain origin: " << count << std::endl;
}
