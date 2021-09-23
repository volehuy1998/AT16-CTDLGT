// Bao cao lan 1 - convert number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

char num_to_char_map[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
int char_to_num_map[255] = { 0 };

/// <summary>
/// convert decimal to X using stack
/// </summary>
/// <param name="N">decimal</param>
std::string exercise_1(int N, int want_to)
{
	std::stack<int> my_stack;
	std::string result = "";

	if (N < 0)
		return "Not support yet!";

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
		my_stack.pop();
		char single_char = num_to_char_map[top];
		result += single_char;
	}

	return result;
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
		char single_char = value[i];
		int single_decimal = char_to_num_map[single_char];
		result += single_decimal * std::pow(want_from, (len - 1) - i);
	}

	return result;
}

int main()
{
	// set up
	for (int i = 0; i < 16; i++)
	{
		char_to_num_map[num_to_char_map[i]] = i;
	}

	int input = 0;
	int want_to = 0;
	std::cout << "Enter number (decimal): ";
	std::cin >> input;
	std::cout << "Enter number (convert to: example 2,8,16): ";
	std::cin >> want_to;
	std::string bin = exercise_1(input, want_to);
	std::cout << "Result of " << input << " to " << want_to << ": " << bin << std::endl;

	std::cout << "------------------------------------------------------------------\n";

	std::string input_str = "";
	int want_from = 0;
	std::cout << "Enter string (example: hexa 6F): ";
	std::cin >> input_str;
	std::cout << "Enter number (convert from: 2,8,16): ";
	std::cin >> want_from;

	int decimal = exercise_2(input_str, want_from);
	std::cout << "Result of " << input_str << " from " << want_from << " to 10:" << decimal << std::endl;

	int temp;
	std::cin >> temp;
}
