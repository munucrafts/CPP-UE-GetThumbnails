// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL_GetThumbnails.generated.h"

/**
 * 
 */
UCLASS()
class GET_THUMBNAILS_API UBFL_GetThumbnails : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "SaveThumbnails")
	static void SaveThumbnail(const FAssetData& AssetData);

	UFUNCTION()
	static void RemoveBackgroundUsingPythonScript(FString AssetPath);
};
