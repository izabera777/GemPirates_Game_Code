#include "Game.h"
#include "Player.h"
#include "UI.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
UI::UI()
	:	menuGraph			(-1)
	,	titleGraph			(-1)
	,	timeLimitGraph		(-1)
	,	frameGraph			(-1)
	,	distanceTraveled	(-1)
	,	menuSentenceGraph	(-1)
	,	clearGraph			(-1)
	,	overGraph			(-1)
	,	playSentenceGraph	(-1)
	,	greatGraph			(-1)
	,	bloodGraph			(-1)
	,	bloodPosY			(0)
	,	clearCount			(0)
	,	countMaxFlag		(false)
	
{
	// �����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
UI::~UI()
{
	// �����Ȃ�
}


/// <summary>
/// ������
/// </summary>
void UI::Initialize()
{
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/Menu/GemPiratesMenuGraph.png");
	}
	if (titleGraph < 0)
	{
		titleGraph = LoadGraph("data/texture/JUMP&JUMP.png");
	}
	if (menuSentenceGraph < 0)
	{
		menuSentenceGraph = LoadGraph("data/texture/SPACE�ŃQ�[���X�^�[�g�I.png");
	}
	if (clearGraph < 0)
	{
		clearGraph = LoadGraph("data/texture/GameClearImg.png");
	}
	if (overGraph < 0)
	{
		overGraph = LoadGraph("data/texture/GameOverImg.png");
	}
	if (playSentenceGraph < 0)
	{
		playSentenceGraph = LoadGraph("data/texture/�����g.png");
	}
	if (greatGraph < 0)
	{
		greatGraph = LoadGraph("data/texture/GREAT.png");
	}
	if (bloodGraph < 0)
	{
		bloodGraph = LoadGraph("data/texture/blood1600x960.png");
	}

	distanceTraveled = 0;
	clearCount = 0;
}


/// <summary>
/// �`��
/// </summary>
void UI::Draw(int state, Player& player, bool clearFlag)
{

	int _uiColor = GetColor(200, 200, 200);
	// �X�e�[�g���Ƃɕ`���ύX
	switch (state)
	{
		// �^�C�g��
	case STATE_MENU:

		// ������`��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Menu", true);

		// �^�C�g���w�i�̕`��
		DrawGraph(0, 0, menuGraph, true);

		break;

		// �Q�[����
	case STATE_GAME:
		


		break;

		// �N���A���
	case STATE_CLEAR:

		// �N���A����
		DrawRotaGraph(800, 400, 1, 0, clearGraph, true);
		// �\��
		SetFontSize(100);
		DrawFormatString(300, 700, GetColor(255, 255, 255), "SPACE�Ń��j���[��", true);

		break;

		// �Q�[���I�[�o�[
	case STATE_GAMEOVER:

		// �Q�[���I�[�o�[����
		DrawRotaGraph(800, 400, 1, 0, overGraph, true);
		// �\��
		SetFontSize(100);
		DrawFormatString(300, 700, GetColor(255, 255, 255), "SPACE�Ń��j���[��", true);
		break;

	default:
		break;
	}



}
