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
	//�e�𐶐�����i�Q�[�����C���̃|�C���^�AX���W�AY���W�A���a�A���x�A�N���ł��o�����̂��A�����p�x�A����̎�ށA�ђʂ���G�̐��j
	void Shoot(GameMainScene* gm_scene, BulletData b_data)override;
	//�e�𐶐�����i����I����ʂ̃|�C���^�AX���W�AY���W�A���a�A���x�A�N���ł��o�����̂��A�����p�x�A����̎�ށA�ђʂ���G�̐��j
	void Shoot(WeaponPickScene* w_pick, BulletData b_data);
	//�e���˗p�f�[�^���܂Ƃ߂č\���̂�Ԃ�
	BulletData UpdateBulletData(BulletData b_data, int i);
};
