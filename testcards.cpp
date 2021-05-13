// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <cstddef>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;





int main(){
  //Player p1,p2;
  runAll();
  return 0;
}



void runAll(){
  test_append();
  test_equal();
  test_card();
  test_contain();
  test_remove();
  test_destructor();
  test_helper();
  test_player();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  END_TEST("test_equal");
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}

void test_contain(){
  START_TEST("test_contain");
  test_contain_continue();
  test_contain_stop();
  test_remove_all_cards();
  END_TEST("test_contain");
}

void test_remove(){
  START_TEST("test_remove");
  test_remove_single_card();
  test_remove_all_cards();
  END_TEST("test_remove");
}
void test_destructor(){
  START_TEST("test_destructor");
  test_destructor_no_cards();
  test_destructor_single_card();
  test_destructor_multiple_cards();  
  END_TEST("test_destructor");
}

void test_helper(){
  START_TEST("test_helper");
  test_helper_getLen();
  test_helper_match_pointer();
  END_TEST("test_helper");
}
void test_player(){
  START_TEST("test_player");
  test_player_name();
  END_TEST("test_player");
}


void test_append_empty_list(){ 
  Card c1;
  c1.append('s','a');
  cout<<"Append to empty list:\n";
  c1.printCards();
}

void test_append_single_element_list(){ 
  Card c1;
  c1.append('s','a');
  c1.append('h','2');
  cout<<"Append to single element list:\n";
  c1.printCards();

}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  Card c1;//initialized empty list
  assertEquals(c1.getLen(),0,testname);
}


void test_card_operator_double_equal(){
  Card c1,c2;
  c1.append('s','a');
  c1.append('h','2');
  c2.append('s','a');
  assertEquals((c1==c2),0,"Doubel Equal");
  //overloaded ==operator implemented just for the requirement
}

void test_contain_continue(){
  Card c1,c2;
  c1.append('s','a');
  c2.append('h','2');
  c2.append('s','a');
  c1.looped(c2,-2);// last(-2) is initialized value,
  //looped returns -1 if no matches found
  assertEquals((c1.looped(c2,-2)!=-1),1,"more matches");
}
void test_contain_stop(){
  Card c1,c2;
  c1.append('c','5');
  c1.append('d','4');
  c2.append('h','2');
  c2.append('s','a');
  c1.looped(c2,-2);// last(-2) is initialized value,
  //looped returns where a match is made in c2
  assertEquals(c1.looped(c2,-2),-1,"no matches");
}
void test_remove_single_card(){
  Card c1,c2;
  c1.append('c','5');
  c1.append('h','2');
  c1.append('s','a');
  c2.append('c','k');
  c2.append('h','2');
  
  int other=c1.looped(c2,-2);//loops through c1, returns where match is found in c2
  c2.removeOther(other);// matching node h2 removed in c2
  c1.removeNode();// matching node h2 removed in c1
  assertEquals(c1.contain('h','2'),-1,"remove first pair");

  // uses p_here to determine which node to remove
  // p_here determined in looped(), using contain()

}
void test_remove_all_cards(){
  Card c1,c2;
  c1.append('c','5');
  c1.append('h','2');
  c1.append('s','a');
  c1.removeAll();
  c2.append('c','k');
  c2.append('h','2');
  c2.removeAll();
  assertEquals(c1.getLen(),0,"remove all");
}
void test_destructor_no_cards(){
  Card c1;
  c1.~Card();
  assertEquals(c1.getLen(),0,"destructor 0");
}

void test_destructor_single_card(){
  Card c1;
  c1.append('h','q');
  c1.~Card();
  assertEquals(c1.getLen(),0,"destructor 1");
}
void test_destructor_multiple_cards(){
  Card c1;
  c1.append('h','q');
  c1.append('d','8');
  c1.append('c','5');
  c1.~Card();
  assertEquals(c1.getLen(),0,"destructor 2+");
}
void test_helper_getLen(){
  Card c1,c2,c3,c4;
  c1.append('c','5');
  c1.append('h','2');
  c1.append('s','a');
  c1.append('h','q');
  c1.append('d','8');
  assertEquals(c1.getLen(),5,"find length");
  c2.append('s','a');
  c2.append('c','k');
  assertEquals(c2.getLen(),2,"find length");
  c3.append('h','2');
  assertEquals(c3.getLen(),1,"find length");
  assertEquals(c4.getLen(),0,"find length");
}
void test_helper_match_pointer(){
  Card c1,c2;
  c1.append('c','5');
  c1.append('h','2');
  c1.append('s','a');
  c2.append('s','a');
  c2.append('c','k');
  c2.append('h','2');
  int other=c1.looped(c2,-2);//c1's turn;
  //looped() returns where match is found in c2
  //p_here is where match is found in c1
  assertEquals(c1.getP(),1,"locate match in this set");//h2 is found for this round
  assertEquals(other,2,"locate match in other player's set");

}
void test_player_name(){
  Player p1;
  p1.setName("Spongebob");
  assertEquals(p1.getName(),"Spongebob","get/set name");
  p1.setName("Patrick");
  assertEquals(p1.getName(),"Patrick","get/set name");
}

//################ CARD  ################
inline Card::Card():first(0),p_here(-1) {}
inline Card::~Card(){
    remove_nodes();}

inline void Card::defaultHere(){p_here=-1;}

inline string Card::getCard() const{
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

inline void Card::append(char suit,char num) {
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
inline int Card::contain(char suit, char num)const{
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
inline void Card::removeOther(int other){
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
inline void Card::removeNode(){
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
inline void Card::removeAll(){
  remove_nodes();
}
inline int Card::looped(Card c, int last){
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
inline int Card::getP(){
  return p_here;
}
inline int Card::getLen(){
  Node*n=first;
  int count=0;
  while (n){
    count++;
    if (n->next){n=n->next;}else{break;}}
  return count;
}

inline Card::Card(const Card& source) {
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

inline Card& Card::operator=(const Card& source){
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
inline bool Card::operator==(const Card & lhs) const{
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
inline void Player::print(Card* cpoint){
  cout<<endl<<name<<"'s cards:\n";
  (*cpoint).printCards();}

