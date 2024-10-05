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

bool thingCmp(thingMapper a, thingMapper b)
{
	if (a.row == b.row)
		return a.column < b.column;
	else
		return a.row < b.row;
}

bool allZero(vector<int> vec)
{
	for (auto kv : vec)
		if (kv)
			return false;
	return true;
}

string summonFrame()
{
	string finalFrame = "";
	
	sort(allThings.begin(), allThings.end(), thingCmp);
	int maxRow = allThings[allThings.size() - 1].row;
	//���߼��в��
	vector<vector<thingMapper> > thingsByRow(maxRow + 2);
	for (auto kv : allThings)
		thingsByRow[kv.row].push_back(kv);
	//���߼�����Ⱦ
	for (int i = 1; i <= maxRow; i++)
	{
		//1.����ÿ���ؼ�����ʵ������
		vector<int> linesPerThing = {};
		for (auto kv : thingsByRow[i])
		{
			switch (kv.mapper.second)
			{
			case image:
				linesPerThing.push_back(allImage[kv.mapper.first].getTotalLines());
				break;
			case text:
				linesPerThing.push_back(1);
				break;
			case progressBar:
				linesPerThing.push_back(1);
				break;
			default:
				break;
			}
		}
		
		//2.��ʵ����һ��һ����ʾ
		//���ڿؼ�֮��ļ�๦�ܻ�δ���룬����Ĭ����߿�һ�ұ߿�һ
		string oneLogicLine = "";
		while (!allZero(linesPerThing))
		{
			for (int j = 0; j < linesPerThing.size(); j++)
			{
				if (linesPerThing[j] == 0)
				{
					//����ؼ������жϡ���
					switch (thingsByRow[i][j].mapper.second)
					{
					case image:
					{
						for (int k = 1; k <= allImage[thingsByRow[i][j].mapper.first].getMaxLineLength(); k++)
							oneLogicLine += " ";
						break;
					}
					case text:
					{
						for (int k = 1; k <= allText[thingsByRow[i][j].mapper.first].getLength(); k++)
							oneLogicLine += " ";
						break;
					}
					case progressBar:
					{
						for (int k = 1; k <= allProgressBars[thingsByRow[i][j].mapper.first].getLength(); k++)
							oneLogicLine += " ";
						break;
					}
					default:
						break;
					}
				}
				else
				{
					//����ؼ������жϡ���
					switch (thingsByRow[i][j].mapper.second)
					{
					case image:
					{
						//���ͼƬ��һ��
						auto thisImage = allImage[thingsByRow[i][j].mapper.first];
						oneLogicLine += thisImage.getOneLine(thisImage.getTotalLines() - linesPerThing[j] + 1);
						if (thisImage.getOneLine(thisImage.getTotalLines() - linesPerThing[j] + 1).length() < thisImage.getMaxLineLength())
						{
							for (int k = 1; k <= thisImage.getOneLine(thisImage.getTotalLines() - linesPerThing[j] + 1).length() - thisImage.getMaxLineLength(); k++)
								oneLogicLine += " ";
						}
						linesPerThing[j]--;
						break;
					}
					case text:
					{
						auto& thisText = allText[thingsByRow[i][j].mapper.first];
						oneLogicLine += thisText.selfDraw();
						linesPerThing[j]--;
						break;
					}
					case progressBar:
					{
						auto thisProgressBar = allProgressBars[thingsByRow[i][j].mapper.first];
						oneLogicLine += thisProgressBar.selfDraw();
						linesPerThing[j]--;
						break;
					}
					default:
						break;
					}
				}
				oneLogicLine = oneLogicLine + " ";
			}
			oneLogicLine = oneLogicLine + "\n";
		}
		finalFrame = finalFrame + oneLogicLine;
	}

	return finalFrame;
}

void refreshScreen()
{
	string frame = summonFrame();
	// ʹ��ANSI��������
	system("cls");
	cout << frame;
	return;
}

//create��غ�������Ҫע��������е��Ű���ز���(row/column)���ᱻ���ԣ���δ���������ع���
basicImage*  createImage(int row, int column, vector<string> imageByLine)
{
	basicImage returnThing(imageByLine);
	thingMapper thisThing = thingMapper(make_pair(allImage.size(), thingType::image), row, column);
	allImage.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allImage[allImage.size()-1];
}

basicText*  createText(int row, int column, string text)
{
	basicText returnThing(text);
	thingMapper thisThing = thingMapper(make_pair(allText.size(), thingType::text), row, column);
	allText.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allText[allText.size() - 1];
}

basicProgressBar*  createProgressBar(int row, int column, int length)
{
<<<<<<< HEAD
	basicProgressBar returnthing(length, 0);//改变样式将会在未来加�?
	thingMapper thisThing = thingMapper(make_pair(allProgressBars.size(), thingType::progressBar), row, column);
=======
	basicProgressBar returnthing(length, 0);//�ı���ʽ������δ������
	thingMapper thisThing = thingMapper(make_pair(allThings.size(), thingType::progressBar), row, column);
>>>>>>> b409db0b33c37ec4b8bfcc2da1909112fa3f8583
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