#pragma once
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include"multiLineText.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

struct pos {
    int row, col;
};
static bool operator<(const pos& lhs, const pos& rhs) {
    return (lhs.row < rhs.row) || (lhs.row == rhs.row && lhs.col < rhs.col);
}

class page
{
public:
    //��Ҫ������ˢ�¡����ֿؼ�����
    std::string toString();
    void update();

    //��ĳ���ؼ��ŵ�...
    void setTo(int row, int col, std::shared_ptr<component> src);

    //��տؼ�
    void clear();

private:
    std::map<pos, std::shared_ptr<component>> components;
    // �������Ϸ�һ������ĸ�
    int getUpperComponentHeight(const pos& current);
    // �������Ϸ���������ĸߵ��ܺ�
    int getAboveComponentHeight(const pos& current);
    // ����������Ŀ�
    int getLeftComponentWidth(const pos& current);
    // ���������е�����������Ŀ�����ͬ�е�Ҳֹͣ
    int getAllLeftComponentWidth(const pos& current, int row);
    // ����������ĸ�
    int getLeftComponentHeight(const pos& current);
};