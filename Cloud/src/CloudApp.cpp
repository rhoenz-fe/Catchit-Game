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

	void CloudApp::Run()
	{
		/*while (true)
		{
			//OnUpdate();
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
		}*/

		/*
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			CLOUD_ERROR("Failed to initialize GLAD");
			return;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		float vdata[] = {
			200.0f, 100.0f, 0.0, 0.0,
			200.0f, 200.0f, 0.0, 1.0,
			300.0f, 200.0f, 1.0, 1.0,
			300.0f, 100.0f, 1.0, 0.0
		};
		
		int edata[] = {
			0, 1, 3,
			1, 2, 3
		};

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vdata), vdata, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edata), edata, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);*/

		

		/*
		//TEXTURE//
		unsigned int texture1;
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Images/test.png", &width, &height, &nrChannels, 0);

		if (data == nullptr) {
			std::cout << "ERROR: Image reading has failed" << std::endl;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		*/










		Renderer renderer;

		Image pic{ "../Assets/Images/test4.png" };
		pic.Activate();

		//Shader
		Shader sProgram{
			"../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl"
		};

		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mNextFrameTime = std::chrono::steady_clock::now();

		while (true) {


			/*glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);*/
			renderer.Clear();

			/*
			glBindVertexArray(VAO);
			sProgram.Activate();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);*/

			renderer.Draw(pic, { 200, 100 });

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Cloud::GameWindow::SwapBuffers();
			Cloud::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now()+ mFrameDuration;

		}




	}

}