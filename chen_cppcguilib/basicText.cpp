#include"basicText.h"
#include <regex>
using namespace std;

basicText::basicText(const string& str) 
	: text(str)
{
	checkText();
	calculateWidth();
}

int basicText::getWidth() const
{
	return width;
}

int basicText::getHeight() const
{
	return 1;
}

std::vector<std::string> basicText::getData() const
{
	return { text };
}

void basicText::setText(const string& str)
{
	text = str;
	checkText();
	calculateWidth();
}

void basicText::checkText()
{
	// ����ַ����������з��滻��' '
	for (char& c : text) {
		if (c == '\n') {
			c = ' ';
		}
	}
}

void basicText::calculateWidth()
{
	width = 0;
	std::regex ansiEscape(R"(\x1B\[[0-9;]*[A-Za-z])");
	// �Ƴ�ANSIת������
	std::string cleanLine = std::regex_replace(text, ansiEscape, "");
	width = cleanLine.length();
}
