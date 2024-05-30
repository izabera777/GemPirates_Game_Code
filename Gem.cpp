#include "Calculation.h"
#include "Gem.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
Gem::Gem()
	: modelHandle			(0)
	, width					(0)
	, height				(0)
	, speed					(0)
	, radius				(0.5f)
	, isHitPlayer			(false)
	, isHitGround			(false)
	, previousIsHitPlayer	(false)
	, boundPower			(0)
{
	modelHandle = MV1LoadModel("data/model/Gem/GemRed.mv1");
	pos = VGet(0, 0, 0);
	dir = VGet(0, 0, 0);
	scale = VGet(1,1,1);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Gem::~Gem()
{
	// 3D���f���̍폜
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// ������
/// </summary>
void Gem::Initialize(VECTOR initPos)
{
	pos = initPos;
	//pos = VGet(0, 0, 0);		// ���W�̐ݒ�
	//dir = VGet(0, 0, 0);		// �����̐ݒ�
	dir = VGet(0, 0, 0);		// �����̐ݒ�
	isHitPlayer = false;		// �v���C���[�ƐڐG������
	visibleFlag = true;			// ���݂��Ă��邩
	radius = 0.1;				// ���^�̂����蔻��̔��a
	isHitGround = false;		// �n��ƐڐG������
	previousIsHitPlayer = false;// �O�̃t���[���Ńv���C���[�ƐڐG������
	isHitPlayer = false;		// �v���C���[�ƐڐG����
	boundPower = 1.5f;			// �o�E���h����l
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="cal">�v�Z�N���X</param>
void Gem::Update(Calculation& cal)
{

	// �ړ����� ///////////////////////////////////////////////////
	// ������ݒ�
	//dir = VGet(0.0f, 0.0f, 0.0f);

	// ���K��
	if (VSquareSize(dir) > 0)
	{
		dir = VNorm(dir);
	}

	// �ړ��ʂ��o��
	auto velocity = VScale(dir, MOVE_SPEED);

	// �ړ�
	pos = VAdd(pos, velocity);

	// ��������
	/*if (VSize(velocity) != 0)
	{
		dir = VNorm(dir);
	}*/
	///////////////////////////////////////////////////////////////
	// �d�͏��� ////////////////////////////////////////////
	// �n�ʂɂ��Ă��Ȃ����ɍ쓮
	if (isHitGround == false)
	{
		pos.y -= GRAVITY_POWER;
	}

	// ����艺�ɂ͗����Ȃ�
	if (pos.y <= 0 && isHitGround == false)
	{
		pos.y = 0;
		isHitGround = true;
	}
	///////////////////////////////////////////////////////////////
	// �o�E���h���� ////////////////////////////////////////////
	// ���ɂ����璵�˂�
	if (isHitGround == true)
	{
		dir.y = 1;
		//isHitGround = false;
	}
	// ���`��ԂŃo�E���h����l�����߂�
	boundPower= cal.Lerp_F(boundPower, 0.0f, 0.01);
	if (pos.y >= boundPower)
	{
		// �o�E���h���ׂ���������Ȃ���
		if (boundPower <= 0.3)
		{
			boundPower = 0;
		}
		isHitGround = false;
	}
	
	// �v���C���[�ƐڐG������
	if (isHitPlayer)
	{
		dir = VGet(1000.0f, 5000.0f, 0.0f);
		isHitGround = false;
	}

	/////////////////////////////////////////////////////////////////
	
	// 3D���f���̍��W�ݒ�
	MV1SetPosition(modelHandle, pos);
}

/// <summary>
/// �`��
/// </summary>
void Gem::Draw()
{
	// 3D���f���̕`��
	MV1DrawModel(modelHandle);

	// ���^�̓����蔻��̕`��
	DrawSphere3D(pos, radius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);

	// �v���C���[�ƐڐG������
	if (isHitPlayer)
	{
		DrawFormatString(100, 100, GetColor(255, 255, 255), "Gem Hit", true);
	}
}