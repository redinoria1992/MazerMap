#include "stdafx.h"
#include "MazeMap.h"
#include <iostream>
using namespace std;

//�вι��캯�����ô�����ַ���ʼ��ǽ���ÿո��ʼ��·
MazeMap::MazeMap(char wall) :m_cWall(wall)
{
	m_cRoad = ' ';
	m_pMap = NULL;
}

//��������
//���ڴ洢��ͼ���ݵĶ�ά�����Ƕ�̬������ڴ�ռ䣬����Ҫ�����������н����ͷ�
MazeMap::~MazeMap()
{
	if (m_pMap) {
		for (int i = 0; i < m_iMapRow; i++)
		{
			delete[] m_pMap[i];
			m_pMap[i] = NULL;
		}
		delete[] m_pMap;
		cout << "~MazeMap()" << endl;
	}
}

//���õ�ͼ
void MazeMap::setMap(int *map, int row, int col)
{
	m_iMapRow = row;
	m_iMapCol = col;
	//Ϊ�洢��ͼ���ݵĶ�ά���鶯̬�����ڴ�ռ�
	m_pMap = new int*[m_iMapRow];    //����m_iMapRow���洢int����ָ����ڴ�ռ�
	for (int i = 0; i < m_iMapRow; i++)
	{
		//��ָ�������е�ָ��ָ�򳤶�Ϊm_iMapCol��int����
		m_pMap[i] = new int[m_iMapCol];
	}

	//���ô���Ķ�ά�����ʼ����ͼ
	int *p = map;
	for (int i = 0; i < m_iMapRow; i++)
	{
		for (int j = 0; j < m_iMapCol; j++)
		{
			m_pMap[i][j] = *p;
			p++;
		}
	}

}

//���ô���ǽ������
void MazeMap::setWallChar(char wall)
{
	m_cWall = wall;
}

//��ӡ��ͼ
void MazeMap::printMap()
{
	for (int i = 0; i < m_iMapRow; i++)
	{
		for (int j = 0; j < m_iMapCol; j++)
		{
			if (m_pMap[i][j]) {		//����Ԫ����Ϊ1�� ���ӡ����ǽ���ַ�
				cout << m_cWall;
			}
			else {		//����Ԫ����Ϊ0�����ӡ����·���ַ�
				cout << m_cRoad;
			}
		}
		cout << endl;
	}
}

//���ص�ͼ��ά����ָ��
int** MazeMap::getMap()
{
	return m_pMap;
}

//���ó���λ��
void MazeMap::setExitPosition(COORD coo)
{
	m_ExitPosition = coo;
}

//��ȡ����λ��
COORD MazeMap::getExitPosition()
{
	return m_ExitPosition;
}