#pragma once
#include "h2dMacros.h"
#include "h2dRender.h"
#include "h2dTool.h"
#include "h2dInbuilt.h"
#include <string>
#include <vector>
#include <map>

namespace helix2d
{
	class Window;
	class Camera;
	
	//����
	class Window
	{
		friend class Renderer;
		friend class Camera;
		friend class Input;
		friend class Inbuilt::Initialize;
	public:

		Window(
			std::wstring title = L"Helix2D",
			unsigned int width = 600, 
			unsigned int height = 600,
			Window* parent = nullptr, 
			unsigned int fps = 60
		);

		~Window();
	public:

		//��ӻ���
		void addPainter(Painter* pPainter);	
		void addPainter(Painter* pPainter, std::wstring name);

		//�Ƴ�����
		bool removePainter(Painter* pPainter);

		//���ӻ����в��һ���
		Painter* findPainter(std::wstring name);
	public:

		//���ô��ڱ�����ɫ
		void setBackgroundColor(const Color& c);

		//��������֡��
		void setFPS(unsigned int fps);

		//���������������ӵ��������
		void setCamera(Camera* camera);

		//�����Ƿ�ȫ��
		void setFullScreen(bool fullScreen);
	public:

		//��ȡ���
		unsigned int getWidth()const;
		//��ȡ�߶�
		unsigned int getHeight()const;

		//��ȡ���ھ��
		HWND getHWND()const;

		//��ȡ��Ⱦ��
		Renderer* getRenderer()const;

		//��ȡ��������ӻ���
		std::vector<Painter*> getAllPainter()const;

		//��ȡ�����
		Camera* getCamera()const;
	public:

		static void uninit();
	protected:

		virtual void Tick(float deltaTime) {};
	private:

		//��������
		void create();

		//����͸��ģʽ
		void setAlphaWindow();

		//���´���
		void Update(float delta);

		//�������
		void clearInput();
	private:

		//���Ҵ���
		static Window* findWindow(HWND hWnd);
	private:

		WNDCLASSEXW wc;

		HWND hWnd;

		std::wstring title;

		int width;
		int height;

		Window* parent;

		bool bCreated;

		bool bFullScreen;

		unsigned int fps;

		bool bWindowDone;
	private:

		Renderer* renderer;
	private:

		std::vector<Painter*> painterList;

		Camera* camera;
	private:

		Color backgroundColor = Color::White;
	private:

		std::vector<KeyCode> downKey;

		std::vector<KeyCode> downPressKey;

		std::vector<KeyCode> upPressKey;

		std::map<KeyCode, float> downKeyTime;
	private:

		std::vector<MouseCode> downMouse;

		std::vector<MouseCode> downPressMouse;

		std::vector<MouseCode> upPressMouse;

		std::map<MouseCode, float> downMouseTime;
	private:

		static size_t ordinal;

		static bool bAllWindowDone;

		static std::vector<Window*> allWindows;
	private:

		static void winControl(Window* window);

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
	};
}