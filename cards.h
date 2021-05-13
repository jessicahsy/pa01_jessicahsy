//cards.h
//Authors: Shin-Yi (Jessica) Ho
//All class declarations go here
#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

class Card{//linkedlist with nodes representing cards
 public:
    inline Card();
    inline ~Card();
    inline void defaultHere();
    inline string getCard() const;
    inline void printCards() const;
    inline void append(char suit,char num);
    inline int contain(char suit, char num)const;
    inline void removeOther(int other);
    inline void removeNode();
    inline void removeAll();
    inline int looped(Card c,int last);
    inline int getP();
    inline int getLen();
    inline Card(const Card& source);
    inline Card& operator=(const Card& source);
    inline bool operator==(const Card& lhs)const;

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
        //Node* operator++(Node obj){return obj.next;}
    };
    Node*first;
    int p_here;
};

class Player{
public:
    inline Player();
    inline void setName(string newName);
    inline string getName();
    inline void addMatch();
    inline int getMatch();//get match num for print()
    inline void print(Card* cpoint);//print player name and match num
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
