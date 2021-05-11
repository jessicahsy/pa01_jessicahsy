#include "cards.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Player p1,p2;
  Card c1,c2;
  Card*cpoint1=&c1;
  Card*cpoint2=&c2;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit=line[0];
    char num=line[2];
    c1.append(suit,num);

  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit=line[0];
    char num=line[2];
    c2.append(suit,num);
  }
  cardFile2.close();

  // Start the game
  //##############################################################
  string name;
  //cout<<"Enter Player1 Name>> ";
  //cin >> name;
  p1.setName("Alice");
  //cout<<"Enter Player2 Name>> ";
  //cin >> name;
  p2.setName("Bob");
  //INITIAL:

 int turn=0;//player1 goes on even num turns, player2 goes on odd num turns
 int point=c1.looped(c2,-1);//returns -1 if there are no matches
 //c1.defaultHere();
 int last1=-2;
 int last2=-2;
 while (point!=-1){//ends game/while loop when there are no matches
  if (point!=-1){
    if (turn%2==0){
      //point=c1.looped(c2);
      p1.addMatch();
      cout<<p1.getName()<<" picked matching card "<<c1.getCard()<<endl;
      last1=c1.getP();
      cout<<"   >>>>>>>>Last match in p1: "<<last1<<endl;
      c2.removeOther(point);
      c1.removeNode();
      c1.defaultHere();
      //check for next hand; update point for while loop
      point=c2.looped(c1,last2); //c2.defaultHere();

    }else{
      //point=c2.looped(c1);
      p2.addMatch();
      cout<<p2.getName()<<" picked matching card "<<c2.getCard()<<endl;
      last2=c2.getP();
      cout<<"   >>>>>>>>Last match in p2: "<<last2<<endl;
      c1.removeOther(point);
      c2.removeNode();
      c2.defaultHere();
      //check for next hand; update point for while loop
      point=c1.looped(c2,last1);//c1.defaultHere();
    }
    
  }
  turn++;
  if (point==-1){break;}
 }
  p1.print(&c1);
  p2.print(&c2);
  //cout<<"P1 Matches:"<<p1.getMatch()<<endl;
  //cout<<"P2 Matches:"<<p2.getMatch()<<endl;
  return 0;
}
