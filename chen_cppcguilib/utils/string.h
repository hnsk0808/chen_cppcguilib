#pragma once
#include <string>
#include <regex>

namespace cgui {

// std::string��ɵ�bug̫���ˣ�Ϊ�˱���ʹ��ֻ���ٷ�װһ��
// ���string��Ϊ�˿���̨ui��ר����Ƶ�
// ���еĴ��벢û��ת����string���Ժ��ת����string��
// 
// �������£�
// 
// length()���ؿɼ��ַ�����
// size()����ȫ���ַ�����
// 
// ���Unicode�ַ�ռ�ó��Ⱥ���ʾ���Ȳ�һ������
// 
// ��ֱ�Ӳ���rgb�����Զ�ת��ascii����
// 
// ����������з���\n���ɿո�
// 
class string {
public:
    string(const char* in);
    string(std::string_view in);
    string(int count, char c);

    size_t size() const;
    int length() const;
    
    void insert(int pos, const string& other);
    void insert(int pos, int count, char c);

    void pushBackDefaultRGB();
    void insertDefaultRGB(int pos);
    void pushBackRGB(int r, int g, int b);
    void insertRGB(int pos, int r, int g, int b);
    void pushBackBackgroundRGB(int r, int g, int b);
    void insertBackgroundRGB(int pos, int r, int g, int b);
    
    string& operator+(const string& other);
    string& operator+(char other);
    void operator+=(const string& other);
    void operator+=(char other);

    const char* data() const;

private:
    std::string str;
    int visibleLength = 0;

    void calculateVisibleLength();
};

}