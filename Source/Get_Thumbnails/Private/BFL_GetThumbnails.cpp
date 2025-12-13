#include "BFL_GetThumbnails.h"
#include <string>
#include <AssetRegistry/AssetRegistryModule.h>
#include <ObjectTools.h>
#include <IImageWrapperModule.h>
#include "Misc/FileHelper.h"
#include "HAL/PlatformProcess.h"
#include "Serialization/ArrayWriter.h"

void UBFL_GetThumbnails::SaveThumbnail(const FAssetData& AssetData)
{
	FString PackageFilename;
	const FName AssetFullName = FName(*AssetData.GetFullName());
	TSet<FName> AssetFullNames;
	AssetFullNames.Add(AssetFullName);

	if (FPackageName::DoesPackageExist(AssetData.PackageName.ToString(), &PackageFilename))
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

		FThumbnailMap ThumbnailMap;
		ThumbnailTools::LoadThumbnailsFromPackage(PackageFilename, AssetFullNames, ThumbnailMap);
		FObjectThumbnail* ObjectThumbnail = ThumbnailMap.Find(AssetFullName);

		IImageWrapperModule& ImageWrapperModule = FModuleManager::Get().LoadModuleChecked<IImageWrapperModule>("ImageWrapper");
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

		ImageWrapper->SetRaw(ObjectThumbnail->GetUncompressedImageData().GetData(), 
							 ObjectThumbnail->GetUncompressedImageData().Num(), 
							 ObjectThumbnail->GetImageWidth(), 
							 ObjectThumbnail->GetImageHeight(), ERGBFormat::BGRA, 8);

		const TArray64<uint8>& CompressedByteArray = ImageWrapper->GetCompressed();

		FString ThumbnailSavePath = (FPaths::ProjectDir() + "Thumbnails");
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*ThumbnailSavePath);
		FString ImageFilename = AssetData.AssetName.ToString() + ".png";
		FString CompleteImageFilePath = FPaths::Combine(ThumbnailSavePath, ImageFilename);
		FFileHelper::SaveArrayToFile(CompressedByteArray, *CompleteImageFilePath);
	} 
}

void UBFL_GetThumbnails::BeginBackgroundRemoval()
{
	FString ProjectDir = FPaths::ProjectDir();

	FString PythonScriptPath = ProjectDir / ("Plugins/CPP-UE-GetThumbnails/Source/Python/BackgroundRemoval.py");
	FString PythonInterpreter = ("python");

	FString FolderPath = ProjectDir / "Thumbnails";

	FString Command = FString::Printf(TEXT("\"%s\" \"%s\""), *PythonScriptPath, *FolderPath);
	FPlatformProcess::CreateProc(*PythonInterpreter, *Command, true, false, false, nullptr, 0, nullptr, nullptr);
}
