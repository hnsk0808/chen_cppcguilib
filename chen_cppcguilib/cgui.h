#pragma once
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include"multiLineText.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

struct logicPos {
    int row, col;
};
static bool operator<(logicPos lhs, logicPos rhs) {
    return (lhs.row < rhs.row) || (lhs.row == rhs.row && lhs.col < rhs.col);
}

class page
{
public:
    //��Ҫ������ˢ�¡����ֿؼ�����
    std::string toString();
    void update();

    //��ĳ���ؼ��ŵ�...
    void setTo(logicPos pos, std::shared_ptr<component> src);

    //��տؼ�
    void clear();

private:
    std::map<logicPos, std::shared_ptr<component>> components;
    std::map<int, int> lineWidthList;
    std::map<int, int> lineHeightList;
};