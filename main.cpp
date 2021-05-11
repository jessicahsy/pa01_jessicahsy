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
  //cout<<"p1: "<<p1.getName()<<endl;
  //c1.printCards();
  //cout<<"p2: "<<p2.getName()<<endl;
  //c2.printCards();
 int turn=0;//player1 goes on even num turns, player2 goes on odd num turns
 int point=c1.looped(c2);
 c1.defaultHere();
 bool go=true;
 while (point!=-1){
  cout<<endl<<"GO"<<endl<<point<<endl;
  if (point!=-1){
    cout<<"turn "<<turn<<endl;
    if (turn%2==0){
      cout<<"_______ALICE_____\n";
      point=c1.looped(c2);
      p1.addMatch();
      cout<<"#######################"<<p1.getName()<<" picked matching card "<<c1.getCard()<<endl;
      c2.removeOther(point);
      c1.removeNode(c2);
      c1.defaultHere();

    }else{
      //if (go==false){c2.defaultHere();go=true;}
      //c2.defaultHere();
      point=c2.looped(c1);
      p2.addMatch();
      cout<<"#######################"<<p2.getName()<<" picked matching card "<<c2.getCard()<<endl;
      c1.removeOther(point);
      c2.removeNode(c1);
      c2.defaultHere();
    }
    
  }
  turn++;
  cout<<">>>>>New turn:";
  if (turn%2==0){point=c1.looped(c2);c1.defaultHere(); }else{point=c2.looped(c1); c2.defaultHere();}
  //cout<<point<<"<--point"<<endl;
  //c1.defaultHere();c2.defaultHere();
  if (point==-1){break;}
 }
 //cout<<c1.looped(c2);
  p1.print(&c1);
  p2.print(&c2);
  cout<<"P1 Matches:"<<p1.getMatch()<<endl;
  cout<<"P2 Matches:"<<p2.getMatch()<<endl;
  return 0;
}
