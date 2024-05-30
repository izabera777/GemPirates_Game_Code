#pragma once


#include "DxLib.h"

class Game;
class Player;

class UI
{
public:
	UI();		// �R���X�g���N�^
	~UI();		// �f�X�g���N�^

	void Initialize();		// ������
	void Draw(int state,Player& player,bool clearFlag);	// �`��


private:
	// �萔

	// �ϐ�
	int		menuGraph;		// ���j���[�摜
	int		menuSentenceGraph;	// ���j���[�����摜
	int		titleGraph;		// �^�C�g���摜
	int		overGraph;		// �Q�[���I�[�o�[�摜
	int		clearGraph;		// �N���A�摜
	int		timeLimitGraph;	// �������ԉ摜
	int		frameGraph;		// �g�̉摜
	int		playSentenceGraph;	// ��������摜
	int		greatGraph;			// �O���C�g�I�����摜
	int		bloodGraph;		// ���̂�摜
	int		bloodPosY;		// ���̂�摜��`�悷��Y�ʒu
	double	clearCount;		// �Q�[���N���A���Ă���̃J�E���g
	bool	countMaxFlag;	// �J�E���g�����t���O

	float	sizeRate;		// �傫��

	
	// �X�R�A
	float	distanceTraveled;	// �i�񂾋����i���[�g���Ƃ����ݒ�j


};






