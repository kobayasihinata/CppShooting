#pragma once
#include "SceneBase.h"
#include "define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletsSpawner.h"

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy;
    Bullet* bullet[MAX_BULLET];

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

    //弾の配列に新しくデータを作成する
    void SpawnBullet();
};



