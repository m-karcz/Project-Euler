#include <iostream>
#include <fstream>
#include <map>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

std::map<char,int> letter_to_value{{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'T',10},{'J',11},{'Q',12},{'K',13},{'A',14}};

enum class Order{
  high_card=1,
  one_pair=2,
  two_pairs=3,
  three_of_kind=4,
  straight=5,
  flush=6,
  full_house=7,
  four_of_kind=8,
  straight_flush=9,
  royal_flush=10
};

struct Hand{
  Hand(int v, Order o):value(v),order(o){}
  int value;
  Order order;
  friend bool operator> (const Hand& a, const Hand& b);
};

bool operator> (const Hand& a, const Hand& b){
  return (a.order>b.order) ? (true)  : ((a.order==b.order) ? (a.value>b.value) : (false));
}

struct Card{
  Card(std::string s):value(letter_to_value[s[0]]),symbol(s[1]){}
  int value;
  char symbol;
};

Hand get_ranked(std::vector<Card> hand){
  std::sort(std::begin(hand),std::end(hand),[](Card& a, Card& b){return a.value<b.value;});
  bool is_consecutive=true;
  char first_card_color=hand[0].symbol;
  bool is_same_suit=std::all_of(std::begin(hand),std::end(hand),[&](Card& c){return c.symbol==first_card_color;});
  int x_of_kind=1;
  int same=1;
  int max_pair=0;
  for(auto it=std::next(std::begin(hand)); it!=std::end(hand); ++it){
    if((it->value-prev(it)->value)!=1){
      is_consecutive=false;
    }
    if((it->value)==(prev(it)->value)){
      same++;
      if(same==2){
        max_pair=std::max(max_pair, it->value);
      }
    }else{
      x_of_kind*=(same!=4)?same:8;
      same=1;
    }
  }
  x_of_kind*=same;
  if(is_consecutive && is_same_suit){
    if(rbegin(hand)->value==14){
      return Hand(100, Order::royal_flush);
    }else{
      return Hand(std::rbegin(hand)->value, Order::straight_flush);
    }
  }
  if(x_of_kind==8){
    return Hand(std::next(std::begin(hand))->value, Order::four_of_kind);
  }
  if(x_of_kind==6){
    return Hand(std::next(std::next(std::begin(hand)))->value, Order::full_house);
  }
  if(is_same_suit){
    return Hand(std::rbegin(hand)->value, Order::flush);
  }
  if(is_consecutive){
    return Hand(std::rbegin(hand)->value, Order::straight);
  }
  if(x_of_kind==3){
    return Hand(std::next(std::next(std::begin(hand)))->value, Order::three_of_kind);
  }
  if(x_of_kind==4){
    return Hand(max_pair, Order::two_pairs);
  }
  if(x_of_kind==2){
    return Hand(max_pair, Order::one_pair);
  }
  return Hand(std::rbegin(hand)->value, Order::high_card);
}

int main(){
  int wins=0;
  std::ifstream txt("txt/Problem54.txt");
  std::string line;
  int i=0;
  while(std::getline(txt,line)){
    std::vector<std::string> card_vect;
    boost::algorithm::split(card_vect, line, boost::algorithm::is_space());
    ++i;
    std::vector<Card> one;
    std::vector<Card> two;
    for(int i=0; i<5; i++){
      one.push_back(Card(card_vect[i]));
      two.push_back(Card(card_vect[i+5]));
    }
    if(get_ranked(one) > get_ranked(two)){
      wins++;
    }
  }
  std::cout << "Player 1 wins " << wins << " times" << std::endl;
}
