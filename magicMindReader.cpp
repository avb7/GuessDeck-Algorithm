// Created by Adi
// Date 25th May 2012

/*
    Card Guess
    Objective- The user thinks of a card, the computer asks
                a few questions and displays the card the user thought about.
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm> //for shuffling an array

using namespace std;

//global variables
int deck[21], deck1[7], deck2[7], deck3[7];

//function prototypes
void question();


//various functions
bool checkno(int n){
	int no_exists = 0;
	for (int i = 0; i < 21; i++){
		if (n == ::deck[i]){ no_exists = 1; }
	}
	return no_exists;
}

void distribution(){

	//STEP 1: DISTRIBUTION INTO 3 DECKS
	int tap1 = 0, tap2 = 1, tap3 = 2;
	for (int i = 0; i < 7; i++){
		::deck1[i] = ::deck[tap1];
		tap1 = tap1 + 3;

	}

	for (int i = 0; i < 7; i++){

		::deck2[i] = ::deck[tap2];
		tap2 = tap2 + 3;


	}
	for (int i = 0; i < 7; i++){

		::deck3[i] = ::deck[tap3];
		tap3 = tap3 + 3;


	}



}

int main(){
	char name[50];
	system("cls");

	//inserting numbers. (in order)
	for (int i = 0; i < 21; i++){
		::deck[i] = i;
	}
	//shuffling the deck of numbers
	random_shuffle(std::begin(::deck), std::end(::deck));

	cout << "Hello, I'm a clever C++ program. " << endl;
	system("pause");
	system("cls");

	cout << "What is your name?" << endl;
	cin >> name;
	system("cls");
	cout << "Hi " << name << "! I can baffle your mind with one simple trick!" << endl;
	system("pause");
	system("cls");

	cout << "I can read your mind." << endl;
	system("pause");
	system("cls");

	cout << "So, I'll let you guess a number,"<<endl<<"then I'll ask a few questions." << endl;
	system("pause");
	system("cls");

	cout << "On the basis of a simple card-trick based algorithm," << endl << " I'll find out the number you guessed." << endl;
	system("pause");
	system("cls");

	cout << "Okay, so guess a number between 0-20 (inclusive)."<<endl;
	system("pause");
	system("cls");

	cout << "Now, answer the following questions. " << endl;


	distribution();
	system("cls");

	question();
	system("cls");

	distribution();
	system("cls");

	question();
	system("cls");

	distribution();
	system("cls");

	question();
	cout << endl;

	system("cls");
	cout << "Okay, i've done my calculations." << endl;
	system("pause");
	cout << endl << "YOU GUESSED:  " << ::deck[10] << endl;
	system("pause");

}

void question(){

	//QUESTION
	char ans1, ans2;
	int q1 = 0;

	cout << "Is your number in this set?" << endl;
	for (int i = 0; i < 7; i++){ cout << ::deck1[i] << ", "; }
	cout << endl;
	cout << "y or n?" << endl;
	cin >> ans1;
	if (ans1 == 'y' || ans1 == 'Y'){ q1 = 1; }
	else if (ans1 == 'n' || ans1 == 'N'){

		cout << "Okay, so is your number in this set?" << endl;
		for (int i = 0; i < 7; i++){ cout << ::deck2[i] << ", "; }
		cout << endl;
		cout << "y or n?" << endl;
		cin >> ans2;
		if (ans2 == 'y' || ans2 == 'Y'){ q1 = 2; }
		else if (ans2 == 'n' || ans2 == 'N'){ q1 = 3; }

	}

	if (q1 == 1){
		int j1 = 0;
		for (int i = 0; i < 7; i++){
			::deck[j1] = ::deck2[i];
			j1++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j1] = ::deck1[i];
			j1++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j1] = ::deck3[i];
			j1++;
		}

	}
	else if (q1 == 2){
		int j2 = 0;
		for (int i = 0; i < 7; i++){
			::deck[j2] = ::deck1[i];
			j2++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j2] = ::deck2[i];
			j2++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j2] = ::deck3[i];
			j2++;
		}


	}
	else if (q1 == 3){

		int j3 = 0;
		for (int i = 0; i < 7; i++){
			::deck[j3] = ::deck1[i];
			j3++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j3] = ::deck3[i];
			j3++;
		}
		for (int i = 0; i < 7; i++){
			::deck[j3] = ::deck2[i];
			j3++;
		}


	}
}
