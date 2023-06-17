#include "trie.hpp"

const unsigned ALPHA_SIZE = 26;

class TrieSimple : public Trie{
private:
	struct TrieNode{
		TrieNode** children;
		bool enWord;

		TrieNode();
		~TrieNode();
	};

	TrieNode* root;

public:
	TrieSimple():root(nullptr){}
	void insert();
	bool search();
	void remove();
	
	string toString(string sep);

};

