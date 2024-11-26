#pragma once
#include "Windows.h"
#include <string>
class TextureConverter
{
public:
	
	void ConvertTextureWICToDDS(const std::string& filePath);


private:

	//�e�N�X�`���t�@�C����ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�}���`�o�C�g���������C�h�����ɕϊ�(DirextTex�̓��C�h������Ńt�@�C���p�X��n������)
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

};

