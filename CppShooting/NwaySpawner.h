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
	//�e�𐶐�����i�Q�[�����C���̃|�C���^�AX���W�AY���W�A���a�A�N���ł��o�����̂��A�����p�x�A����̎�ށj
	void Shoot(GameMainScene* gm_scene, float x, float y, float radius,int who, float angle,int b_type)override;
};
