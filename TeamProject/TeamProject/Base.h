#ifndef BASE_H
#define BASE_H

// =============
// �x�[�X�N���X
// =============
class Base
{
public:
	Base();
	virtual ~Base();

public:
	virtual void Move();
	virtual void Draw();

public:
	virtual bool CheckHit();
};

#endif // !BASE_H
