#pragma once

#define PLAYER1_SHOT 1			//Bullet�p�̃v���C���[�����������̃}�N��
#define PLAYER2_SHOT 2			//Bullet�p�̃v���C���[�����������̃}�N��
#define PLAYER3_SHOT 3			//Bullet�p�̃v���C���[�����������̃}�N��
#define PLAYER4_SHOT 4			//Bullet�p�̃v���C���[�����������̃}�N��
#define PLAYER5_SHOT 5			//Bullet�p�̃v���C���[�����������̃}�N��
#define ENEMY_SHOT  6			//Bullet�p�̃v���C���[�����������̃}�N��

#define SINGLE_SHOT 1			//�e�̌��p
#define DOUBLE_SHOT 2			//�e�̌��p
#define TRIPLE_SHOT 3			//�e�̌��p
#define QUAD_SHOT 4				//�e�̌��p
#define PENTA_SHOT 5			//�e�̌��p

#define STRAIGHT_SHOT 0			//�e�̎�ޗp
#define BEND_SHOT 1				//�e�̎�ޗp
#define CHASING_SHOT 2				//�e�̎�ޗp

#define SCREEN_WIDTH 1280		//��ʉ���
#define SCREEN_HEIGHT 720		//��ʍ���

#define MAX_BULLET 500		//��ʂɑ��݂ł���ő勅��
#define MAX_ENEMY  10		//��ʂɑ��݂ł���ő�G��

struct BulletData {
	float x;		//X���W
	float y;		//Y���W
	float radius;	//���a
	float speed;	//���x
	int who;		//�N���ł��o������
	float b_angle;	//�p�x
	int b_num;		//�e�𓯎��ɉ�������
	int h_count;	//�ђʏo����G�̐�
	int delete_time;//�e�������܂ł̎���
	int b_type;		//�e�̎��
};

struct RankingData {
	int score;		//���_
	int time;		//�N���A����
	char name;		//���O
};
