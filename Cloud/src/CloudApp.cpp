#include "pch.h"
#include "CloudApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"

namespace Cloud 
{
	CloudApp::CloudApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(800, 600, "Test Name");

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
		//SetWindowCloseCallback(std::bind(&CloudApp::DefaultWindowCloseHandler, this));
	}

	void CloudApp::Run()
	{
	
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose) 
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Cloud::GameWindow::SwapBuffers();
			Cloud::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}

	}

	void CloudApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void CloudApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void CloudApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void CloudApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}

}