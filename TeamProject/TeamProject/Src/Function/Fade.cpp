#include "../Main.h"
#include "DxLib.h"
#include "Fade.h"

// ================================================================================
// フェードイン、フェードアウト
// ===============================================================================
Fade::Fade()
{
	m_alpha = 0;
	m_isFading = false;
	m_fadeType = -1;
}

Fade::~Fade()
{
}

void Fade::Start(FadeType fadeType_)
{
	m_alpha = (fadeType_ == fadeIn) ? 255 : 0;
	m_isFading = true;
	m_fadeType = fadeType_;
}

void Fade::Draw()
{
	if (m_fadeType == fadeIn)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		DrawBox(0, 0, WindowWidth, WindowHeight, GetColor(0, 0, 0), TRUE);

	}
	if (m_fadeType == fadeOut)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		DrawBox(0, 0, WindowWidth, WindowHeight, GetColor(0, 0, 0), TRUE);
	}

}

void Fade::Exec(float fadeSpeed_)
{
	if (m_fadeType == fadeIn)
	{
		m_alpha -= fadeSpeed_;
		if (m_alpha <= 0)
		{
			m_isFading = false;
		}
	}
	else if (m_fadeType == fadeOut)
	{
		m_alpha += fadeSpeed_;
		if (m_alpha >= 255)
		{
			m_isFading = false;
		}
	}
}

bool Fade::IsFading()
{
	return m_isFading;
}
