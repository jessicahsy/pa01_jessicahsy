//cards.cpp
//Authors: Shin-Yi (Jessica) Ho
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
  // uses p_here to determine which node to remove
  // p_here determined in looped() and points to where the match is found
  //   in player playing this hand
  // variable other is returned by contain() and looped(),
  //   which indicates where the match is found in the other player's set
  // if there are no matches, contain() returns -1, break from while loop, game ends

//################ CARD  ################
inline Card::Card():first(0),p_here(-1) {}
inline Card::~Card(){
    remove_nodes();}

inline void Card::defaultHere(){p_here=-1;}

inline string Card::getCard() const{
  //used to locate card for output right after match is found
  //dependent on p_here
  Node*n=first;
  for(int i=0;i<p_here;i++){n=n->next;}
  string suit(1,(n->_suit));
  string num(1,(n->_num));
  string s=suit+" "+num;
  return s;
}

inline void Card::printCards() const{
  Node *n = first;
  if (n==NULL){cout<<"Empty: No Cards"<<endl;}
  while (n) 
  {
    cout << n->_suit<<" "<<n->_num;
    if (n->next) cout <<endl;
    n = n->next;
  }
  cout <<endl;} 

inline void Card::append(char suit,char num) {//append card node to end of list
  if (first == 0) { // empty list
    first = new Node;
    first->_suit = suit;
    first->_num = num;
    first->next = 0;
  }
  else {
    Node *n = first;
    while (n->next) // not last node yet
      n = n->next;
    n->next = new Node;
    n->next->_suit = suit;
    n->next->_num = num;
    n->next->next = 0;
  }}
inline int Card::contain(char suit, char num)const{//returns where match is found in other player's set
  Node *n = first;
  int other=0;
  while (n) {
    if ((n->_suit==suit)&&(n->_num==num)){
      return other;}
    if (n->next){
      other++;
      n = n->next;
    }else{
      break;}
    }
  return -1; }
inline void Card::removeOther(int other){//remove card in the other player's set
  Node*o=first;
  Node*prev;
  for(int i=0;i<other-1;i++){o=o->next;}
  prev=o;
  o=o->next;//o is now node to be removed
  if (o->next){
      prev->next=o->next;
  }else{
    prev->next=NULL;
  }
  delete o;
  }
inline void Card::removeNode(){//remove card in the playing player's set
  Node*n=first;
  Node*prev;
  for(int i=0;i<p_here-1;i++){n=n->next;}
  prev=n;
  n=n->next;//n is now node to be removed
  if (n->next){
      prev->next=n->next;
  }else{
    prev->next=NULL;
  }
  delete n;
}
inline void Card::removeAll(){//remove all nodes
  remove_nodes();
}
inline int Card::looped(Card c, int last){
  //sets p_here to where match is found in playing player's set
  //returns where match is found in the other player's set
  Node*n=first;
  Node*h=n;
  bool lastFound=false;
  //int pt;
  if (last!=-2){
    p_here=last-1;
    for(int i=0;i<last;i++){n=n->next;h=h->next;}
    }

  while (n){
    if (lastFound==true){lastFound=false;}else{p_here++;}
    //cout<<h->_suit<<h->_num<<"<-CARD,P->"<<p_here<<endl; 

    int test=(c.contain(h->_suit,h->_num));
    if (test!=-1){
      return test;}
    if (n->next){
      n=n->next;
      if (h->next){
        h=h->next;
      }else{h=first;}
    }else{
      break;}
    }
  return -1;
}
inline int Card::getP(){//used for testing, get p_here
  return p_here;
}
inline int Card::getLen(){//get length of list
  Node*n=first;
  int count=0;
  while (n){
    count++;
    if (n->next){n=n->next;}else{break;}}
  return count;
}

inline Card::Card(const Card& source) {//copy constructor
  if (source.first!=nullptr){
    Node*obj=source.first;
    first=new Node;
    Node*cur=first;
    while (obj->next!=nullptr){
      cur->_suit=obj->_suit;
      cur->_num=obj->_num;
      cur->next=new Node;
      cur=cur->next;
      obj=obj->next;
    }
    cur->next=nullptr;
    cur->_suit=obj->_suit;
    cur->_num=obj->_num;
  }
}

inline Card& Card::operator=(const Card& source){//overloaded assignment operator
  if (this!=&source){
    remove_nodes();
    if (source.first!=nullptr){
      Node*obj=source.first;
      first=new Node;
      Node*cur=first;
      while (obj->next!=nullptr){
        cur->_suit=obj->_suit;
        cur->_num=obj->_num;
        cur->next=new Node;
        cur=cur->next;
        obj=obj->next;
      }
      cur->next=nullptr;
      cur->_suit=obj->_suit;
      cur->_num=obj->_num;
    }
  }
  return *this;}
inline bool Card::operator==(const Card & lhs) const{//overloaded double equal operator
// tests if both card lists are exactly the same
  if (first){
    if (!lhs.first){return false;}
    Node* n=first;
    Node* o= lhs.first;
    while ((n->next)&&(o->next)){
      if ((n->_suit==o->_suit)&&(n->_num==o->_num)){cout<<"yay\n";}else{return false;}
      n=n->next; o=o->next;
    }
    if ((n->next)||(o->next)){return false;}//len of lists are different
    }
  else{
    if(lhs.first){return false;}}
  return true;}


//################ PLAYER  ################
inline Player::Player():match(0),name("NoName"){}
inline void Player::setName(string newName){name=newName;}
inline string Player::getName(){return name;}
inline void Player::addMatch(){match++;}
inline int Player::getMatch(){return match;}
inline void Player::print(Card* cpoint){//outputs player name and all cards
  cout<<endl<<name<<"'s cards:\n";
  (*cpoint).printCards();}


