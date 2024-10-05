#pragma once
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include<algorithm>
#include<iostream>
#include<map>
#include <memory>
using namespace std;

enum thingType{image,text,progressBar};

struct thingMapper
{
	pair<int, thingType> mapper;
	int row, column;
	thingMapper(pair<int, thingType> x, int row, int column);
};
//typedef pair<int, thingType> thingMapper;
//first������һ���ؼ��ڵ����Ŀؼ��б��е��±�

//��Ҫ������ˢ�¡����ֿؼ�����
string summonFrame();
void refreshScreen();


//�����ؼ�
std::shared_ptr<basicImage>  createImage(int row, int column, vector<string> imageByLine);
std::shared_ptr<basicText>   createText(int row, int column, string text);
std::shared_ptr<basicProgressBar>  createProgressBar(int row, int column, int Length);
//���Ŀؼ�
void  changeImage(std::shared_ptr<basicImage> youwant, vector<string> imageByLine);
void  changeText(std::shared_ptr<basicText> youwant, string text);
void  changeProgress(std::shared_ptr<basicProgressBar> youwant, int progress);

//һЩ������������
//�Ű����
template<typename T> void changeLocation(thingType type, T* thing, int row, int column);