#include "pch.h"
#include "CloudEvents.h"

namespace Cloud
{
	KeyPressed::KeyPressed(int kCode): mKeyCode(kCode)
	{
	
	}

	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int kCode): mKeyCode(kCode)
	{
	}

	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}