#pragma once
#include "h2dMacros.h"
#include "h2dTool.h"
#include <string>
#include <vector>

namespace helix2d
{
	class Window;
	class Module;

	//��Ⱦ��
	class Renderer 
	{
		friend class Window;
	private:

		explicit Renderer(Window* window);

		~Renderer();
	public:

		//�����豸�����Դ
		bool createDeviceResources();
		//�����豸�����Դ
		void discardDeviceResources();
	public:

		//�����豸�޹���Դ
		static bool createDeviceIndependentResources();
		//�����豸�޹���Դ
		static void discardResources();
	private:

		//��Ⱦ
		void _render(float delta);
	public:

		static ID2D1Factory* pD2D1Factory;

		static ID2D1StrokeStyle* pD2D1MiterStrokeStyle;
		static ID2D1StrokeStyle* pD2D1BevelStrokeStyle;
		static ID2D1StrokeStyle* pD2D1RoundStrokeStyle;

		static IWICImagingFactory* pWICFactory;

		static IDWriteFactory5* pDWriteFactory;

		static IDWriteTextFormat* pDWTextFormat;
	public:

		ID2D1HwndRenderTarget* pD2D1RenderTarget;
		ID2D1SolidColorBrush* pD2D1SolidBrush;

	private:

		float fDPIScaleX;
		float fDPIScaleY;

		bool bVSyncEnabled;
		bool bDeviceResourceRecreated;
	private:

		Window* window;
	};

	//��ɫ
	class Color
	{
	public:

