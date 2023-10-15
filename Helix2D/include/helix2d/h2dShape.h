#pragma once
#include "h2dRender.h"


namespace helix2d
{
	//Բ��
	class Circle :
		public Painter
	{
	public:

		Circle();

		Circle(float radiusX, float radiusY);

		Circle(float radius);
	public:

		//���ð뾶
		void setRadius(float radiusX, float radiusY);
		//����X��뾶
		void setRadiusX(float radiusX);
		//����Y��뾶
		void setRadiusY(float radiusY);
	public:

		//��ȡX��뾶
		float getRadiusX()const;
		//��ȡY��뾶
		float getRadiusY()const;
	public:

		void Render() override;
	};

	//����
	class Rect :
		public Painter
	{
	public:

		Rect();

		Rect(float width, float height);

		Rect(float side);
	public:

		//����ʵ�ʿ��
		void setRealWidth(float width);
		//����ʵ�ʸ߶�
		void setRealHeight(float height);
	public:

		//��ȡ���
		float getWidth()const;
		//��ȡ�߶�
		float getHeight()const;
	public:

		void Render()override;
	};

	//ֱ��
	class Line :
		public Painter
	{
	public:

		Line();

		Line(Vector2 ep1, Vector2 ep2, float width = 2.0f);
	public:

		//���������˵�
		void setEndpoint(Vector2 ep1, Vector2 ep2);

		//�����������
		void setLineWidth(float width);
	public:

		//��ȡ�����˵�
		void getEndpoint(Vector2& ep1, Vector2& ep2)const;

		//��ȡ�������
		float getLineWidth()const;

		//��ȡʵ�ʰ�Χ���
		float getRealBoundingWidth()const;
		//��ȡʵ�ʰ�Χ�߶�
		float getRealBoundingHeight()const;

		//��ȡʵ�ʰ�Χ���
		float getBoundingWidth()const;
		//��ȡʵ�ʰ�Χ�߶�
		float getBoundingHeight()const;
	public:

		void Render() override;
	private:

		Vector2 endpoint1;
		Vector2 endpoint2;

		float lineWidth;
	};
}