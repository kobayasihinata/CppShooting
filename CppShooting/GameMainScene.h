#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "NwaySpawner.h"

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy[MAX_ENEMY];

    int enemy_spawn_int;    //敵出現間隔

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
    static void SpawnBullet(int x,int y,int radius,int type);
};



