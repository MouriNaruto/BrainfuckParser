// BrainfuckParser.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

void BrainFuckParser(std::string& BrainFuckCodeSegment)
{
	size_t CodeLength = BrainFuckCodeSegment.size();
	const char* CodeSegment = BrainFuckCodeSegment.c_str();

	size_t DataPointer = 0;
	std::vector<char> DataSegment;
	std::stack<size_t> StackSegment;

	for (size_t CodePointer = 0; CodePointer < CodeLength; ++CodePointer)
	{
		if (DataPointer >= DataSegment.size())
		{
			DataSegment.push_back(0);
		}

		switch (CodeSegment[CodePointer])
		{
		case '>':
			++DataPointer;
			break;
		case '<':
			--DataPointer;
			break;
		case '+':
			++DataSegment[DataPointer];
			break;
		case '-':
			--DataSegment[DataPointer];
			break;
		case '.':
			std::cout << DataSegment[DataPointer];
			break;
		case ',':
			DataSegment[DataPointer] = std::cin.get();
			break;
		case '[':
			if (DataSegment[DataPointer])
			{
				StackSegment.push(CodePointer);
			}
			else
			{
				while (CodePointer < CodeLength && CodeSegment[++CodePointer] != ']');
			}

			break;
		case ']':
			if (DataSegment[DataPointer])
			{
				CodePointer = StackSegment.top() - 1;
				StackSegment.pop();
			}
			break;
		default:
			break;
		}
	}

	return;
}

int main()
{
	//std::string CodeSegment;

	//std::cin >> CodeSegment;

	//BrainFuckParser(CodeSegment);

	BrainFuckParser(std::string("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."));

	return 0;
}
