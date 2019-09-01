#include <bits/stdc++.h>
using namespace std;

class Trie{
	vector< vector<int> > T;
	vector<bool> endOfWord;
	int prox = 1;

public:
	Trie(int maxNodes, int alphabetSize){ //maxNodes is the maximum amount of letters allowed
		T = vector< vector<int> >(maxNodes, vector<int>(alphabetSize, 0));
		endOfWord = vector<bool>(maxNodes, false);
	}

	void insert(string s){
		int at = 1;
		for(int i = 0; i<s.length(); ++i){
			int let = s[i] - 'a'; //base letter of the alphabet
			if(T[at][let] == 0){
				T[at][let] = ++this->prox;
			}
			at = T[at][let];
			if(i == s.length() - 1) endOfWord[at] = true;
		}
	}

	bool search(string s){ //retorna verdadeiro se s é prefixo de alguém que está na TRIE
		int at = 1;
		for(int i = 0; i<s.length(); ++i){
			int let = s[i] - 'a';
			if(T[at][let] == 0) return false;
			at = T[at][let];
		}

		return true;
	}
};
