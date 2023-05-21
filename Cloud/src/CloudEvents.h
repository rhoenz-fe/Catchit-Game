#pragma once

#include "CloudUtil.h"

namespace Cloud 
{
	class CLOUD_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		 
		int GetKeyCode() const;


	private:
		int mKeyCode;
	};

	class CLOUD_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class CLOUD_API WindowClosed 
	{

	};

}