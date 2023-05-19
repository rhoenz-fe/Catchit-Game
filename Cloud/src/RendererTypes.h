#pragma once

namespace Cloud {


	struct TextureBox {
		int xTexCoord{ 0 };
		int yTexCoord{ 0 };
		int texWidth{ 0 };
		int texHeight{ 0 };

		TextureBox(int xOnPicture, int yOnPicture, int boxWidth, int boxHeight) :
			xTexCoord(xOnPicture), yTexCoord(yOnPicture), texWidth(boxWidth), texHeight(boxHeight) {};
	};

	struct ScreeCoord {
		int xCoord{ 0 };
		int yCoord{ 0 };

		ScreeCoord(int x, int y) : xCoord(x), yCoord(y) {};
	};
}