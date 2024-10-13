#pragma once
#include "components/component.h"
#include "logicPos.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class page // : public component
{
public:
    size_t getWeight() const;
    size_t getHeight() const;
    std::vector<cgui::string> getData() const;

    // ��page�е����ݸ�ʽ��Ϊ�ַ���
    std::string toString();

    // ��ӡpage
    void update();

    // ��ĳ���ؼ��ŵ�...
    void setTo(logicPos pos, std::shared_ptr<component> src);

    // ɾ��ĳ���ؼ�
    void erase(logicPos pos);

    // ��տؼ�
    void clear();

private:
    std::map<logicPos, std::shared_ptr<component>> components;
    std::map<int, size_t> lineWidthList;
    std::map<int, size_t> lineHeightList;
};