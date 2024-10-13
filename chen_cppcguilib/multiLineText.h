#pragma once
#include "component.h"

//�����ı������
class multiLineText : public component
{
public:
    multiLineText(std::vector<cgui::string> textByLine);
    size_t getWidth() const override;
    size_t getHeight() const override;
    std::vector<cgui::string> getData() const override;
    void setMultiText(std::vector<cgui::string> textByLine);

private:
    std::vector<cgui::string> textByLine;
    size_t calcuateLength() const;
};

