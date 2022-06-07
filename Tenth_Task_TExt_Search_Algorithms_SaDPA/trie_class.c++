#include "trie_class.h"

void TrieClass::AddKey(const std::string& key)
{
	if (!head_node_)
	{
		head_node_ = get_new_node();
	}

	// Starting insertion from the root node
	TrieNodeClass* curr_node = head_node_;

	for (size_t i = 0; i < key.length(); i++)
	{
		// Creating a new node if the path doesn't exist:
		if (curr_node->map_.find(key.at(i)) == curr_node->map_.end())
		{
			curr_node->map_[key.at(i)] = get_new_node();
		}

		// Moving to the next node:
		curr_node = curr_node->map_[key.at(i)];
	}

	// Marking the current node as a leaf:
	curr_node->IsLeaf_ = true;
}

bool TrieClass::SearchKey(const std::string& key)
{
	// If trie is empty:
	if (!head_node_) { return false; }

	// Starting searching from the root node
	TrieNodeClass* curr_node = head_node_;

	for (size_t i = 0; i < key.length(); i++)
	{
		// Moving to the next node:
		curr_node = curr_node->map_[key.at(i)];

		// If the string is invalid (reached end of a path in the Trie):
		if (curr_node == nullptr) { return false; }
	}

	// Returns true if the current node is a leaf and the
	// end of the string is reached:
	return curr_node->IsLeaf_;
}
