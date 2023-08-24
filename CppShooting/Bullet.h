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
	int hit_count;			//�G�����̊ђʂ��邩
	int b_color;			//�e�̐F
	int delete_time;		//�e�������܂ł̎���

public:

	//�R���X�g���N�^�i�e���\���́j
	Bullet(BulletData b_data);

	//�f�X�g���N�^
	~Bullet();

	//�`��ȊO�̍X�V
	void Update(float player_x,float player_y);

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

	//�G�ɓ����������Ɋђʂ��邩���f
	int GetHitCount() { return --hit_count; }

	//�e�̐F�I��
	int GetBulletColor(int type);

	//�e���������Ԃ����f
	int GetDeleteTime() { return delete_time; }
};


