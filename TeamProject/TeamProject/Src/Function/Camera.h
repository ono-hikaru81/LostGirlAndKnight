#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	Camera();
	~Camera();

	void Update();
	int ConvertPosXWorldToScreen(int x_);
	int ConvertPosYWorldToScreen(int y_);
	float GetCameraX() { return m_PosX; }
	float GetCameraY() { return m_PosY; }

private:
	int m_PosX;
	int m_PosY;
};


#endif // !CAMERA_H
