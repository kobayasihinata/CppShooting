#pragma once
#include"BulletsSpawner.h"

class NwaySpawner:
	public BulletsSpawner
{
private:
	int numBullets;		//���˂���e�̐�
	float BaseAngle;	//���˂���ŏ��̒e�̌���
	float AngleDiff;	//�e���m�̊p�x��
public:
	void Shoot()override;
};
