#pragma once

struct Location
{
    float x;    
    float y; 
    float radius;   //”¼Œa
};

class SphereCollider
{
protected:
    Location location;

public:
    //“–‚½‚è”»’è
    bool CheckCollision(SphereCollider* s_collider);

    //À•W‚Ìæ“¾
    Location GetLocation();

};
