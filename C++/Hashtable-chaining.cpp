/*
 *
 * Author: Mark renzo Santiago
 * University of California, Merced 2017
 * 
 * This implementation of a Hash Table with Chaining was written for the CSE 100: Algorithms Class at UC Merced. 
 * 
 * Description:
 * For the sake of simplicity and time, I will utilize the list class from the c++ library.
 */

#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;


// All values being inserted into the hash table will pass through this has function
int hashFunction(int k, int m) {

	return k % m;
}

// Parses the key from a string to an int
int parseCommand(string c) {

	int key;
	stringstream convert_stm(c.substr(1, c.size()-1));

	if(!(convert_stm >> key)) {
		key = -1;
	}

	return key;
}

// Inserts the key into the table
void Insert(list<int>* Hash, int key, int m) {

	// Pass the key into the hash function and get the index which it will go too
	int index = hashFunction(key, m);

	Hash[index].push_front(key);
}

// Deletes the key from the table
void Delete(list<int>* Hash, int key, int m) {

	int index = hashFunction(key, m), count = 0;

	list<int>::iterator it;
	bool flag;

	for(it = Hash[index].begin(); it != Hash[index].end(); ++it) {
		if(*it == key) {
			list<int>::iterator it_del = Hash[index].begin();
			advance(it_del, count);
			Hash[index].erase(it_del);
			flag = true;
			cout << key << ":DELETED;" <<endl;
			break;
		}

		count++;
	}

	if(!flag) {
		cout << key << ":DELETE_FAILED;" <<endl;
	}

}

// Searches the table for a specific key 
void Search(list<int>* Hash, int key, int m) {

	int index = hashFunction(key, m), count = 0;
	bool flag;

	list<int>::iterator it;

	for(it = Hash[index].begin(); it != Hash[index].end(); ++it) {
		if(*it == key) {	
			cout << key << ":" << "FOUND_AT" << index << "," << count << ";" <<endl;
			flag = true;
			break;
		}
		count++;
	}

	if(!flag) {
		cout << key << ":NOT_FOUND;" <<endl;
	}
}

// Outputs the ENTIRE hash table
void Output(list<int>* Hash, int m) {

	list<int>::iterator it;

	for(int i = 0; i < m; i++) {

		cout << i << ":";
		for(it = Hash[i].begin(); it != Hash[i].end(); ++it) {

			cout << *it << "->";
		}
		cout << ";" <<endl;
	}
}

// main method will listen to instructions from user
int main() {

	// Init our variables and hash table
	int m, key;
	string command = " ";	
	cin >> m;

	list<int>* Hash = new list<int>[m];

	while(command != "e") {
		cin >> command;
		key = parseCommand(command);

		// Switch statement to process commands
		switch(command[0]) {
			case 'i':
				Insert(Hash, key, m);
				break;
			case 'd':
				Delete(Hash, key, m);
				break;
			case 's':
				Search(Hash, key, m);
				break;
			case 'o':
				Output(Hash, m);
				break;
			default:
				break;
		}
	}
	
	return 0;
}
