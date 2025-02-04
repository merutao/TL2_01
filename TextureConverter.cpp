#include "TextureConverter.h"
#include <stringapiset.h>

using namespace DirectX;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);


}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド文字列に変換する
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//WICテクスチャのロード
	HRESULT result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_,scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字列を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);	//nullptrで文字数取得

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);		//文字数分のBuffer用意

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);		//変換


	return wString;
}
