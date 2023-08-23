#pragma once
#include"BulletsSpawner.h"
#include"WeaponPickScene.h"

class WeaponPickScene;

class NwaySpawner:
	public BulletsSpawner
{
private:
	int numBullets;		//���˂���e�̐�
	float BaseAngle;	//���˂���ŏ��̒e�̌���
	float AngleDiff;	//�e���m�̊p�x��
public:
	//�e�𐶐�����i�Q�[�����C���̃|�C���^�AX���W�AY���W�A���a�A���x�A�N���ł��o�����̂��A�����p�x�A����̎�ށj
	void Shoot(GameMainScene* gm_scene, float x, float y, float radius, float speed, int who, float angle,int b_type)override;
	//�e�𐶐�����i����I����ʂ̃|�C���^�AX���W�AY���W�A���a�A���x�A�N���ł��o�����̂��A�����p�x�A����̎�ށj
	void Shoot(WeaponPickScene* w_pick, float x, float y, float radius, float speed, int who, float angle, int b_type);
};
