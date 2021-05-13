// testcards.h
//Authors: Shin-Yi (Jessica) Ho
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructor();
void test_append();
void test_equal();
void test_card();
void test_contain();
void test_remove();
void test_destructor();
void test_helper();
void test_player();



void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); //
void test_equal_empty_list();
void test_card_operator_double_equal();
void test_contain_continue();// matches found, continue
void test_contain_stop();// no more matches found
void test_contain_getCard();// uses 
void test_contain_looped();
void test_remove_single_card();
void test_remove_all_cards();
void test_destructor_no_cards();
void test_destructor_single_card();
void test_destructor_multiple_cards();
void test_helper_getLen();
void test_helper_match_pointer();
void test_player_name();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

// You should add more assertEquals function for your classes. For example, Node/Card class
/*
void assertEquals(Node *expected, Node *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
*/


#endif
