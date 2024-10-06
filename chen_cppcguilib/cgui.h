#pragma once
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
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
    std::string summonFrame();
    void refreshScreen();

    //���ɲ����ÿؼ�
    template<class T, class...Args>
    std::shared_ptr<T> set(pos pos, Args...args)
    {
        auto ret = std::make_shared<T>(args...);
        components[pos] = ret;
        refreshScreen();
        return ret;
    }
    std::shared_ptr<basicImage> setImage(int row, int col, std::vector<std::string> imageByLine);
    std::shared_ptr<basicText> setText(int row, int col, std::string text);
    std::shared_ptr<basicProgressBar>  setProgressBar(int row, int col, int len);

    //��ĳ���ؼ��ŵ�...
    void setTo(int row, int col, std::shared_ptr<component> src);

    //���Ŀؼ�
    void  modifyImage(std::shared_ptr<basicImage> src, std::vector<std::string> imageByLine);
    void  modifyText(std::shared_ptr<basicText> src, std::string text);
    void  updateProgress(std::shared_ptr<basicProgressBar> src, int progress);

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