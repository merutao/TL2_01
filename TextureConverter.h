#pragma once
#include "Windows.h"
#include <string>
class TextureConverter
{
public:
	
	void ConvertTextureWICToDDS(const std::string& filePath);


private:

	//テクスチャファイルを読み込む
	void LoadWICTextureFromFile(const std::string& filePath);

	//マルチバイト文字をワイド文字に変換(DirextTexはワイド文字列でファイルパスを渡すため)
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

};

