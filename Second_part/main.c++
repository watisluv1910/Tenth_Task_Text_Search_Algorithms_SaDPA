#include <iostream>
#include <vector>
#include <string>
#include <regex>

using std::cin;
using std::cout;

int main()
{
	std::cmatch res_expressions;
	std::regex regular("(\-|\()?\s*\d+(\.|\,)?(?(2)(\d+|\0))\s*(\+|\-|\*|\/)\s*[\-]?\d+\2?(?(2)\3)\s*[\)]?", std::regex_constants::basic);
	std::string source_string;

	cout << "Enter the text:\n";
	cin >> source_string;

	if (std::regex_match(source_string.c_str(), res_expressions, regular))
	{
		cout << "\nThe list of operations:";

		for (size_t i = 0; i < res_expressions.size(); i++)
		{
			cout << '\n' << res_expressions[i];
		}
	}

	return 0;
}