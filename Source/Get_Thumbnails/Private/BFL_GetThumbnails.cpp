// Fill out your copyright notice in the Description page of Project Settings.


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
		// Getting the asset registry module
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

		// Getting the asset registry
		IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

		// Loading the Thumbnails from Above Created Vars (PackageFileName, AssetFullNames) and Filling the Map (ThumbnailMap)
		FThumbnailMap ThumbnailMap;
		ThumbnailTools::LoadThumbnailsFromPackage(PackageFilename, AssetFullNames, ThumbnailMap);

		// Finding the Asset's Thumbnail from the Now Filled Map Var (ThumbnailMap)
		FObjectThumbnail* ObjectThumbnail = ThumbnailMap.Find(AssetFullName);

		// Loading the ImageWrapperModule and Creating an ImageWrapper Var
		IImageWrapperModule& ImageWrapperModule = FModuleManager::Get().LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

		// Adding the ObjectThumbnail on the Image Wrapper and Compressing it to a ByteArray
		ImageWrapper->SetRaw(ObjectThumbnail->GetUncompressedImageData().GetData(), ObjectThumbnail->GetUncompressedImageData().Num(), ObjectThumbnail->GetImageWidth(), ObjectThumbnail->GetImageHeight(), ERGBFormat::BGRA, 8);
		const TArray64<uint8>& CompressedByteArray = ImageWrapper->GetCompressed();

		// Save the texture to Thumbnails Folder
		FString ThumbnailSavePath = (FPaths::ProjectDir() + "Thumbnails");
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*ThumbnailSavePath);
		FString ImageFilename = AssetData.AssetName.ToString() + ".png";
		FString CompleteImageFilePath = FPaths::Combine(ThumbnailSavePath, ImageFilename);
		FFileHelper::SaveArrayToFile(CompressedByteArray, *CompleteImageFilePath);
		RemoveBackgroundUsingPythonScript(CompleteImageFilePath);
	}
}

void UBFL_GetThumbnails::RemoveBackgroundUsingPythonScript(FString AssetPath)
{
	// Path to the Python interpreter and script
	FString ProjectDir = FPaths::ProjectDir();
	FString PythonScriptPath = ProjectDir / TEXT("Plugins/Get_Thumbnails/Content/Python/RemoveThumbnail_BG.py");

	// Command to execute the Python script
	FString PythonInterpreter = TEXT("python");
	FString Command = FString::Printf(TEXT("\"%s\" \"%s\""), *PythonScriptPath, *AssetPath);

	// Execute the command as a subprocess
	FPlatformProcess::CreateProc(*PythonInterpreter, *Command, true, false, false, nullptr, 0, nullptr, nullptr);
}
