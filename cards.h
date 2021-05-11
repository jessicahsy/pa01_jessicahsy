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
    void defaultHere();
    string getCard() const;
    void printCards() const;
    void append(char suit,char num);
    int contain(char suit, char num)const;
    void removeOther(int other);
    void removeNode();
    int looped(Card c,int last);
    int getP();
    Card(const Card& source);
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
    int p_here;
};

class Player{
public:
    Player();
    void setName(string newName);
    string getName();
    void addMatch();
    int getMatch();//get match num for print()
    //void append(Card* cpoint, char suit, char num);// dont need this
    void print(Card* cpoint);//print player name and match num
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
