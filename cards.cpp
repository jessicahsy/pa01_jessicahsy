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
Card::Card():first(0),here(0) {}
Card::~Card(){
    cout<<"Destroy"<<endl;
    remove_nodes();}
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
bool Card::contain(char suit, char num){
  Node *n = first;
  while (n) {
    if ((n->_suit==suit)&&(n->_num==num)){
      cout<<"Found "<<suit<<" "<<num<<endl;
      here=n;
      cout<<"Here"<<here->_suit<<endl;
      return true;}
    if (n->next){
      n = n->next;
    }else{
      break;}
    }
  return false; }
string Card::readList() const{
  Node*n = here;
  string s;
  if (n) {
    string suit(1,(here->_suit));
    string num(1,(here->_num));
    s=suit+" "+num;
    cout<<"READ:done\n";
  }else{cout<<"READ:empty\n";}

  return s;
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
    }}
    return *this;}
  
//Hand::Hand(){}


//################ HAND  ################
bool Hand::endGame(){
  
  //if there are no matches in the two decks, return true, end game; else return false, continue
  return false;}
bool Hand::Hcontains(Card* cpoint, char suit, char num) const{return true;}



//################ PLAYER  ################
Player::Player():match(0),name("NoName"){}
void Player::addMatch(){}
void Player::setName(string newName){
  name=newName;}
string Player::getName(){return name;}
void Player::append(Card* cpoint, char suit,char num){
    (*cpoint).append(suit,num);}
void Player::print(Card* cpoint){
  (*cpoint).printCards();}


