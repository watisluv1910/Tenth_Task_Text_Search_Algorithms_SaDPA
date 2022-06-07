#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "trie_class.h"

using std::cin;
using std::cout;
using std::string;

void FilterList(TrieClass& trie, std::vector<string>& source_list, 
	std::vector<string>& search_list);

int main()
{
	TrieClass trie;

	size_t list_size = 0;

	cout << "Enter the source list size:\n";
	cin >> list_size;

	std::vector<string> source_list(list_size);

	cout << "\nEnter the words for the source list:\n";

	for (auto& word : source_list)
	{
		cin >> word;
	}

	cout << "\n\nEnter the search list size:\n";
	cin >> list_size;

	std::vector<string> search_list(list_size);

	cout << "\nEnter the words for the source list:\n";

	for (auto& word : search_list)
	{
		cin >> word;
	}

	FilterList(trie, source_list, search_list);

	cout << "\n\nOutput:";

	for (auto& word : source_list)
	{
		cout << '\n' << word;
	}
	return 0;
}

void FilterList(TrieClass& trie, std::vector<string>& source_list, 
	std::vector<string>& search_list)
{
	for (auto& word : search_list)
	{
		trie.AddKey(word);
	}

	for (int i = 0; i < source_list.size(); i++)
	{
		bool is_found = false;

		for (size_t j = 0; j < source_list.at(i).length(); j++)
		{
			for (size_t k = j; k < source_list.at(i).length(); k++)
			{
				if (trie.SearchKey(source_list.at(i).substr(j, k - j + 1)))
				{
					source_list.erase(source_list.begin() + i);

					is_found = true;

					i--;

					break;
				}
			}

			if (is_found)
			{
				break;
			}
		}
	}
}
