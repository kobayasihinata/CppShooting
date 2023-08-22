#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Player;
class Enemy;

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy[MAX_ENEMY];
    Bullet* bullet[MAX_BULLET];

    int enemy_spawn_int;    //敵出現間隔
    int time;               //
public:

    //コンストラクタ
    GameMainScene();

    //デストラクタ
    ~GameMainScene();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

    //弾/プレイヤー/敵の当たり判定のチェックを行う
    void HitCheck();

    //弾の配列に新しくデータを作成する（スポーンするX座標、Y座標、弾の半径、誰が打ち出したか、弾の移動角度）
    void SpawnBullet(float x, float y,int radius,int who, float angle);
};



