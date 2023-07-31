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
    int CheckCollision();

};
