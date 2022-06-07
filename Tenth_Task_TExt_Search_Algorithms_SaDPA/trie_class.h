#ifndef TRIE_CLASS_H
#define TRIE_CLASS_H

#include <vector>
#include <unordered_map>

class TrieClass // A class to store a trie
{
public:
	
	TrieClass() {};

	// Iterative function to insert a string into a trie
	void AddKey(const std::string& key);

	// Iterative function to search a string in a trie. 
	// It returns true if the string is found in the trie.
	bool SearchKey(const std::string& key);
private:

	class TrieNodeClass
	{
	public:

		// Node constructor
		TrieNodeClass() : IsLeaf_(false) {};

		// True when the node is a leaf node
		bool IsLeaf_;

		// Each node stores a map to its child nodes
		std::unordered_map<char, TrieNodeClass*> map_;
	};

	TrieNodeClass* head_node_ = nullptr;

	// Method that returns a new Trie node
	TrieNodeClass* get_new_node()
	{
		TrieNodeClass* node = new TrieNodeClass;

		return node;
	};
};

#endif // !TRIE_CLASS_H
