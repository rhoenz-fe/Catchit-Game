#pragma once

#include "pch.h"
#include "CloudUtil.h"
#include "WindowImplementation.h"

namespace Cloud
{
	class CLOUD_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int GetWidth();
		static int GetHeight();

		~GameWindow();
	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };
		
		WindowImplementation* mImplementation{ nullptr };

	};
}