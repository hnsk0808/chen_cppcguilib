#include "basicImage.h"
#include<vector>
#include <regex>
using namespace std;

basicImage::basicImage(const vector<string>& image)
	: image(image)
{
	checkImage();
	calculateWidth();
}

int basicImage::getWidth() const
{
	return width;
}

int basicImage::getHeight() const
{
	return image.size();
}

std::vector<std::string> basicImage::getData() const
{
	return image;
}

void basicImage::setImage(const std::vector<std::string>& image)
{
	this->image = image;
	checkImage();
	calculateWidth();
}

void basicImage::checkImage()
{
	// ����ַ����������з��滻��' '
	for (auto& line : image) {
		for (char& c : line) {
			if (c == '\n') {
				c = ' ';
			}
		}
	}
}

void basicImage::calculateWidth()
{
	width = 0;
	std::regex ansiEscape(R"(\x1B\[[0-9;]*[A-Za-z])");
	for (const auto& line : image)
	{
		// �Ƴ�ANSIת������
		std::string cleanLine = std::regex_replace(line, ansiEscape, "");
		width = std::max(cleanLine.length(), width);
	}
}
