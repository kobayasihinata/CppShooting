#pragma once

class SceneBase
{
protected:


public:

	//描画以外の更新
	virtual SceneBase* Update() = 0;

	//描画の更新
	virtual void Draw() const = 0;

};

