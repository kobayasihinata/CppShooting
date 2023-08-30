#pragma once

#define PLAYER1_SHOT 1			//Bullet用のプレイヤーが撃った時のマクロ
#define PLAYER2_SHOT 2			//Bullet用のプレイヤーが撃った時のマクロ
#define PLAYER3_SHOT 3			//Bullet用のプレイヤーが撃った時のマクロ
#define PLAYER4_SHOT 4			//Bullet用のプレイヤーが撃った時のマクロ
#define PLAYER5_SHOT 5			//Bullet用のプレイヤーが撃った時のマクロ
#define ENEMY_SHOT  6			//Bullet用のプレイヤーが撃った時のマクロ

#define SINGLE_SHOT 1			//弾の個数用
#define DOUBLE_SHOT 2			//弾の個数用
#define TRIPLE_SHOT 3			//弾の個数用
#define QUAD_SHOT 4				//弾の個数用
#define PENTA_SHOT 5			//弾の個数用

#define STRAIGHT_SHOT 0			//弾の種類用
#define BEND_SHOT 1				//弾の種類用
#define CHASING_SHOT 2				//弾の種類用

#define SCREEN_WIDTH 1280		//画面横幅
#define SCREEN_HEIGHT 720		//画面高さ

#define MAX_BULLET 500		//画面に存在できる最大球数
#define MAX_ENEMY  10		//画面に存在できる最大敵数

struct BulletData {
	float x;		//X座標
	float y;		//Y座標
	float radius;	//半径
	float speed;	//速度
	int who;		//誰が打ち出したか
	float b_angle;	//角度
	int b_num;		//弾を同時に何発撃つか
	int h_count;	//貫通出来る敵の数
	int delete_time;//弾を消すまでの時間
	int b_type;		//弾の種類
};

struct RankingData {
	int score;		//得点
	int time;		//クリア時間
	char name;		//名前
};
