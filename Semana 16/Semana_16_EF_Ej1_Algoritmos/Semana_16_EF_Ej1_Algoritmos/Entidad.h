/* Entidad.h */
#pragma once
using namespace System::Drawing;

class Entidad {
	protected:
		int x, y, dx, dy;
		int width, height;
		int idX_Sprite, idY_Sprite;
		char direction;

	public:
		virtual void Move(Graphics^ g) {}
		virtual void Draw(Graphics^ g, Bitmap^ sprite) {}
		virtual Rectangle getRectangle() { return Rectangle(0, 0, 0, 0); }
};