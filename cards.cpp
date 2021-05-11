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
//################ CARD  ################
Card::Card():first(0),p_here(-1) {}
Card::~Card(){
    remove_nodes();}
// void Card::tryy(){
//   Node*n=first;
//   cout<<n->_suit<<n->_num<<"<-CARD"<<endl; n++;
//   cout<<n->_suit<<n->_num<<"<-CARD"<<endl;
// }

void Card::defaultHere(){p_here=-1;}

string Card::getCard() const{
  Node*n=first;
  for(int i=0;i<p_here;i++){n=n->next;}
  string suit(1,(n->_suit));
  string num(1,(n->_num));
  string s=suit+" "+num;
  return s;
}

void Card::printCards() const{
  Node *n = first;
  if (n==NULL){cout<<"Empty: No Cards"<<endl;}
  while (n) 
  {
    cout << n->_suit<<" "<<n->_num;
    if (n->next) cout <<endl;
    n = n->next;
  }
  cout <<endl;} 

void Card::append(char suit,char num) {
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
int Card::contain(char suit, char num)const{
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
void Card::removeOther(int other){
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
void Card::removeNode(){
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
int Card::looped(Card c, int last){
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
int Card::getP(){
  return p_here;
}

Card::Card(const Card& source) {
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

Card& Card::operator=(const Card& source){
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
  

//################ PLAYER  ################
Player::Player():match(0),name("NoName"){}
void Player::setName(string newName){name=newName;}
string Player::getName(){return name;}
void Player::addMatch(){match++;}
int Player::getMatch(){return match;}
void Player::print(Card* cpoint){
  cout<<endl<<name<<"'s cards:\n";
  (*cpoint).printCards();}


