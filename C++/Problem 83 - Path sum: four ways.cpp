#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <climits>

using namespace std;

struct MatrixFromFile{
  static vector<vector<int>> read(string path);
};

struct Node{
  int cost;
  int to;
  Node(int _to, int _cost):to(_to),cost(_cost){}
};

struct Vertex{
  int value=INT_MAX;
  vector<Node> nodes;
  bool visited=false;
};

class Graph{
public:
  Graph(const vector<vector<int>>& matrix, int beginning=0);
protected:
  vector<Vertex> vertexes;
  int beginning;
};

class Dijkstra : public Graph{
public:
  Dijkstra(const vector<vector<int>>& _matrix, int _beginning, int _finish):Graph(_matrix, _beginning),finish(_finish),vertexes_size(vertexes.size()){}
  int get_only_path_cost(void);
private:
  const int vertexes_size;
  const int finish;
  Vertex& vertex_with_lowest_value(void);
  void make_step(void);
};

int main(){
  vector<vector<int>> matrix=MatrixFromFile::read("txt/Problem83.txt");
  Dijkstra dijkstra(matrix,0,matrix.size()*matrix.size()-1);
  cout << dijkstra.get_only_path_cost() << endl;
  return 0;
}

vector<vector<int>> MatrixFromFile::read(string path){
  vector<vector<int>> matrix;
  ifstream input;
  input.open(path);
  string line, temp_str;
  while(getline(input,line)){
    stringstream ss(line);
    vector<int> temp_vect;
    while(getline(ss, temp_str, ',')){
      temp_vect.push_back(stoi(temp_str));
    }
    matrix.push_back(temp_vect);
  }
  input.close();
  return matrix;
}

Graph::Graph(const vector<vector<int>>& matrix,int beginning):beginning(beginning){
  for(int y=0; y<matrix.size(); y++){
    for(int x=0; x<matrix[y].size(); x++){
      Vertex vert;
      if(x>0){
        vert.nodes.push_back(Node(x+y*matrix[0].size()-1,matrix[y][x-1]));
      }
      if(x<matrix[y].size()-1){
        vert.nodes.push_back(Node(x+y*matrix[0].size()+1,matrix[y][x+1]));
      }
      if(y>0){
        vert.nodes.push_back(Node(x+(y-1)*matrix[0].size(), matrix[y-1][x]));
      }
      if(y<matrix.size()-1){
        vert.nodes.push_back(Node(x+(y+1)*matrix[0].size(), matrix[y+1][x]));
      }
      vertexes.push_back(vert);
    }
  }
  vertexes[beginning].value=matrix[beginning/matrix.size()][beginning%matrix.size()];
  for(const auto& node : vertexes[beginning].nodes){
    vertexes[node.to].value=node.cost+vertexes[beginning].value;
  }
}

int Dijkstra::get_only_path_cost(void){
  while(!vertexes[finish].visited){
    make_step();
  }
  return vertexes[finish].value;
}

Vertex& Dijkstra::vertex_with_lowest_value(void){
  int lowest=INT_MAX, index;
  for(int i=0; i<vertexes_size; i++){
    if(!vertexes[i].visited && vertexes[i].value<lowest){
      lowest=vertexes[i].value;
      index=i;
    }
  }
  return vertexes[index];
}

void Dijkstra::make_step(void){
  Vertex& visiting = vertex_with_lowest_value();
  for(const auto& node : visiting.nodes){
    Vertex& to = vertexes[node.to];
    if(to.value>visiting.value+node.cost){
      to.value=visiting.value+node.cost;
    }
  }
  visiting.visited=true;
}
