#pragma once

#include "DxLib.h"

class Calculation;


/// <summary>
/// ��΁i�W�F���j
/// </summary>
class Gem
{
public:
	Gem();
	~Gem();

	// ���\�b�h
	void Initialize(VECTOR initPos);		// ������
	void Update(Calculation& cal);	// �X�V.
	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	const bool GetVisibleFlag() { return visibleFlag; }
	const int GetWidth() { return width; }
	const int GetHeight() { return height; }
	const float GetRadius() { return radius; }
	const bool GetIsHitPlayer() { return isHitPlayer; }
	const bool GetIsHitGround() { return isHitGround; }
	// setter
	void SetPos(const VECTOR set) { pos = set; }
	void SetIsHitPlayer(const bool set) { isHitPlayer = set; }
	void SetIsHitGround(const bool set) { isHitGround = set; }

private:
	// �萔
	const float GRAVITY_POWER = 0.1f;		// ��΂ɂ�����d�͂̒l
	const float MOVE_SPEED = 0.05f;			// �ړ����x

	// �ϐ�
	int		modelHandle;	// ���f���n���h��
	VECTOR	pos;			// �|�W�V����.
	VECTOR	dir;			// ����
	int		width;			// ��
	int		height;			// ����
	VECTOR	scale;			// �X�P�[��
	float	speed;			// �ړ��X�s�[�h
	float	radius;			// ���^�����蔻��̔��a
	bool	visibleFlag;	// ���݂��Ă��邩
	bool	isHitPlayer;	// �v���C���[�ƐڐG����
	bool	previousIsHitPlayer;	// �O�̃t���[���Ńv���C���[�ƐڐG���Ă�����
	bool	isHitGround;	// ���ƐڐG������
	float	boundPower;		// �o�E���h����l
};

