#pragma once
#include "h2dMacros.h"
#include <string>
#include <random>

namespace helix2d
{
	enum class KeyCode;
	enum class MouseCode;

	class Window;

	//��ά����
	class Vector2
	{
	public:

		Vector2();

		Vector2(const D2D1_POINT_2F& point);

		Vector2(float x, float y);
	public:

		Vector2 operator+(const Vector2& vec)const;

		Vector2 operator-(const Vector2& vec)const;

		Vector2 operator=(const Vector2& vec);

		Vector2 operator+=(const Vector2& vec);

		Vector2 operator-=(const Vector2& vec);

		Vector2 operator*(float num)const;
		friend Vector2 operator*(float num, const Vector2& vec);
		Vector2 operator/(float num)const;

		Vector2 operator*=(float num);
		Vector2 operator/=(float num);

		Vector2 operator-();

		operator D2D1_POINT_2F();
	public:

		//���
		float dot(const Vector2& vec)const;

		//���
		Vector2 cross(const Vector2& vec)const;
	public:

		//��ȡ����
		Vector2 getLeftNormalLine()const;
		//��ȡ�ҷ���
		Vector2 getRightNormalLine()const;

		//��ȡ������֮�����
		float getDistance(const Vector2& vec)const;

		//��ȡ������ģ�����ȣ�
		float getModulus()const;

		//��ȡ��λ����
		Vector2 getUnit()const;
	public:

		//��ȡ������֮�����
		static float getDistance(const Vector2& vec1, const Vector2& vec2);

		//���
		static float dot(const Vector2& vec1, const Vector2& vec2);

		//���
		static Vector2 cross(const Vector2& vec1, const Vector2& vec2);
	public:

		float x;
		float y;
	};

	//����
	using Scale = Vector2;

	//3x2����
	using Matrix3x2 = D2D1::Matrix3x2F;

	//����
	class Input
	{
		friend class Window;
	public:

		//�Ƿ���ָ���������Ұ���ʱ��ﵽ�೤ʱ��
		static bool isDown(Window* window, const KeyCode& key, float downTime = 0.0f);
		static bool isDown(Window* window, const MouseCode& key, float downTime = 0.0f);

		//�Ƿ��ɿ�ָ������
		static bool isRelease(Window* window, const KeyCode& key);
		static bool isRelease(Window* window, const MouseCode& key);

		//�Ƿ���ָ���������ҵ��ʱ��ﵽ�೤ʱ�䣨̧��ʱ��
		static bool isUpPress(Window* window, const KeyCode& key, float downTime = 0.0f);
		static bool isUpPress(Window* window, const MouseCode& key, float downTime = 0.0f);

		//�Ƿ���ָ������������ʱ��
		static bool isDownPress(Window* window, const KeyCode& key);
		static bool isDownPress(Window* window, const MouseCode& key);
	private:

		static void addKeyCode(Window* window, const KeyCode& key);
		static void removeKeyCode(Window* window, const KeyCode& key);

		static void addMouseCode(Window* window, const MouseCode& key);
		static void removeMouseCode(Window* window, const MouseCode& key);

		static KeyCode getLRKeyCode(const KeyCode& key, LPARAM lparam);
	};

	//������
	enum class MouseCode
	{
		Left,
		Mid,
		Right
	};

	//���̼���
	enum class KeyCode
	{
		Unknown = 0,
		Up = VK_UP,
		Left = VK_LEFT,
		Right = VK_RIGHT,
		Down = VK_DOWN,
		Enter = VK_RETURN,
		Space = VK_SPACE,
		Esc = VK_ESCAPE,

		Ctrl = VK_CONTROL,
		LCtrl = VK_LCONTROL,
		RCtrl = VK_RCONTROL,

		Shift = VK_SHIFT,
		LShift = VK_LSHIFT,
		RShift = VK_RSHIFT,

		Alt = VK_MENU,
		LAlt = VK_LMENU,
		RAlt = VK_RMENU,

		Tab = VK_TAB,
		Delete = VK_DELETE,
		Back = VK_BACK,
		Home = VK_HOME,
		End = VK_END,
		Insert = VK_INSERT,
		PageUp = VK_PRIOR,
		PageDown = VK_NEXT,

		A = 0x41,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,

		Num0 = 0x30,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,

		Numpad0 = VK_NUMPAD0,
		Numpad1,
		Numpad2,
		Numpad3,
		Numpad4,
		Numpad5,
		Numpad6,
		Numpad7,
		Numpad8,
		Numpad9,

		NumpadAdd = VK_ADD,
		NumpadMinus = VK_SUBTRACT,
		NumpadMultiply = VK_MULTIPLY,
		NumpadDivide = VK_DIVIDE,
		NumpadDot = VK_DECIMAL,

		F1 = VK_F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,

		Add = VK_OEM_PLUS,
		Minus = VK_OEM_MINUS,
		Comma = VK_OEM_COMMA,
		Dot = VK_OEM_PERIOD,
		Backslash = VK_OEM_5,
		Slash = VK_OEM_2,
		Semicolon = VK_OEM_1,
		LSquareBrackets = VK_OEM_4,
		RSquareBrackets = VK_OEM_6,
		Apostrophe = VK_OEM_7,
		Tilde = VK_OEM_3,
	};

	//��ѧ����
	class Math
	{
	public:

		//Բ����
		static const float Pi;
		static const float e;
	public:

		//�Ƕ�ת����
		static float getRadian(float angle);

		//����ת�Ƕ�
		static float getAngle(float radian);
	};

	//��־
	class Logger
	{
	public:

		//����
		static void warning(std::wstring detail);

		//����
		static void error(std::wstring detail);

		//��Ϣ
		static void message(std::wstring detail);

		//�Ƿ����þ�����־
		static void enableWarning(bool b);

		//�Ƿ����ô�����־
		static void enableError(bool b);

		//�Ƿ�������Ϣ��־
		static void enableMessage(bool b);
	private:

		static bool isEnableWarning;
		static bool isEnableError;
		static bool isEnableMessage;
	};

	class Random
	{
	public:

		template<typename T>
		static T range(T min, T max)
		{
			std::uniform_real_distribution<T> maker(min, max);
			return static_cast<T>(maker(seedGenerator));
		}

		static double range(double min, double max);

		static float range(float min, float max);

		static int range(int min, int max);

		static bool probability(float probability);
	private:

		static std::default_random_engine engine;
		static std::random_device seedGenerator;
	};
}
