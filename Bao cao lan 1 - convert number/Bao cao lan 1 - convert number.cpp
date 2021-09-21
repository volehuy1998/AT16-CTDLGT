// Bao cao lan 1 - convert number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility> // using pair

std::vector< std::pair<char, int> > rename_map =
{
	{'F', 15},
	{'E', 14},
	{'D', 13},
	{'C', 12},
	{'B', 11},
	{'A', 10},
};

char rename(int value)
{
	char result = 0;

	switch (value)
	{
	case 15:
		result = 'F';
		break;
	case 14:
		result = 'E';
		break;
	case 13:
		result = 'D';
		break;
	case 12:
		result = 'C';
		break;
	case 11:
		result = 'B';
		break;
	case 10:
		result = 'A';
		break;
	default:
		result = value + 48;
		break;
	}

	return result;
}

std::string convert_decimal_to_X(int N, int want_to)
{
	std::stack<int> my_stack;
	std::string result = "";

	// build data stack
	do
	{
		int remain = N % want_to;
		my_stack.push(remain);
		N /= want_to;
	} while (N > 0);

	// get result from stack
	while (my_stack.empty() == false)
	{
		int top = my_stack.top();
		result += rename(top);
		my_stack.pop();
	}

	return result;
}

/// <summary>
/// convert decimal to X using stack
/// </summary>
/// <param name="N">decimal</param>
std::string exercise_1(int N, int want_to)
{
	if (N < 0)
		return "Not support yet!";

	return convert_decimal_to_X(N, want_to);
}

/// <summary>
/// convert X to decimal
/// </summary>
/// <param name="value"></param>
/// <param name="want_from"></param>
/// <returns></returns>
int exercise_2(std::string value, int want_from)
{
	int result = 0;
	int len = value.length();

	for (int i = 0; i < len; i++)
	{
		char single = value[i];
		int single_decimal = 0;
		auto it = std::find_if(
			rename_map.begin(),
			rename_map.end(),
			[single](const std::pair<char, int>& element)
			{
				// return pair if vector contain character
				return element.first == single;
			});

		if (it == rename_map.end())
		{
			// not found
			single_decimal = single - 48;
		}
		else
		{
			// found
			single_decimal = (*it).second;
		}

		result += single_decimal * std::pow(want_from, (len - 1) - i);
	}

	return result;
}

int main()
{
	int input = 253;

	std::string bin = exercise_1(input, 2);
	std::string oct = exercise_1(input, 8);
	std::string hex = exercise_1(input, 16);

	int bin_2_dec = exercise_2(bin, 2);
	int oct_2_dec = exercise_2(oct, 8);
	int hex_2_dec = exercise_2(hex, 16);

	std::cout << bin_2_dec << std::endl;
	std::cout << oct_2_dec << std::endl;
	std::cout << hex_2_dec << std::endl;
}
