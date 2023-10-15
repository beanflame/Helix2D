#pragma once
#include "h2dMacros.h"
#include "h2dRender.h"
#include <string>

namespace helix2d
{
	//����
	class Font
	{
	public:

		Font();

		Font(const std::wstring& fontFamily, size_t fontSize = 20);
	public:

		//��ȡ������
		std::wstring getFontFamily()const;

		//��ȡ�ֺ�
		size_t getFontSize()const;
	private:

		std::wstring fontFamily;

		size_t fontSize;
	};

	//�ı�
	class Text :
		public Painter
	{
	public:

		Text();

		Text(const std::wstring& text, Font font = Font{});
	public:

		//������ʾ�ı�
		void setText(std::wstring text);

		//��������
		void setFont(Font font);
	public:

		//��ȡ��ʾ�ı�
		std::wstring getText()const;

		//��ȡ����
		Font getFont()const;
	public:

		void Render() override;
	private:

		//���´�����Դ
		void recreateSources();
	private:

		std::wstring text;

		Font font;

		IDWriteTextFormat* textFormat;

		IDWriteTextLayout* textLayout;
	};
}