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
	int input = 0;
	int want_to = 0;
	std::cout << "Enter number (decimal): ";
	std::cin >> input;
	std::cout << "Enter number (want to convert: example 2,8,16): ";
	std::cin >> want_to;
	std::string bin = exercise_1(input, want_to);
	std::cout << "Result of " << input << " to " << want_to << ": " << bin << std::endl;

	std::cout << "------------------------------------------------------------------\n";

	std::string input_str = "";
	int want_from = 0;
	std::cout << "Enter string (6F): ";
	std::cin >> input_str;
	std::cout << "Enter number (example: 2,8,16): ";
	std::cin >> want_from;

	int decimal = exercise_2(input_str, want_from);
	std::cout << "Result of " << input_str << " to " << want_from << ": " << decimal << std::endl;

	int temp;
	std::cin >> temp;
}
