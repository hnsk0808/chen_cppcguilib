#include "string.h"

using namespace cgui;

string::string(const char* in) : str(in) { calculateVisibleLength(); }
string::string(std::string_view in) : str(in) { calculateVisibleLength(); }
string::string(int count, char c) : str(count, c) {}

size_t string::size() const { return str.size(); }
int string::length() const { return visibleLength; }

void string::insert(int pos, const string& other) {
    str.insert(pos, other.str);
    visibleLength += other.visibleLength;
}
void string::insert(int pos, int count, char c) {
    str.insert(pos, count, c);
}

void cgui::string::pushBackDefaultRGB()
{
    str += "\033[0m";
}

void cgui::string::insertDefaultRGB(int pos)
{
    str.insert(pos, "\033[0m");
}

void string::pushBackRGB(int r, int g, int b) {
    str += "\x1b[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}
void string::insertRGB(int pos, int r, int g, int b) {
    str.insert(pos, "\x1b[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}

void cgui::string::pushBackBackgroundRGB(int r, int g, int b)
{
    str += "\x1b[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

void cgui::string::insertBackgroundRGB(int pos, int r, int g, int b)
{
    str.insert(pos, "\x1b[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m");
}

string& string::operator+(const string& other) {
    str += other.str;
    visibleLength += other.visibleLength;
    return *this;
}
string& cgui::string::operator+(char other)
{
    str += other;
    visibleLength += 1;
    return *this;
}
void string::operator+=(const string& other) {
    str += other.str;
    visibleLength += other.visibleLength;
}
void cgui::string::operator+=(char other)
{
    str += other;
    visibleLength += 1;
}

const char* cgui::string::data() const
{
    return str.data();
}

void string::calculateVisibleLength() {
    visibleLength = 0;
    // �����л��з�
    for (auto& c : str) {
        if (c == '\n') { c == ' '; }
    }
    // �Ƴ�ANSIת������
    std::regex ansiEscape(R"(\x1B\[[0-9;]*[A-Za-z])");
    std::string cleanLine = std::regex_replace(str, ansiEscape, "");
    // ����unicode�ַ�
    // todo
    visibleLength = cleanLine.size();
}