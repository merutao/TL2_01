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

	//フォルダパスとファイル名を分離する
	void SeparateFilePath(const std::wstring& filePath);

	//DDSテクスチャとしてのだいる書き出し
	void SaveDDSTectureToFile();

	//マルチバイト文字をワイド文字に変換(DirextTexはワイド文字列でファイルパスを渡すため)
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのこんてな
	DirectX::ScratchImage scratchImage_;

	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;
};

