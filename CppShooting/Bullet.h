#pragma once
#include"SphereCollider.h"
#include"Define.h"

class Bullet:
	public SphereCollider
{
private:
	int frame;				//�t���[���v�Z�p
	int who_shot;			//�N���������e���@1 = player  -1 = enemy
	int b_type;				//�e�̎��
	int damage;				//�^����_���[�W
	float b_speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angle_velocity;	//�p�x�̕ω���
	int bend_time;			//�Ȃ���e�p
	float rad;				//�p�x�v�Z�p
	float base_angle;		//�ŏ��̃A���O��

public:

	//�R���X�g���N�^�i�X�|�[������X���W�AY���W�A�e�̔��a�A�e�̑��x�A�N���ł��o�������A�e�̈ړ��p�x�j
	Bullet(float x, float y, float radius, float speed, int who, float b_angle);

	//�f�X�g���N�^
	~Bullet();

	//�`��ȊO�̍X�V
	void Update();

	//�`��̍X�V
	void Draw()const;

	//�_���[�W�ʂ��擾
	int GetDamage() { return damage; }

	//���W���擾
	Location GetLocation() { return location; }

	//�N����o���e�����f
	int GetBulletType() { return who_shot; }

	//�e�̊p�x���擾
	float GetAngle() { return angle; }
};


