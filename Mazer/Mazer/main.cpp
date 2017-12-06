#include "stdafx.h"
#include "MazeMap.h"
#include "stdlib.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "Mazer.h"
using namespace std;


int main(void)
{
	//���岢��ʼ���洢��ͼ���ݵĶ�ά����
	int map[11][11] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD },
		{ WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL },
		{ ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
	};
	//������ͼ����
	MazeMap *mm = new MazeMap('H');
	COORD exitPosition;
	exitPosition.X = 0;
	exitPosition.Y = 9;
	//���õ�ͼ�����еĵ�ͼ
	mm->setMap(&map[0][0], 11, 11);
	//���õ�ͼ�ĳ���
	mm->setExitPosition(exitPosition);
	//��ӡ��ͼ
	mm->printMap();

	string emptySpace(5, '\n');
	cout << emptySpace;

	//������Ϸ�Ƕ�
	Mazer *mzer = new Mazer();
	//���ô�����Ϸ��ɫ���ַ�������������'o'������Ϸ��ɫ
	mzer->setHero('o');
	//����Ϸ��ɫ�����Թ����
	mzer->setPosition(10, 1);
	//������Ϸ��ɫ�ĳ���
	mzer->setDirection('D');
	//������Ϸ��ɫҪ�ߵĵ�ͼ
	mzer->setMap(mm);
	//��ʼ��Ϸ
	mzer->start();

	cout << "�ܹ�����" << mzer->getSteps() << "��" << endl;

	//����ʹ����new�ķ�ʽ�����Ѷ�����������֮��Ҫ�ֶ�����
	delete mzer;
	mzer = NULL;

	delete mm;
	mm = NULL;

	system("pause");
}