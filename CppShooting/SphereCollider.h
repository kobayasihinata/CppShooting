#pragma once

struct Location
{
    float x;    
    float y; 
    float radius;   //���a
};

class SphereCollider
{
protected:
    Location location;


public:

    //�����蔻��
    int CheckCollision();

};
