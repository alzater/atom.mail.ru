// Problem 1
// Check brackets

#include <iostream>
#include <stack>


bool checkBrackets(const std::string& s)
{
	std::stack<char> openedBrackets;

	for (const auto& c : s)
	{
		switch (c)
		{
		case '<':
		case '{':
		case '(':
		case '[':
			openedBrackets.push(c);
			break;
		case ')':
			if (openedBrackets.empty() || openedBrackets.top() != '(')
				return false;
			openedBrackets.pop();
			break;
		case '}':
		case '>':
		case ']':
			// in ASCII there is anothoer simbol between open and close bracket of these types
			if (openedBrackets.empty() || openedBrackets.top() != c-2) 
				return false;
			openedBrackets.pop();
			break;
		default:
			return false;
		}
	}

	if (openedBrackets.empty())
		return true;
	else
		return false;
}

int main()
{
	std::string s;
	std::cin >> s;
	if (checkBrackets(s))
		std::cout << "YES";
	else
		std::cout << "NO";
	
	return 0;
}
	
