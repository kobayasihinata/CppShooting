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
    bool CheckCollision(SphereCollider* s_collider);

    //���W�̎擾
    Location GetLocation();

};