		//��ɫֵ
		enum 
		{
			AliceBlue = 0xF0F8FF,
			AntiqueWhite = 0xFAEBD7,
			Aqua = 0x00FFFF,
			Aquamarine = 0x7FFFD4,
			Azure = 0xF0FFFF,
			Beige = 0xF5F5DC,
			Bisque = 0xFFE4C4,
			Black = 0x000000,
			BlanchedAlmond = 0xFFEBCD,
			Blue = 0x0000FF,
			BlueViolet = 0x8A2BE2,
			Brown = 0xA52A2A,
			BurlyWood = 0xDEB887,
			CadetBlue = 0x5F9EA0,
			Chartreuse = 0x7FFF00,
			Chocolate = 0xD2691E,
			Coral = 0xFF7F50,
			CornflowerBlue = 0x6495ED,
			Cornsilk = 0xFFF8DC,
			Crimson = 0xDC143C,
			Cyan = 0x00FFFF,
			DarkBlue = 0x00008B,
			DarkCyan = 0x008B8B,
			DarkGoldenrod = 0xB8860B,
			DarkGray = 0xA9A9A9,
			DarkGreen = 0x006400,
			DarkKhaki = 0xBDB76B,
			DarkMagenta = 0x8B008B,
			DarkOliveGreen = 0x556B2F,
			DarkOrange = 0xFF8C00,
			DarkOrchid = 0x9932CC,
			DarkRed = 0x8B0000,
			DarkSalmon = 0xE9967A,
			DarkSeaGreen = 0x8FBC8F,
			DarkSlateBlue = 0x483D8B,
			DarkSlateGray = 0x2F4F4F,
			DarkTurquoise = 0x00CED1,
			DarkViolet = 0x9400D3,
			DeepPink = 0xFF1493,
			DeepSkyBlue = 0x00BFFF,
			DimGray = 0x696969,
			DodgerBlue = 0x1E90FF,
			Firebrick = 0xB22222,
			FloralWhite = 0xFFFAF0,
			ForestGreen = 0x228B22,
			Fuchsia = 0xFF00FF,
			Gainsboro = 0xDCDCDC,
			GhostWhite = 0xF8F8FF,
			Gold = 0xFFD700,
			Goldenrod = 0xDAA520,
			Gray = 0x808080,
			Green = 0x008000,
			GreenYellow = 0xADFF2F,
			Honeydew = 0xF0FFF0,
			HotPink = 0xFF69B4,
			IndianRed = 0xCD5C5C,
			Indigo = 0x4B0082,
			Ivory = 0xFFFFF0,
			Khaki = 0xF0E68C,
			Lavender = 0xE6E6FA,
			LavenderBlush = 0xFFF0F5,
			LawnGreen = 0x7CFC00,
			LemonChiffon = 0xFFFACD,
			LightBlue = 0xADD8E6,
			LightCoral = 0xF08080,
			LightCyan = 0xE0FFFF,
			LightGoldenrodYellow = 0xFAFAD2,
			LightGreen = 0x90EE90,
			LightGray = 0xD3D3D3,
			LightPink = 0xFFB6C1,
			LightSalmon = 0xFFA07A,
			LightSeaGreen = 0x20B2AA,
			LightSkyBlue = 0x87CEFA,
			LightSlateGray = 0x778899,
			LightSteelBlue = 0xB0C4DE,
			LightYellow = 0xFFFFE0,
			Lime = 0x00FF00,
			LimeGreen = 0x32CD32,
			Linen = 0xFAF0E6,
			Magenta = 0xFF00FF,
			Maroon = 0x800000,
			MediumAquamarine = 0x66CDAA,
			MediumBlue = 0x0000CD,
			MediumOrchid = 0xBA55D3,
			MediumPurple = 0x9370DB,
			MediumSeaGreen = 0x3CB371,
			MediumSlateBlue = 0x7B68EE,
			MediumSpringGreen = 0x00FA9A,
			MediumTurquoise = 0x48D1CC,
			MediumVioletRed = 0xC71585,
			MidnightBlue = 0x191970,
			MintCream = 0xF5FFFA,
			MistyRose = 0xFFE4E1,
			Moccasin = 0xFFE4B5,
			NavajoWhite = 0xFFDEAD,
			Navy = 0x000080,
			OldLace = 0xFDF5E6,
			Olive = 0x808000,
			OliveDrab = 0x6B8E23,
			Orange = 0xFFA500,
			OrangeRed = 0xFF4500,
			Orchid = 0xDA70D6,
			PaleGoldenrod = 0xEEE8AA,
			PaleGreen = 0x98FB98,
			PaleTurquoise = 0xAFEEEE,
			PaleVioletRed = 0xDB7093,
			PapayaWhip = 0xFFEFD5,
			PeachPuff = 0xFFDAB9,
			Peru = 0xCD853F,
			Pink = 0xFFC0CB,
			Plum = 0xDDA0DD,
			PowderBlue = 0xB0E0E6,
			Purple = 0x800080,
			Red = 0xFF0000,
			RosyBrown = 0xBC8F8F,
			RoyalBlue = 0x4169E1,
			SaddleBrown = 0x8B4513,
			Salmon = 0xFA8072,
			SandyBrown = 0xF4A460,
			SeaGreen = 0x2E8B57,
			SeaShell = 0xFFF5EE,
			Sienna = 0xA0522D,
			Silver = 0xC0C0C0,
			SkyBlue = 0x87CEEB,
			SlateBlue = 0x6A5ACD,
			SlateGray = 0x708090,
			Snow = 0xFFFAFA,
			SpringGreen = 0x00FF7F,
			SteelBlue = 0x4682B4,
			Tan = 0xD2B48C,
			Teal = 0x008080,
			Thistle = 0xD8BFD8,
			Tomato = 0xFF6347,
			Turquoise = 0x40E0D0,
			Violet = 0xEE82EE,
			Wheat = 0xF5DEB3,
			White = 0xFFFFFF,
			WhiteSmoke = 0xF5F5F5,
			Yellow = 0xFFFF00,
			YellowGreen = 0x9ACD32,
		};
	public:

		Color();

		Color(float r, float g, float b, float a = 1.0f);

		Color(long rgb, float a = 1.0f);
	public:

		//������ɫֵ
		void setColor(float r, float g, float b, float a = 1.0f);
		void setColor(long rgb, float a = 1.0f);
	public:

		operator D2D1_COLOR_F();
	public:

		
	public:

		float r;
		float g;
		float b;
		float a;
	};

	//����
	class Painter
	{
		friend class Window;
		friend class Renderer;
	public:

