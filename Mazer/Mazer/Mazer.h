#pragma once
#ifndef MAZER_H
#define MAZER_H

#include <windows.h>
#include "MazeMap.h"

class Mazer
{
public:
	Mazer();
	//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkUp();
	//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkDown();
	//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false	
	bool walkLeft();
	//�����߶�һ�������ɹ����򷵻�true����ʧ�ܣ�������ǽ�����򷵻�false
	bool walkRight();
	//������Ϸ��ɫ��λ��
	void setPosition(int x, int y);
	//���ô�����Ϸ��ɫ���ַ�
	void setHero(char hero);
	//������Ϸ��ɫ�ĳ����������Ҫ����Ϊ����ԭ�����'��'����Ϸ��ɫ��'��'�������ǵ�����Ļ��'��'
	void setDirection(char direction);
	//���ݴ���ķ���ʹ��Ϸ��ɫ�ƶ�һ��
	void moveForward(char direction);
	//���õ�ͼ����
	void setMap(MazeMap *map);
	//��Ϸ��ʼ����
	void start();
	//��ȡ����
	int getSteps();
private:
	//������Ϸ��ɫ���ַ�
	char m_cHero;
	//��Ϸ��ɫ�ĳ���
	char m_cHeroLookAt;
	//��Ϸ��ɫ�ĵ�ǰλ��
	COORD m_heroCurrentPosition;
	//��ͼ����
	MazeMap *m_pMap;
	//��¼��Ϸ��ɫ���˶��ٲ�
	int m_iSteps;
};

#endif
