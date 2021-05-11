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
Card::Card():first(0),here(0),p_here(-1) {}
Card::~Card(){
    remove_nodes();}

void Card::defaultHere(){p_here=-1;}

string Card::getCard() const{
  Node*n=first;
  for(int i=0;i<p_here;i++){n=n->next;}
  cout<<p_here<<"HERE//";
  string suit(1,(n->_suit));
  string num(1,(n->_num));
  string s=suit+" "+num;
  return s;
}

void Card::printCards() const{
  Node *n = first;
  if (n==NULL){cout<<"empty: no cards"<<endl;}
  while (n) 
  {
    cout << n->_suit<<" "<<n->_num;
    if (n->next) cout <<endl;
    n = n->next;
  }
  cout <<endl;} 

void Card::append(char suit,char num) {
  if (first == 0) { // empty list
    //cout<<"NewList"<<endl;
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
      //here=n;
      cout<<"   contain return: other for"<<n->_suit<<n->_num<<"  "<<other<<endl;
      return other;}
    other++;
    if (n->next){
      n = n->next;
    }else{
      break;}
    }
  return -1; }
void Card::removeOther(int other){
  Node*o=first;
  Node*prev;
  cout<<other<<"  OTHER^^\n";
  for(int i=0;i<other-1;i++){o=o->next;}
  prev=o;
  o=o->next;
  if (o->next){
      prev->next=o->next;
  }else{
    prev->next=NULL;
  }
  delete o;
  }
void Card::removeNode(Card c2){
  //if (here){cout<<here->_suit<<here->_num<<"<-CARD,P->"<<p_here<<endl;}else{cout<<"nothing here";}
  Node*n=first;
  Node*prev;
  for(int i=0;i<p_here-1;i++){n=n->next;}
  prev=n;
  n=n->next;//n is node to be removed
  if (n->next){
      prev->next=n->next;
  }else{
    prev->next=NULL;
  }
  //if (p_here)
  delete n;

}
int Card::looped(Card c){
  Node*n=first;
  Node*h=n;
  int p_=p_here;
  bool lastFound=false;
  //c.defaultHere();
  while (n){
    //if (p_here+1==c.getLen()){p_here=0;lastFound=true;}
    if (lastFound==true){lastFound=false;}else{p_here++;}
    cout<<h->_suit<<h->_num<<"<-CARD,P->"<<p_here<<endl;

    //if (!h){h=n;}

    int test=(c.contain(h->_suit,h->_num));
    if (test!=-1){
      lastFound=true;
      cout<<"   "<<test<<" looped return\n";
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
int Card::getLen(){
  Node*n=first;
  int count=0;
  while (n){
    count++;
    if (n->next){n=n->next;}else{break;}
  }
  //cout<<"Len: "<<count<<endl;
  return count;
}
void Card::getP(){
  cout<<p_here<<"<--P_HERE"<<endl;
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


