#ifndef BOTTON_H
#define BOTTON_H

class Button
{
public:
	Button();
	~Button();

public:
	void Update();
	void Draw();

	void InitTexture();
	void ReleaseTexture();

public:
	int Number1;
	int Number2;
	int Number3;
	int Number4;
	int Number5;
	int Number6;
	int Number7;
	int Number8;
	int Number9;
	int Number10;
	int Number11;
	int Number12;

	int TextureSizeX;
	int TextureSizeY;

	int SelectNum;
};

#endif // !BOTTON_H
