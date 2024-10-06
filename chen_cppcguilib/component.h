#pragma once
#include <vector>
#include <string>

/*
* ��������Ļ���
* 
*/

class component
{
public:
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual std::vector<std::string> getData() const = 0;
};