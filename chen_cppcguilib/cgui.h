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
    // �������Ϸ�һ������ĸ�
    int getUpperComponentHeight(logicPos current);
    // �������Ϸ���������ĸߵ��ܺ�
    int getAboveComponentHeight(logicPos current);
    // ����������Ŀ�
    int getLeftComponentWidth(logicPos current);
    // ���������е�����������Ŀ�����ͬ�е�Ҳֹͣ
    int getAllLeftComponentWidth(logicPos current, int row);
    // ����������ĸ�
    int getLeftComponentHeight(logicPos current);
    // ������Ĵ��ڵ������y��ʾÿ�������߸�����x��ʾÿ�������߸���������Ϊ�������򷵻�λ�ã����򷵻�-1,-1
    logicPos findNearestComponent(logicPos current, int y, int x);
    // �ж�λ���ǲ��ǲ������
    bool isBadLogicPos(logicPos pos);
};