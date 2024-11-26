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

	//コマンドライン引数
	enum Argument
	{
		kApplicationPath,	//アプリケーションのパス
		kFilePath,			//渡されたファイルのパス

		NumArgument
	};

	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//テクスチャコンバータのインスタンス生成
	TextureConverter converter;

	//テクスチャの変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}