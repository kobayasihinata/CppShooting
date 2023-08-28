#include"Define.h"
#include"PadInput.h"
#include"Title.h"
#include"WeaponPickScene.h"

Title::Title()
{
	cursor_num = 0;
	cursor_y = 0;
	interval = 0;
}

Title::~Title()
{
	
}

SceneBase* Title::Update()
{
	cursor_y = cursor_num * 35;
	if (interval < 70) {
		interval++;
	}

	if (PAD_INPUT::GetLStick().ThumbY > MARGIN && interval >= 70) {
		cursor_num--;
		interval = 0;
	}
	else if (PAD_INPUT::GetLStick().ThumbY < -MARGIN && interval >= 70) {
		cursor_num++;
		interval = 0;
	}

	if (cursor_num < 0)cursor_num = 2;
	if (cursor_num > 2)cursor_num = 0;

	if (cursor_num == 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		return new WeaponPickScene();
	}
	return this;
}


void Title::Draw()const
{
	DrawString(0, 0, "ƒ^ƒCƒgƒ‹	", 0xffffff);
	DrawCircle(TITLEMODESELECT_X - 50, TITLEMODESELECT_Y - 20 + cursor_y,10,0xffffff,true);
}
