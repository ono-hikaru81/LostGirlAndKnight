#ifndef FADE_H
#define FADE_H

//==============================
//フェードクラス
//==============================
class Fade
{
public:
	int m_alpha;
	bool m_isFading;
	int m_fadeType;

public:
	Fade();
	virtual~Fade();
	void Start(enum FadeType fadeType_);			// フェードの種類を決める
	void Draw();							// 矩形を描画する関数
	void Exec(float fadeSpeed_);			// フェード処理を実行
	bool IsFading();						// フェードが終わったかどうか
};

enum FadeType
{
	fadeIn,
	fadeOut
};

enum FadeScene
{
	Wait,
	FadeIn,
	FadeOut
};


#endif // !FADE_H
