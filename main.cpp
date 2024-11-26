#include "Windows.h"
#include "stdio.h"
#include "stdlib.h"
#include <cassert>
#include "TextureConverter.h"
#include <combaseapi.h>


int main(int argc, char* argv[])
{

	for (int i = 0; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
	}

	//�R�}���h���C������
	enum Argument
	{
		kApplicationPath,	//�A�v���P�[�V�����̃p�X
		kFilePath,			//�n���ꂽ�t�@�C���̃p�X

		NumArgument
	};

	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//�e�N�X�`���R���o�[�^�̃C���X�^���X����
	TextureConverter converter;

	//�e�N�X�`���̕ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;
}