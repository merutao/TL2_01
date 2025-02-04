#pragma once
#include "Windows.h"
#include <string>
#include <d3d12.h>
#include "externals/DirectXTex/DirectXTex.h"
class TextureConverter
{
public:
	
	//指定ファイルのテクスチャをDDS形式に変換
	void ConvertTextureWICToDDS(const std::string& filePath);


private:

	//テクスチャファイルを読み込む
	void LoadWICTextureFromFile(const std::string& filePath);

	//マルチバイト文字をワイド文字に変換(DirextTexはワイド文字列でファイルパスを渡すため)
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのこんてな
	DirectX::ScratchImage scratchImage_;
};