		Painter();
	public:

		//����ӻ���
		void addPainter(Painter* pPainter);
		void addPainter(Painter* pPainter, std::wstring name);

		//���ģ��
		void addModule(Module* pMod);

		//�Ƴ��ӻ���
		bool removePainter(Painter* pPainter);

		//�Ƴ�ģ��
		bool removeModule(Module* pMod);

		//���ӻ����в��һ���
		Painter* findPainter(std::wstring name);
	public:

		//��������
		void setPos(float x, float y);
		void setPos(Vector2 pos);

		//����X������
		void setPosX(float x);
		//����Y������
		void setPosY(float y);

		//��������
		void setScale(Scale scale);
		void setScale(float scaleX, float scaleY);

		//����ê��
		void setAnchor(Vector2 anchor);
		void setAnchor(float x, float y);

		//������ת�Ƕ�
		void setAngle(float angle);

		//������ɫ
		void setColor(Color c);

		//�����Ƿ�X�ᷭת�����·�ת��
		void setFlipX(bool flipX);
		//�����Ƿ�Y�ᷭת�����ҷ�ת��
		void setFlipY(bool flipY);

		//�����ٶ�
		void setVelocity(Vector2 v);
		void setVelocity(float vx, float vy);
		//����X���ٶ�
		void setVelocityX(float vx);
		//����Y���ٶ�
		void setVelocityY(float vy);

		//��������
		void setMass(float m);

		//������Ⱦ˳��
		void setOrder(size_t nOrder);

		//��������
		void setName(std::wstring name);

		//�����Ƿ�����Tick����
		void enableTick(bool b);
		//�����Ƿ�����Render����
		void enableRender(bool b);
		//�����Ƿ����
		void enableUpdate(bool b);
	public:

		//�ƶ�����
		void movePos(float x, float y);
		void movePos(Vector2 pos);

		//�ƶ�X������
		void movePosX(float x);
		//�ƶ�Y������
		void movePosY(float y);

		//�Ե�ǰ����ǰ��
		void moveAhead(float size);
		//��ָ������ǰ��
		void moveAhead(float size, float angle);

		//��ת
		void rotate(float angle);

		//X�ᷭת�����·�ת��
		void flipX();
		//Y�ᷭת�����ҷ�ת��
		void flipY();

		//�����ٶ�
		void addVelocity(Vector2 a);
		void addVelocity(float ax, float ay);
		//����X���ٶ�
		void addVelocityX(float a);
		//����Y���ٶ�
		void addVelocityY(float a);

		//�Ե�ǰ�������
		void addVelocityAhead(float size);
		//��ָ���������
		void addVelocityAhead(float size, float angle);
	public:

		//��ȡ�������ڴ���
		Window* getWindow()const;

		//��ȡ������
		Painter* getParent()const;

		//��ȡ�����ӻ���
		std::vector<Painter*> getAllPainter()const;
		//��ȡ���������ģ��
		std::vector<Module*> getAllModule()const;

		//��ȡ����
		Vector2 getPos()const;
		//��ȡX������
		float getPosX()const;
		//��ȡY������
		float getPosY()const;

		//��ȡʵ�ʿ��
		float getRealWidth()const;
		//��ȡʵ�ʸ߶�
		float getRealHeight()const;

		//��ȡ����
		Scale getScale()const;
		//��ȡX������
		float getScaleX()const;
		//��ȡY������
		float getScaleY()const;

		//��ȡê��
		Vector2 getAnchor()const;

		//��ȡ��ת�Ƕ�
		float getAngle()const;

		//��ȡ��������
		Vector2 getWorldPos()const;

		//��ȡʵ������
		Vector2 getRealPos()const;

		//��ȡ���Ͻ����꣨��ʾ��С�£�
		Vector2 getDisplayUpperleftPos()const;

		//��ȡ���Ͻ����꣨ԭʼ��С�£�
		Vector2 getUpperleftPos()const;
		//��ȡ���Ͻ�X���꣨ԭʼ��С�£�
		float getUpperleftPosX()const;
		//��ȡ���Ͻ�Y���꣨ԭʼ��С�£�
		float getUpperleftPosY()const;

