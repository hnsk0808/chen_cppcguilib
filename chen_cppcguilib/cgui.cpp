#include"cgui.h"
using namespace std;
//tmd�⼸������������һ���ˣ�
vector<thingMapper> allThings;
vector<basicImage> allImage;
vector<basicText> allText;
vector<basicProgressBar> allProgressBars;


//todo:�����Ű�

thingMapper::thingMapper(pair<int, thingType> x, int _row, int _column)
{
	mapper = x;
	row = _row, column = _column;
}

string summonFrame()
{
	string finalFrame = "";
	return finalFrame;
}

void refreshScreen()
{
	string frame = summonFrame();
	system("cls");//����windows(msvc),��ʱ�����Ǽ���Linux���֧��
	cout << frame;
	return;
}

//create��غ�������Ҫע��������е��Ű���ز���(row/column)���ᱻ���ԣ���δ���������ع���
basicImage*  createImage(int row, int column, vector<string> imageByLine)
{
	basicImage returnThing(imageByLine);
	thingMapper thisThing = thingMapper(make_pair(allThings.size(), thingType::image), row, column);
	allImage.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allImage[allImage.size()-1];
}

basicText*  createText(int row, int column, string text)
{
	basicText returnThing(text);
	thingMapper thisThing = thingMapper(make_pair(allThings.size(), thingType::text), row, column);
	allText.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allText[allText.size() - 1];
}

basicProgressBar*  createProgressBar(int row, int column, int length)
{
	basicProgressBar returnthing(length, 0);//�ı���ʽ������δ������
	thingMapper thisThing = thingMapper(make_pair(allThings.size(), thingType::progressBar), row, column);
	allProgressBars.push_back(returnthing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allProgressBars[allProgressBars.size() - 1];
}

//change��غ���
void  changeImage(basicImage* youwant, vector<string> imageByLine)
{
	youwant->changeImage(imageByLine);
	refreshScreen();
	return;
}

void  changeProgress(basicProgressBar* youwant, int progress)
{
	youwant->updateProgress(progress);
	refreshScreen();
	return;
}

void changeText(basicText* youwant, string text)
{
	youwant->changeText(text);
	refreshScreen();
	return;
}