#pragma once

namespace Cloud 
{
	class ImplImage
	{
	public:
		//virtual void Activate() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

	};
}