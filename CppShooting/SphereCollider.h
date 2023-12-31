#pragma once

struct Location
{
    float x;    
    float y; 
    float radius;   //半径
};

class SphereCollider
{
protected:
    Location location;

public:
    //当たり判定
    bool CheckCollision(SphereCollider* s_collider);

    //座標の取得
    Location GetLocation();

};
