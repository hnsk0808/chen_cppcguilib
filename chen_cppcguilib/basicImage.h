#pragma once
#include<string>
#include<vector>
using namespace std;
class basicImage
{
public:
    basicImage(vector<string> _image);
    void changeImage(vector<string> _image);
    string selfDraw();//��ʱ���ã�
    string getOneLine(int lineNumber);
    int getTotalLines();
private:
    vector<string> image;
};

