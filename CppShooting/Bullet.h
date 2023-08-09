#pragma once
#include"SphereCollider.h"
#include"Define.h"

class Bullet:
	public SphereCollider
{
private:
	int damage;				//�^����_���[�W
	float speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angulVelocity;	//�p�x�̕ω���

public:

	//�R���X�g���N�^
	Bullet(float x, float y, float radius);

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
};


