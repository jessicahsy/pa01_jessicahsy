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
  Hand h;
  Card*cpoint1=&c1;
  Card*cpoint2=&c2;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit=line[0];
    char num=line[2];
    p1.append(cpoint1,suit,num);

  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit=line[0];
    char num=line[2];
    p2.append(cpoint2,suit,num);
  }
  cardFile2.close();

  // Start the game
  //##############################################################
  // string name;
  // cout<<endl<<"Enter Player1 Name>> ";
  // cin >> name;
  // p1.setName(name);
  // cout<<endl<<"Enter Player2 Name>> ";
  // cin >> name;
  // p2.setName(name);
  //INITIAL ^uncomment that later
  //cout<<"p1 name: "<<p1.getName()<<endl;
  cout<<"P1 CARDS\n\n";
  c1.printCards();
  //cout<<"p2 name: "<<p2.getName()<<endl;
  cout<<"P2 CARDS\n\n";
  c2.printCards();
  //_________________________________
  


 cout<<c1.contain('h','3')<<endl;
//  char sc='a';
//  string s(1,sc);
//  cout<<s<<endl;
  while (h.endGame()==false){
     //game continues
    char suit=c1.readList()[0];
    char num=c1.readList()[2];
    cout<<"Contain?"<<c2.contain(suit,num)<<endl;
    cout<<"continue"<<endl;
    break;
  }

  return 0;
}
