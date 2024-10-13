#pragma once
#include <string>

namespace cgui {

// std::string��ɵ�bug̫���ˣ�Ϊ�˱���ʹ��ֻ���ٷ�װһ��
// ���string��Ϊ�˿���̨ui��ר����Ƶ�
// 
// �������£�
// 
// length()���ؿɼ��ַ�����
// size()����ȫ���ַ�����
// 
// ���Unicode�ַ�ռ�ó��Ⱥ���ʾ���Ȳ�һ������
// 
// ��ֱ�Ӳ���rgb�����Զ�ת��ascii����
// ĩβ���Զ��ָ�Ĭ����ɫ
// 
// ����������з���\n���ɿո�
// 
class string {
public:
    string();
    string(const char* in);
    string(std::string_view in);
    string(size_t count, char c);

    size_t size() const;
    size_t length() const;
    
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
    void operator=(const string& other);
    void operator=(std::string_view other);

    const char* data() const;

private:
    std::string str;
    size_t visibleLength = 0;
    int colorCount = 0; // ������ɫ��asciiת���ַ�����

    size_t pushBackPos() const; // �������ɫ��pos�������һ���ָ�Ĭ����ɫ֮ǰ
    void calculateVisibleLength();
};
string operator+(std::string_view lhs, string& rhs);
string operator+(std::string_view lhs, string&& rhs);

}