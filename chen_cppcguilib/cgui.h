#pragma once
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include <memory>

//��Ҫ������ˢ�¡����ֿؼ�����
std::string summonFrame();
void refreshScreen();

//���ɲ����ÿؼ�
std::shared_ptr<basicImage>  setImage(int row, int col, std::vector<std::string> imageByLine);
std::shared_ptr<basicText>   setText(int row, int col, std::string text);
std::shared_ptr<basicProgressBar>  setProgressBar(int row, int col, int len);
//��ĳ���ؼ��ŵ�...
void setTo(int row, int col, std::shared_ptr<component> src);
//���Ŀؼ�
void  modifyImage(std::shared_ptr<basicImage> target, std::vector<std::string> imageByLine);
void  modifyText(std::shared_ptr<basicText> target, std::string text);
void  updateProgress(std::shared_ptr<basicProgressBar> target, int progress);
