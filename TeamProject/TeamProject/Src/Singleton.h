
#ifndef SINGLETON_H
#define SINGLETON_H

// �V���O���g���f�U�C���p�^�[��
template< class T >
class Singleton
{
protected:
	Singleton(){ }				// �R���X�g���N�^�}��
	virtual ~Singleton(){ }		// �f�X�g���N�^�}��

private:
	// �������g�̃|�C���^�ϐ�(�������g�̗B��̎���)
	static T* m_pInstance;

public:
	// ���̂����֐�
	static void CreateInstansce()
	{
		// ���łɍ���Ă���Ȃ�V�������Ȃ����Ƃ�ۏ�
		if ( m_pInstance == nullptr )
		{
			m_pInstance = new T();
		}
	}
	// ���̂�j�󂷂�֐�
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
	// ���̂��擾����֐�
	static T* GetInstance()
	{
		return m_pInstance;
	}
	// ���̂����݂��邩�m�F����֐�
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};
// static�ȃ����o�ϐ���������(�R���X�g���N�^�ł͂��Ȃ�)
template< class T >
T* Singleton<T>::m_pInstance = nullptr;

#endif // !SINGLETON_H