		//��ȡ���½����꣨ԭʼ��С�£�
		Vector2 getLowerrightPos()const;
		//��ȡ���½�X���꣨ԭʼ��С�£�
		float getLowerrightPosX()const;
		//��ȡ���½�Y���꣨ԭʼ��С�£�
		float getLowerrightPosY()const;

		//��ȡ���Ͻ����꣨ԭʼ��С�£�
		Vector2 getUpperrightPos()const;
		//��ȡ���Ͻ�X���꣨ԭʼ��С�£�
		float getUpperrightPosX()const;
		//��ȡ���Ͻ�Y���꣨ԭʼ��С�£�
		float getUpperrightPosY()const;

		//��ȡ���½����꣨ԭʼ��С�£�
		Vector2 getLowerleftPos()const;
		//��ȡ���½�X���꣨ԭʼ��С�£�
		float getLowerleftPosX()const;
		//��ȡ���½�Y���꣨ԭʼ��С�£�
		float getLowerleftPosY()const;

		//��ȡ�ٶ�
		Vector2 getVelocity()const;
		//��ȡX���ٶ�
		float getVelocityX()const;
		//��ȡY���ٶ�
		float getVelocityY()const;

		//��ȡ����
		float getMass()const;

		//��ȡ��Ⱦ˳��
		size_t getOrder()const;

		//��ȡ����
		std::wstring getName()const;
	public:

		//�Ƿ������������ص�
		bool isOverlap(const Painter* other)const;

		//�Ƿ�����Tick����
		bool isEnableTick()const;
		//�Ƿ�����Render����
		bool isEnableRender()const;
		//�Ƿ����
		bool isEnableUpdate()const;
	public:

		//����ͼ��
		void paint();
		void paint(Vector2 pos, float angle);
		void paint(Window* window);
		void paint(Vector2 pos, float angle, Window* window);
	public:

		//ÿ֡����һ��
		virtual void Tick(float delta) {};
	public:

		//����Ĭ��ê��
		static void setDefaultAnchor(Vector2 pos);
		static void setDefaultAnchor(float x, float y);

		//��������
		static void updateProperty(Window* window);

		//����Tick
		static void updateTick(Window* window, float delta);

		//������Ⱦ
		static void updateRender(Window* window);

		//ÿ֡������һ��
		static void updateEnd(Window* window, float delta);
	protected:

		//��Ⱦ
		virtual void Render() {};

		//���ӻ�����Ⱦ֮�����
		virtual void AfterChildRender() {};

		//�ڸ�������ʱ����
		virtual void UpdateProperty() {};
	private:

		void _render();

		void _render(Vector2 pos, float angle, Window* window);		

		void _update(float delta);

		void _updateModule(float delta);
	private:

		void setWindow(Window* window);

		void updateProperty();
		void updateEnd(float delta);
		
		//ģ������
		void sortModule();
		//��Ⱦ����
		void sortOrder();
	protected:

		//��ʾ���
		float width;
		//��ʾ�߶�
		float height;

		//ʵ�ʿ��
		float realWidth;
		//ʵ�ʸ߶�
		float realHeight;

		float angle;
		float realAngle;

		Scale scale;

		Color color;

		size_t order;

		std::wstring name;
	protected:

		Vector2 velocity;

		float mass;
	protected:

		Window* window;

		Painter* parent;
	private:

		float fFlipX;
		float fFlipY;
	private:

		//�������
		Vector2 pos;

		//��������
		Vector2 worldPos;

		//ʵ������
		Vector2 realPos;

		//��ת����
		Matrix3x2 rotationMatrix;

		//ʵ������
		Scale realScale;
	private:

		Vector2 anchor;

		bool bEnableTick;
		bool bEnableRender;
		bool bEnableUpdate;

		bool bSortModule;

		bool bSortOrder;
	private:

		std::vector<Painter*> painterList;
		std::vector<Module*> modList;
	private:

		static Vector2 defaultAnchor;
	};
}
