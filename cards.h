//cards.h
//Authors: Shin-Yi (Jessica) Ho
//All class declarations go here
#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

class Card{//linkedlist with nodes representing cards
 public:
    Card();
    ~Card();
    void printCards() const;
    void append(char suit,char num);
    bool contain(char suit, char num);
    string readList() const;
    Card& operator=(const Card& source);
    

 private:
    void remove_nodes(){
        while(first!=nullptr){
            Node* temp=first->next;
            delete first;
            first=temp; 
        }
    }
    
    struct Node {
        char _suit;
        char _num;
        Node* next;
    };
    Node*first;
    Node*here;
};

class Hand{
 public:
    //static Hand* c;//if 
    bool endGame();
    bool Hcontains(Card* cpoint, char suit, char num) const;//searches if player hand has a particular card using a function in Card class
    void remove_both();//remove, delete c
 private:
    
    

};

class Player{
public:
    Player();
    void addMatch();
    void setName(string newName);
    string getName();
    void print(Card* cpoint);//print player name and match num
    int getMatch();//get match num for print()
    void append(Card* cpoint, char suit, char num);//add cards to set hand
private:
    int match;
    string name;
    
};


#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
