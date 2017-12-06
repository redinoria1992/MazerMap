#pragma once

#ifndef MAZEMAP_H
#define MAZEMAP_H

#include <windows.h>
//�ڶ�ά�����У�1����ǽ��0����·
#define WALL 1
#define ROAD 0

class MazeMap
{
public:
	MazeMap(char wall);
	MazeMap::~MazeMap();
	void setWallChar(char wall);	//���ô���ǽ���ַ�
	void setMap(int *map, int row, int col);	//����ָ���ͼ��ά�����ָ��
	void printMap();	//��ӡ��ͼ
	int** getMap();		//��ȡ��ͼ��ά�����ָ��
	void setExitPosition(COORD coo);	//���ó���λ��
	COORD getExitPosition();	//��ȡ����λ��
private:
	char m_cWall;	//����ǽ���ַ�
	char m_cRoad;	//����·���ַ�
	int **m_pMap;	//ָ���ͼ��ά�����ָ��
	int m_iMapRow;	//��ά���������
	int m_iMapCol;	//��ά���������
	COORD m_ExitPosition;	//�Թ����ڵ�����
};

#endif

