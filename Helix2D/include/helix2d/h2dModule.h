#pragma once
#include "h2dMacros.h"
#include "h2dTool.h"
#include <vector>
#include <map>

namespace helix2d
{
	class Painter;
	class Window;

	//ģ��
	class Module
	{
		friend class Painter;
	public:

		enum class Type
		{
			//�޸�ģ��
			Modifier,
			//���ģ��
			Detector
		};
	public:

		Module();

		~Module();
	public:

		//��ȡ������
		Painter* getParent()const;

		//��ȡģ������
		Module::Type getModuleType()const;
	public:

		//����ģ��
		static void updateModule(Window* window, float delta);
	public:

		//��ȡ����ģ��
		static std::vector<Module*> getAllModule();
	protected:

		//����
		virtual void Update(float delta) {};

		//��Ⱦ
		virtual void BeforeRender() {};

		//��Painter��Ⱦ��
		virtual void AfterChildRender() {};
	private:

		//�����ض�����ģ��
		static void updateTypeModule(Window* window, float delta, Type type);
	protected:

		Painter* parent;
	protected:

		Type modType;
	private:

		static std::vector<Module*> allMod;
	};

	//����
	class Gravity :
		public Module
	{
	public:

		explicit Gravity(float g = 1.0f);
	public:

		//��������ϵ��
		void setGravity(float g);
	public:

		//��ȡ����ϵ��
		float getGravity()const;
	private:

		void Update(float delta) override;
	private:

		float gravity;
	};

	//����
	class Mask :
		public Module
	{
	public:

		Mask();
		Mask(float width, float height);

		~Mask();
	public:

		//����ʵ�ʿ��
		void setRealWidth(float width);
		//����ʵ�ʿ��
		void setRealHeight(float height);

		//�����Ƿ�ת
		void setInverse(bool inverse);

		//���������Painter���Ͻǵ�����
		void setPos(Vector2 pos);
		void setPos(float x, float y);
	public:

		//��ȡ�����Painter���Ͻǵ�����
		Vector2 getPos();
	private:

		void BeforeRender() override;

		void AfterChildRender() override;
	private:

		ID2D1Layer* pLayer;
		ID2D1GeometrySink* pGeoSink;
		ID2D1PathGeometry* pPathGeo;

		bool isInverse;

		float width;
		float height;

		Vector2 pos;
	private:

		static ID2D1Geometry* currGeometry;

		static std::map<Painter*, ID2D1Geometry*> lastGeometries;

		static bool isPushLayer;
	};
}