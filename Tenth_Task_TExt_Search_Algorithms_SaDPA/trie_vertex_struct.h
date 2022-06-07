#ifndef TRIE_VERTEX_STRUCT_H
#define TRIE_VERTEX_STRUCT_H

#include <vector>

#define ALPHABET_LENGTH 26

struct trie_vertex_struct
{
	trie_vertex_struct(int parent_vrtx = -1, char edge_symbol = 0) :
		is_sample(false), suffix_link(-1), 
		parent_vrtx(parent_vrtx), suffix_flink(-1),
		pattern_num(-1), edge_symbol(edge_symbol)
	{
		children_vrtx.resize(ALPHABET_LENGTH, -1);
		auto_move.resize(ALPHABET_LENGTH, -1);
	};

	std::vector<int> children_vrtx; // vrtx stands for vertexes

	std::vector<int> auto_move; // For memorizing the transition of the automate

	bool is_sample; // Indicates whether this vertex is the initial row

	int suffix_link, // Link on the suffix of this vertex
		suffix_flink, // Link on closest suffix in trie for which is_sample field is true
		parent_vrtx, // Father of this vertex in trie
		pattern_num; // The number of the sample row denoted by this vertex

	char edge_symbol; // Symbol on the edge from parent_vrtx to this vertex
};

#endif // !TRIE_VERTEX_STRUCT_H