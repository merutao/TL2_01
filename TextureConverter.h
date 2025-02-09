#pragma once
#include "Windows.h"
#include <string>
#include <d3d12.h>
#include "externals/DirectXTex/DirectXTex.h"
class TextureConverter
{
public:
	
	//�w��t�@�C���̃e�N�X�`����DDS�`���ɕϊ�
	void ConvertTextureWICToDDS(const std::string& filePath);


private:

	//�e�N�X�`���t�@�C����ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�t�H���_�p�X�ƃt�@�C�����𕪗�����
	void SeparateFilePath(const std::wstring& filePath);

	//DDS�e�N�X�`���Ƃ��Ă̂����鏑���o��
	void SaveDDSTectureToFile();

	//�}���`�o�C�g���������C�h�����ɕϊ�(DirextTex�̓��C�h������Ńt�@�C���p�X��n������)
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̂���Ă�
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
};

